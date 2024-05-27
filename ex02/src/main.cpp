/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:47:40 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/27 15:45:12 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>

int main( void ) {
	{
		std::cout << "\e[90m\e[107mSubject tests:\e[0m" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}

	{
		std::cout << std::endl << std::endl;
		std::cout << "\e[90m\e[107mMy tests:\e[0m" << std::endl;
		Fixed a (1.5f);
		Fixed b (1.5f);

		if (a > b)
			std::cout << "a is larger than b" << std::endl;
		if (a >= b)
			std::cout << "a is larger than or equal to b" << std::endl;
		if (a < b)
			std::cout << "a is smaller than b" << std::endl;
		if (a <= b)
			std::cout << "a is smaller than or equal to b" << std::endl;
		if (a == b)
			std::cout << "a is equal to b" << std::endl;
		if (a != b)
			std::cout << "a is different than b" << std::endl;

		Fixed c(a + b);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "c + b = " << c + b << std::endl;
		std::cout << "c + b - a = " << c + b - a << std::endl;
		std::cout << "a * b = " << a * b << std::endl;
		std::cout << "a / b = " << a / b << std::endl;
	}
	return 0;
}
