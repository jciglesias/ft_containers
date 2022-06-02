// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map_tests.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/01 15:01:31 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/02 16:31:55 by jiglesia         ###   ########.fr       //
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
	a['c'] = 30;
	b['c'] = 30;
	a['d'] = 40;
	b['d'] = 40;
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
	std::cout << "map.key_comp()(map.begin()->first, map.rbegin()->first):\n";
	if (c.key_comp()(c.begin()->first, (c.rbegin())->first) == d.key_comp()(d.begin()->first, d.rbegin()->first))
		std::cout << "OK\n";
	else
		std::cout << "KO\n";
	std::cout << "map.value_comp()(*map.begin(), *map.rbegin()):\n";
	if (c.value_comp()(*c.begin(), *c.rbegin()) == d.value_comp()(*d.begin(), *d.rbegin()))
		std::cout << "OK\n";
	else
		std::cout << "KO\n";
	std::cout << "map.find('x'):\n";
	if ((*(c.find('b'))).second == (*(d.find('b'))).second)
		std::cout << "OK\n";
	else
		std::cout << "KO\n";
	std::cout << "map.count('x'):\n";
	if (c.count('b') == d.count('b'))
		std::cout << "OK\n";
	else
		std::cout << "KO\n";
	std::cout << "map.lower_bound('x'):\n";
	if ((*(c.lower_bound('b'))).second == (*(d.lower_bound('b'))).second)
		std::cout << "OK\n";
	else
		std::cout << "KO\n";
	std::cout << "map.upper_bound('x'):\n";
	if ((*(c.upper_bound('b'))).second == (*(d.upper_bound('b'))).second)
		std::cout << "OK\n";
	else
		std::cout << "KO\n";
	std::cout << "map.equal_range('x'):\n";
	if ((c.equal_range('b')).second->second == (d.equal_range('b')).second->second)
		std::cout << "OK\n";
	else
		std::cout << "KO\n";
}
