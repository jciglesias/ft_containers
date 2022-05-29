// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   bst_test.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/23 00:37:47 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/27 17:41:20 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "map_bst.hpp"
#include "ft.hpp"
#include "bst_iterator.hpp"

int main(){
	map_bst<int, char> foo;

	ft::pair<int,char>	a = ft::make_pair(5,'5');
	ft::pair<int,char>	b = ft::make_pair(9,'9');
	ft::pair<int,char>	c = ft::make_pair(3,'3');
	ft::pair<int,char>	d = ft::make_pair(6,'6');
	ft::pair<int,char>	e = ft::make_pair(4,'4');
	foo.insert(b);
	foo.insert(a);
	foo.insert(c);
	foo.insert(d);
	foo.insert(e);
	foo.insert(ft::make_pair(7, '7'));
	foo.insert(ft::make_pair(8, '8'));
	foo.insert(ft::make_pair(2, '2'));
	foo.insert(ft::make_pair(8, '8'));
	foo.insert(ft::make_pair(1, '1'));
//	std::cout << "root->left->right->right->right = " << foo.root()->left->right->right->right->second << std::endl;
	ft::bst_iterator< int, char > it(foo.biggest());
	std::cout << it->second << " it\n";
	std::cout << (it -= 3)->second << " it - 3\n";
	std::cout << it->second << " it\n";
	std::cout << (it += 2)->second << " it + 2\n";
	std::cout << it->second << " it\n";
/*	for (int i = 0; i < 9; i++)
		std::cout << "iteraror++: " << it++->second << std::endl;
	it = foo.biggest();
	for (int i = 0; i < 9; i++)
	std::cout << "iteraror--: " << (it--)->second << std::endl;*/
	foo.print_bst();
}
