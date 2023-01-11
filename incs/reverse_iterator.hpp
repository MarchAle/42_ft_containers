/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:34:26 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/11 16:42:58 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
	template<typename T>
	class reverse_iterator
	{
		private:
			T *data;

		public:
			reverse_iterator(T* ptr)
			{
				data = ptr;
			};
			reverse_iterator(const reverse_iterator &src)
			{
				data = src.data;
			};
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
	};
};


#endif