#pragma once


class propertyForSale {
protected:
	char* city;
	char* region;
	int price;
	double squaring;

public:
	propertyForSale();
	propertyForSale(const char* city, const char* region, const int price, const double squaring);
	propertyForSale(const propertyForSale&);
	propertyForSale& operator=(const propertyForSale&);
	virtual ~propertyForSale();

	virtual void print() = 0;
	
	virtual propertyForSale* clone() = 0;
	
	virtual int getRooms() = 0;
	void getPropertysFromCity(const char*);
	void getPropertyInPriceRange(const int , const int);
	void getPropertyInSquaringRange(const double, const double);




private:
	void copy(const propertyForSale&);
	void free();
};