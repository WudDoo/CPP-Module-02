/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:26:56 by mortins-          #+#    #+#             */
/*   Updated: 2024/01/24 18:25:20 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point {
	private:
		Fixed const x;
		Fixed const y;

	public:
		// Constructors
		Point( void );
		Point( const float x, const float y);
		Point( const Point& source );

		// Destructor
		~Point( void );

		// Copy assignment operator overload
		Point & operator=( const Point& src );

		// Getters
		Fixed getX( void ) const;
		Fixed getY( void ) const;

		// Setters
		void setX( Fixed const x );
		void setY( Fixed const y );
};

#endif