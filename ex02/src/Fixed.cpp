/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:49:53 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/27 15:54:24 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// Default constructor
Fixed::Fixed( void ) {
	//std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

// Copy constructor
Fixed::Fixed( const Fixed &src ) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Int constructor
Fixed::Fixed( const int integer ) {
	//std::cout << "Int constructor called" << std::endl;
	this->value = integer << this->fractionalBits;
}

// Float constructor
Fixed::Fixed( const float number ) {
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf((float)number * (1 << this->fractionalBits));
}

// Destructor
Fixed::~Fixed( void ) {
	//std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed&	Fixed::operator = ( const Fixed &src ) {
	//std::cout << "Copy assignment operator called" << std::endl;

	if (this != &src)
		this->setRawBits(src.getRawBits());

	return *this;
}

// Getter for this->value
int	Fixed::getRawBits( void )	const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

// Setter for this->value
void	Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

// Converts the fixed-point value to a floating-point
float	Fixed::toFloat( void )	const {
	return (float)this->value / (float)(1 << this->fractionalBits);
}

// Converts the fixed-point value to an integer
int	Fixed::toInt( void )	const {
	int	i = 0;

	if (this->getRawBits() < 0)
	{
		while (i < fractionalBits)
		{
			if ((this->getRawBits() >> i) & 1)
				return ((this->value >> fractionalBits) + 1);
			i++;
		}
	}

	return this->value >> fractionalBits;
}

// Overload of the insertion '«' operator. Inserts a floating-point representation
// of the fixed-point number into the ostream object passed as parameter
std::ostream&	operator << ( std::ostream &out, const Fixed& fixed ) {
	out << fixed.toFloat();

	return (out);
}


// -------------------------- Comparison operators -----------------------------
// Greater than '>' operator
bool	Fixed::operator > ( const Fixed& other ) {
	return ( this->getRawBits() > other.getRawBits() );
}

// Less than '<' operator
bool	Fixed::operator < ( const Fixed& other ) {
	return ( this->getRawBits() < other.getRawBits() );
}

// Greater than/equal to '>=' operator
bool	Fixed::operator >= ( const Fixed& other ) {
	return !( this->getRawBits() < other.getRawBits() );
}

// Less than/equal to '<=' operator
bool	Fixed::operator <= ( const Fixed& other ) {
	return !( this->getRawBits() > other.getRawBits() );
}

// Equal to '==' operator
bool	Fixed::operator == ( const Fixed& other ) {
	return ( this->getRawBits() == other.getRawBits() );
}

// Different than '!=' operator
bool	Fixed::operator != ( const Fixed& other ) {
	return ( this->getRawBits() != other.getRawBits() );
}

// -------------------------- Arithmetic operators -----------------------------
// Addition '+' operator
Fixed	Fixed::operator + (const Fixed& other) {
	return Fixed( this->toFloat() + other.toFloat() );
}

// Subtraction '-' operator
Fixed	Fixed::operator - ( const Fixed& other ) {
	return Fixed( this->toFloat() - other.toFloat() );
}

// Multiplication '*' operator
Fixed	Fixed::operator * ( const Fixed& other ) {
	return Fixed( this->toFloat() * other.toFloat() );
}

// Division '/' operator
Fixed	Fixed::operator / ( const Fixed& other ) {
	return Fixed( this->toFloat() / other.toFloat() );
}

// -------------------------- Increment/Decrement operators --------------------
// Pre-increment operator
Fixed&	Fixed::operator ++ ( void ) {
	this->value++;
	return *this;
}

// Post-increment operator
Fixed	Fixed::operator ++ ( int ) {
	Fixed temp( this->toFloat() );
	this->value++;
	return temp;
}

// Pre-decrement operator
Fixed&	Fixed::operator -- ( void ) {
	this->value--;
	return *this;
}

// Post-decrement operator
Fixed	Fixed::operator -- ( int ) {
	Fixed temp( this->toFloat() );
	this->value--;
	return temp;
}

// -------------------------- Min and Max functions ----------------------------
// Min - no const
Fixed&	Fixed::min( Fixed& fixed1, Fixed& fixed2 ) {
	if ( fixed1.getRawBits() > fixed2.getRawBits() )
		return fixed2;
	return fixed1;
}

// Min - const
const Fixed&	Fixed::min( const Fixed& fixed1, const Fixed& fixed2 ) {
	if ( fixed1.getRawBits() > fixed2.getRawBits() )
		return fixed2;
	return fixed1;
}

// Max - no const
Fixed&	Fixed::max( Fixed& fixed1, Fixed& fixed2 ) {
	if ( fixed1.getRawBits() < fixed2.getRawBits() )
		return fixed2;
	return fixed1;
}

// Max - const
const Fixed&	Fixed::max( const Fixed& fixed1, const Fixed& fixed2 ) {
	if ( fixed1.getRawBits() < fixed2.getRawBits() )
		return fixed2;
	return fixed1;
}