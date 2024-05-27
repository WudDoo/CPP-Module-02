/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:17:54 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/27 12:37:42 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int	numberValue;
		static const int	fractionalBits = 8;

	public:
		// Constructors
		Fixed( void );
		Fixed( const Fixed &src );
		Fixed( const int integer );
		Fixed( const float number );

		// Destructor
		~Fixed( void );

		// Copy assignment operator
		Fixed & operator = ( const Fixed &src );

		// Getter / Setter
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );

		// Conversion to float and int
		float	toFloat( void ) const;
		int	toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif