#include "propertyCatalog.h"
#include <cstring>
#include <limits>

void propertyCatalog::copy(const propertyCatalog& other) {
	size = other.size;
	capacity = other.capacity;

	list = new propertyForSale * [capacity];

	for (size_t i = 0; i < size; i++) {
		list[i] = other.list[i]->clone();
	}
}

void propertyCatalog::free() {
	for (size_t i = 0; i < size; i++)
		delete list[i];

	delete[] list;
}

void propertyCatalog::resize() {
	propertyForSale** temp = new propertyForSale * [capacity *= 2];

	for (size_t i = 0; i < size; i++)
		temp[i] = list[i];

	delete[] list;
	list = temp;
}

propertyCatalog::propertyCatalog() {
	size = 0;
	capacity = 10;
	list = new propertyForSale * [capacity];
}

propertyCatalog::propertyCatalog(const propertyCatalog& other) {
	copy(other);
}

propertyCatalog& propertyCatalog::operator=(const propertyCatalog& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

propertyCatalog::~propertyCatalog() {
	free();
}

void propertyCatalog::addProperty(const propertyForSale* newProperty) {
	if (size >= capacity)
		resize();

	list[size++] = newProperty->clone();
}

void propertyCatalog::removeProperty(const int index) {
	if (index < 0 || index > size)
		throw "Out if range!";

	delete list[index];
	list[index] = list[size];
	list[size] = nullptr;
	size--;
}

void propertyCatalog::printGarages() const {
	for (size_t i = 0; i < size; i++) {
		if (list[i]->type == 0)
			list[i]->print();
	}
}

void propertyCatalog::printApartments()const {
	for (size_t i = 0; i < size; i++) {
		if (list[i]->type == 1)
			list[i]->print();
	}
}

void propertyCatalog::printHouses()const {
	for (size_t i = 0; i < size; i++) {
		if (list[i]->type == 2)
			list[i]->print();
	}
}

void propertyCatalog::getPropertiesFromCity(const char* city)const {
	for (size_t i = 0; i < size; i++)
		list[i]->getPropertyFromCity(city);
}

void propertyCatalog::getPropertiesInPriceRange(const int lowerLimit, const int upperLimit)const {
	for (size_t i = 0; i < size; i++)
		list[i]->getPropertyInPriceRange(lowerLimit, upperLimit);
}

void propertyCatalog::getPropertiesInSquaringRange(const double lowerLimit, const double upperLimit)const {
	for (size_t i = 0; i < size; i++)
		list[i]->getPropertyInSquaringRange(lowerLimit, upperLimit);
}

void propertyCatalog::getPropertiesInRoomsRange(const int lowerLimit, const int upperLimit)const {
	for (size_t i = 0; i < size; i++)
		if (list[i]->getRooms() > lowerLimit && list[i]->getRooms() <= upperLimit)
			list[i]->print();
}

void propertyCatalog::print()const {
	for (size_t i = 0; i < size; i++)
		list[i]->print();
}

void propertyCatalog::sortByCity() {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size - i; i++)
			if (strcmp(list[i]->city, list[i + 1]->city) > 0) {
				propertyForSale* temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
			}
	}
}

void propertyCatalog::sortByPrice() {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size - i; i++)
			if (list[i]->price > list[i + 1]->price) {
				propertyForSale* temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
			}
	}
}

void propertyCatalog::sortBySquaring() {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size - i; i++)
			if (list[i]->squaring - list[i + 1]->squaring > DBL_EPSILON) {
				propertyForSale* temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
			}
	}
}