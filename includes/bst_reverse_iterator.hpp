// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   bst_reverse_iterator.hpp                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/02 15:10:20 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/02 16:04:17 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BST_REVERSE_ITERATOR_HPP
# define BST_REVERSE_ITERATOR_HPP

# include "ft.hpp"
//https://www.cplusplus.com/reference/iterator/bst_reverse_iterator/

namespace ft {template < typename Iterator > class bst_reverse_iterator;}

template < typename Iterator >
class ft::bst_reverse_iterator :
	public ft::iterator< typename ft::iterator_traits<Iterator>::iterator_category,
	typename ft::iterator_traits<Iterator>::value_type,
	typename ft::iterator_traits<Iterator>::difference_type,
	typename ft::iterator_traits<Iterator>::pointer,
	typename ft::iterator_traits<Iterator>::reference>
{
public:
/*
**Alias
*/
	typedef Iterator									iterator_type;
	typedef ft::iterator_traits<Iterator>				iterator_traits;
	typedef typename iterator_traits::iterator_category	iterator_category;
	typedef typename iterator_traits::value_type		value_type;
	typedef typename iterator_traits::difference_type	difference_type;
	typedef typename iterator_traits::pointer			pointer;
	typedef typename iterator_traits::reference			reference;
/*
**constructor
*/
	bst_reverse_iterator(void) : _i() {}
	explicit bst_reverse_iterator(iterator_type ri) : _i(ri) {}
	template < class Iter >
	bst_reverse_iterator(const bst_reverse_iterator< Iter > & ri) : _i(ri.base()) {}
	~bst_reverse_iterator(void) {}
/*
**getter
*/
	iterator_type base(void) const {return (this->_i);}
/*
**operators
*/
	reference				operator*(void) const {return (*(this->_i - 1));}
	reference			operator[](difference_type n) const {return (*(this->_i + n));}
	pointer				operator->(void) const {return (&(_i.base()->val));}
	bst_reverse_iterator &	operator++(void)
		{
			--this->_i;
			return (*this);
		}
	bst_reverse_iterator	operator++(int)
		{
			bst_reverse_iterator tmp(*this);

			--this->_i;
			return (tmp);
		}
	bst_reverse_iterator &	operator--(void)
		{
			++this->_i;
			return (*this);
		}
	bst_reverse_iterator	operator--(int)
		{
			bst_reverse_iterator tmp(*this);

			++this->_i;
			return (tmp);
		}
	bst_reverse_iterator	operator+(difference_type n) const
		{
			bst_reverse_iterator tmp(this->_i - n);

			return (tmp);
		}
	bst_reverse_iterator	operator-(difference_type n) const
		{
			bst_reverse_iterator tmp(this->_i + n);

			return (tmp);
		}
	bst_reverse_iterator &	operator+=(difference_type n)
		{
			this->_i -= n;
			return (*this);
		}
	bst_reverse_iterator &	operator-=(difference_type n)
		{
			this->_i += n;
			return (*this);
		}
private:
	iterator_type	_i;
};

namespace ft
{
/*
**non member funcions
**https://www.cplusplus.com/reference/iterator/bst_reverse_iterator/operators/
*/
	template <class Iterator>
	inline bool	operator==(const bst_reverse_iterator<Iterator>& lhs,
						   const bst_reverse_iterator<Iterator>& rhs)
	{return (lhs.base() == rhs.base());}

	template <class Iterator>
	inline bool	operator!=(const bst_reverse_iterator<Iterator>& lhs,
						   const bst_reverse_iterator<Iterator>& rhs)
	{return (lhs.base() != rhs.base());}

	template <class Iterator>
	inline bool	operator<(const bst_reverse_iterator<Iterator>& lhs,
						  const bst_reverse_iterator<Iterator>& rhs)
	{return (lhs.base() > rhs.base());}

	template <class Iterator>
	inline bool	operator<=(const bst_reverse_iterator<Iterator>& lhs,
						   const bst_reverse_iterator<Iterator>& rhs)
	{return (lhs.base() >= rhs.base());}

	template <class Iterator>
	inline bool	operator>(const bst_reverse_iterator<Iterator>& lhs,
						  const bst_reverse_iterator<Iterator>& rhs)
	{return (lhs.base() < rhs.base());}

	template <class Iterator>
	inline bool	operator>=(const bst_reverse_iterator<Iterator>& lhs,
						   const bst_reverse_iterator<Iterator>& rhs)
	{return (lhs.base() <= rhs.base());}
//https://www.cplusplus.com/reference/iterator/bst_reverse_iterator/operator_plus-free/
	template <class Iterator>
	bst_reverse_iterator<Iterator> operator+(typename bst_reverse_iterator<Iterator>::difference_type n,
										 const bst_reverse_iterator<Iterator>& rev_it)
	{return (rev_it.base() - n);}
//https://www.cplusplus.com/reference/iterator/bst_reverse_iterator/operator_minus-free/
	template <class Iterator>
	typename bst_reverse_iterator<Iterator>::difference_type operator-(
		const bst_reverse_iterator<Iterator>& lhs, const bst_reverse_iterator<Iterator>& rhs)
	{return (rhs.base() - lhs.base());}
}

#endif
