// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map_tests.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/03 16:37:37 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/29 12:18:11 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_TESTS_HPP
# define MAP_TESTS_HPP

# include "map.hpp"
# include <map>

template < typename T >
void cmpmap(T &m){
	std::cout << m.size() << std::endl;
	std::cout << m.empty() << std::endl;
	typename T::iterator mit = m.begin();
	unsigned long size = m.size();
	for (unsigned long i = 0; i < size; i++){
		std::cout << "[" << i << "] = " << m[i] << std::endl;
		mit++;
	}
}

template < class T >
void map_test(T &m){
	m[1] = 1;
	typename T::iterator it = m.begin();
	std::cout << it->second << std::endl;
	m[-1] = -1;
	std::cout << it->second << std::endl;
	std::cout << "map['x'] = y:\n";
	for (int i = 0; i < 1000; i++)
		m[i] = i;
	cmpmap(m);
	std::cout << "map.insert(iterator, iterator):\n";
	T c;
	c.insert(m.begin(), m.end());
	std::cout << "map == map: " << (m == c) << std::endl;
	std::cout << "map <= map: " << (m <= c) << std::endl;
	std::cout << "map >= map: " << (m >= c) << std::endl;
	std::cout << "map < map: " << (m < c) << std::endl;
	std::cout << "map > map: " << (m > c) << std::endl;
	std::cout << "map != map: " << (m != c) << std::endl;
	cmpmap(c);
	std::cout << "map.erase('x'):\n";
	m.erase('b');
	cmpmap(m);
	m.erase(m.begin());
	std::cout << "map.erase(iterator):\n";
	cmpmap(m);
	m.erase(m.begin(), m.end());
	std::cout << "map.erase(iterator, iterator):\n";
	cmpmap(m);
	m.insert(c.begin(), c.end());
	c.clear();
	std::cout << "map.clear():\n";
	cmpmap(c);
	m.swap(c);
	std::cout << "map.swap(map):\n";
	cmpmap(c);
	std::cout << "map.key_comp()(map.begin()->first, map.rbegin()->first):\n";
	std::cout << c.key_comp()(c.begin()->first, (c.rbegin())->first) << std::endl;
	std::cout << "map.value_comp()(*map.begin(), *map.rbegin()):\n";
	std::cout << c.value_comp()(*c.begin(), *c.rbegin()) << std::endl;
	std::cout << "map.find('x'):\n";
	std::cout << (*(c.find('b'))).second << std::endl;
	std::cout << "map.count('x'):\n";
	std::cout << c.count('b') << std::endl;
	std::cout << "map.lower_bound('x'):\n";
	std::cout << (*(c.lower_bound('b'))).second << std::endl;
	std::cout << "map.upper_bound('x'):\n";
	std::cout << (*(c.upper_bound('b'))).second << std::endl;
	std::cout << "map.equal_range('x'):\n";
	std::cout << (c.equal_range('b')).second->second << std::endl;
	std::cout << "map == map: " << (m == c) << std::endl;
	std::cout << "map <= map: " << (m <= c) << std::endl;
	std::cout << "map >= map: " << (m >= c) << std::endl;
	std::cout << "map < map: " << (m < c) << std::endl;
	std::cout << "map > map: " << (m > c) << std::endl;
	std::cout << "map != map: " << (m != c) << std::endl;
}
#endif
