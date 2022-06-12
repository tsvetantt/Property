#pragma once
#include "propertyForSale.h"

class House :public propertyForSale {
private:
	size_t amountOfRooms;
	size_t yearOfConstruction;
	size_t houseNumber;
public:
	House() = default;
	House(const char*, const char*, const int, const double, const bool, const int, const int, const int);

	const size_t getRooms()const override;
	const size_t getYearOfConstruction()const;
	const size_t getHouseNumber()const;

	void print()const override;
	propertyForSale* clone()const override;
	

	void getHouseInRoomsRange(const int, const int)const;
	
};