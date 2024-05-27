/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:45:44 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/27 13:57:36 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>
// #include <bitset> // Comment before submission

int	main( void )	{
	{
		std::cout << "\e[90m\e[107mSubject tests:\e[0m" << std::endl;
		Fixed	a;
		Fixed const	b( 10 );
		Fixed const	c( 42.42f );
		Fixed const	d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	// { // Comment before submission
	// 	std::cout << std::endl << std::endl;
	// 	std::cout << "\e[90m\e[107mTest for negative float to int conversion:\e[0m" << std::endl;
	// 	Fixed const	a( -105.01f );

	// 	std::cout << "a is " << a << std::endl;
	// 	std::cout << "a is " << std::bitset<32>(a.getRawBits()) << std::endl;

	// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// 	std::cout << "a is " << std::bitset<32>(a.toInt()) << std::endl;
	// 	std::cout << "\e[90m\e[107mREMEMBER TO COMMENT THIS BEFORE SUBMISSION\e[0m" << std::endl;
	// }
	return 0;
}