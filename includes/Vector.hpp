// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vector.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/03 15:21:58 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/13 11:38:33 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ft.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

template < class T, class Alloc >
class ft::vector
{
public:
	typedef T														value_type;
	typedef Alloc													allocator_type;
	typedef typename allocator_type::reference						reference;
	typedef typename allocator_type::const_reference				const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef ft::random_access_iterator<value_type>					iterator;
	typedef ft::random_access_iterator<const value_type>			const_iterator;
	typedef ft::reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
	typedef typename allocator_type::size_type						size_type;
/*
**member functions
*/
	explicit vector(const allocator_type& alloc = allocator_type()) :
		_alloc(alloc), _start(0), _end(0), _capacity(0), _size(0){};
	explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) :
		_alloc(alloc), _start(0), _end(0), _capacity(n), _size(n)
		{
			_start = _alloc.allocate(_capacity);
			_end = _start;
			while (n--)
				_alloc.construct(_end++, val);
		};
	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
		   const allocator_type& alloc = allocator_type(),
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) :
		_alloc(alloc), _start(0), _end(0), _capacity(0), _size(0)
		{
			_capacity = static_cast<size_type>(ft::distance(first, last));
			_size = _capacity;
			_start = _alloc.allocate(_capacity);
			_end = _start;
			while (first != last)
				_alloc.construct(_end++, *first++);
		}
	vector(const vector& x) : _alloc(x.get_allocator()), _start(0), _end(0), _capacity(0), _size(0)
		{
			this->insert(this->begin(), x.begin(), x.end());
		}
	~vector(void) {_alloc.deallocate(this->_start, this->_size);}
	vector & operator=(const vector & x){
		if (*this != x){
			this->~vector();
			this->insert(_start, x.begin(), x.end());
		}
		return (*this);
	}
/*
**iterators
*/
	iterator begin(){return (iterator(this->_start));}
	const_iterator begin() const{return (iterator(this->_start));}
	iterator end(){return (iterator(this->_end));}
	const_iterator end() const{return (iterator(this->_end));}
	reverse_iterator rbegin(){return (reverse_iterator(--this->_end));}
	const_reverse_iterator rbegin() const{return (const_reverse_iterator(--this->_end));}
	reverse_iterator rend(){return (reverse_iterator(--this->_start));}
	const_reverse_iterator rend() const{return (const_reverse_iterator(--this->_start));}
