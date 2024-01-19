/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:49:53 by mortins-          #+#    #+#             */
/*   Updated: 2024/01/19 14:31:30 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// Default constructor.
Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

// Copy constructor.
Fixed::Fixed( const Fixed &src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Int constructor.
Fixed::Fixed( const int integer ) {
	std::cout << "Int constructor called" << std::endl;
	this->value = integer << this->fractionalBits;
}

// Float constructor.
Fixed::Fixed( const float number ) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf((float)number * (1 << this->fractionalBits));
}

// Destructor.
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator.
Fixed& Fixed::operator= ( const Fixed &src ) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src)
		this->setRawBits(src.getRawBits());

	return *this;
}

// Getter for this->value.
int Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

// Setter for this->value.
void Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

// Converts the fixed-point value to a floating-point.
float Fixed::toFloat( void ) const {
	return (float)this->value / (float)(1 << this->fractionalBits);
}

// Converts the fixed-point value to an integer.
int Fixed::toInt( void ) const {
	return this->value >> this->fractionalBits;
}

// Overload of the insertion '«' operator. Inserts a floating-point representation
// of the fixed-point number into the ostream object passed as parameter.
std::ostream & operator<< (std::ostream &out, const Fixed& fixed ) {
	out << fixed.toFloat();

	return (out);
}

// Overload of the greater than '>' operator
bool operator> (const Fixed& fixed1, const Fixed& fixed2) {
	if ( fixed1.getRawBits() > fixed2.getRawBits())
		return true;
	return false;
}

// Overload of the less than '<' operator
bool operator< (const Fixed& fixed1, const Fixed& fixed2) {
	if ( fixed1.getRawBits() < fixed2.getRawBits())
		return true;
	return false;
}

// Overload of the greater than/equal to '>=' operator
bool operator>= (const Fixed& fixed1, const Fixed& fixed2) {
	if ( fixed1.getRawBits() >= fixed2.getRawBits())
		return true;
	return false;
}

// Overload of the less than/equal to '<=' operator
bool operator<= (const Fixed& fixed1, const Fixed& fixed2) {
	if ( fixed1.getRawBits() <= fixed2.getRawBits())
		return true;
	return false;
}