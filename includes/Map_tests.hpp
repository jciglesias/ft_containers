// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map_tests.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/03 16:37:37 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/03 17:02:06 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_TESTS_HPP
# define MAP_TESTS_HPP

# include "Map.hpp"
# include <map>

template < typename T >
void cmpmap(T &m){
	std::cout << m.size() << std::endl;
	std::cout << m.empty() << std::endl;
/*	if (a.max_size() != b.max_size()){
		std::cout << "ft max_size = " << a.max_size() << std::endl;
		std::cout << "std max_size = " << b.max_size() << std::endl;
		return ;
	}
*/
	typename T::iterator mit = m.begin();
	for (unsigned long i = 0; i < m.size(); i++){
		std::cout << "[" << mit->first << "] = " << mit->second << std::endl;
		mit++;
	}
}

template < class T >
void map_test(T &m){
	std::cout << "map['x'] = y:\n";
	m['a'] = 10;
	m['b'] = 20;
	m['c'] = 30;
	m['d'] = 40;
	cmpmap(m);
	std::cout << "map.insert(iterator, iterator):\n";
	T c;
	c.insert(m.begin(), m.end());
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
}
#endif
