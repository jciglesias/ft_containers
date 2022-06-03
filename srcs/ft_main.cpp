// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2021/10/01 16:01:30 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/03 17:00:20 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Stack_tests.hpp"
#include "Map_tests.hpp"
#include "Vector_tests.hpp"

int main()
{
	ft::stack<int> s;
	ft::vector<int> v(3, 200);
	ft::map<char, int> m;
	vector_test(v);
	map_test(m);
	stack_test(s);
}
