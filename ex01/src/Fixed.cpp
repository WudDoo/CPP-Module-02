/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:49:53 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/27 12:41:42 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// Default Constructor
Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

// Copy constructor
Fixed::Fixed( const Fixed &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Int constructor
Fixed::Fixed( const int integer ) {
	std::cout << "Int constructor called" << std::endl;
	this->value = integer << this->fractionalBits;
}

// Float constructor
Fixed::Fixed( const float number ) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf((float)number * (1 << this->fractionalBits));
}

// Destructor
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator= ( const Fixed &src ) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src)
		this->setRawBits(src.getRawBits());

	return *this;
}

// Getter for this->value
int	Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

// Setter for this->numberValue
void	Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

// Converts the fixed-point value to a floating-point
float	Fixed::toFloat( void ) const {
	return (float)this->value / (float)(1 << this->fractionalBits);
}

// Converts the fixed-point value to an integer
int	Fixed::toInt( void ) const {
	return this->value >> this->fractionalBits;
}

// Overload of the insertion '«' operator. Inserts a floating-point representation
// of the fixed-point number into the ostream object passed as parameter
std::ostream & operator<< (std::ostream &out, const Fixed& fixed ) {
	out << fixed.toFloat();

	return (out);
}