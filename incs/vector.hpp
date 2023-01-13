/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:32:39 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/13 17:37:30 by amarchal         ###   ########.fr       */
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
			vector(const vector &x)
			{
				*this = x;
			};
			/////////// ASSIGNATION OPERATOR OVERLOAD
			vector &operator=(const vector &src)
			{
				this->alloc = src.alloc;
				this->array = alloc.allocate(src.vec_capacity);
				for (size_t i = 0; i < src.arr_size; i++)
					alloc.construct(array + i, src.array[i]);
				this->arr_size = src.arr_size;
				this->vec_capacity = src.vec_capacity;
				
				return (*this);
			};
			/////////// DESTRUCTOR
			~vector()
			{
				clear();
				array = NULL;
				// for (size_t i = 0; i < arr_size; i++)
				// 	alloc.destroy(array + i);
				// alloc.deallocate(array, vec_capacity);
			};

			///////// MODIFIERS
			template<class InputIterator>
			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				size_type size = 0;
				InputIterator tmp = first;
				
				while (tmp != last)
				{
					size++;
					tmp++;
				}
				for (size_t i = 0; i < arr_size; i++)
					alloc.destroy(array + i);
				if (size > vec_capacity)
				{
					reserve(size);
					arr_size = size;
				}
				for (size_t i = 0; i < size; i++)
					alloc.construct(array + i, *(first + i));
			}
			
			void	assign(size_t n, const T &val)
			{
				// *this->clear();
				// *this->reserve(n);
				// *this->insert(*this->begin(), n, val);
				for (size_t i = 0; i < arr_size; i++)
					alloc.destroy(array + i);
				reserve(n);
				for (size_t i = 0; i < n; i++)
					alloc.construct(array + i, val);
				// if (n <= vec_capacity)
				// {
				// 	for (size_t i = 0; i < n; i++)
				// 		alloc.construct(array + i, val);
				// }
				// else
				// {
				// 	for (size_t i = 0; i < arr_size; i++)
				// 		alloc.construct(array + i, val);
				// 	reserve(n);
				// 	for (size_t i = arr_size; i < n; i++)
				// 		alloc.construct(array + i, val);
				// }
				arr_size = n;
			}

			void	push_back(const T &e)
			{
				if (arr_size == 0)
					array = alloc.allocate(vec_capacity);
				else if (arr_size + 1 > vec_capacity)
					_move_array(vec_capacity * 2);
				alloc.construct(array + arr_size, e);
				arr_size++;
				if (arr_size > vec_capacity)
					vec_capacity = arr_size;
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
				arr_size++;
				if (arr_size > vec_capacity)
				{
					// if (vec_capacity == 0)
					// {
					// 	vec_capacity++;
					// 	array = alloc.allocate(vec_capacity);
					// }
					// while (arr_size > vec_capacity)
					// 	vec_capacity *= 2;
					_move_array(arr_size);
				}
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
				size_type	index = position - this->begin();
				size_type	end = arr_size;
				
				if (index > end || index < 0)
					throw std::out_of_range("Can't insert outside vector");
				arr_size += n;
				if (arr_size > vec_capacity)
				{
					// if (vec_capacity == 0)
					// {
					// 	vec_capacity++;
					// 	array = alloc.allocate(vec_capacity);
					// }
					// while (arr_size > vec_capacity)
					// 	vec_capacity *= 2;
					_move_array(arr_size);
				}
				while (end >= index)
				{
					alloc.construct(array + end + n, array[end]);
					alloc.destroy(array + end);
					if (end == 0)
						break ;
					end--;
				}
				while (n > 0)
				{
					n--;
					alloc.construct(array + index + n, val);
					if (n == 0)
						break ;
				}
			}

			template<class InputIterator>
			void	insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				size_type	index = position - this->begin();
				size_type	end = arr_size;
				ptrdiff_t	n = std::distance(first, last);
				
				last--;
				if (index > end || index < 0)
					throw std::out_of_range("Can't insert outside vector");
				arr_size += n;
				if (arr_size > vec_capacity)
				{
					// if (vec_capacity == 0)
					// {
					// 	vec_capacity++;
					// 	array = alloc.allocate(vec_capacity);
					// }
					// while (arr_size > vec_capacity)
					// 	vec_capacity *= 2;
					_move_array(arr_size);
				}
				while (end > index)
				{
					alloc.construct(array + end + n, array[end]);
					alloc.destroy(array + end);
					if (end == 0)
						break ;
					end--;
				}
				while (n > 0)
				{
					alloc.construct(array + index + n - 1, *last);
					if (n == 0)
						break ;
					last--;
					n--;
				}
			}

			iterator	›(iterator position)
			{
				size_type	index = position - this->begin();
				
				alloc.destroy(array + index);
				arr_size--;
				while (array + index != array + arr_size)
				{
					alloc.construct(array + index, *(array + index + 1));
					alloc.destroy(array + index + 1);
					index++;
				}
				return (position);
			}

			iterator	erase(iterator first, iterator last)
			{
				size_type	index = first - this->begin();
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
					// alloc.deallocate(new_array, vec_capacity);
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

			void	shrink_to_fit()
			{
				if (vec_capacity > arr_size)
					_move_array(arr_size);
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
				return reverse_iterator(this->end());
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