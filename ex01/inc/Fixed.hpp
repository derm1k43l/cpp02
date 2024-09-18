/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:14:21 by mrusu             #+#    #+#             */
/*   Updated: 2024/09/17 15:44:18 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
	public:
		// Def constructor
		Fixed();

		// Constructor int and float
		Fixed(const int value);
		Fixed(const float value);

		// Copy constructor
		Fixed(const Fixed& other);

		// Destructor
		~Fixed();

		// Copy assignation operator
		Fixed& operator=(const Fixed& other);
		
		// Getters and setters
		int getRawBits(void) const;
		void setRawBits(int const raw);

		// Conversion methods
		float toFloat(void) const;
		int toInt(void) const;


	private:
		int value_;
		static const int bits_ = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
