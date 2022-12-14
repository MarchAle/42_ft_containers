/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:32:39 by amarchal          #+#    #+#             */
/*   Updated: 2022/12/14 17:07:25 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstring>
# include <stdexcept>

# include <memory>

namespace ft
{
	template<typename T, class Allocator = std::allocator<T> > 
	class vector
	{
		// typedef typename std::size_t size_type;

		private:
			T*			array;
			Allocator 	alloc;
			size_t		arr_size;
			size_t		vec_capacity;
			
		public:
			vector()
			{
				array = NULL;
				arr_size = 0;
				vec_capacity = 1;
			};
			~vector()
			{
				alloc.deallocate(array, arr_size);
			};

			///////// MODIFIERS
			void	push_back(const T &e)
			{
				if (arr_size == 0)
					array = alloc.allocate(vec_capacity);
				else if (arr_size + 1 > vec_capacity)
					move_array();
				array[arr_size] = e;
				arr_size++;
			};

			void	move_array()
			{
				T*		new_array;
				
				vec_capacity *= 2;
				new_array = alloc.allocate(vec_capacity);
				for (size_t i = 0; i < arr_size; i++)
					new_array[i] = array[i];
				alloc.deallocate(array, vec_capacity / 2);
				array = new_array;
			};
			
			///////// CAPACITY
			size_t	size() const
			{
				return (arr_size);
			};
			
			size_t	max_size() const
			{
				return (alloc.max_size());
			};

			void	resize(size_t n)
			{
				T*		new_array;
				size_t	i = 0;
				
				if (n == arr_size)
					return ;
				new_array = alloc.allocate(n);
				while (i < arr_size && i < n)
				{
					new_array[i] = array[i];
					i++;
				}
				while (i < n)
				{
					new_array[i] = 0;
					i++;
				}
				alloc.deallocate(array, vec_capacity);		
				array = new_array;
				arr_size = n;
				vec_capacity = n;
			};
			
			// void	resize(size_t n, value_type val = value_type())
			// {
				
			// };
			
			size_t	capacity() const
			{
				return (vec_capacity);
			};

			///////// ELEMENT ACCESS
			T &operator[](int index)
			{
				return (array[index]);	
			};
			T const &operator[](int index) const
			{
				return (array[index]);	
			};
			
			T &at(int index)
			{
				if (index < 0 || index > (int)arr_size)
					throw std::out_of_range ("vector");
				return (array[index]);	
			};
			T const &at(int index) const
			{
				if (index < 0 || index > (int)arr_size)
					throw std::out_of_range ("vector");
				return (array[index]);	
			};

			T &front()
			{
				return (array[0]);
			};
			T const &front() const
			{
				return (array[0]);
			};

			T &back()
			{
				return (array[arr_size - 1]);
			};
			T const &back() const
			{
				return (array[arr_size - 1]);
			};

	};
}


#endif