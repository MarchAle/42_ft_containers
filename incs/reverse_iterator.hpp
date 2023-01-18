/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:34:26 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/18 11:46:29 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "./iterator_traits.hpp"

namespace ft
{
	template<typename Iter>
	class reverse_iterator
	{
		protected:
			Iter data;

		public:
			typedef Iter													iterator_type;
			typedef	typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;
			
			iterator_type	base() const
			{
				return (data);
			}
			explicit reverse_iterator(iterator_type it) : data(it)
			{
				// data = it;
			};
			reverse_iterator() : data()
			{
				
			}
			reverse_iterator(const reverse_iterator &src) : data(src.data)
			{
				// data = src.data;
			};
			reverse_iterator	&operator=(const reverse_iterator &src)
			{
				this->data = src.base();
				return (*this);
			}
			~reverse_iterator(){};
			
			//////// INCREMENT DECREMENT
			reverse_iterator &operator++()
			{
				data--;
				return (*this);
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				data--;
				return (tmp);
			}
			reverse_iterator &operator--()
			{
				data++;
				return (*this);
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				data++;
				return (tmp);
			}
			
			//////// INDEX OPERATOR
			reference operator[](int index)
			{
				return (*(data[index]));	
			};
			
			pointer	operator->()
			{
				return (--base().operator->());	
			};
			
			reference operator*()
			{
				Iter tmp = data;
				tmp--;
				return (*tmp);
			};

			//////// COMPARAISON OPERATOR
			bool operator==(const reverse_iterator &other) const
			{
				return (data == other->data);
			}
			
			bool operator!=(const reverse_iterator &other) const
			{
				return (data != other->data);
			}
			bool operator>=(const reverse_iterator &other) const
			{
				return (data >= other->data);
			}
			
			bool operator<=(const reverse_iterator &other) const
			{
				return (data <= other->data);
			}
			bool operator>(const reverse_iterator &other) const
			{
				return (data > other->data);
			}
			
			bool operator<(const reverse_iterator &other) const
			{
				return (data < other->data);
			}

			//////// ARITHMETIC OPERATOR
			reverse_iterator operator+(int n) const
			{
				return reverse_iterator(data + n);
			}
			
			reverse_iterator operator-(int n) const
			{
				return reverse_iterator(data - n);
			}
			
			int operator+(reverse_iterator other) const
			{
				return data + other.data;
			}
			
			int operator-(reverse_iterator other) const
			{
				return data - other.data;
			}

			reverse_iterator &operator+=(difference_type n)
			{
				data += n;
				return (*this);
			}

			reverse_iterator &operator-=(difference_type n)
			{
				data += n;
				return (*this);
			}
	};
};


#endif