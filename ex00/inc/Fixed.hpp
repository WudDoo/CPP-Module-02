/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:17:54 by mortins-          #+#    #+#             */
/*   Updated: 2024/05/22 13:05:49 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	numberValue;
		static const int	fractionalBits = 8;

	public:
		// Contructors
		Fixed( void );
		Fixed( const Fixed &src );

		// Destructor
		~Fixed( void );

		// Copy assignment operator
		Fixed & operator = ( const Fixed &src );

		// Setter
		void	setRawBits( int const raw );

		// Getter
		int	getRawBits( void ) const;
};

#endif