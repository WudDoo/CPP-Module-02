/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:17:54 by mortins-          #+#    #+#             */
/*   Updated: 2024/01/19 14:30:39 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int	value;
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

		// Setter / Getter
		void	setRawBits( int const raw );
		int	getRawBits( void ) const;

		// Conversion to float and int
		float	toFloat( void ) const;
		int	toInt( void ) const;

		// Comparison operands
		friend bool	operator>(const Fixed& fixed1, const Fixed& fixed2);
		friend bool	operator<(const Fixed& fixed1, const Fixed& fixed2);
		friend bool	operator>=(const Fixed& fixed1, const Fixed& fixed2);
		friend bool	operator<=(const Fixed& fixed1, const Fixed& fixed2);
};

// Overload of the insertion («) operator, inserts a floating-point
// representation of the fixed-point number into the ostream passed as parameter
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif