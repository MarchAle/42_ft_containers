/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:22:52 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/11 14:22:53 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:30:01 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/06 14:02:28 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
	////// par default aucun typedef `type` n'est defini
	template<bool B, class T = void>
	class enable_if
	{
			
	};

	////// si le premier parametre est `true` alors un typedef `type` est defini avec comme type `T`
	template<class T>
	class enable_if<true, T>
	{
		public :
			typedef T type;
	};
}

#endif/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:21:35 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/05 15:28:25 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{
	template <class Iterator>
	class iterator_traits
	{
		public :
			typedef typename Iterator::difference_type   difference_type;
			typedef typename Iterator::value_type        value_type;
			typedef typename Iterator::pointer           pointer;
			typedef typename Iterator::reference         reference;
			typedef typename Iterator::iterator_category iterator_category;
	};
	
	template <class T>
	class iterator_traits <T *>
	{
		public :
			typedef std::ptrdiff_t   					difference_type;
			typedef T			      					value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::random_access_iterator_tag 	iterator_category;
	};
	
	template <class T>
	class iterator_traits <const T *>
	{
		public :
			typedef 		std::ptrdiff_t   					difference_type;
			typedef 		T	      							value_type;
			typedef const 	T*									pointer;
			typedef const 	T&									reference;
			typedef 		std::random_access_iterator_tag 	iterator_category;
	};
}

#endif/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:51:26 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/06 17:03:45 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template<typename T>
	class is_integral
	{
		public :
			static const bool value = false;
	};
	
	template<>
	class is_integral<char>
	{
		public :
			static const bool value = true;
	};
	
	template<>
	class is_integral<short>
	{
		public :
			static const bool value = true;
	};
	
	template<>
	class is_integral<int>
	{
		public :
			static const bool value = true;
	};
	
	template<>
	class is_integral<long>
	{
		public :
			static const bool value = true;
	};
	
	template<>
	class is_integral<long long>
	{
		public :
			static const bool value = true;
	};
}

#endif/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:14:02 by amarchal          #+#    #+#             */
/*   Updated: 2023/01/11 13:23:07 by amarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}
}

#endif