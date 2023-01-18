/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:32:39 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/18 11:52:17 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstring>
# include <stdexcept>
// # include <iterator>

# include <memory>
# include <new>

# include "./reverse_iterator.hpp"
# include "./enable_if.hpp"
# include "./is_integral.hpp"
# include "./lexicographical_compare.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> > 
	class vector
	{
			//////////////// ITERATORS
			class my_iterator
			{
				private:
					T *data;

				public:
					typedef	std::ptrdiff_t					difference_type;
					typedef T								value_type;
					typedef	T*								pointer;
					typedef	T&								reference;
					typedef std::random_access_iterator_tag iterator_category;
					
					my_iterator()
					{};
					my_iterator(T* ptr)
					{
						data = ptr;
					};
					my_iterator(const my_iterator &src)
					{
						data = src.data;
					};
					~my_iterator(){};
					
					//////// INCREMENT DECREMENT
					my_iterator &operator++()
					{
						data++;
						return (*this);
					}
					my_iterator operator++(int)
					{
						my_iterator tmp = *this;
						++(*this);
						return (tmp);
					}
					my_iterator &operator--()
					{
						data--;
						return (*this);
					}
					my_iterator operator--(int)
					{
						my_iterator tmp = *this;
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
					bool operator==(const my_iterator &other) const
					{
						return (data == other.data);
					}
					
					bool operator!=(const my_iterator &other) const
					{
						return (data != other.data);
					}
					bool operator>=(const my_iterator &other) const
					{
						return (data >= other.data);
					}
					
					bool operator<=(const my_iterator &other) const
					{
						return (data <= other.data);
					}
					bool operator>(const my_iterator &other) const
					{
						return (data > other.data);
					}
					
					bool operator<(const my_iterator &other) const
					{
						return (data < other.data);
					}

					//////// ARITHMETIC OPERATOR
					my_iterator operator+(int n) const
					{
						return my_iterator(data + n);
					}
					
					my_iterator operator-(int n) const
					{
						return my_iterator(data - n);
					}
					
					int operator+(my_iterator other) const
					{
						return data + other.data;
					}
					
					int operator-(my_iterator other) const
					{
						return data - other.data;
					}

					my_iterator &operator+=(difference_type n)
					{
						data += n;
						return (*this);
					}

					my_iterator &operator-=(difference_type n)
					{
						data += n;
						return (*this);
					}
			};
			class const_iterator
			{
				private:
					T *data;

				public:
					typedef	std::ptrdiff_t					difference_type;
					typedef T								value_type;
					typedef	const T*						pointer;
					typedef	const T&						reference;
					typedef std::random_access_iterator_tag iterator_category;
					
					const_iterator(T* ptr)
					{
						data = ptr;
					};
					const_iterator(const const_iterator &src)
					{
						data = src.data;
					};
					~const_iterator(){};
					
					//////// INCREMENT DECREMENT
					const_iterator &operator++()
					{
						data++;
						return (*this);
					}
					const_iterator operator++(int)
					{
						const_iterator tmp = *this;
						++(*this);
						return (tmp);
					}
					const_iterator &operator--()
					{
						data--;
						return (*this);
					}
					const_iterator operator--(int)
					{
						const_iterator tmp = *this;
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
					bool operator==(const const_iterator &other) const
					{
						return (data == other->data);
					}
					
					bool operator!=(const const_iterator &other) const
					{
						return (data != other->data);
					}
					bool operator>=(const const_iterator &other) const
					{
						return (data >= other->data);
					}
					
					bool operator<=(const const_iterator &other) const
					{
						return (data <= other->data);
					}
					bool operator>(const const_iterator &other) const
					{
						return (data > other->data);
					}
					
					bool operator<(const const_iterator &other) const
					{
						return (data < other->data);
					}
			};

			// class reverse_iterator
			// {
			// 	private:
			// 		T *data;

			// 	public:
			// 		reverse_iterator(T* ptr)
			// 		{
			// 			data = ptr;
			// 		};
			// 		reverse_iterator(const reverse_iterator &src)
			// 		{
			// 			data = src.data;
			// 		};
			// 		~reverse_iterator(){};
					
			// 		//////// INCREMENT DECREMENT
			// 		reverse_iterator &operator++()
			// 		{
			// 			data--;
			// 			return (*this);
			// 		}
			// 		reverse_iterator operator++(int)
			// 		{
			// 			reverse_iterator tmp = *this;
			// 			data--;
			// 			return (tmp);
			// 		}
			// 		reverse_iterator &operator--()
			// 		{
			// 			data++;
			// 			return (*this);
			// 		}
			// 		reverse_iterator operator--(int)
			// 		{
			// 			reverse_iterator tmp = *this;
			// 			data++;
			// 			return (tmp);
			// 		}
					
			// 		//////// INDEX OPERATOR
			// 		T &operator[](int index)
			// 		{
			// 			return (*(data[index]));	
			// 		};
					
			// 		T *operator->()
			// 		{
			// 			return (data);	
			// 		};
					
			// 		T &operator*()
			// 		{
			// 			return (*data);	
			// 		};

			// 		//////// COMPARAISON OPERATOR
			// 		bool operator==(const reverse_iterator &other) const
			// 		{
			// 			return (data == other->data);
			// 		}
					
			// 		bool operator!=(const reverse_iterator &other) const
			// 		{
			// 			return (data != other->data);
			// 		}
			// 		bool operator>=(const reverse_iterator &other) const
			// 		{
			// 			return (data >= other->data);
			// 		}
					
			// 		bool operator<=(const reverse_iterator &other) const
			// 		{
			// 			return (data <= other->data);
			// 		}
			// 		bool operator>(const reverse_iterator &other) const
			// 		{
			// 			return (data > other->data);
			// 		}
					
			// 		bool operator<(const reverse_iterator &other) const
			// 		{
			// 			return (data < other->data);
			// 		}
			// };


		private:
			T*			array;
			Allocator 	alloc;
			size_t		arr_size;
			size_t		old_capacity;
			size_t		vec_capacity;
			
			// void	_move_array(size_t new_capacity)
			// {
			// 	T*		new_array;
				
			// 	old_capacity = vec_capacity;
			// 	vec_capacity = new_capacity;
			// 	new_array = alloc.allocate(vec_capacity);
			// 	for (size_t i = 0; i < arr_size; i++)
			// 	{
			// 		alloc.construct(new_array + i, array[i]);
			// 		alloc.destroy(array + i);
			// 	}
			// 	if (old_capacity > 0)
			// 		alloc.deallocate(array, old_capacity);
			// 	array = new_array;
			// };

			// void	_resize_cpy(T *new_array, size_t &n)
			// {
			// 	size_t	i = 0;

			// 	while (i < arr_size && i < n)
			// 	{
			// 		alloc.construct(new_array + i, array[i]);
			// 		i++;
			// 	}
			// 	while (i < n)
			// 	{
			// 		alloc.construct(new_array + i, T());
			// 		i++;
			// 	}
			// }

			// void	_resize_cpy(T *new_array, size_t &n, T &val)
			// {
			// 	size_t	i = 0;

			// 	while (i < arr_size && i < n)
			// 	{
			// 		alloc.construct(new_array + i, array[i]);
			// 		i++;
			// 	}
			// 	while (i < n)
			// 	{
			// 		alloc.construct(new_array + i, val);
			// 		i++;
			// 	}
			// }
			
		public:
			typedef T 								value_type;
			typedef Allocator 						allocator_type;
			typedef	ptrdiff_t						difference_type;
			typedef	size_t							size_type;
			typedef my_iterator						iterator;
			typedef typename ft::reverse_iterator<iterator>	reverse_iterator;
			
			/////////// DEFAULT CONSTRUCTOR
			explicit vector(const allocator_type& alloc = allocator_type()) : alloc(alloc)
			{
				array = NULL;
				arr_size = 0;
				vec_capacity = 0;
			};
			/////////// RANGE CONSTRUCTOR
			 // si lors de la compilation `type` n'est pas defini par enable_if, alors cette fonction sera ignoree sans erreur
			template <class InputIterator>
			vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()) : alloc(alloc)
			{
				difference_type		size = std::distance(first, last);
				
				arr_size = size;
				vec_capacity = size;
				array = this->alloc.allocate(vec_capacity);
				for (difference_type i = 0; i < size; i++)
				{
					this->alloc.construct(array + i, *first);
					first++;
				}
			}
			/////////// FILL CONSTRUCTOR
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : alloc(alloc)
			{
				arr_size = n;
				vec_capacity = n;
				array = this->alloc.allocate(vec_capacity);
				for (size_type i = 0; i < arr_size; i++)
					this->alloc.construct(array + i, val);
			};
			/////////// COPY CONSTRUCTOR
			vector(const vector &x) : alloc(x.alloc)
			{
				arr_size = x.arr_size;
				vec_capacity = x.vec_capacity;
				array = alloc.allocate(vec_capacity);
				for (size_type i = 0; i < arr_size; i++)
					alloc.construct(array + i, x[i]);
			};
			/////////// ASSIGNATION OPERATOR OVERLOAD
			vector &operator=(const vector &src)
			{
				if (this == &src)
					return (*this);
				clear();
				arr_size = src.arr_size;
				for (size_t i = 0; i < arr_size; i++)
					alloc.construct(array + i, src[i]);
				
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
			template<class InputIterator>
			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				ptrdiff_t size = std::distance(first, last);
				clear();
				reserve(size);
				for (ptrdiff_t i = 0; i < size; i++)
					alloc.construct(array + i, *(first + i));
				arr_size = size;
			}
			
			void	assign(size_t n, const T &val)
			{
				clear();
				reserve(n);
				for (size_t i = 0; i < n; i++)
					alloc.construct(array + i, val);
				arr_size = n;
			}

			void	push_back(const T &e)
			{
				reserve(arr_size + 1);
				alloc.construct(array + arr_size, e);
				arr_size++;
			};

			void	pop_back()
			{
				alloc.destroy(array + arr_size);
				arr_size--;
			}

			iterator insert(iterator position, const value_type& val)
			{
				size_type	index = position - this->begin();
				size_type	end = arr_size;
				
				if (index > end || index < 0)
					throw std::out_of_range("Can't insert outside vector");
				if (arr_size == 0)
				{
					this->push_back(val);
					return (array + index);
				}
				arr_size++;
				reserve(arr_size);
				while (end >= index)
				{
					alloc.construct(array + end + 1, array[end]);
					alloc.destroy(array + end);
					if (end == 0)
						break ;
					end--;
				}
				alloc.construct(array + index, val);
				return (array + index);
			}

			void	insert(iterator position, size_type n, const value_type& val)
			{
				size_type	index = position - begin();
				
				if (position < begin() || position > end())
					throw std::out_of_range("Invalid iterator position");
				if (arr_size == 0)
				{
					reserve(n);
					for (size_type i = 0; i < n; i++)
						push_back(val);
					return ;
				}
				reserve(arr_size + n);
				for (size_type i = arr_size; i > index + n; i--)
				{
					alloc.construct(array + i, *(array + i - n));
					alloc.destroy(array + i - n);
				}
				for (size_type i = 0; i < n; i++)
					alloc.construct(array + index + i, val);
				arr_size += n;
			}

			// template<class InputIterator>
			// void	insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			// {
			// 	size_type	index = position - begin();
			// 	ptrdiff_t	n = std::distance(first, last);

			// 	if (position < begin() || position > end())
			// 		throw std::out_of_range("Invalid iterator position");
			// 	if (first > last)
			// 		throw std::invalid_argument("Invalid range");
			// 	if (arr_size == 0)
			// 	{
			// 		reserve(n);
			// 		for (ptrdiff_t i = 0; i < n; i++)
			// 			push_back(*(first + i));
			// 		return ;
			// 	}
			// 	reserve(arr_size + n);
			// 	for (size_type i = arr_size; i > index + n; i--)
			// 	{
			// 		alloc.construct(array + i, *(array + i - n));
			// 		alloc.destroy(array + i - n);
			// 	}
			// 	for (ptrdiff_t i = 0; i < n; i++)
			// 		alloc.construct(array + index + i, *(first + i));
			// 	arr_size += n;
			// }

			template<class InputIterator>
			void	insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				if (position < begin() || position > end())
					throw std::out_of_range("Invalid iterator position");
				if (first > last)
					throw std::invalid_argument("Invalid range");
				ft::vector<typename ft::iterator_traits<InputIterator>::value_type> tmp;
				
				while (first != last)
					tmp.push_back(*first++);

				difference_type index = &(*position) - array;
				size_type       count = tmp.size();
				size_type       new_size = size() + count;

				reserve(new_size);
				for (size_type i = 0; i < count; i++)
					alloc.construct(array + i, *(array + i - std::distance(first, last)));
				for (size_type i = size() + count - 1; i >= index + count; i--)
					array[i] = array[i - count];
				try
				{
					for (size_type i = 0; i < count; i++)
						array[index + i] = tmp[i];
				}
				catch (...)
				{
					vec_capacity = 0;
					throw;
				}
				arr_size += count;
			}

			iterator	erase(iterator position)
			{
				size_type	index = position - begin();
				
				arr_size--;
				while (array + index != array + arr_size)
				{
					array[index] = array[index + 1];
					index++;
				}
				alloc.destroy(array + arr_size);
				return (position);
			}

			iterator	erase(iterator first, iterator last)
			{
				size_type	index = first - begin();
				size_type	n = last - first;
				
				for (size_type i = 0; i < n; i++)
					alloc.destroy(array + index + i);
				arr_size -= n;
				while (index < arr_size)
				{
					alloc.construct(array + index, *(array + index + n));
					alloc.destroy(array + index + n);
					index++;
				}
				return (first);
			}

			void	swap(vector &x)
			{
				T* tmp_array = x.array;
				x.array = this->array;
				this->array = tmp_array;

				size_type tmp_arr_size = x.arr_size;
				x.arr_size = this->arr_size;
				this->arr_size = tmp_arr_size;
				
				size_type tmp_vec_capacity = x.vec_capacity;
				x.vec_capacity = this->vec_capacity;
				this->vec_capacity = tmp_vec_capacity;
			}

			void	clear()
			{
				for (size_type i = arr_size; i > 0; i--)
					alloc.destroy(array + i - 1);
				arr_size = 0;
			}
			
			///////// ALLOCATOR
			allocator_type	get_allocator() const
			{
				return (allocator_type());
			}

			///////// CAPACITY
			size_t	size() const
			{
				return (arr_size);
			};
			
			size_t	max_size() const
			{
				return (alloc.max_size());
			};

			void	resize(size_t n, T val = value_type())
			{
				if (n == arr_size)
					return ;
				if (n > size())
				{
					reserve(n);
					for (size_type i = arr_size; i < vec_capacity; i++)
						alloc.construct(array + i, val);
					arr_size = vec_capacity;
				}
				else if (n < size())
				{
					for (size_type i = n; i < arr_size; i++)
						alloc.destroy(array + i);
				}
				arr_size = n;
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
				T*		new_array;

				try
				{
					if (n <= vec_capacity)
						return ;
					old_capacity = vec_capacity;
					if (n > vec_capacity * 2 )
						vec_capacity = n;
					else
						vec_capacity *= 2;
					new_array = alloc.allocate(vec_capacity);
					for (size_t i = 0; i < arr_size; i++)
					{
						alloc.construct(new_array + i, array[i]);
						alloc.destroy(array + i);
					}
					alloc.deallocate(array, old_capacity);
					array = new_array;
				}
				catch(const std::bad_alloc& e)
				{
					throw;
				}
				
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

			my_iterator begin()
			{
				return (my_iterator(array));
			};

			my_iterator cbegin() const
			{
				return (my_iterator(array));
			};

			my_iterator end() const
			{
				return (my_iterator(array + arr_size));
			};

			my_iterator cend() const
			{
				return (my_iterator(array + arr_size));
			};

			reverse_iterator rbegin() const
			{
				return reverse_iterator(this->end() - 1);
				// return (reverse_iterator(array + arr_size - 1));
			};

			// reverse_iterator crbegin() const
			// {
			// 	return (reverse_iterator<T>(array + arr_size - 1));
			// };

			reverse_iterator rend()
			{
				return (reverse_iterator(array - 1));
			};

			// reverse_iterator crend() const
			// {
			// 	return (reverse_iterator<T>(array - 1));
			// };

	};

	template<class T, class Alloc>
	bool	operator== (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}

	template<class T, class Alloc>
	bool	operator!= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool	operator< (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()));
	}

	template<class T, class Alloc>
	bool	operator> (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool	operator<= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Alloc>
	bool	operator>= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}
	
}

namespace std
{
	template<class T, class Alloc>
	void	swap (ft::vector<T, Alloc> &x, ft::vector<T, Alloc> &y)
	{
		x.swap(y);
	}
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