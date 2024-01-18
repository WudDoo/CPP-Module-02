/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:49:53 by mortins-          #+#    #+#             */
/*   Updated: 2024/01/18 17:30:26 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->numberValue = 0;
}

Fixed::Fixed( const Fixed &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( const int integer ) {
	std::cout << "Int constructor called" << std::endl;
	this->numberValue = integer << this->fractionalBits;
}

Fixed::Fixed( const float number ) {
	std::cout << "Float constructor called" << std::endl;
	this->numberValue = (float)number * (1 << this->fractionalBits);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= ( const Fixed &src ) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src)
		this->setRawBits(src.getRawBits());

	return *this;
}

int	Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->numberValue;
}

void	Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->numberValue = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)this->numberValue / (float)(1 << this->fractionalBits);
}

int	Fixed::toInt( void ) const {
	return this->numberValue >> this->fractionalBits;
}

std::ostream & operator<< (std::ostream &out, const Fixed& fixed ) {
	out << fixed.toFloat();

	return (out);
}