/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:14:21 by mrusu             #+#    #+#             */
/*   Updated: 2024/09/13 13:59:24 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
	public:
		// Def constructor
		Fixed();

		// Copy constructor
		Fixed(const Fixed& other);

		// Copy assignation operator
		Fixed& operator=(const Fixed& other);

		// Destructor
		~Fixed();
		
		// Getters and setters
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int value_;
		static const int bits_ = 8;
};
