// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   bst_iterator.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/22 22:51:28 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/24 19:00:40 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BST_ITERATOR_HPP
# define BST_ITERATOR_HPP

# include "../ft.hpp"
# include "../binary_search_tree/map_bst.hpp"
//https://en.cppreference.com/w/cpp/iterator/bst_iterator
//namespace ft {class bst_iterator;}

template < class Key, class T >
class ft::bst_iterator : public ft::iterator< ft::random_access_iterator_tag, ft::pair<const Key, T> >
{
public:
	typedef typename ft::iterator<ft::random_access_iterator_tag, ft::pair<const Key, T> >	iterator;
	typedef typename iterator::value_type								value_type;
	typedef ft::node<value_type>*										t_pointer;
	typedef typename iterator::difference_type							difference_type;
	typedef typename iterator::pointer									pointer;
	typedef typename iterator::reference								reference;
	typedef typename iterator::iterator_category						iterator_category;

	bst_iterator(void) : _node(0) {}
	bst_iterator(t_pointer ptr, t_pointer end) : _node(ptr), _end(end) {}
	bst_iterator(const bst_iterator & rhs) : _node(rhs.base()), _end(rhs.end()) {}
	~bst_iterator(void) {}
/*
**getter
*/
	t_pointer	base(void) const {return (this->_node);}
	t_pointer	end(void) const { return _end; }
/*
**operators
*/
	bst_iterator &	operator=(const bst_iterator & rhs){
		if (this == &rhs)
			return (*this);
		this->_node = rhs.base();
		this->_end = rhs.end();
		return (*this);
	}

	reference		operator*(void) const {return (_node->val);}
	pointer			operator->(void) {return &(_node->val);}
	bst_iterator &	operator++(void){
		_node = upper_bound(_node, _node);
		if (_node == 0)
			_node = _end;
		return (*this);
	}
	bst_iterator		operator++(int){
		bst_iterator tmp(this->_node, _end);
		_node = upper_bound(_node, _node);
		if (_node == 0){
			_node = _end;
		}
		return (tmp);
	}
	bst_iterator &	operator--(void){
		if (_node == _end){
			_node = _end->right;
		}
		else
			this->_node = search_behind(this->_node, _node);
		return (*this);
	}
	bst_iterator		operator--(int){
		bst_iterator tmp(this->_node, _end);

		if (_node == _end)
			_node = _end->right;
		else
			this->_node = search_behind(_node, _node);
		return (tmp);
	}
	bst_iterator		operator+(difference_type n) const {
		bst_iterator	tmp(_node, _end);

		for (difference_type i = 0; i < n; i++)
			++tmp;
		return (tmp);
	}
	bst_iterator		operator-(difference_type n) const {
		bst_iterator	tmp(_node, _end);

		for (difference_type i = 0; i < n; i++)
			--tmp;
		return (tmp);
	}
	bst_iterator &	operator+=(difference_type n){
		for (difference_type i = 0; i < n; i++)
			operator++();
		return (*this);
	}
	bst_iterator &	operator-=(difference_type n){
		for (difference_type i = 0; i < n; i++)
			operator--();
		return (*this);
	}
	reference					operator[](difference_type n) const {return *(*this + n);}
	operator bst_iterator<const Key, const T> () const{
		return (bst_iterator<const Key, const T>(this->_node));
	}
/*	operator bst_iterator<Key, T> () {
		return (bst_iterator<Key, T>(this->_node));
		}*/
private:
	t_pointer	_node;
	t_pointer	_end;
	t_pointer	search_behind(t_pointer n, t_pointer before){
		if (n->left != 0){
			if (n->left->right != 0)
				n = search_behind(n->left->right, n->left);
			else
				n = n->left;
		}
		else if (n->right != 0 && n->right->val.first < _node->val.first)
			n = search_behind(n->right, n);
		else if (n->up != 0 && n->up != before)
			return n->up;
		return n;
	}
	t_pointer	upper_bound(t_pointer node, t_pointer before){
		if (node == 0)
			return node;
		if (node != 0 && node->val.first > _node->val.first)
			return node;
		if (node->right != 0 && node->right != before)
			node = upper_bound(node->right, node);
		else
			node = upper_bound(node->up, node);
		return node;
	}
};

namespace ft
{
	template < typename KL, typename TL, typename KR, typename TR >
	inline bool	operator==(const ft::bst_iterator<KL, TL> lhs,
						   const ft::bst_iterator<KR, TR> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template < typename KL, typename TL, typename KR, typename TR >
	inline bool	operator!=(const ft::bst_iterator<KL, TL> lhs,
						   const ft::bst_iterator<KR, TR> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template < typename KL, typename TL, typename KR, typename TR >
	inline bool	operator<(const ft::bst_iterator<KL, TL> lhs,
						  const ft::bst_iterator<KR, TR> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template < typename KL, typename TL, typename KR, typename TR >
	inline bool	operator>(const ft::bst_iterator<KL, TL> lhs,
						  const ft::bst_iterator<KR, TR> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template < typename KL, typename TL, typename KR, typename TR >
	inline bool	operator<=(const ft::bst_iterator<KL, TL> lhs,
						   const ft::bst_iterator<KR, TR> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template < typename KL, typename TL, typename KR, typename TR >
	inline bool	operator>=(const ft::bst_iterator<KL, TL> lhs,
						   const ft::bst_iterator<KR, TR> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template < typename Key, typename T >
	inline long	operator+(const ft::bst_iterator<Key, T> lhs,
											  const ft::bst_iterator<Key, T> rhs)
	{
		return (lhs.base() + rhs.base());
	}

	template < typename Key, typename T >
	inline long	operator-(const ft::bst_iterator<Key, T> lhs,
											  const ft::bst_iterator<Key, T> rhs)
	{
		return (lhs.base() - rhs.base());
	}
}

#endif