/*
**capacity
*/
	size_type size() {return (this->_size);}
	size_type max_size() {return (_alloc.max_size());}
	void	resize(size_type n, value_type val = value_type()){
			if (n == _size)
				return ;
			if (n > this->max_size())
				throw std::length_error("vector::reserve");
			if (n < _capacity){
				pointer	tmp = _alloc.allocate(n);

				for (size_type i = 0; i < n; i++)
					_alloc.construct(tmp + i, *(_start + i));
				_alloc.deallocate(this->_start, _capacity);
				_capacity = n;
				_size = n;
				this->_start = tmp;
				this->_end = tmp + _size;
				return ;
			}
			if (n > _capacity)
				this->reserve(n);
			for (; _size < _capacity; _size++)
				_alloc.construct(_start + _size, val);
			_end = _start + _size;
	}
	size_type	capacity(){return _capacity;}
	bool	empty() const {return _size ? false : true;}
	void reserve(size_type n)
		{
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
/*
**element acces
*/
	reference	operator[](size_type n){
		reference	tmp(*(_start + n));
		return tmp;
	}
	const_reference	operator[](size_type n) const {
		const_reference	tmp(*(_start + n));
		return tmp;
	}
	reference	at(size_type n) {
		if (n >= _size)
			throw std::out_of_range("vector::out_of_range: n >= this->size()");
		return ((*this)[n]);
	}
	const_reference	at(size_type n) const{
		if (n >= _size)
			throw std::out_of_range("vector::out_of_range: n >= this->size()");
		return ((*this)[n]);
	}
	reference	front(){return ((*this)[0]);}
	const_reference	front() const{return ((*this)[0]);}
	reference	back(){return ((*this)[_size - 1]);}
	const_reference	back() const{return ((*this)[_size - 1]);}
/*
**modifiers
*/
	void	assign(size_type n, const value_type & val){
		this->clear();
		if (!n)
			return ;
		this->reserve(n);
		while (_size++ < n)
			_alloc.construct(_end++, val);
	}
	template < class InputIterator >
	void	assign(InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
		size_type n = ft::distance(first, last);
		this->clear();
		if (!n)
			return ;
		this->reserve(n);
		while (first != last){
			_alloc.construct(_end++, *first++);
			_size++;
		}
	}
	void push_back(const value_type & val) {this->insert(_end, val);}
	void pop_back() {
		if (!_size)
			return ;
		_alloc.destroy(--_end);
		_size--;
	}
	iterator insert(iterator p, const value_type & val)
		{
			size_type	pos = ft::distance(iterator(this->_start), p);

			this->reserve(_size + 1);
			p = _start + pos;
			for (int i = 0; p != iterator(_end - i); i++)
				_alloc.construct((_end - i), *(_end - (i + 1)));
			_alloc.construct(_start + pos, val);
			this->_size++;
			_end = _start + _size;
			return (iterator(p));
		}
	iterator insert(iterator p, size_type n, const value_type & val)
		{
			size_type	pos = ft::distance(iterator(this->_start), p);

			this->reserve(_size + n);
			p = _start + pos;
			for (size_type i = 0; p != (_start + (_size + n - i)); i++)
				_alloc.construct(_start + (_size + n - i), *(_start + (_size + n - (i + 1))));
			while (n--)
				_alloc.construct(p + n, val);
			_size += n;
			_end = _start + _size;
			return (p);
		}
	template < class InputIterator >
	iterator insert(iterator p, InputIterator first, InputIterator last,
					typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			size_type	dist = ft::distance(first, last);
			size_type	pos = ft::distance(iterator(this->_start), p);

			this->reserve(_size + dist);
			p = _start + pos;
			for (size_type i = 0; p != iterator(_start + (_size + dist - i)); i++)
				_alloc.construct(_start + (_size + dist - i), *(_start + (_size + dist - (i + 1))));
			for (difference_type i = 0; first != last; i++)
				_alloc.construct(_start + pos + i, *(first++));
			_size += dist;
			_end = _start + _size;
			return (p);
		}
	iterator	erase(iterator p) {
		iterator tmp = p;
		while ((tmp + 1) != iterator(_end)){
			_alloc.construct(tmp, *(tmp + 1));
			tmp++;
		}
		_alloc.destroy(tmp);
		_end--;
		_size--;
		return (p);
	}
	iterator	erase(iterator first, iterator last) {
		iterator	tmp = first;
		size_type	dist = ft::distance(first, last);

		while ((tmp + dist) != iterator(_end)){
			_alloc.construct(tmp, *(tmp + dist));
			tmp++;
		}
		while (iterator(--_end) != tmp){
			_alloc.destroy(_end);
			_size--;
		}
		_alloc.destroy(_end);
		_size--;
		return (first);
	}
	void	swap(vector& x) {
//		allocator_type x_alloc = x.get_allocator();
//		iterator	x_start = x.begin();
//		iterator	x_end	= x.end();
		vector	tmp(x);

		x.assign(this->begin(), this->end());
//		this->assign(x_start, x_end);
		this->assign(tmp.begin(), tmp.end());
	}
	void	clear(){
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(--_end);
		_size = 0;
	}
/*
**allocator
*/
	allocator_type get_allocator(void) const {return (this->_alloc);}
private:
	allocator_type	_alloc;
	pointer			_start;
	pointer			_end;
	size_type		_capacity;
	size_type		_size;
};

//swap
template <class T, class Alloc>
bool operator==(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs){
	if (lhs.size() != rhs.size())
		return (false);
	for (typename ft::vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return (false);
	return (true);
}
template <class T, class Alloc>
bool operator!=(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs){
	if (lhs.size() != rhs.size())
		return (true);
	for (typename ft::vector<T,Alloc>::size_type i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return (true);
	return (false);
}
//template <class T, class Alloc>
//bool operator<(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs);
//template <class T, class Alloc>
//bool operator<=(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs);
//template <class T, class Alloc>
//bool operator>(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs);
//template <class T, class Alloc>
//bool operator>=(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs);

#endif
