// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   map_bst.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/18 11:29:51 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/23 12:27:32 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_BST_HPP
# define MAP_BST_HPP

# include "../ft.hpp"

//https://en.wikipedia.org/wiki/Sorting_algorithm
//https://www.geeksforgeeks.org/tree-sort/

template < class T >
class t_node{
public:
//	Key		first;
//	T		second;
	T		val;
	t_node	*up;
	t_node	*left;
	t_node	*right;
	t_node() : val(), up(0), left(0), right(0){}
	t_node(const T &n) : val(n), up(0), left(0), right(0){}
	t_node(const t_node &node) : val(&(node.val)),
								up(&(node.up)), left(&(node.left)), right(&(node.right)) {}
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
	typedef ft::pair<const Key, T>			value_type;
	map_bst(const Compare comp = Compare(), const Alloc &alloc = Alloc()) :
		_root(0), _comp(comp), _alloc(alloc), _size(0){
		_end = new t_node<value_type>;
		_rend = new t_node<value_type>;
	}
	~map_bst(){
		this->erase_tree(_root);
		delete _end;
		delete _rend;
	}
	t_node<value_type> *root(){return _root;}
/*	t_node<value_type> *search(Key &k) {
		return this->search(_root, k);
	}*/
	unsigned long	size() const { return _size; }
	t_node<value_type> *search(Key k) {
		return this->search(_root, k);
	}
	t_node<value_type> *search(const Key k) const{
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
		this->_end->up = _root;
		this->_end->left = this->smallest();
		this->_end->right = this->biggest();
		this->_rend->up = _root;
		this->_rend->left = this->_end->right;
		this->_rend->right = this->_end->left;
		return true;
	}
	void erase(t_node<value_type> *node) {
		t_node<value_type> *left = node->left;
		t_node<value_type> *right = node->right;

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
		t_node<value_type> *tmp = search(k);

		if (tmp != 0)
			erase(tmp);
	}*/
	void erase(Key k) {
		t_node<value_type> *tmp = search(k);

		if (tmp != 0)
			erase(tmp);
	}
	t_node<value_type>	*smallest() {
		t_node<value_type> *tmp = _root;

		if (tmp != 0){
			while (tmp->left != 0)
				tmp = tmp->left;
		}
		return (tmp);
	}
	t_node<value_type>	*smallest() const{
		t_node<value_type> *tmp = _root;

		if (tmp != 0){
			while (tmp->left != 0)
				tmp = tmp->left;
		}
		return (tmp);
	}
	t_node<value_type>	*biggest() {
		t_node<value_type> *tmp = _root;

		if (tmp != 0){
			while (tmp->right != 0){
//				std::cout << tmp->first << " bst debug\n";
				tmp = tmp->right;
			}
		}
		return (tmp);
	}
	t_node<value_type>	*biggest() const{
		t_node<value_type> *tmp = _root;

		if (tmp != 0){
			while (tmp->right != 0)
				tmp = tmp->right;
		}
		return (tmp);
	}
	void print_bst(){
		print_bst(_root);
	}
	void print_bst(t_node<value_type> *root){
		if (root != 0){
			print_bst(root->left);
			std::cout << root->val.second << std::endl;
			print_bst(root->right);
		}
	}
	void erase_tree(){
		erase_tree(_root);
		_root = 0;
	}
	t_node<value_type>	*end() const{ return _end; }
	t_node<value_type>	*rend() const{ return _rend; }
private:
	t_node<value_type>	*_root;
	Compare			_comp;
	Alloc			_alloc;
	unsigned long	_size;
	t_node<value_type>	*_end;
	t_node<value_type>	*_rend;
	void	erase_tree(t_node<value_type> *n){
		if (n == 0)
			return ;
		if (n->left != 0)
			erase_tree(n->left);
		if (n->right != 0)
			erase_tree(n->right);
		delete n;
		n = 0;
		--_size;
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
	t_node<value_type> *insert(t_node<value_type> *root, t_node<value_type> *node) {
		if (root == 0)
			return node;
		if (root != 0 && _comp(node->val.first, root->val.first)){
			root->left = insert(root->left, node);
			root->left->up = root;
		}
		else if (root != 0 &&_comp(root->val.first, node->val.first)){
			root->right = insert(root->right, node);
			root->right->up = root;
		}
		return root;
	}
	t_node<value_type> *search(t_node<value_type> *node, Key &k) {
		t_node<value_type> *tmp = 0;

		if (node != 0){
			if (k == node->val.first)
				tmp = node;
			else if (_comp(k, node->val.first))
				tmp = search(node->left, k);
			else if (_comp(node->val.first, k))
				tmp = search(node->right, k);
		}
		return (tmp);
	}
	t_node<value_type> *search(t_node<value_type> *node, const Key &k) const{
		t_node<value_type> *tmp = 0;

		if (node != 0){
			if (k == node->val.first)
				tmp = node;
			else if (_comp(k, node->val.first))
				tmp = search(node->left, k);
			else if (_comp(node->val.first, k))
				tmp = search(node->right, k);
		}
		return (tmp);
	}
};

#endif
