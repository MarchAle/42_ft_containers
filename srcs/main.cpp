/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:08:50 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/09 11:12:06 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/vector.hpp"
#include "../incs/iterator_traits.hpp"
#include <vector>
#include <iterator>

int	main()
{
	int array_size = 5;
	std::vector<int> my_vec;
	std::vector<int> my_vec_assign;
	
	for (int i = 0; i < array_size; i++)
	{
		my_vec.push_back(i);
	}

	my_vec_assign.assign(my_vec.begin(), my_vec.end());
	my_vec_assign.assign(4, 444);
	// ft::vector<int>::value_type a = 5;
	// my_vec.push_back(a);
	// ft::vector<int> my_vec;
	// std::vector<std::vector<int> > my_vec;
	// ft::vector<ft::vector<int> > my_vec;

	// vec.push_back(0);
	// std::cout << vec[6] << std::endl;
	
	// ft::vector<int>::iterator it_beg = my_vec.begin();
	// ft::vector<int>::iterator it_end = my_vec.end() - 1;
	try
	{
		// std::vector<int>::iterator it_begin = my_vec.begin();
		// std::vector<int>::iterator it_end = my_vec.end();

		// my_vec_assign.assign(2, 123);
		// my_vec.assign(5, 555);

		std::cout << "Size : " << my_vec.size() << " Capacity : " << my_vec.capacity() << std::endl;
		std::cout << "Size : " << my_vec_assign.size() << " Capacity : " << my_vec_assign.capacity() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << "print my_vec[i]\t" << my_vec[i] << " " << my_vec[i] << std::endl;
		// std::cout << my_vec[i].front() << " " << my_vec.at(i).back() << std::endl;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < my_vec_assign.size(); i++)
	{
		std::cout << "print my_vec_assign[i]\t" << my_vec_assign[i] << " " << my_vec_assign[i] << std::endl;
		// std::cout << my_vec_assign[i].front() << " " << my_vec_assign.at(i).back() << std::endl;
	}
	
	// std::cout << "Max size : " << my_vec.max_size() << std::endl;
	// std::cout << "\nFront : " << my_vec.front().size() << std::endl;
	// std::cout << "Back : " << my_vec.back().size() << std::endl;
}