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

#endif