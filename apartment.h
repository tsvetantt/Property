#pragma once
#include "propertyForSale.h"


class Apartment : public propertyForSale{
private:
	int amountOfRooms;
	int yearOfConstruction;
	int blockNumber;
	int floor;

public:
	Apartment();
	Apartment(const char* city, const char* region, const int price, const double squaring, int amountOfRooms, int yearOfConstruction,int blockNum,int floor,bool rent);

	int getAmountOfRooms() const;
	int getYearOfConstruction() const;
	int getBlockNum() const;
	int getFloor() const;


	void print() override;
	propertyForSale* clone() override;
	int getRooms() override;




};