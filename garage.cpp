#include "garage.h"
#include <iostream>

Garage::Garage(const char*, const char*, const int, const double, const int yearOfConstruction, bool rent)
:propertyForSale(city, region, price, squaring, rent) {
	if (yearOfConstruction < 0)
		throw; // ADD THE CORRECT EXCEPTION
	type = Type::GARAGE;
	this->yearOfConstruction = yearOfConstruction;
}

void Garage::print()const {
	std::cout << "Garage:" << std::endl;
	std::cout << "-City: " << city << std::endl;
	std::cout << "-Region: " << region << std::endl;
	std::cout << "-Price: " << price << std::endl;
	std::cout << "-Squaring: " << squaring << std::endl;
	std::cout << "-Year of construction: : " << yearOfConstruction << std::endl;
}

const int Garage::getRooms()const {
	return 0;
}
