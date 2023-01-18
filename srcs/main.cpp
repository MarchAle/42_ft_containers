/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:08:50 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/18 11:50:35 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/vector.hpp"
#include "../incs/iterator_traits.hpp"
#include <vector>
#include <iterator>

template<typename T>
void	print_vec(T vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "[" << i << "] " << vec[i] << std::endl;
}

int	main()
{
	try
	{
	int array_size = 6;
	ft::vector<int> my_vec;
	std::vector<int> my_vec_assign;
	std::vector<int> fill;

	ft::vector<int>::iterator it;
	std::vector<int>::iterator stdit;

	for (int i = 1; i < array_size + 1; i++)
	{
		fill.push_back(i);
		// my_vec.push_back(i);
		// my_vec_assign.push_back(i);
	}
	// for (int i = 1; i < array_size + 1; i++)
	// {
	// 	fill.pop_back();
	// 	my_vec.pop_back();
	// 	my_vec_assign.pop_back();
	// }
	
	// my_vec.assign(5, 1);
	my_vec.insert(my_vec.end(), fill.begin(), fill.end());
	// my_vec_assign.assign(5, 1);
	my_vec_assign.insert(my_vec_assign.end(), fill.begin(), fill.end());
	
	it = my_vec.begin();
	stdit = my_vec_assign.begin();

	std::cout << "it " << *it << std::endl;
	std::cout << "stdit " << *stdit << std::endl;
	// std::cout << "my_vec[2121] " << my_vec[2121] << std::endl;
	// std::cout << "my_vec_assign[2121] " << my_vec_assign[2121] << std::endl;

	std::cout << "my_vec\t\tSize : " << my_vec.size() << " Capacity : " << my_vec.capacity() << std::endl;
	std::cout << "my_vec_assign\tSize : " << my_vec_assign.size() << " Capacity : " << my_vec_assign.capacity() << std::endl;
	
	std::cout << std::endl << "my_vec" << std::endl;
	print_vec(my_vec);
	std::cout << std::endl << "my_vec_assign" << std::endl;
	print_vec(my_vec_assign);
	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}