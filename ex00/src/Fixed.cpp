/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:49:53 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/27 12:39:24 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed( const Fixed &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= ( const Fixed &src ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->setRawBits(src.getRawBits());
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}