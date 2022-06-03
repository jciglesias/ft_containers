// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   std_main.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/06/03 15:04:18 by jiglesia          #+#    #+#             //
//   Updated: 2022/06/03 17:00:26 by jiglesia         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <vector>

#include <iostream>
#include "Stack_tests.hpp"
#include "Map_tests.hpp"
#include "Vector_tests.hpp"

int main()
{
	std::stack<int> s;
	std::vector<int> v(3, 200);
	std::map<char, int> m;
	vector_test(v);
	map_test(m);
	stack_test(s);
}
