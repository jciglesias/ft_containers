// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   map_bst.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/18 11:29:51 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/28 11:39:10 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_BST_HPP
# define MAP_BST_HPP

# include "../ft.hpp"

//https://en.wikipedia.org/wiki/Sorting_algorithm
//https://www.geeksforgeeks.org/tree-sort/
namespace ft{
	template < class T >
	class node{
	public:
	//	Key		first;
	//	T		second;
		T		val;
		node	*up;
		node	*left;
		node	*right;
		node() : val(), up(0), left(0), right(0){}
		node(const T &n) : val(n), up(0), left(0), right(0){}
		node(const node &node) : val(&(node.val)),
									up(&(node.up)), left(&(node.left)), right(&(node.right)) {}
	/*	struct s_node &operator=(const struct s_node &node){
			this->val = node.val;
			this->up = node.up;
			this->left = node.left;
			this->right = node.right;
		}*/
		~node(){}
	};

	template < class T >
	bool operator==(const ft::node<T> *lhs, const ft::node<T> *rhs){
		return (lhs->val == rhs->val);
	}
	template < class T >
	bool operator!=(const ft::node<T> *lhs, const ft::node<T> *rhs){
		return (lhs->val != rhs->val);
	}
	template < class T >
	bool operator>(const ft::node<T> *lhs, const ft::node<T> *rhs){
		return (lhs->val > rhs->val);
	}
	template < class T >
	bool operator>=(const ft::node<T> *lhs, const ft::node<T> *rhs){
		return (lhs->val >= rhs->val);
	}
	template < class T >
	bool operator<(const ft::node<T> *lhs, const ft::node<T> *rhs){
		return (lhs->val < rhs->val);
	}
	template < class T >
	bool operator<=(const ft::node<T> *lhs, const ft::node<T> *rhs){
		return (lhs->val <= rhs->val);
	}
	template < class T >
	T operator+(const ft::node<T> *lhs, const ft::node<T> *rhs){
		return (lhs->val + rhs->val);
	}
	template < class T >
	T operator-(const ft::node<T> *lhs, const ft::node<T> *rhs){
		return (lhs->val - rhs->val);
	}
}

template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator<ft::pair<const Key, T> > >
class map_bst{
public:
	//create heap_iterator
	typedef ft::pair<const Key, T>			value_type;
	map_bst(const Compare comp = Compare(), const Alloc &alloc = Alloc()) :
		_root(0), _comp(comp), _alloc(alloc), _size(0), _end(0), _rend(0){
	}
	~map_bst(){
		this->erase_tree(_root);
		delete _end;
		delete _rend;
	}
	ft::node<value_type> *root(){return _root;}
/*	ft::node<value_type> *search(Key &k) {
		return this->search(_root, k);
	}*/
	unsigned long	size() const { return _size; }
	ft::node<value_type> *search(Key k) {
		return this->search(_root, k);
	}
	ft::node<value_type> *search(const Key k) const{
		return this->search(_root, k);
	}
/*	bool insert(value_type &p) {
		if (this->search(_root, p.first) != 0)
			return false;
		_root = this->insert(_root, p);
		_size++;
		return true;
	}*/
	void setEnd(){
		if (_end == 0)
			_end = new ft::node<value_type>;
		if (_rend == 0)
			_rend = new ft::node<value_type>;
		this->_end->up = _root;
		this->_end->left = this->smallest();
		this->_end->right = this->biggest();
		this->_rend->up = _root;
		this->_rend->left = this->_end->right;
		this->_rend->right = this->_end->left;
	}
	bool insert(value_type p) {
		if (this->search(_root, p.first) != 0)
			return false;
		_root = this->insert(_root, p);
		_size++;
		this->setEnd();
		return true;
	}
	void erase(ft::node<value_type> *node) {
		ft::node<value_type> *left = node->left;
		ft::node<value_type> *right = node->right;

		if (node->up != 0 && node->up->left == node)
			node->up->left = 0;
		else if (node->up != 0)
			node->up->right = 0;
		if (node == _root)
			_root = 0;
		delete node;
		_size--;
		if (!_size){
			delete _end;
			delete _rend;
			_end = 0;
			_rend = 0;
		}
		if (right != 0){
			right->up = 0;
			_root = insert(_root, right);
			this->setEnd();
		}
		if (left != 0){
			left->up = 0;
			_root = insert(_root, left);
			this->setEnd();
		}
		this->setEnd();
	}
/*	void erase(Key &k) {
		ft::node<value_type> *tmp = search(k);

		if (tmp != 0)
			erase(tmp);
	}*/
	void erase(Key k) {
		ft::node<value_type> *tmp = search(k);

		if (tmp != 0)
			erase(tmp);
	}
	ft::node<value_type>	*smallest() {
		ft::node<value_type> *tmp = _root;

		if (tmp != 0){
			while (tmp->left != 0)
				tmp = tmp->left;
		}
		return (tmp);
	}
	ft::node<value_type>	*smallest() const{
		ft::node<value_type> *tmp = _root;

		if (tmp != 0){
			while (tmp->left != 0)
				tmp = tmp->left;
		}
		return (tmp);
	}
	ft::node<value_type>	*biggest() {
		ft::node<value_type> *tmp = _root;

		if (tmp != 0){
			while (tmp->right != 0){
				tmp = tmp->right;
			}
		}
		return (tmp);
	}
	ft::node<value_type>	*biggest() const{
		ft::node<value_type> *tmp = _root;

		if (tmp != 0){
			while (tmp->right != 0)
				tmp = tmp->right;
		}
		return (tmp);
	}
	void print_bst(){
		print_bst(_root);
	}
	void print_bst(ft::node<value_type> *root){
		if (root != 0){
			print_bst(root->left);
			std::cout << root->val.second << std::endl;
			print_bst(root->right);
		}
	}
	void erase_tree(){
		erase_tree(_root);
		_root = 0;
		delete _end;
		delete _rend;
		_end = 0;
		_rend = 0;
	}
	ft::node<value_type>	*end() const{ return _end; }
	ft::node<value_type>	*rend() const{ return _rend; }
private:
	ft::node<value_type>	*_root;
	Compare					_comp;
	Alloc					_alloc;
	unsigned long			_size;
	ft::node<value_type>	*_end;
	ft::node<value_type>	*_rend;
	void	erase_tree(ft::node<value_type> *n){
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
	ft::node<value_type>	*insert(ft::node<value_type> *node, value_type &p) {
		if (node == 0)
			return new ft::node<value_type>(p);
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
	ft::node<value_type> *insert(ft::node<value_type> *root, ft::node<value_type> *node) {
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
	ft::node<value_type> *search(ft::node<value_type> *node, Key &k) {
		ft::node<value_type> *tmp = 0;

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
	ft::node<value_type> *search(ft::node<value_type> *node, const Key &k) const{
		ft::node<value_type> *tmp = 0;

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
