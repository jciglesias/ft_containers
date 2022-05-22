// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   bst_iterator.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/22 22:51:28 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/23 00:32:27 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BST_ITERATOR_HPP
# define BST_ITERATOR_HPP

# include "ft.hpp"
# include "map_bst.hpp"
//https://en.cppreference.com/w/cpp/iterator/bst_iterator
//namespace ft {class bst_iterator;}

//template < typename T >
class ft::bst_iterator : public ft::iterator< ft::random_access_iterator_tag, t_node* >
{
public:
	typedef typename ft::iterator<ft::random_access_iterator_tag, t_node* >	iterator;
	typedef typename iterator::value_type								value_type;
	typedef typename iterator::difference_type							difference_type;
	typedef typename iterator::pointer									pointer;
	typedef typename iterator::reference								reference;
	typedef typename iterator::iterator_category						iterator_category;

	bst_iterator(void) : _node(0) {}
	bst_iterator(t_node *ptr) : _node(ptr) {}
	bst_iterator(const bst_iterator & rhs) : _node(rhs.base()) {}
	~bst_iterator(void) {}
/*
**getter
*/
	t_node *base(void) const {return (this->_node);}
/*
**operators
*/
	bst_iterator &	operator=(const bst_iterator & rhs){
		if (this == &rhs)
			return (*this);
		this->_node = rhs.base();
		return (*this);
	}

	reference					operator*(void) {return (*this->_node->val);}
	pointer						operator->(void) {return (*this->_node->val);}
	bst_iterator &	operator++(void){
		if (_node->right != 0)
			_node = _node->right;
		else
			_node = _node->up;
		return (*this);
	}
	bst_iterator		operator++(int){
		bst_iterator tmp(this->_node);

		*this++;
		return (tmp);
	}
	bst_iterator &	operator--(void){
		this->_node = search_behind(this->_node);
		return (*this);
	}
	bst_iterator		operator--(int){
		bst_iterator tmp(this->_i);

		this->_i--;
		return (tmp);
	}
	bst_iterator		operator+(difference_type n) const {return (this->_i + n);}
	bst_iterator		operator-(difference_type n) const {return (this->_i - n);}
	bst_iterator &	operator+=(difference_type n)
		{
			this->_i += n;
			return (*this);
		}
	bst_iterator &	operator-=(difference_type n)
		{
			this->_i -= n;
			return (*this);
		}
	reference					operator[](difference_type n) const {return *(*this + n);}
	operator bst_iterator<const T> () const
		{
			return (bst_iterator<const T>(this->_i));
		}
private:
	t_node	*_node;
	t_node	*search_next(t_node *n){
		t_node *tmp = 0;
		if (n->right != 0){
			tmp = n->right;
			while (tmp->left != 0)
				tmp = tmp->left;
		}
		else if (n->up < n && n->up->up > n)
			tmp = n->up->up;
		else if (n->up > n)
			tmp = n->up;
		return tmp;
	}
	t_node	*search_behind(t_node *n){
		if (n->left != 0)
			n = n->left;
	}
};

namespace ft
{
	template < typename TL, typename TR >
	inline bool	operator==(const ft::bst_iterator<TL> lhs,
						   const ft::bst_iterator<TR> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template < typename TL, typename TR >
	inline bool	operator!=(const ft::bst_iterator<TL> lhs,
						   const ft::bst_iterator<TR> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template < typename TL, typename TR >
	inline bool	operator<(const ft::bst_iterator<TL> lhs,
						   const ft::bst_iterator<TR> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template < typename TL, typename TR >
	inline bool	operator>(const ft::bst_iterator<TL> lhs,
						   const ft::bst_iterator<TR> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template < typename TL, typename TR >
	inline bool	operator<=(const ft::bst_iterator<TL> lhs,
						   const ft::bst_iterator<TR> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template < typename TL, typename TR >
	inline bool	operator>=(const ft::bst_iterator<TL> lhs,
						   const ft::bst_iterator<TR> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template < typename T >
	inline ft::bst_iterator<T>	operator+(const ft::bst_iterator<T> lhs,
						   const ft::bst_iterator<T> rhs)
	{
		return (lhs.base() + rhs.base());
	}

	template < typename T >
	inline ft::bst_iterator<T>	operator-(const ft::bst_iterator<T> lhs,
						   const ft::bst_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	}
}

#endif
