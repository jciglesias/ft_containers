// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   random_access_iterator.hpp                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/04/28 20:48:56 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/26 13:09:22 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "ft.hpp"
//https://en.cppreference.com/w/cpp/iterator/random_access_iterator
//namespace ft {class random_access_iterator;}

template < typename T >
class ft::random_access_iterator : public ft::iterator< ft::random_access_iterator_tag, T >
{
public:
	typedef typename ft::iterator<ft::random_access_iterator_tag, T>	iterator;
	typedef typename iterator::value_type								value_type;
	typedef typename iterator::difference_type							difference_type;
	typedef typename iterator::pointer									pointer;
	typedef typename iterator::reference								reference;
	typedef typename iterator::iterator_category						iterator_category;

	random_access_iterator(void) : _i(0) {}
	random_access_iterator(pointer ptr) : _i(ptr) {}
	random_access_iterator(const random_access_iterator & rhs) : _i(rhs.base()) {}
	~random_access_iterator(void) {}
/*
**getter
*/
	pointer base(void) const {return (this->_i);}
/*
**operators
*/
	random_access_iterator &	operator=(const random_access_iterator & rhs)
		{
			if (this == &rhs)
				return (*this);
			this->_i = rhs.base();
			return (*this);
		}

	reference					operator*(void) {return (*this->_i);}
	pointer						operator->(void) {return &(*this->_i);}
	random_access_iterator &	operator++(void)
		{
			this->_i++;
			return (*this);
		}
	random_access_iterator		operator++(int)
		{
			random_access_iterator tmp(this->_i);

			this->_i++;
			return (tmp);
		}
	random_access_iterator &	operator--(void)
		{
			this->_i--;
			return (*this);
		}
	random_access_iterator		operator--(int)
		{
			random_access_iterator tmp(this->_i);

			this->_i--;
			return (tmp);
		}
	random_access_iterator		operator+(difference_type n) const {return (this->_i + n);}
	random_access_iterator		operator-(difference_type n) const {return (this->_i - n);}
	random_access_iterator &	operator+=(difference_type n)
		{
			this->_i += n;
			return (*this);
		}
	random_access_iterator &	operator-=(difference_type n)
		{
			this->_i -= n;
			return (*this);
		}
	reference					operator[](difference_type n) const {return *(*this + n);}
	operator random_access_iterator<const T> () const
		{
			return (random_access_iterator<const T>(this->_i));
		}
private:
	pointer	_i;
};

namespace ft
{
	template < typename TL, typename TR >
	inline bool	operator==(const ft::random_access_iterator<TL> lhs,
						   const ft::random_access_iterator<TR> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template < typename TL, typename TR >
	inline bool	operator!=(const ft::random_access_iterator<TL> lhs,
						   const ft::random_access_iterator<TR> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template < typename TL, typename TR >
	inline bool	operator<(const ft::random_access_iterator<TL> lhs,
						   const ft::random_access_iterator<TR> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template < typename TL, typename TR >
	inline bool	operator>(const ft::random_access_iterator<TL> lhs,
						   const ft::random_access_iterator<TR> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template < typename TL, typename TR >
	inline bool	operator<=(const ft::random_access_iterator<TL> lhs,
						   const ft::random_access_iterator<TR> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template < typename TL, typename TR >
	inline bool	operator>=(const ft::random_access_iterator<TL> lhs,
						   const ft::random_access_iterator<TR> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template < typename T >
	inline ft::random_access_iterator<T>	operator+(const ft::random_access_iterator<T> lhs,
						   const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() + rhs.base());
	}

	template < typename T >
	inline ft::random_access_iterator<T>	operator-(const ft::random_access_iterator<T> lhs,
						   const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	}
}

#endif
