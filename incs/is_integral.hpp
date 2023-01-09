/* ************************************************************************** */
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

#endif