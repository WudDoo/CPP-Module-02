/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:17:54 by mortins-          #+#    #+#             */
/*   Updated: 2024/01/16 15:24:32 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int	numberValue;
		static const int	fractionalBits;

	public:
		Fixed( void );
		Fixed( const Fixed &fixed );
		~Fixed( void );
		Fixed & operator = ( const Fixed &fixed );
		
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif