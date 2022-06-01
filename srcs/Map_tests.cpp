// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map_tests.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/01 15:01:31 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/01 15:27:44 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Map.hpp"
#include <map>

template < typename Key, typename T >
void cmpmap(ft::map<Key, T> a, std::map<Key, T> b){
	if (a.size() != b.size()){
		std::cout << "ft size = " << a.size() << std::endl;
		std::cout << "std size = " << b.size() << std::endl;
		return ;
	}
	if (a.empty() != b.empty()){
		std::cout << "KO\n";
		return ;
	}
/*	if (a.max_size() != b.max_size()){
		std::cout << "ft max_size = " << a.max_size() << std::endl;
		std::cout << "std max_size = " << b.max_size() << std::endl;
		return ;
	}
*/	typename ft::map<Key, T>::iterator ait = a.begin();
	typename std::map<Key, T>::iterator bit = b.begin();
	for (unsigned long i = 0; i < b.size(); i++){
		if (ait->first != bit->first || ait->second != bit->second){
			std::cout << "KO\n";
			return ;
		}
		ait++;
		bit++;
	}
	std::cout << "OK\n";
}

void map_test(){
	ft::map<char, int> a;
	std::map<char, int> b;

	a['a'] = 10;
	b['a'] = 10;
	a['b'] = 20;
	b['b'] = 20;
	a['c'] = 10;
	b['c'] = 10;
	a['d'] = 20;
	b['d'] = 20;
	std::cout << "map['x'] = y:\n";
	cmpmap(a, b);
	a.insert(ft::make_pair('e', 30));
	b.insert(std::make_pair('e', 30));
	std::cout << "map.insert(pair('x', y)):\n";
	cmpmap(a, b);
	ft::map<char, int> c;
	std::map<char, int> d;

	c.insert(a.begin(), a.end());
	d.insert(b.begin(), b.end());
	std::cout << "map.insert(iterator, iterator):\n";
	cmpmap(c, d);
	a.erase('b');
	b.erase('b');
	std::cout << "map.erase('x'):\n";
	cmpmap(a, b);
	a.erase(a.begin());
	b.erase(b.begin());
	std::cout << "map.erase(iterator):\n";
	cmpmap(a, b);
	a.erase(a.begin(), a.end());
	b.erase(b.begin(), b.end());
	std::cout << "map.erase(iterator, iterator):\n";
	cmpmap(a, b);
	a.insert(c.begin(), c.end());
	b.insert(d.begin(), d.end());
	c.clear();
	d.clear();
	std::cout << "map.clear():\n";
	cmpmap(c, d);
	a.swap(c);
	b.swap(d);
	std::cout << "map.swap(map):\n";
	cmpmap(c, d);
}
