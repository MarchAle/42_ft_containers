/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:08:50 by amarchal          #+#    #+#             */
/*   Updated: 2022/12/15 16:47:09 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/vector.hpp"
#include <vector>

int	main()
{
	std::vector<std::string> my_vec;
	// std::vector<std::vector<int> > my_vec;
	// ft::vector<ft::vector<int> > my_vec;

	// vec.push_back(0);
	// std::cout << vec[6] << std::endl;
	
	int array_size = 5;
	for (int i = 0; i < array_size; i++)
	{
		// std::vector<int> test;
		// ft::vector<int> test;
		// test.push_back(123);
		// test.push_back(789);
		my_vec.push_back("test");
		// std::cout << "Size : " << my_vec.size() << " Capacity : " << my_vec.capacity() << std::endl;
		// std::cout << "test " << test.front() << " " << test.back() << std::endl;
		// std::cout << "my_vec.at(i)\t" << my_vec.at(i).front() << " " << my_vec.at(i).back() << std::endl;
		// std::cout << "my_vec[i]\t" << my_vec[i].front() << " " << my_vec[i].back() << std::endl;
	}
	try
	{
		// my_vec.at(189) = 88;
		// my_vec.at(0) = 456;
		// std::cout << "Size : " << my_vec.size() << " Capacity : " << my_vec.capacity() << std::endl;
		// ft::vector<int> blabla;
		// blabla.push_back(333);
		// my_vec.resize(1, "blabla");
		// my_vec.resize(5, "blabla");
		// blabla[0] = 111;
		// my_vec.push_back("test");
		// my_vec.resize(39, "blabla");
		// my_vec.resize(3, "blabla");
		// my_vec.resize(10);
		// my_vec.resize(11);
		// my_vec.resize(9);
		// my_vec.resize(13, "plus");
		// my_vec.resize(11);
		// std::cout << "Size : " << my_vec.size() << " Capacity : " << my_vec.capacity() << std::endl;
		// my_vec.push_back("coucou");
		my_vec.reserve(19);
		std::cout << "Size : " << my_vec.size() << " Capacity : " << my_vec.capacity() << std::endl;
		// std::cout << "Size : " << my_vec[0].front() << " Capacity : " << my_vec[0].capacity() << std::endl;
		// my_vec.push_back(666);
		// my_vec.push_back(666);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		
	for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << "print my_vec[i]\t" << my_vec[i] << " " << my_vec[i] << std::endl;
		// std::cout << my_vec[i].front() << " " << my_vec.at(i).back() << std::endl;
	}
	
	// std::cout << "Max size : " << my_vec.max_size() << std::endl;
	// std::cout << "\nFront : " << my_vec.front().size() << std::endl;
	// std::cout << "Back : " << my_vec.back().size() << std::endl;
}