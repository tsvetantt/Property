#pragma once
#include "propertyForSale.h"

class Garage :public propertyForSale {
private:
	int yearOfConstruction;
public:
	Garage() = default;
	Garage(const char*, const char*, const int, const double, const int yearOfConstruction, bool rent);

	void print()const;
	const size_t getRooms() const override;
};
