/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:08:50 by amarchal          #+#    #+#             */
/*   Updated: 2022/12/14 17:07:08 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/vector.hpp"
#include <vector>

int	main()
{
	std::vector<int> vec;
	ft::vector<int> my_vec;

	// vec.push_back(0);
	// std::cout << vec[6] << std::endl;
	
	int array_size = 5;
	for (int i = 1; i < array_size + 1; i++)
		my_vec.push_back(i);

	// try
	// {
	// 	// my_vec.at(189) = 88;
	// 	my_vec.at(0) = 456;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	std::cout << "Size : " << my_vec.size() << " Capacity : " << my_vec.capacity() << std::endl;
	my_vec.resize(11);
	std::cout << "Size : " << my_vec.size() << " Capacity : " << my_vec.capacity() << std::endl;
	my_vec.push_back(666);
	std::cout << "Size : " << my_vec.size() << " Capacity : " << my_vec.capacity() << std::endl;
	// my_vec.push_back(666);
	// my_vec.push_back(666);
		
	for (size_t i = 0; i < my_vec.size(); i++)
		std::cout << my_vec[i] << " " << my_vec.at(i) << std::endl;
	
	// std::cout << "Max size : " << my_vec.max_size() << std::endl;
	std::cout << "\nFront : " << my_vec.front() << std::endl;
	std::cout << "Back : " << my_vec.back() << std::endl;
}