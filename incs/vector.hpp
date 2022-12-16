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
# include <new>

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
			size_t		old_capacity;
			size_t		vec_capacity;
			
			void	_move_array(size_t new_capacity)
			{
				T*		new_array;
				
				old_capacity = vec_capacity;
				vec_capacity = new_capacity;
				new_array = alloc.allocate(vec_capacity);
				for (size_t i = 0; i < arr_size; i++)
				{
					alloc.construct(new_array + i, array[i]);
					alloc.destroy(array + i);
				}
				alloc.deallocate(array, old_capacity);
				array = new_array;
			};
			
		public:
			/////////// CONSTRUCTOR
			vector()
			{
				array = NULL;
				arr_size = 0;
				vec_capacity = 1;
			};
			/////////// COPY CONSTRUCTOR
			vector(const vector &src)
			{
				*this = src;
			};
			/////////// ASSIGNATION OPERATOR OVERLOAD
			vector &operator=(const vector &src)
			{
				this->alloc = src.alloc;
				this->array = alloc.allocate(src.vec_capacity);
				for (size_t i = 0; i < src.arr_size; i++)
				{
					alloc.construct(array + i, src.array[i]);
				}
				this->arr_size = src.arr_size;
				this->vec_capacity = src.vec_capacity;
				
				return (*this);
			};
			/////////// DESTRUCTOR
			~vector()
			{
				for (size_t i = 0; i < arr_size; i++)
					alloc.destroy(array + i);
				alloc.deallocate(array, vec_capacity);
			};

			///////// MODIFIERS
			void	push_back(const T &e)
			{
				if (arr_size == 0)
					array = alloc.allocate(vec_capacity);
				else if (arr_size + 1 > vec_capacity)
					_move_array(vec_capacity *= 2);
				alloc.construct(array + arr_size, e);
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

			void	_resize_cpy(T *new_array, size_t &n, T &val)
			{
				size_t	i = 0;

				while (i < arr_size && i < n)
				{
					alloc.construct(new_array + i, array[i]);
					i++;
				}
				while (i < n)
				{
					alloc.construct(new_array + i, val);
					i++;
				}
			}
				
			void	resize(size_t n)
			{
				T*		new_array;
				T		def_val;
				
				if (n == arr_size)
					return ;
				try
				{
					old_capacity = vec_capacity;
					if (n > vec_capacity)
					{
						if (n < 16)
						{
							while (vec_capacity < n)
								vec_capacity += 4;
						}
						else
							vec_capacity = n;
					}
					new_array = alloc.allocate(vec_capacity);
					_resize_cpy(new_array, n, def_val);
					for (size_t i = 0; i < arr_size; i++)
						alloc.destroy(array + i);
					alloc.deallocate(array, old_capacity);
					array = new_array;
					arr_size = n;
				}
				catch(const std::bad_alloc& e)
				{
					alloc.deallocate(new_array, vec_capacity);
					throw ;
				}
			};

			void	resize(size_t n, T val)
			{
				T*		new_array;
				
				if (n == arr_size)
					return ;
				try
				{
					old_capacity = vec_capacity;
					if (n > vec_capacity)
					{
						if (n < 16)
						{
							while (vec_capacity < n)
								vec_capacity += 4;
						}
						else
							vec_capacity = n;
					}
					new_array = alloc.allocate(vec_capacity);
					_resize_cpy(new_array, n, val);
					for (size_t i = 0; i < arr_size; i++)
						alloc.destroy(array + i);
					alloc.deallocate(array, old_capacity);
					array = new_array;
					arr_size = n;
				}
				catch(const std::bad_alloc& e)
				{
					alloc.deallocate(new_array, vec_capacity);
					throw ;
				}
			};
				
			size_t	capacity() const
			{
				return (vec_capacity);
			};

			bool	empty() const
			{
				if (arr_size == 0)
					return true;
				else
					return false;
			};

			void	reserve(size_t n)
			{
				if (n <= vec_capacity)
					return ;
				else
					_move_array(n);
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