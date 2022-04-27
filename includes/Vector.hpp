// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vector.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/03 15:21:58 by jiglesia          #+#    #+#             //
//   Updated: 2022/04/27 21:42:22 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ft.hpp"

template < class T, class Alloc >
class ft::vector
{
public:
	T	i;
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
//	typedef ft::random_access_iterator<value_type> iterator;
//	typedef ft::random_access_iterator<const value_type> const_iterator;
//	typedef ft::reverse_iterator<iterator> reverse_iterator;
//	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
//	typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
	typedef typename allocator_type::size_type size_type;
	/*
	**member functions
	*/
	explicit vector(const allocator_type& alloc = allocator_type()) :
		_alloc(alloc), _start(0), _end(0), _memsize(0), _size(0){};
	explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
		   const allocator_type& alloc = allocator_type());
	vector(const vector& x);
	~vector(){}
	//operator=
	/*
	**iterators
	*/
	//begin
	//end
	//rbegin
	//rend
	//cbegin
	//cend
	//crbegin
	//crend
	/*
	**capacity
	*/
	//size
	//max_size
	//resize
	//capacity
	//empty
	//reserve
	//shrink_to_fit
	/*
	**element acces
	*/
	//operator[]
	//at
	//front
	//back
	//data
	/*
	**modifiers
	*/
	//assign
	//push_back
	//pop_back
	//insert
	//erase
	//swap
	//clear
	//emplace
	//emplace_back
	/*
	**allocator
	*/
	//get_allocator
private:
	allocator_type	_alloc;
	pointer			_start;
	pointer			_end;
	pointer			_memsize;
	size_type		_size;
};

//swap
//template <class T, class Alloc>
//bool operator==(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs);
//template <class T, class Alloc>
//bool operator!=(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs);
//template <class T, class Alloc>
//bool operator<(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs);
//template <class T, class Alloc>
//bool operator<=(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs);
//template <class T, class Alloc>
//bool operator>(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs);
//template <class T, class Alloc>
//bool operator>=(const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs);

#endif
