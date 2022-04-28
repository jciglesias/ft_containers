// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   random_access_iterator.hpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/04/28 20:48:56 by jiglesia          #+#    #+#             //
//   Updated: 2022/04/28 21:00:12 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "ft.hpp"
//https://en.cppreference.com/w/cpp/iterator/random_access_iterator
template < typename T >
class ft::rantom_access_iterator : public ft::iterator< ft::random_access_iterator_tag, T >
{

}

#endif
