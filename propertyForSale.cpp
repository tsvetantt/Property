#include "propertyForSale.h"
#include <cstring>
#include <iostream>

#pragma warning (disable: 4996)

void propertyForSale::copy(const propertyForSale& other) {
	this->city = new char[strlen(other.city) + 1];
	strcpy(this->city, other.city);

	this->region = new char[strlen(other.region) + 1];
	strcpy(this->region, other.region);

	this->price = other.price;
	this->squaring = other.squaring;
}
void propertyForSale::free() {
	delete[] city;
	delete[] region;
}




propertyForSale::propertyForSale() {
	this->city = nullptr;
	this->region = nullptr;
	this->price = 0;
	this->squaring = 0;
}
propertyForSale::propertyForSale(const char* city, const char* region, const int price, const double squaring,bool rent) {
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);

	this->region = new char[strlen(region) + 1];
	strcpy(this->region, region);

	this->price = price;
	this->squaring = squaring;
	this->forRent = rent;
}
propertyForSale::propertyForSale(const propertyForSale& other) {
	copy(other);
}
propertyForSale& propertyForSale::operator=(const propertyForSale& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}
propertyForSale::~propertyForSale() {
	free();
}

void propertyForSale::setForRentOrForSell(int check) {
	this->forRent = check;
}

void propertyForSale::getPropertysFromCity(const char* city) {
	if (strcmp(this->city, city) == 0) {
		print();
	}
}

void propertyForSale::getPropertyInPriceRange(const int lowerLimit, const int upperLimit) {
	if (lowerLimit <= this->price && this->price <= upperLimit) {
		print();
	}
}

void propertyForSale::getPropertyInSquaringRange(const double lowerLimit, const double upperLimit) {
	if (lowerLimit <= this->squaring && this->squaring <= upperLimit) {
		print();
	}
}