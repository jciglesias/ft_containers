// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft.hpp                                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/04/27 15:50:02 by jiglesia          #+#    #+#             //
//   Updated: 2022/04/27 21:12:12 by jiglesia         ###   ########.fr       //
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
	template < class T, class Alloc = std::allocator<T> >
	class vector;

	template < class T, class Alloc = std::allocator<T> >
	class stack;

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
}

#endif
