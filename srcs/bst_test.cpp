// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   bst_test.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/05/23 00:37:47 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/25 11:43:59 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "map_bst.hpp"
#include "ft.hpp"

int main(){
	map_bst<int, char> foo;

	ft::pair<int,char>	a = ft::make_pair(5,'5');
	ft::pair<int,char>	b = ft::make_pair(9,'9');
	ft::pair<int,char>	c = ft::make_pair(3,'3');
	ft::pair<int,char>	d = ft::make_pair(6,'6');
	ft::pair<int,char>	e = ft::make_pair(4,'4');
	foo.insert(a);
	foo.insert(b);
	foo.insert(c);
	foo.insert(d);
	foo.insert(e);
	foo.erase((int)6);
	foo.print_bst();
}
