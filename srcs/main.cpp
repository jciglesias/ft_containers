// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/01 16:01:30 by jiglesia          #+#    #+#             //
//   Updated: 2022/04/27 21:15:59 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Vector.hpp"
#include <iostream>
#include <vector>
int main()
{
	ft::vector<int> a;
	std::vector<int> b;
	a.i = 42;
	std::cout << a.i << std::endl;
	return 0;
}
