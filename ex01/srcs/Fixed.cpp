/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:40:24 by mrusu             #+#    #+#             */
/*   Updated: 2024/09/13 14:09:35 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// Def constructor
Fixed::Fixed() : value_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int value) : value_(value << bits_)
{
	std::cout << "Int constructor called" << std::endl;
}

// Float constructor
Fixed::Fixed(const float value) : value_(roundf(value * (1 << bits_)))
{
	std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignation operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		value_ = other.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
