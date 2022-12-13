/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:32:39 by amarchal          #+#    #+#             */
/*   Updated: 2022/12/13 17:02:19 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

# include <memory>

namespace ft
{
	template<typename T, class Allocator = std::allocator<T> > 
	class vector
	{
		private:
			T*			element;
			Allocator 	alloc;
			
		public:
			vector(){};
			~vector(){};

			void push_back(T e)
			{
				std::cout << alloc.max_size() << std::endl;
				int	*ptr = alloc.allocate(1);
				ptr[0] = e;
				std::cout << ptr << std::endl;
				alloc.destroy(ptr);
				alloc.deallocate(ptr, 1);
				// ptr[0] = 33;
				std::cout << "ICI " << e << std::endl;
			};
		
	};
}


#endif