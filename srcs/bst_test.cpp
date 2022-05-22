// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   bst_test.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/23 00:37:47 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/23 01:03:09 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "map_bst.hpp"
#include "ft.hpp"

int main(){
	map_bst<int, char> foo;

	foo.insert(ft::make_pair((int)5,(char)'5'));
	foo.insert(ft::make_pair(9,'9'));
	foo.insert(ft::make_pair(3,'3'));
	foo.insert(ft::make_pair(6,'6'));
	foo.insert(ft::make_pair(4,'4'));
	foo.print_bst(foo.root());
}
