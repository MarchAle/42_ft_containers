/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:08:50 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/10 16:32:58 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/vector.hpp"
#include "../incs/iterator_traits.hpp"
#include <vector>
#include <iterator>

int	main()
{
	try
	{
	int array_size = 5;
	ft::vector<int> my_vec;
	ft::vector<int> my_vec_assign;
	

	for (int i = 1; i < array_size + 1; i++)
	{
		my_vec.push_back(i);
	}
	// my_vec.insert(my_vec.begin(), 3, 789);
	// my_vec_assign.assign(my_vec.begin(), my_vec.end());
	// my_vec_assign.assign(2, 111);
	// my_vec_assign.push_back(555);
	// my_vec_assign.pop_back();
	my_vec_assign.insert(my_vec_assign.begin(), my_vec.begin(), my_vec.end());
	
	std::cout << "erase : " << *(my_vec_assign.erase(my_vec_assign.begin() + 1, my_vec_assign.end() - 2)) << std::endl;
	// ft::vector<int>::value_type a = 5;
	// my_vec.push_back(a);
	// ft::vector<int> my_vec;
	// std::vector<std::vector<int> > my_vec;
	// ft::vector<ft::vector<int> > my_vec;

	// vec.push_back(0);
	// std::cout << vec[6] << std::endl;
	
	// ft::vector<int>::iterator it_beg = my_vec.begin();
	// ft::vector<int>::iterator it_end = my_vec.end() - 1;
		// std::vector<int>::iterator it_begin = my_vec.begin();
		// std::vector<int>::iterator it_end = my_vec.end();

		// my_vec_assign.assign(2, 123);
		// my_vec.assign(5, 555);

	std::cout << "Size : " << my_vec.size() << " Capacity : " << my_vec.capacity() << std::endl;
	std::cout << "Size : " << my_vec_assign.size() << " Capacity : " << my_vec_assign.capacity() << std::endl;
	
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
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}