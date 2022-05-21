// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   map_bst.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/18 11:29:51 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/18 21:14:51 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_BST_HPP
# define MAP_BST_HPP

# include "ft.hpp"

//https://en.wikipedia.org/wiki/Sorting_algorithm
//https://www.geeksforgeeks.org/tree-sort/

template < class T >
typedef struct s_node{
	T					val;
	struct s_node	*up;
	struct s_node	*left;
	struct s_node	*right;
	s_node() : val(0), before(0), next(0), up(0), left(0), right(0){}
	s_node(const T &n) : val(n), before(0), next(0), up(0), left(0), right(0){}
	s_node(const struct s_node &node) : val(node.val),before(node.before),
												  next(node.next), up(node.up), left(node.left),
												  right(node.right) {}
/*	struct s_node &operator=(const struct s_node &node){
		this->val = node.val;
		this->up = node.up;
		this->left = node.left;
		this->right = node.right;
		}*/
	~s_node(){}
}	t_node;

template < class Key, class T, class Compare = std::less<Key>,
		   class Alloc = std::allocator<pair<const Key, T> > >
class map_bst{
public:
	//create heap_iterator
	typedef pair<Key, T>			value_type;
	map_bst(const Compare comp = Compare(), const Alloc &alloc = Alloc()) :
		_comp(comp), _alloc(alloc), _root(0), _size(0){}
	~map_bst(){this->erase_tree(_root);}
	t_node *root(){return _root;}
	t_node *search(Key &k) {
		return this->search(_root, k);
	}
	t_node *search(t_node *node, Key &k) {
		t_node *tmp = 0;

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
	void erase(t_node &node) {}
	void erase(Key &k) {}
private:
	t_node		*_root;
	Compare			_comp;
	Alloc			_alloc;
	unsigned long	_size;
	void	erase_tree(t_node *n){
		if (n == 0)
			return ;
		if (n->left != 0)
			erase_tree(n->left);
		if (n->right != 0)
			erase_tree(n->right);
		delete n;
		return ;
	}
	t_node	*insert(t_node *node, value_type &p) {
		if (node == 0)
			return new t_node(p);
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
