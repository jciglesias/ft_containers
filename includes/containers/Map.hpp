// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/04 09:32:15 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/24 18:03:08 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_HPP
# define MAP_HPP

# include "../ft.hpp"
# include "../binary_search_tree/map_bst.hpp"
# include "../iterators/bst_iterator.hpp"
# include "../iterators/bst_reverse_iterator.hpp"

template <class Key, class T, class Compare, class Alloc>
class ft::map {
public:
	typedef Key							key_type;
	typedef T							mapped_type;
	typedef ft::pair<const Key, T>		value_type;
	typedef Compare						key_compare;
	typedef Alloc						allocator_type;

	class value_compare{
		friend class map<Key, T, Compare, Alloc>;
	protected:
		key_compare	comp;
		value_compare(key_compare c) : comp(c) {}
	public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		bool operator()(const value_type &x, const value_type &y) const{
			return comp(x.first, y.first);
		}
	};

	typedef t_node<value_type>*										pointer;
	typedef t_node<value_type>*										const_pointer;
	typedef	ft::bst_iterator<Key, T>								iterator;
	typedef ft::bst_iterator<Key, T>								const_iterator;
	typedef	ft::bst_reverse_iterator<iterator>						reverse_iterator;
	typedef ft::bst_reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef typename iterator::reference							reference;
	typedef typename const_iterator::reference						const_reference;
	typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	typedef typename allocator_type::size_type						size_type;
/*
**member functions
*/
	explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) : _alloc(alloc), _size(0), _comp(comp){}
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) :
		_alloc(alloc), _size(0), _comp(comp){
		_size = ft::distance(first, last);
		while (first != last)
			_bst.insert(*first++);
	}
	map(const map &x) : _alloc(x.get_allocator()), _size(x.size()), _comp(x.key_comp()){
		map::iterator it = x.begin();
		for (size_type i = 0; i < _size; i++){
			_bst.insert(ft::make_pair(it->first, it->second));
			it++;
		}
	}
	~map(){}
	map& operator=(const map &x){
		if (this != &x){
			this->clear();
			if (x.size())
				this->insert(x.begin(), x.end());
		}
		return *this;
	}
/*
**iterators
*/
	iterator begin(){
		iterator tmp(iterator(this->_bst.smallest(), _bst.end()));
		return tmp;
	}
	const_iterator begin() const {
		return const_iterator(_bst.smallest(), _bst.end());
	}
	iterator end(){ return iterator(_bst.end(), _bst.end()); }
	const_iterator end() const{
		return const_iterator(_bst.end(), _bst.end());
	}
	reverse_iterator rbegin(){
		return reverse_iterator(iterator(_bst.biggest(), _bst.rend()));
	}
	const_reverse_iterator rbegin() const{
		return const_reverse_iterator(iterator(_bst.biggest(), _bst.rend()));
	}
	reverse_iterator rend(){
		return reverse_iterator(iterator(_bst.rend(), _bst.rend()));
	}
	const_reverse_iterator rend() const{
		return const_reverse_iterator(iterator(_bst.rend(), _bst.rend()));
	}
/*
**capacity
*/
	bool empty() const {return (_size == 0);}
	size_type size() const{return _bst.size();}
	size_type max_size() const{return (std::allocator< t_node<value_type> >()).max_size();}
/*
**element access
*/
	mapped_type & operator[](const key_type &k){
		pointer	tmp(_bst.search(k));

		if (tmp == 0){
			_bst.insert(ft::make_pair(k,T()));
			tmp = _bst.search(k);
			_size++;
		}
		return (tmp->val.second);
	}
