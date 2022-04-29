// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft.hpp                                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/04/27 15:50:02 by jiglesia          #+#    #+#             //
//   Updated: 2022/04/29 17:41:57 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_HPP
# define FT_HPP

# include <memory>
# include <iostream>
# include <string>
# include <stddef.h>

namespace ft
{
/*
**containers
*/
	template < class T, class Alloc = std::allocator<T> >
	class vector;

	template < class T, class Alloc = std::allocator<T> >
	class stack;
/*
**iterator struct
*/
	template < class Category,				//iterator::iterator_category
			   class T,						//iterator::value_type
			   class Distance = ptrdiff_t,	//iterator::difference_type
			   class Pointer = T*,			//iterator::pointer
			   class Reference = T& >		//iterator::reference
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};
/*
**types of iterators
*/
	template < typename T >
	class rantom_access_iterator;

	template < typename T >
	class reverse_iterator;
/*
**Empty classes to identify the category of an iterator
*/
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};
/*
**iterator traits
*/
	template < class Iterator >
	struct iterator_traits
	{
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template < class T >
	struct iterator_traits< T* >
	{
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template < class T >
	struct iterator_traits< const T* >
	{
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template < class Iterator >
	ft::iterator_traits<Iterator>::difference_type distance(Iterator first, Iterator last)
	{
		ft::iterator_traits<Iterator>::difference_type dst;

		while (first != last)
		{
			first++;
			dst++;
		}
		return (dst);
	}
}

#endif
