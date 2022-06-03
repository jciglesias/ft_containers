// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft.hpp                                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/04/27 15:50:02 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/03 10:09:04 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FT_HPP
# define FT_HPP

# include <memory>
# include <iostream>
# include <string>
# include <stddef.h>
# include <typeinfo>

namespace ft
{
/*
**containers
*/
	template < class T, class Alloc = std::allocator<T> >
	class vector;

	template < class T, class Container = vector<T> >
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
	class random_access_iterator;

	template < typename T >
	class reverse_iterator;

	template < class key, class T >
	class bst_iterator;
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
/*
**functions
*/
	template < class Iterator >
	typename iterator_traits<Iterator>::difference_type distance(Iterator first, Iterator last)
	{
		typename iterator_traits<Iterator>::difference_type dst = 0;

		while (first != last)
		{
			first++;
			dst++;
		}
		return (dst);
	}
/*
**type traits
*/
//https://www.cplusplus.com/reference/type_traits/integral_const/
	template < class T, T v>
	struct integral_const
	{
		static const T value = v;
		typedef bool value_type;
		typedef integral_const<T, v> type;
		operator bool() { return value; }
	};
//https://www.cplusplus.com/reference/type_traits/is_integral/
	template < typename >
	struct is_integral : public integral_const<bool, false> {};
	template <>
	struct is_integral<bool> : public integral_const<bool, true> {};
	template <>
	struct is_integral<char> : public integral_const<bool, true> {};
	template <>
	struct is_integral<wchar_t> : public integral_const<bool, true> {};
	template <>
	struct is_integral<signed char> : public integral_const<bool, true> {};
	template <>
	struct is_integral<short int> : public integral_const<bool, true> {};
	template <>
	struct is_integral<int> : public integral_const<bool, true> {};
	template <>
	struct is_integral<long int> : public integral_const<bool, true> {};
	template <>
	struct is_integral<long long int> : public integral_const<bool, true> {};
	template <>
	struct is_integral<unsigned char> : public integral_const<bool, true> {};
	template <>
	struct is_integral<unsigned short int> : public integral_const<bool, true> {};
	template <>
	struct is_integral<unsigned int> : public integral_const<bool, true> {};
	template <>
	struct is_integral<unsigned long int> : public integral_const<bool, true> {};
	template <>
	struct is_integral<unsigned long long int> : public integral_const<bool, true> {};

//https://www.cplusplus.com/reference/type_traits/enable_if/
	template < bool Cond, class T = void >
	struct enable_if {};
	template < class T >
	struct enable_if<true, T>
	{ typedef T type; };
//https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 f1, InputIterator1 l1,
								 InputIterator2 f2, InputIterator2 l2){
		while (f1 != l1) {
			if (f2 == l2 || *f2 < *f1)
				return false;
			else if (*f1 < *f2)
				return true;
			++f1;
			++f2;
		}
		return (f2 != l2);
	}
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 f1, InputIterator1 l1,
								 InputIterator2 f2, InputIterator2 l2, Compare cmp){
		while (f1 != l1) {
			if (f2 == l2 || cmp(*f2, *f1))
				return false;
			else if (cmp(*f1, *f2))
				return true;
			++f1;
			++f2;
		}
		return (f2 != l2);
	}
//https://www.cplusplus.com/reference/algorithm/equal/
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 f1, InputIterator1 l1, InputIterator2 f2 ) {
		while (f1!=l1) {
			if (!(*f1 == *f2))
				return false;
			++f1;
			++f2;
		}
		return true;
	}
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 f1, InputIterator1 l1,
				InputIterator2 f2, BinaryPredicate pred){
		while (f1!=l1) {
			if (!pred(*f1, *f2))
				return false;
			++f1;
			++f2;
		}
		return true;
	}
//https://www.cplusplus.com/reference/utility/pair/?kw=pair
	template <class T1, class T2>
	struct pair {
	public:
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;
	/*
	**member functions
	*/
		pair() : first(), second(){}
		template <class U, class V>
		pair(const pair<U,V> &pr) : first(pr.first), second(pr.second){}
		pair(const first_type &a, const second_type &b) : first(a), second(b){}
		~pair(){}
		pair& operator=(const pair &pr){
			if (*this == pr)
				return *this;
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};
	/*
	**relational operators
	*/
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1,T2> &rhs){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1,T2> &rhs){
		return !(lhs == rhs);
	}
		template <class T1, class T2>
		bool operator<(const pair<T1, T2> &lhs, const pair<T1,T2> &rhs){
			return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
		}
	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1,T2> &rhs){
		return !(rhs < lhs);
	}
	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1,T2> &rhs){
		return (rhs < lhs);
	}
	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1,T2> &rhs){
		return !(lhs < rhs);
	}

	template < class Key, class T, class Compare = std::less<Key>,
			   class Alloc = std::allocator<pair<const Key, T> > >
	class map;
	template < class T1, class T2 >
	pair<T1, T2> make_pair(T1 x, T2 y){ return (pair<T1, T2>(x, y));}
}

#endif
