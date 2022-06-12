#include "garage.h"
#include <iostream>

Garage::Garage(const char* city, const char* region, const int price, const double squaring, const int yearOfConstruction, bool rent)
	:propertyForSale(city, region, price, squaring, rent) {
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

const size_t Garage::getRooms()const {
	return 0;
}

propertyForSale* Garage::clone()const {
	return new Garage(*this);
}
