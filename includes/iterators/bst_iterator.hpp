// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   bst_iterator.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/22 22:51:28 by jiglesia          #+#    #+#             //
//   Updated: 2022/07/05 13:29:45 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BST_ITERATOR_HPP
# define BST_ITERATOR_HPP

# include "../ft.hpp"
# include "../binary_search_tree/map_bst.hpp"
//https://en.cppreference.com/w/cpp/iterator/bst_iterator
//namespace ft {class bst_iterator;}

template < class Key, class T, class Compare >
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

	bst_iterator(const Compare &comp = Compare()) : _node(0), _comp(comp) {}
	bst_iterator(t_pointer ptr, t_pointer end, const Compare &comp = Compare()) : _node(ptr), _end(end), _comp(comp) {}
	bst_iterator(const bst_iterator & rhs, const Compare &comp = Compare()) : _node(rhs.base()), _end(rhs.end()), _comp(comp) {}
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
		_tmp = 0;
		if (_end != 0 && (upper_bound(_end->up, _node->val.first) == false)) {
			_node = _end;
		}
/*		if (_node == 0)
			_node = _end;
*/		return (*this);
	}
	bst_iterator		operator++(int){
		bst_iterator tmp(this->_node, _end);
		_tmp = 0;
		if (_end != 0 && (upper_bound(_end->up, _node->val.first) == false)) {
			_node = _end;
		}
/*		if (_node == 0){
			_node = _end;
		}
*/		return (tmp);
	}
	bst_iterator &	operator--(void){
		if (_node == _end){
			_node = _end->right;
		}
		else{
			_tmp = 0;
			if (search_behind(_end->up, _node->val.first) == false)
				_node = _end;
		}
		return (*this);
	}
	bst_iterator		operator--(int){
		bst_iterator tmp(this->_node, _end);

		if (_node == _end)
			_node = _end->right;
		else{
			_tmp = 0;
			if (search_behind(_end->up, _node->val.first) == false)
				_node = _end;
		}
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
	operator bst_iterator<const Key, const T, const Compare> () const{
		return (bst_iterator<const Key, const T, const Compare>(this->_node));
	}
/*	operator bst_iterator<Key, T> () {
		return (bst_iterator<Key, T>(this->_node));
		}*/
private:
	t_pointer	_node;
	t_pointer	_end;
	Compare		_comp;
	t_pointer	_tmp;
/*	t_pointer	search_behind(t_pointer n, t_pointer before){
		if (n->left != 0){
			if (n->left->right != 0)
				n = search_behind(n->left->right, n->left);
			else
				n = n->left;
		}
		else if (n->right != 0 && _comp(n->right->val.first, _node->val.first))
			n = search_behind(n->right, n);
		else if (n->up != 0 && n->up != before){
			if (_comp(n->val.first, n->up->val.first))
				n = search_behind(n->up, n);
			else
				return n->up;
		}
		return n;
		}*/
	bool search_behind(t_pointer node, Key k) {
		if (node != 0) {
			if (_comp(node->val.first, k)){
				if (search_behind(node->right, k) == true)
					return true;
			}
			if (_tmp != 0 && _tmp->val.first == k) {
				_node = node;
				_tmp = 0;
				return true;
			}
			_tmp = node;
			if (!_comp(node->val.first, k)) {
				if (search_behind(node->left, k) == true)
					return true;
			}
		}
		return false;
	}
	bool upper_bound(t_pointer node, Key k){
		if (node != 0) {
			if (_comp(k, node->val.first)){
				if (upper_bound(node->left, k) == true)
					return true;
			}
			if (_tmp != 0 && _tmp->val.first == k) {
				_node = node;
				_tmp = 0;
				return true;
			}
			_tmp = node;
			if (!_comp(k, node->val.first)){
				if (upper_bound(node->right, k) == true)
					return true;
			}
		}
		return false;
	}
};

namespace ft
{
	template < typename KL, typename TL, typename CL, typename KR, typename TR, typename CR >
	inline bool	operator==(const ft::bst_iterator<KL, TL, CL> lhs,
						   const ft::bst_iterator<KR, TR, CR> rhs){
		return (lhs.base() == rhs.base());
	}

	template < typename KL, typename TL, typename CL, typename KR, typename TR, typename CR >
	inline bool	operator!=(const ft::bst_iterator<KL, TL, CL> lhs,
						   const ft::bst_iterator<KR, TR, CR> rhs){
		return (lhs.base() != rhs.base());
	}

	template < typename KL, typename TL, typename CL, typename KR, typename TR, typename CR >
	inline bool	operator<(const ft::bst_iterator<KL, TL, CL> lhs,
						  const ft::bst_iterator<KR, TR, CR> rhs){
		return (lhs.base() < rhs.base());
	}

	template < typename KL, typename TL, typename CL, typename KR, typename TR, typename CR >
	inline bool	operator>(const ft::bst_iterator<KL, TL, CL> lhs,
						  const ft::bst_iterator<KR, TR, CR> rhs){
		return (lhs.base() > rhs.base());
	}

	template < typename KL, typename TL, typename CL, typename KR, typename TR, typename CR >
	inline bool	operator<=(const ft::bst_iterator<KL, TL, CL> lhs,
						   const ft::bst_iterator<KR, TR, CR> rhs){
		return (lhs.base() <= rhs.base());
	}

	template < typename KL, typename TL, typename CL, typename KR, typename TR, typename CR >
	inline bool	operator>=(const ft::bst_iterator<KL, TL, CL> lhs,
						   const ft::bst_iterator<KR, TR, CR> rhs){
		return (lhs.base() >= rhs.base());
	}
}

#endif
