/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:33:17 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/27 12:30:58 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Fixed.hpp"

int	main( void ) {
	{
		std::cout << "\e[90m\e[107mSubject tests:\e[0m" << std::endl;
		Fixed a;
		Fixed b( a );
		Fixed c;

		c = b;

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	{
		std::cout << std::endl << std::endl;
		std::cout << "\e[90m\e[107mMy tests:\e[0m" << std::endl;

		Fixed a;
		a.setRawBits(16);
		std::cout << a.getRawBits() << std::endl;

		Fixed b( a );
		std::cout << b.getRawBits() << std::endl;

		b.setRawBits(48);
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;

		Fixed c;
		std::cout << c.getRawBits() << std::endl;

		c = b;

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
}