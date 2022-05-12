// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/01 16:01:30 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/12 13:38:51 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Vector.hpp"
#include <iostream>
#include <vector>
int main()
{
	ft::vector<int> a(3, 100);
	std::vector<int> b(3, 100);

	std::cout << "v.empty() ft <-> std" << std::endl;
	std::cout << a.empty() << " <-> " << b.empty() << std::endl;
	std::cout << "ft::vector <-> std::vector" << std::endl;
	for (unsigned long i = 0; i < b.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	std::cout << "--v.end() ft <-> std" << std::endl;
	std::cout << *(--a.end()) << " <-> " << *(--b.end()) << std::endl;
	std::cout << "v.begin() ft <-> std" << std::endl;
	std::cout << *(a.begin()) << " <-> " << *(b.begin()) << std::endl;
	std::cout << "v.size() ft <-> std" << std::endl;
	std::cout << a.size() << " <-> " << b.size() << std::endl;
	std::cout << "v.max_size() ft <-> std" << std::endl;
	std::cout << a.max_size() << " <-> " << b.max_size() << std::endl;
	std::cout << "v.capacity() ft <-> std" << std::endl;
	std::cout << a.capacity() << " <-> " << b.capacity() << std::endl;
	a.insert(--a.end(), 200);
	b.insert(--b.end(), 200);
	std::cout << "v.insert(--v.end(), 200) ft <-> std" << std::endl;
	for (unsigned long i = 0; i < b.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	a.insert(a.begin(), 200);
	b.insert(b.begin(), 200);
	std::cout << "v.insert(v.begin(), 200) ft <-> std" << std::endl;
	for (unsigned long i = 0; i < b.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	a.resize(2);
	b.resize(2);
	std::cout << "v.resize(2) ft <-> std" << std::endl;
	for (unsigned long i = 0; i < b.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	a.resize(5);
	b.resize(5);
	std::cout << "v.resize(5) ft <-> std" << std::endl;
	for (unsigned long i = 0; i < b.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	a.resize(6, 500);
	b.resize(6, 500);
	std::cout << "v.resize(6, 500) ft <-> std" << std::endl;
	for (unsigned long i = 0; i < b.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	std::cout << "v.capacity() ft <-> std" << std::endl;
	std::cout << a.capacity() << " <-> " << b.capacity() << std::endl;
	a.reserve(20);
	b.reserve(20);
	std::cout << "v.reserve(20) ft <-> std" << std::endl;
	for (unsigned long i = 0; i < a.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	std::cout << "v.capacity() ft <-> std" << std::endl;
	std::cout << a.capacity() << " <-> " << b.capacity() << std::endl;
	ft::vector<int> c(5, 900);
	a.swap(c);
	std::cout << "a.swap(c) a <-> c" << std::endl;
	for (unsigned long i = 0; i < c.size(); i++)
		std::cout << "pos " << i << ": " << ((i < a.size()) ? a[i] : 404) << " <-> " << c[i] << std::endl;
	return 0;
}
