#include "apartment.h"
#include <iostream>


Apartment::Apartment() : propertyForSale() {
	this->amountOfRooms = 0;
	this->yearOfConstruction = 0;
	this->blockNumber = 0;
	this->floor = 0;
}

Apartment::Apartment(const char* city, const char* region, const int price, const double squaring, int amountOfRooms, int yearOfConstruction,int blockNum,int floor,bool rent)
: propertyForSale(city,region,price,squaring,rent) {
	type = Type::APARTMENT;
	this->amountOfRooms = amountOfRooms;
	this->yearOfConstruction = yearOfConstruction;
	this->blockNumber = blockNum;
	this->floor = floor;
}

int Apartment::getYearOfConstruction() const {
	return this->yearOfConstruction;
}
int Apartment::getBlockNum() const {
	return this->blockNumber;
}
int Apartment::getFloor() const {
	return this->floor;
}

void Apartment::print()const {
	std::cout << "Apartment:" << std::endl;
	std::cout<<  "- City: " << this->city <<std::endl;
	std::cout << "- Region: " << this->region <<std::endl;
	std::cout << "- Price: " << this->price << "$" <<std::endl;
	std::cout << "- Squaring: " << this->squaring << std::endl;
	std::cout << "- Amount of rooms: " << this->amountOfRooms << std::endl;
	std::cout << "- Year of construction: " << this->yearOfConstruction << std::endl;
	std::cout << "- Block number: " << this->blockNumber << std::endl;
	std::cout << "- Floor: " << this->floor << std::endl;
}

propertyForSale* Apartment::clone()const {
	return new Apartment(*this);
}

const size_t Apartment::getRooms()const {
	return amountOfRooms;
}