#include "house.h"
#include <iostream>

House::House(const char* city, const char* region, const int price, const double squaring, const bool rent, int amountOfRooms, int yearOfConstruction, int houseNumber)
    :propertyForSale(city, region, price, squaring, rent) {

    type = Type::HOUSE;
    this->amountOfRooms = amountOfRooms;
    this->yearOfConstruction = yearOfConstruction;
    this->houseNumber = houseNumber;
}

void House::print()const {
    std::cout << "House:" << std::endl;
    std::cout << "- City: " << city << std::endl;
    std::cout << "- Region: " << region << std::endl;
    std::cout << "- Price: " << price << "$" << std::endl;
    std::cout << "- Squaring: " << squaring << std::endl;
    std::cout << "- Amount of rooms: " << amountOfRooms << std::endl;
    std::cout << "- Year of construction: " << yearOfConstruction << std::endl;
    std::cout << "- House number: " << houseNumber << std::endl;
}

const size_t House::getRooms()const {
    return amountOfRooms;
}

const size_t House::getYearOfConstruction()const {
    return yearOfConstruction;
}

const size_t House::getHouseNumber()const {
    return houseNumber;
}

propertyForSale* House::clone()const {
    return new House(*this);
}

void House::getHouseInRoomsRange(const int lowerLimit, const int upperLimit)const {
    if (lowerLimit < 0 || upperLimit < 0)
        throw "Out of range!";

    if (lowerLimit < amountOfRooms && upperLimit < amountOfRooms)
        print();

}