/*
**modifiers
*/
	ft::pair<iterator, bool> insert(const value_type &val){
		if (_bst.insert(val) == false){
			return (ft::make_pair(iterator(_bst.search(val.first), _bst.end()), false));
		}
		return ft::make_pair(iterator(_bst.search(val.first), _bst.end()), true);
	}
	iterator insert(iterator pos, const value_type &val){
		(void)pos;
		_bst.insert(val);
		return (iterator(_bst.search(val.first), _bst.end()));
	}
	template < class InputIterator >
	void insert(InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
		while (first != last){
			insert(*(first++));
			_size++;
		}
	}
	void erase(iterator pos){
		_bst.erase(pos.base());
		_size--;
	}
	size_type erase(const key_type &k){
		iterator tmp = this->find(k);
		if (tmp == this->end())
			return (0);
		this->erase(tmp);
		return (1);
	}
	void erase(iterator first, iterator last){
		while (first != last)
			this->_bst.erase(first++.base());
		_size = _bst.size();
	}
	void swap(map &x){
		if (this != &x){
			map tmp(x);

			x = *this;
			*this = tmp;
		}
	}
	void clear(){
		_bst.erase_tree();
		_size = 0;
	}
/*
**observers
*/
	key_compare key_comp() const{
		return _comp;
	}
	value_compare value_comp()const{ return value_compare(_comp);}
/*
**operations
*/
	iterator find(const key_type &k){
		pointer		n = _bst.search(k);
		iterator	tmp(n != 0 ? n : _bst.end(), _bst.end());
		return (tmp);
	}
	const_iterator find(const key_type &k) const{
		pointer		n = _bst.search(k);
		const_iterator tmp(n != 0 ? n : _bst.end(), _bst.end());
		return (tmp);
	}
	size_type count(const key_type &k) const{
		if (_bst.search(k) != 0)
			return (1);
		return (0);
	}
	iterator lower_bound(const key_type &k){
		iterator tmp(_bst.smallest(), _bst.end());
		for (size_type i = 0; i < _bst.size(); i++){
			if (!_comp(tmp->first, k))
				return (tmp);
			++tmp;
		}
		return (this->end());
	}
	const_iterator lower_bound(const key_type & k) const{
		const_iterator tmp(_bst.smallest(), _bst.end());
		for (size_type i = 0; i < _bst.size(); i++){
			if (!_comp(tmp->first, k))
				return (tmp);
			++tmp;
		}
		return (this->end());
	}
	iterator upper_bound(const key_type &k){
		iterator tmp(_bst.smallest(), _bst.end());
		for (size_type i = 0; i < _bst.size(); i++){
			if (_comp(k, tmp->first))
				return (tmp);
			++tmp;
		}
		return (this->end());
	}
	const_iterator upper_bound(const key_type &k) const{
		const_iterator tmp(_bst.smallest(), _bst.end());
		for (size_type i = 0; i < _bst.size(); i++){
			if (_comp(k, tmp->first))
				return (tmp);
			++tmp;
		}
		return (this->end());
	}
	ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const{
		return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
	}
	ft::pair<iterator, iterator> equal_range(const key_type &k){
		return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
	}
/*
**allocator
*/
	allocator_type get_allocator() const{return _alloc;}
private:
	allocator_type	_alloc;
	map_bst<Key, T>	_bst;
	size_type		_size;
	key_compare		_comp;
};

namespace ft{
	template < class Key, class T, class Compare, class Alloc >
	bool operator==(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs){
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template < class Key, class T, class Compare, class Alloc >
	bool operator!=(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs){
		if (lhs.size() != rhs.size())
			return (true);
		return (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template < class Key, class T, class Compare, class Alloc >
	bool operator<(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template < class Key, class T, class Compare, class Alloc >
	bool operator<=(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs){
		return (!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	template < class Key, class T, class Compare, class Alloc >
	bool operator>(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs){
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	template < class Key, class T, class Compare, class Alloc >
	bool operator>=(const ft::map<Key, T, Compare, Alloc> & lhs, const ft::map<Key, T, Compare, Alloc> & rhs){
		return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
/*	template < class T, class Alloc >
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y){
		x.swap(y);
		}*/
}

#endif
