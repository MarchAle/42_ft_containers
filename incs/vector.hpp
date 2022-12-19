/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:32:39 by amarchal          #+#    #+#             */
/*   Updated: 2022/12/19 16:53:40 by amarchal         ###   ########.fr       */
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

			void	_resize_cpy(T *new_array, size_t &n)
			{
				size_t	i = 0;

				while (i < arr_size && i < n)
				{
					alloc.construct(new_array + i, array[i]);
					i++;
				}
				while (i < n)
				{
					alloc.construct(new_array + i, T());
					i++;
				}
			}

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
				
			void	resize(size_t n)
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
					_resize_cpy(new_array, n);
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

			//////////////// ITERATOR
			class iterator
			{
				private:
					T *data;

				public:
					iterator(T* ptr)
					{
						data = ptr;
					};
					iterator(const iterator &src)
					{
						data = src.data;
					};
					~iterator(){};
					
					//////// INCREMENT DECREMENT
					iterator &operator++()
					{
						data++;
						return (*this);
					}
					iterator operator++(int)
					{
						iterator tmp = *this;
						++(*this);
						return (tmp);
					}
					iterator &operator--()
					{
						data--;
						return (*this);
					}
					iterator operator--(int)
					{
						iterator tmp = *this;
						--(*this);
						return (tmp);
					}
					
					//////// INDEX OPERATOR
					T &operator[](int index)
					{
						return (*(data[index]));	
					};
					
					T *operator->()
					{
						return (data);	
					};
					
					T &operator*()
					{
						return (*data);	
					};

					//////// COMPARAISON OPERATOR
					bool operator==(const iterator &other) const
					{
						return (data == other->data);
					}
					
					bool operator!=(const iterator &other) const
					{
						return (data != other->data);
					}
			};

			iterator begin()
			{
				return (iterator(array));
			};

			iterator end()
			{
				return (iterator(array + arr_size));
			};

	};
}

/*
template <typename T>
class VectorIterator {
public:
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::random_access_iterator_tag;

    // Constructors and destructor
    VectorIterator(pointer ptr) : ptr_(ptr) {}
    VectorIterator(const VectorIterator& other) : ptr_(other.ptr_) {}
    ~VectorIterator() = default;

    // Operators
    reference operator*() const { return *ptr_; }
    pointer operator->() const { return ptr_; }
    VectorIterator& operator++() { ++ptr_; return *this; }
    VectorIterator operator++(int) { VectorIterator tmp(*this); ++ptr_; return tmp; }
    VectorIterator& operator--() { --ptr_; return *this; }
    VectorIterator operator--(int) { VectorIterator tmp(*this); --ptr_; return tmp; }
    VectorIterator& operator+=(difference_type n) { ptr_ += n; return *this; }
    VectorIterator& operator-=(difference_type n) { ptr_ -= n; return *this; }
    reference operator[](difference_type n) const { return ptr_[n]; }

    // Comparison operators
    bool operator==(const VectorIterator& other) const { return ptr_ == other.ptr_; }
    bool operator!=(const VectorIterator& other) const { return ptr_ != other.ptr_; }
    bool operator<(const VectorIterator& other) const { return ptr_ < other.ptr_; }
    bool operator>(const VectorIterator& other) const { return ptr_ > other.ptr_; }
    bool operator<=(const VectorIterator& other) const { return ptr_ <= other.ptr_; }
    bool operator>=(const VectorIterator& other) const { return ptr_ >= other.ptr_; }

private:
    pointer ptr_;
};

template <typename T>
VectorIterator<T> operator+(VectorIterator<T> it, typename VectorIterator<T>::difference_type n) {
    it += n;
    return it;
}

template <typename T>
VectorIterator<T> operator-(VectorIterator<T> it, typename VectorIterator<T>::difference_type n) {
    it -= n;
    return it;
}

template <typename T>
typename VectorIterator<T>::difference_type operator-(const VectorIterator<T>& a, const VectorIterator<T>& b) {
    return a.ptr_ - b.ptr_;
}


*/

#endif