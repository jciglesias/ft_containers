// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/04 09:32:15 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/16 01:39:05 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_HPP
# define MAP_HPP

namespace ft{class map;}

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
	}

	typedef typename allocator_type::reference						reference;
	typedef typename allocator_type::const_reference				const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef	ft::random_access_iterator<value_type>					iterator;
	typedef ft::random_access_iterator<const value_type>			const_iterator;
	typedef	ft::reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	typedef typename allocator_type::size_type						size_type;
/*
**member functions
*/
	explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) : _alloc(alloc), _start(0), _end(0), _size(0), _comp(comp){}
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type()) :
		_alloc(alloc), _start(0), _end(0), _size(0), _comp(comp){
		_size = ft::distance(first, last);
		_capacity = _size;
		_start = _alloc.allocate(_size);
		_end = _start;
		while (first != last)
			_alloc.construct(_end++, *first++);
	}
	map(const map &x) : _alloc(x.get_allocator()), _start(0), _end(0), _size(x.size()), _comp(x.key_comp()){
		_capacity = _size;
		_start = _alloc.allocate(_size);
		_end = _start;
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(_end++, *(x.begin() + i));
	}
	~map(){_alloc.deallocate(_capacity);}
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
	iterator begin(){return iterator(_start);}
	const_iterator begin() const{return const_iterator(_start);}
	iterator end(){return iterator(_end);}
	const_iterator end() const{return const_iterator(_end);}
	reverse_iterator rbegin(){return reverse_iterator(--_end);}
	const_reverse_iterator rbegin() const{return const_reverse_iterator(--_end);}
	reverse_iterator rend(){return reverse_iterator(--_start);}
	const_reverse_iterator rend() const{return const_reverse_iterator(--_start);}
/*
**capacity
*/
	bool empty(){return (_size == 0);}
	size_type size() const{return _size;}
	size_type max_size() const{return _alloc.max_size();}
/*
**element access
*/
	mapped_type & operator[](const key_type &k){
		iterator tmp = this->find(k);
		if (*tmp && (*tmp).first == k)
			return (*tmp).second;
		return ((this->insert(tmp, value_type(k, 0))).second);
	}
/*
**modifiers
*/
	pair<iterator, bool> insert(const value_type &val){
		iterator tmp = this->lower_bound(val.first);
		if (*tmp && (*tmp).first == val.first)
			return (pair(tmp, false));
		return pair(insert(tmp, val), true);
	}
	iterator insert(iterator pos, const value_type &val){
		if ((*pos).first == val.first)
			return pos;
		iterator tmp = this->find(val.first);
		if (tmp != this->end())
			return tmp;
		size_type dist = ft::distance(iterator(this->_start), pos);
		this->reserve(_size + 1);
		if (_comp((_start + dist).first, val.first) && _comp(val.first, (*(_start + dist + 1)).first))
			pos = iterator(_start + dist);
		else{
			pos = this->lower_bound(val.first) - 1;
			dist = ft::distance(iterator(this->_start), pos);
		}
		for (int i = 0; (_start + _size - i) != (pos + 1); i++)
			_alloc.construct((_start + _size - i), *(_start + _size - (i + 1)));
		_alloc.construct(_start + dist + 1, val);
		return (pos);
	}
	template < class InputIterator >
	void insert(InputIterator first, InputIterator last){
		//insertar [first-last[
		//verificar que no exista cada uno
	}
	void erase(iterator pos){
		//destroy pos
	}
	size_type erase(const key_type &k){
		//destroy element that matches k
		//return number of elements erased
	}
	void erase(iterator first, iterator last){
		//destroy from [first to last[
	}
	void swap(map &x){
		if (*this != x){
			map tmp(x);

			x = *this;
			*this = tmp;
		}
	}
	void clear(){
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_start + i);
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
		for (size_type i = 0; i < _size; i++){
			if ((_start + i).first == k)
				return (iterator(_start + i));
		}
		return (this->end());
	}
	const_iterator find(const key_type &k) const{
		for (size_type i = 0; i < _size; i++){
			if ((_start + i).first == k)
				return (const_iterator(_start + i));
		}
		return (this->end());
	}
	size_type count(const key_type &k) const{
		for (size_type i = 0; i < _size; i++){
			if ((_start + i).first == k)
				return (1);
		}
		return (0);
	}
	iterator lower_bound(const key_type &k){
		for (size_type i = 0; i < _size; i++){
			if (!_comp((_start + i).first, k))
				return (iterator(_start + i));
		}
		return (this->end());
	}
	const_iterator lower_bound(const key_type & k) const{
		for (size_type i = 0; i < _size; i++){
			if (!_comp((_start + i).first, k))
				return (const_iterator(_start + i));
		}
		return (this->end());
	}
	iterator upper_bound(const key_type &k){
		for (size_type i = 0; i < _size; i++){
			if (_comp(k, (_start + i).first))
				return (iterator(_start + i));
		}
		return (this->end());
	}
	const_iterator upper_bound(const key_type &k){
		for (size_type i = 0; i < _size; i++){
			if (_comp(k, (_start + i).first))
				return (const_iterator(_start + i));
		}
		return (this->end());
	}
	pair<const_iterator, const_iterator> equal_range(const key_type &k) const{
		return pair(this->lower_bound(k), this->upper_bound(k));
	}
	pair<iterator, iterator> equal_range(const key_type &k){
		return pair(this->lower_bound(k), this->upper_bound(k));
	}
/*
**allocator
*/
	allocator_type get_allocator() const{return _alloc;}
private:
	allocator_type	_alloc;
	pointer			_start;
	pointer			_end;
	size_type		_size;
	size_type		_capacity;
	key_compare		_comp;
/*
**own functions
*/
	void	reserve(size_type n){
		if (n <= _capacity)
			return ;
		pointer	tmp = _alloc.allocate(n);

		for (size_type i = 0; i < _size; i++)
			_alloc.construct(tmp + i, *(_start + i));
		_alloc.deallocate(this->_start, _capacity);
		_capacity = n;
		this->_start = tmp;
		this->_end = tmp + _size;
	}
}

#endif
