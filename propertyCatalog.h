#pragma once
#include "propertyForSale.h"

class propertyCatalog {
private:
	propertyForSale** list;
	size_t size, capacity;
public:
	propertyCatalog();
	propertyCatalog(const propertyCatalog&);
	propertyCatalog& operator=(const propertyCatalog&);
	~propertyCatalog();

	void addProperty(const propertyForSale*);
	void removeProperty(const int);

	void printGarages()const;
	void printApartments()const;
	void printHouses()const;
	void print()const;

	void getPropertiesFromCity(const char*)const;
	void getPropertiesInPriceRange(const int, const int)const;
	void getPropertiesInSquaringRange(const double, const double)const;
	void getPropertiesInRoomsRange(const int, const int)const;

	void sortByCity();
	void sortByPrice();
	void sortBySquaring();
private:
	void copy(const propertyCatalog&);
	void free();
	void resize();
};