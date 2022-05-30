// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   map_bst.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/18 11:29:51 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/30 12:20:22 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_BST_HPP
# define MAP_BST_HPP

# include "ft.hpp"

//https://en.wikipedia.org/wiki/Sorting_algorithm
//https://www.geeksforgeeks.org/tree-sort/

template < class Key, class T >
class t_node{
public:
	Key		first;
	T		second;
	t_node	*up;
	t_node	*left;
	t_node	*right;
	t_node() : first(), second(), up(0), left(0), right(0){}
	t_node(const Key &k, const T &n) : first(k), second(n), up(0), left(0), right(0){}
	t_node(const t_node &node) : first(node.first), second(node.second),
										up(node.up), left(node.left), right(node.right) {}
/*	struct s_node &operator=(const struct s_node &node){
		this->val = node.val;
		this->up = node.up;
		this->left = node.left;
		this->right = node.right;
		}*/
	~t_node(){}
};

template < class Key, class T >
bool operator==(const t_node<Key, T> *lhs, const t_node<Key, T> *rhs){
	return (lhs->val == rhs->val);
}
template < class Key, class T >
bool operator!=(const t_node<Key, T> *lhs, const t_node<Key, T> *rhs){
	return (lhs->val != rhs->val);
}
template < class Key, class T >
bool operator>(const t_node<Key, T> *lhs, const t_node<Key, T> *rhs){
	return (lhs->val > rhs->val);
}
template < class Key, class T >
bool operator>=(const t_node<Key, T> *lhs, const t_node<Key, T> *rhs){
	return (lhs->val >= rhs->val);
}
template < class Key, class T >
bool operator<(const t_node<Key, T> *lhs, const t_node<Key, T> *rhs){
	return (lhs->val < rhs->val);
}
template < class Key, class T >
bool operator<=(const t_node<Key, T> *lhs, const t_node<Key, T> *rhs){
	return (lhs->val <= rhs->val);
}


template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator<ft::pair<const Key, T> > >
class map_bst{
public:
	//create heap_iterator
	typedef ft::pair<Key, T>			value_type;
	map_bst(const Compare comp = Compare(), const Alloc &alloc = Alloc()) :
		_root(0), _comp(comp), _alloc(alloc), _size(0){}
	~map_bst(){this->erase_tree(_root);}
	t_node<Key, T> *root(){return _root;}
/*	t_node<Key, T> *search(Key &k) {
		return this->search(_root, k);
	}*/
	unsigned long	size(){ return _size; }
	t_node<Key, T> *search(Key k) {
		return this->search(_root, k);
	}
/*	bool insert(value_type &p) {
		if (this->search(_root, p.first) != 0)
			return false;
		_root = this->insert(_root, p);
		_size++;
		return true;
	}*/
	bool insert(value_type p) {
		if (this->search(_root, p.first) != 0)
			return false;
		_root = this->insert(_root, p);
		_size++;
		this->end.up = _root;
		this->end.left = this->smallest();
		this->end.right = this->biggest();
		this->rend.up = _root;
		this->rend.left = this->end.right;
		this->rend.right = this->end.left;
		return true;
	}
	void erase(t_node<Key, T> *node) {
		t_node<Key, T> *left = node->left;
		t_node<Key, T> *right = node->right;

		if (node->up != 0 && node->up->left == node)
			node->up->left = 0;
		else if (node->up != 0)
			node->up->right = 0;
		if (node == _root)
			_root = 0;
		delete node;
		_size--;
		if (right != 0){
			right->up = 0;
			_root = insert(_root, right);
		}
		if (left != 0){
			left->up = 0;
			_root = insert(_root, left);
		}
	}
/*	void erase(Key &k) {
		t_node<Key, T> *tmp = search(k);

		if (tmp != 0)
			erase(tmp);
	}*/
	void erase(Key k) {
		t_node<Key, T> *tmp = search(k);

		if (tmp != 0)
			erase(tmp);
	}
	t_node<Key, T>	*smallest(){
		t_node<Key, T> *tmp = _root;

		if (tmp != 0){
			while (tmp->left != 0)
				tmp = tmp->left;
		}
		return (tmp);
	}
	t_node<Key, T>	*biggest(){
		t_node<Key, T> *tmp = _root;

		if (tmp != 0){
			while (tmp->right != 0)
				tmp = tmp->right;
		}
		return (tmp);
	}
	void print_bst(){
		print_bst(_root);
	}
	void print_bst(t_node<Key, T> *root){
		if (root != 0){
			print_bst(root->left);
			std::cout << root->second << std::endl;
			print_bst(root->right);
		}
	}
	void	erase_tree(t_node<Key, T> *n){
		if (n == 0)
			return ;
		if (n->left != 0)
			erase_tree(n->left);
		if (n->right != 0)
			erase_tree(n->right);
		delete n;
		return ;
	}
	t_node<Key, T>	end;
	t_node<Key, T>	rend;
private:
	t_node<Key, T>	*_root;
	Compare			_comp;
	Alloc			_alloc;
	unsigned long	_size;
	t_node<Key, T>	*insert(t_node<Key, T> *node, value_type &p) {
		if (node == 0)
			return new t_node<Key, T>(p.first, p.second);
		if (_comp(p.first, node->first)){
			node->left = insert(node->left, p);
			node->left->up = node;
		}
		else if (_comp(node->first, p.first)){
			node->right = insert(node->right, p);
			node->right->up = node;
		}
		return node;
	}
	t_node<Key, T> *insert(t_node<Key, T> *root, t_node<Key, T> *node) {
		if (root == 0)
			return node;
		if (root != 0 && _comp(node->first, root->first)){
			root->left = insert(root->left, node);
			root->left->up = root;
		}
		else if (root != 0 &&_comp(root->first, node->first)){
			root->right = insert(root->right, node);
			root->right->up = root;
		}
		return root;
	}
	t_node<Key, T> *search(t_node<Key, T> *node, Key &k) {
		t_node<Key, T> *tmp = 0;

		if (node != 0){
			if (k == node->first)
				tmp = node;
			else if (_comp(k, node->first))
				tmp = search(node->left, k);
			else if (_comp(node->first, k))
				tmp = search(node->right, k);
		}
		return (tmp);
	}
};

#endif
