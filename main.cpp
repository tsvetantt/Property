#include "propertyCatalog.h"
#include "apartment.h"
#include "garage.h"
#include "house.h"


#include <iostream>
using namespace std;
const int MAX_C = 40;
const int MAX_F = 150;

int main() {
	propertyCatalog catalog;

	cout << "Commands: " << endl;

	cout << " add property - ap" << endl;
	cout << " remove property - rp" << endl;
	cout << " print all garages - pg" << endl;
	cout << " print all apartments - pa" << endl;
	cout << " print all houses - ph" << endl;
	cout << " print all - p" << endl;
	cout << " get properties from city - gpc" << endl;
	cout << " get properties in price range - gpr" << endl;
	cout << " get properties in squaring range - gsr" << endl;
	cout << " get properties in room range - grr" << endl;
	cout << " sort by city - sc, " << endl;
	cout << " sort by price - sp, " << endl;
	cout << " sort by squaring - ss, " << endl;

	char commandLine[MAX_C];
	do {
		cout << endl << ">";
		cin.getline(commandLine, MAX_C);

		if (strcmp(commandLine, "ap") == 0) {
			cout << "Enter the property you want to add: (apartment,garage,house)" << endl;

			cout << endl << ">";
			cin.getline(commandLine, MAX_C);
			int price, floor, blockNum, rooms, yearOfC,houseNum;
			double squaring;
			char city[MAX_F], region[MAX_F],check[MAX_F];
			if (strcmp(commandLine, "apartment") == 0) {
				cout << "Enter the city: " << endl;
				cin.getline(city, MAX_F);
				cout << "Enter the region: " << endl;
				cin.getline(region, MAX_F);
				cout << "Enter the price: " << endl;
				cin >> price;
				cout << "Enter the squaring: " << endl;
				cin >> squaring;
				cout << "Enter the amount of rooms: " << endl;
				cin >> rooms;
				cout << "Enter the year of construction: " << endl;
				cin >> yearOfC;
				cout << "Enter the block number: " << endl;
				cin >> blockNum;
				cout << "Enter the apatment floor: " << endl;
				cin >> floor;
				cout << "Are you selling it or giving it for rent: (selling,renting)" << endl;
				cin.ignore();
				cin.getline(check, MAX_F);
				if (strcmp(check, "selling") == 0) {
					Apartment newAp(city, region, price, squaring, rooms, yearOfC, blockNum, floor, true);
					catalog.addProperty(&newAp);
					
				}
				if (strcmp(check, "renting") == 0) {
					Apartment newAp(city, region, price, squaring, rooms, yearOfC, blockNum, floor, false);
					catalog.addProperty(&newAp);
				}
			}
			if (strcmp(commandLine, "garage") == 0) {
				cout << "Enter the city: " << endl;
				cin.getline(city, MAX_F);
				cout << "Enter the region: " << endl;
				cin.getline(region, MAX_F);
				cout << "Enter the price: " << endl;
				cin >> price;
				cout << "Enter the squaring: " << endl;
				cin >> squaring;
				cout << "Enter the year of construction: " << endl;
				cin >> yearOfC;
				cout << "Are you selling it or giving it for rent: (selling,renting)" << endl;
				cin.ignore();
				cin.getline(check, MAX_F);
				if (strcmp(check, "selling") == 0) {
					Garage newGar(city, region, price, squaring,yearOfC, true);
					catalog.addProperty(&newGar);

				}
				if (strcmp(check, "renting") == 0) {
					Garage newGar(city, region, price, squaring, yearOfC, true);
					catalog.addProperty(&newGar);
				}
			}
			if (strcmp(commandLine, "house") == 0) {
				cout << "Enter the city: " << endl;
				cin.getline(city, MAX_F);
				cout << "Enter the region: " << endl;
				cin.getline(region, MAX_F);
				cout << "Enter the price: " << endl;
				cin >> price;
				cout << "Enter the squaring: " << endl;
				cin >> squaring;
				cout << "Enter the amount of rooms: " << endl;
				cin >> rooms;
				cout << "Enter the year of construction: " << endl;
				cin >> yearOfC;
				cout << "Enter the house number: " << endl;
				cin >> houseNum;
				cout << "Are you selling it or giving it for rent: (selling,renting)" << endl;
				cin.ignore();
				cin.getline(check, MAX_F);
				if (strcmp(check, "selling") == 0) {
					House newHouse(city, region, price, squaring,true, rooms, yearOfC, houseNum);
					catalog.addProperty(&newHouse);

				}
				if (strcmp(check, "renting") == 0) {
					House newHouse(city, region, price, squaring, true, rooms, yearOfC, houseNum);
					catalog.addProperty(&newHouse);
				}
			}
		}
		if (strcmp(commandLine, "rp") == 0) {
			int index = 0;
			cout << "Enter the index of property you want to delete: " << endl;
			cin >> index;
			catalog.removeProperty(index);
		}
		if (strcmp(commandLine, "pg") == 0) {
			catalog.printGarages();
		}
		if (strcmp(commandLine, "pa") == 0) {
			catalog.printApartments();
		}
		if (strcmp(commandLine, "ph") == 0) {
			catalog.printHouses();
		}
		if (strcmp(commandLine, "p") == 0) {
			catalog.print();
		}
		if (strcmp(commandLine, "gpc") == 0) {
			cout << "Enter the city name: ";
			char city[MAX_F];
			cin.getline(city, MAX_F);
			catalog.getPropertiesFromCity(city);
		}
		if (strcmp(commandLine, "gpr") == 0) {
			cout << "Enter the price range: ";
			int price1, price2;
			cout << "From: "<<endl;
			cin >> price1;
			cout << "To: "<<endl;
			cin >> price2;
	
			catalog.getPropertiesInPriceRange(price1,price2);
		}
		if (strcmp(commandLine, "gsr") == 0) {
			cout << "Enter the squaring range: ";
			double s1, s2;
			cout << "From: " << endl;
			cin >> s1;
			cout << "To: " << endl;
			cin >> s2;

			catalog.getPropertiesInSquaringRange(s1, s2);
		}
		if (strcmp(commandLine, "grr") == 0) {
			cout << "Enter the rooms range: ";
			int r1, r2;
			cout << "From: " << endl;
			cin >> r1;
			cout << "To: " << endl;
			cin >> r2;

			catalog.getPropertiesInRoomsRange(r1, r2);
		}
		if (strcmp(commandLine, "sc") == 0) {
			catalog.sortByCity();
			catalog.print();
		}
		if (strcmp(commandLine, "sp") == 0) {
			catalog.sortByPrice();
			catalog.print();
		}
		if (strcmp(commandLine, "ss") == 0) {
			catalog.sortBySquaring();
			catalog.print();
		}
		
		
	} while (!(strcmp(commandLine, "quit") == 0));
	


	return 0;
}