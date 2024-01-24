/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:33:02 by mortins-          #+#    #+#             */
/*   Updated: 2024/01/24 18:27:24 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point( void ) : x(0), y(0) {	
	// std::cout << "Point: Default constructor called" << std::endl;
}

Point::Point( const float x, const float y ) : x(x), y(y){
	// std::cout << "Point: Const floats constructor called" << std::endl;
}

Point::Point( const Point& src ) {
	// std::cout << "Point: Copy constructor called" << std::endl;
	*this = src;
}

Point::~Point( void ) {
	// std::cout << "Point: Destructor called" << std::endl;
}

Point & Point::operator=( const Point& src ) {
	if (this != &src)
	{
		this->setX( src.getX() );
		this->setY( src.getY() );
	}

	return *this;
}

Fixed Point::getX( void ) const {
	return this->x;
}

Fixed Point::getY( void ) const {
	return this->y;
}

void Point::setX( Fixed const x ) {
	(Fixed) this->x = x;
}

void Point::setY( Fixed const y ) {
	(Fixed) this->y = y;
}