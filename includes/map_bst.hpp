// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   map_bst.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/18 11:29:51 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/23 00:58:32 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_BST_HPP
# define MAP_BST_HPP

# include "ft.hpp"

//https://en.wikipedia.org/wiki/Sorting_algorithm
//https://www.geeksforgeeks.org/tree-sort/

template < class T >
class t_node{
public:
	T		val;
	t_node	*up;
	t_node	*left;
	t_node	*right;
	t_node() : val(0), up(0), left(0), right(0){}
	t_node(const T &n) : val(n), up(0), left(0), right(0){}
	t_node(const struct t_node &node) : val(node.val), up(node.up), left(node.left),
										right(node.right) {}
/*	struct s_node &operator=(const struct s_node &node){
		this->val = node.val;
		this->up = node.up;
		this->left = node.left;
		this->right = node.right;
		}*/
	~t_node(){}
};

template < class T >
bool operator==(const t_node<T> *lhs, const t_node<T> *rhs){
	return (lhs->val == rhs->val);
}
template < class T >
bool operator!=(const t_node<T> *lhs, const t_node<T> *rhs){
	return (lhs->val != rhs->val);
}
template < class T >
bool operator>(const t_node<T> *lhs, const t_node<T> *rhs){
	return (lhs->val > rhs->val);
}
template < class T >
bool operator>=(const t_node<T> *lhs, const t_node<T> *rhs){
	return (lhs->val >= rhs->val);
}
template < class T >
bool operator<(const t_node<T> *lhs, const t_node<T> *rhs){
	return (lhs->val < rhs->val);
}
template < class T >
bool operator<=(const t_node<T> *lhs, const t_node<T> *rhs){
	return (lhs->val <= rhs->val);
}


template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator<ft::pair<const Key, T> > >
class map_bst{
public:
	//create heap_iterator
	typedef ft::pair<Key, T>			value_type;
	map_bst(const Compare comp = Compare(), const Alloc &alloc = Alloc()) :
		_comp(comp), _alloc(alloc), _root(0), _size(0){}
	~map_bst(){this->erase_tree(_root);}
	t_node<value_type> *root(){return _root;}
	t_node<value_type> *search(Key &k) {
		return this->search(_root, k);
	}
	t_node<value_type> *search(t_node<value_type> *node, Key &k) {
		t_node<value_type> *tmp = 0;

		if (k == node->val.first)
			tmp = node;
		else if (_comp(k, node->val.first))
			tmp = search(node->left, k);
		else if (_comp(node->val.first, k))
			tmp = search(node->right, k);
		return (tmp);
	}
	bool insert(value_type &p) {
		if (this->search(_root, p.first) != 0)
			return false;
		_root = this->insert(_root, p);
		_size++;
		return true;
	}
	t_node<value_type> *insert(t_node<value_type> *root, t_node<value_type> *node) {
		if (root == 0)
			return node;
		if (_comp(node->val.first, root->val.first)){
			root->left = insert(root->left, node);
			root->left->up = root;
		}
		else if (_comp(root->val.first, node->val.first)){
			root->right = insert(root->right, node);
			root->right->up = root;
		}
		return root;
	}
	void erase(t_node<value_type> *node) {
		t_node<value_type> *left = node->left;
		t_node<value_type> *right = node->right;

		if (node->up->left == node)
			node->up->left = 0;
		else
			node->up->right = 0;
		delete node;
		if (right != 0)
			_root = insert(_root, right);
		if (left != 0)
			_root = insert(_root, left);
	}
	void erase(Key &k) {
		t_node<value_type> *tmp = search(k);

		erase(tmp);
	}
	void print_bst(t_node<value_type> *root){
		if (root != 0){
			print_bst(root->left);
			std::cout << root->val.second << std::endl;
			print_bst(root->right);
		}
	}
private:
	t_node<value_type>		*_root;
	Compare			_comp;
	Alloc			_alloc;
	unsigned long	_size;
	void	erase_tree(t_node<value_type> *n){
		if (n == 0)
			return ;
		if (n->left != 0)
			erase_tree(n->left);
		if (n->right != 0)
			erase_tree(n->right);
		delete n;
		return ;
	}
	t_node<value_type>	*insert(t_node<value_type> *node, value_type &p) {
		if (node == 0)
			return new t_node<value_type>(p);
		if (_comp(p.first, node->val.first)){
			node->left = insert(node->left, p);
			node->left->up = node;
		}
		else if (_comp(node->val.first, p.first)){
			node->right = insert(node->right, p);
			node->right->up = node;
		}
		return node;
	}
};

#endif
