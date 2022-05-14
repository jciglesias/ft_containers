// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/04 09:32:15 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/14 02:15:10 by jiglesia         ###   ########.fr       //
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
	typedef typename pair<Key, T>	value_type;
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
	map(const map &x) : _alloc(x.get_allocator()), _start(0), _end(0), _size(x.size())
	~map(){}
	map &operator=(){}
/*
**iterators
*/
	iterator begin(){}
	iterator end(){}
	reverse_iterator rbegin(){}
	reverse_iterator rend(){}
/*
**capacity
*/
	bool empty(){}
	size_type size(){}
	size_type max_size(){}
/*
**element access
*/
	value_type operator[](){}
/*
**modifiers
*/
	void insert(){}
	void erase(){}
	void swap(){}
	void clear(){}
/*
**observers
*/
	bool key_comp(){}
	bool value_comp(){}
/*
**operations
*/
	iterator find(){}
	size_type count(){}
	iterator lower_bound(){}
	iterator upper_bound(){}
	pair<const_iterator, const_iterator> equal_range(const key_type &k) const{}
	pair<iterator, iterator> equal_range(const key_type &k){}
/*
**allocator
*/
	allocator_type get_allocator() const{}
private:
	allocator_type	_alloc;
	pointer			_start;
	pointer			_end;
	size_type		_size;
	size_type		_capacity;
	key_compare		_comp;
}

#endif
