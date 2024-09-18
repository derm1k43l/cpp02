/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:14:21 by mrusu             #+#    #+#             */
/*   Updated: 2024/09/18 10:37:18 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		
		// Copy assignment operator
		Fixed& operator=(const Fixed& other);
		// Operators arithmetic
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		// Operators increment and decrement
		Fixed& operator++(); // pre increment
		Fixed operator++(int); // post increment
		Fixed& operator--(); // pre decrement
		Fixed operator--(int); // post decrement

		// unary operators
		Fixed operator-() const;

		// abs
		Fixed abs() const;

		// Operators comparison		
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		
		// Getters and setters
		int getRawBits() const;
		void setRawBits(int const raw);

		// Conversion methods
		float toFloat(void) const;
		int toInt(void) const;

		// static min and max
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		

	private:
		int value_;
		static const int bits_ = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
