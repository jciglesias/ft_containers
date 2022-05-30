// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/04 09:32:15 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/30 12:18:27 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_HPP
# define MAP_HPP

# include "ft.hpp"
# include "map_bst.hpp"
# include "bst_iterator.hpp"

template <class Key, class T, class Compare, class Alloc>
class ft::map {
public:
	typedef Key						key_type;
	typedef T						mapped_type;
	typedef pair<Key, T>			value_type;
	typedef Compare					key_compare;
	typedef Alloc					allocator_type;

	class value_compare{
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

//	typedef typename allocator_type::reference						reference;
//	typedef typename allocator_type::const_reference				const_reference;
//	typedef typename allocator_type::pointer						pointer;
//	typedef typename allocator_type::const_pointer					const_pointer;
	typedef	ft::bst_iterator<Key, T>								iterator;
	typedef ft::bst_iterator<const Key, const T>					const_iterator;
	typedef	ft::reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	typedef typename iterator::reference							reference;
	typedef typename const_iterator::reference						const_reference;
	typedef typename iterator::pointer								pointer;
	typedef typename const_iterator::pointer						const_pointer;
	typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	typedef typename allocator_type::size_type						size_type;
/*
**member functions
*/
	explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) : _alloc(alloc), _size(0), _comp(comp){}
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type()) :
		_alloc(alloc), _bst(0), _size(0), _comp(comp){
		_size = ft::distance(first, last);
		while (first != last)
			_bst.insert(*first++);
	}
	map(const map &x) : _alloc(x.get_allocator()), _size(x.size()), _comp(x.key_comp()){
		for (size_type i = 0; i < _size; i++)
			_bst.insert(*(x.begin() + i));
	}
	~map(){}
	map &operator=(const map &x){
		if (*this != x){
			this->clear();
			this->insret(x.begin(), x.end());
		}
		return *this;
	}
/*
**iterators
*/
	iterator begin(){
		iterator tmp(iterator(this->_bst.smallest(), _bst.end));
		return tmp;
	}
	const_iterator begin() const{return const_iterator(_bst.smallest());}
	iterator end(){return iterator(&_bst.end, &_bst.end);}
	const_iterator end() const{return const_iterator(&_bst.end, &_bst.end);}
	reverse_iterator rbegin(){return reverse_iterator(_bst.biggest(), &_bst.rend);}
	const_reverse_iterator rbegin() const{return const_reverse_iterator(_bst.biggest(), &_bst.rend);}
	reverse_iterator rend(){return reverse_iterator(&_bst.rend, &_bst.rend);}
	const_reverse_iterator rend() const{return const_reverse_iterator(&_bst.rend, &_bst.rend);}
/*
**capacity
*/
	bool empty(){return (_size == 0);}
	size_type size() const{return _bst.size();}
	size_type max_size() const{return _alloc.max_size();}
/*
**element access
*/
	mapped_type & operator[](const key_type &k){
		pointer	tmp(_bst.search(k));

		if (tmp == 0){
			_bst.insert(make_pair(k,0));
			tmp = _bst.search(k);
		}
		return (tmp->second);
	}
/*
**modifiers
*/
	pair<iterator, bool> insert(const value_type &val){
		if (_bst.insert(val) == false)
			return (make_pair(iterator(_bst.search(val.first), _bst.end()), false));
		return make_pair(iterator(_bst.search(val.first), _bst.end()), true);
	}
	iterator insert(iterator pos, const value_type &val){
		(void)pos;
		_bst.insert(val);
		return (iterator(_bst.search(val.first), &_bst.end));
	}
	template < class InputIterator >
	void insert(InputIterator first, InputIterator last){
		while (first != last)
			insert(*first++);
	}
	void erase(iterator pos){
		_bst.erase(pos.base());
	}
	size_type erase(const key_type &k){
		iterator tmp = this->find(k);
		if (tmp == 0)
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
		if (*this != x){
			map tmp(x);

			x = *this;
			*this = tmp;
		}
	}
	void clear(){
		_bst.erase_tree(_bst.root());
		_size = 0;
	}
/*
**observers
*/
	key_compare key_comp() const{ return _comp;}
	value_compare value_comp()const{ return value_compare(_comp);}
/*
**operations
*/
	iterator find(const key_type &k){
		pointer		n = _bst.search(k);
		iterator	tmp(n != 0 ? n : &_bst.end, &_bst.end);
		return (tmp);
	}
	const_iterator find(const key_type &k) const{
		pointer		n = _bst.search(k);
		const_iterator tmp(n != 0 ? n : &_bst.end, &_bst.end);
		return (tmp);
	}
	size_type count(const key_type &k) const{
		if (_bst.search(k) != 0)
			return (1);
		return (0);
	}
	iterator lower_bound(const key_type &k){
		iterator tmp(_bst.smallest(), &_bst.end);
		for (size_type i = 0; i < _bst.size(); i++){
			if (!_comp(tmp->first, k))
				return (tmp);
			++tmp;
		}
		return (this->end());
	}
	const_iterator lower_bound(const key_type & k) const{
		const_iterator tmp(_bst.smallest(), &_bst.end);
		for (size_type i = 0; i < _bst.size(); i++){
			if (!_comp(tmp->first, k))
				return (tmp);
			++tmp;
		}
		return (this->end());
	}
	iterator upper_bound(const key_type &k){
		iterator tmp(_bst.smallest(), &_bst.end);
		for (size_type i = 0; i < _bst.size(); i++){
			if (_comp(k, tmp->first))
				return (tmp);
			++tmp;
		}
		return (this->end());
	}
	const_iterator upper_bound(const key_type &k) const{
		const_iterator tmp(_bst.smallest(), &_bst.end);
		for (size_type i = 0; i < _bst.size(); i++){
			if (_comp(k, tmp->first))
				return (tmp);
			++tmp;
		}
		return (this->end());
	}
	pair<const_iterator, const_iterator> equal_range(const key_type &k) const{
		return make_pair(this->lower_bound(k), this->upper_bound(k));
	}
	pair<iterator, iterator> equal_range(const key_type &k){
		return make_pair(this->lower_bound(k), this->upper_bound(k));
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

#endif
