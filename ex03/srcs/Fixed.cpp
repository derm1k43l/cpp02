/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:40:24 by mrusu             #+#    #+#             */
/*   Updated: 2024/09/18 10:39:23 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value_(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value << bits_)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value_(roundf(value * (1 << bits_)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value_ = other.value_;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// Getters and setters
int Fixed::getRawBits(void) const
{
	return (value_);
}

void Fixed::setRawBits(int const raw)
{
	value_ = raw;
}

// conversion methods
float Fixed::toFloat(void) const
{
	return (static_cast<float>(value_) / (1 << bits_));
}

int Fixed::toInt(void) const
{
	return (value_ >> bits_);
}

// overload (<<) of the insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const
{
	return (value_ > other.value_);
}
bool Fixed::operator<(const Fixed& other) const
{
	return (value_ < other.value_);
}
bool Fixed::operator>=(const Fixed& other) const
{
	return (value_ >= other.value_);
}
bool Fixed::operator<=(const Fixed& other) const
{
	return (value_ <= other.value_);
}
bool Fixed::operator==(const Fixed& other) const
{
	return (value_ == other.value_);
}
bool Fixed::operator!=(const Fixed& other) const
{
	return (value_ != other.value_);
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}
Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

// Unary operators used to negate a Fixed number
Fixed Fixed::operator-() const
{
    return Fixed(-toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}
Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.toFloat() == 0)
	{
		std::cout << "Error: Division by zero" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(toFloat() / other.toFloat()));
}

// Increment and decrement operators
Fixed& Fixed::operator++(void)
{
	value_++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}
Fixed& Fixed::operator--(void)
{
	value_--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed Fixed::abs() const
{
	return (value_ < 0 ? Fixed(-toFloat()) : *this);
}

// Static min and max
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

