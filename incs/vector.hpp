/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:32:39 by amarchal          #+#    #+#             */
/*   Updated: 2022/12/15 16:54:16 by amarchal         ###   ########.fr       */
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
		typedef T value_type;

		private:
			T*			array;
			Allocator 	alloc;
			size_t		arr_size;
			size_t		vec_capacity;
			
			void	_move_array()
			{
				T*		new_array;
				
				vec_capacity *= 2;
				new_array = alloc.allocate(vec_capacity);
				for (size_t i = 0; i < arr_size; i++)
				{
					alloc.construct(new_array + i, array[i]);
					alloc.destroy(array + i);
				}
				alloc.deallocate(array, vec_capacity / 2);
				array = new_array;
			};
			
		public:
			vector()
			{
				array = NULL;
				arr_size = 0;
				vec_capacity = 1;
			};
			vector(const vector &src)
			{
				std::cout << "copy constr called" << std::endl;
				*this = src;
			};
			vector &operator=(const vector &src)
			{
				this->array = src.array;
				this->arr_size = src.arr_size;
				this->vec_capacity = src.vec_capacity;
				this->alloc = src.alloc;
				
				return (*this);
			};
			~vector()
			{
				// alloc.deallocate(array, vec_capacity);
			};

			///////// MODIFIERS
			void	push_back(const T &e)
			{
				if (arr_size == 0)
					array = alloc.allocate(vec_capacity);
				else if (arr_size + 1 > vec_capacity)
					_move_array();
				alloc.construct(array + arr_size, e);
				// array[arr_size] = e;
				arr_size++;
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
				T*			new_array;
				T			test;
				size_t		i = 0;
				
				if (n > max_size())
					throw std::out_of_range("Can't allocate");
				if (n == arr_size)
					return ;
				if (n < vec_capacity)
				{
					new_array = alloc.allocate(vec_capacity);
					while (i < arr_size && i < n)
					{
						new_array[i] = array[i];
						i++;
					}
					while (i < n)
					{
						new_array[i] = test;
						i++;
					}
					alloc.deallocate(array, vec_capacity);
				}
				else
				{
					size_t old_capacity = vec_capacity;
					while (vec_capacity < n && vec_capacity < max_size())
						vec_capacity *= 2;
					try
					{
						new_array = alloc.allocate(vec_capacity);
					}
					catch(const std::exception& e)
					{
						std::cerr << e.what() << '\n';
						return ;
					}
					while (i < arr_size && i < n)
					{
						new_array[i] = array[i];
						i++;
					}
					while (i < n)
					{
						new_array[i] = test;
						i++;
					}
					alloc.deallocate(array, old_capacity);
				}
				array = new_array;
				arr_size = n;
			};
				
			void	resize(size_t n, T val)
			{
				T*		new_array;
				size_t	i = 0;
				
				if (n > max_size())
					throw std::out_of_range("Can't allocate");
				if (n == arr_size)
					return ;
				if (n < vec_capacity)
				{
					new_array = alloc.allocate(vec_capacity);
					while (i < arr_size && i < n)
					{
						alloc.construct(new_array + i, array[i]);
						alloc.destroy(array + i);
						// new_array[i] = array[i];
						i++;
					}
					while (i < n)
					{
						alloc.construct(new_array + i, val);
						// new_array[i] = val;
						i++;
					}
					alloc.deallocate(array, vec_capacity);
				}
				else
				{
					size_t old_capacity = vec_capacity;
					while (vec_capacity < n && vec_capacity < max_size())
						vec_capacity *= 2;
					try
					{
						new_array = alloc.allocate(vec_capacity);
					}
					catch(const std::exception& e)
					{
						std::cerr << e.what() << '\n';
						return ;
					}
					while (i < arr_size && i < n)
					{
						alloc.construct(new_array + i, array[i]);
						alloc.destroy(array + i);
						// new_array[i] = array[i];
						i++;
					}
					while (i < n)
					{
						alloc.construct(new_array + i, val);
						// new_array[i] = val;
						// std::cout << " Ici " << (int)val[0] << std::endl;
						i++;
					}
					alloc.deallocate(array, old_capacity);
				}
				array = new_array;
				arr_size = n;
			};
			
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

			T& front()
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