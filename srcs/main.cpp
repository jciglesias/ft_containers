// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/01 16:01:30 by jiglesia          #+#    #+#             //
//   Updated: 2022/05/11 13:09:56 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Vector.hpp"
#include <iostream>
#include <vector>
int main()
{
	ft::vector<int> a(3, 100);
	std::vector<int> b(3, 100);

	std::cout << "ft::vector <-> std::vector" << std::endl;
	a.insert(--a.end(), (int)200);
	b.insert(--b.end(), (int)200);
	for (unsigned long i = 0; i < a.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	a.resize(2);
	b.resize(2);
	std::cout << "ft::vector <-> std::vector" << std::endl;
	for (unsigned long i = 0; i < b.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	a.resize(6, 50);
	b.resize(6, 50);
	std::cout << "ft::vector <-> std::vector" << std::endl;
	for (unsigned long i = 0; i < b.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	a.resize(5);
	b.resize(5);
	std::cout << "ft::vector <-> std::vector" << std::endl;
	for (unsigned long i = 0; i < b.size(); i++)
		std::cout << "pos " << i << ": " << a[i] << " <-> " << b[i] << std::endl;
	return 0;
}
