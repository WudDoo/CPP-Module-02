/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:47:40 by mortins-          #+#    #+#             */
/*   Updated: 2024/01/19 14:31:53 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>

int main( void ) {

	Fixed a (6);
	Fixed b (5.25f);

	if (a > b)
	{
		std::cout << "a is larger" << std::endl;
	}
	if (a >= b)
	{
		std::cout << "a is larger or equal" << std::endl;
	}
	if (a < b)
	{
		std::cout << "a is smaller" << std::endl;
	}
	if (a <= b)
	{
		std::cout << "a is smaller or equal" << std::endl;
	}
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}