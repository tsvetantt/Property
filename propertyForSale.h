#pragma once


class propertyForSale {
protected:
	enum Type {
		GARAGE,
		HOUSE,
		APARTMENT,
		UNKNOWN
	}type;
	char* city;
	char* region;
	int price;
	double squaring;
	bool forRent;

public:
	propertyForSale();
	propertyForSale(const char* city, const char* region, const int price, const double squaring, bool rent);
	propertyForSale(const propertyForSale&);
	propertyForSale& operator=(const propertyForSale&);
	virtual ~propertyForSale();

	virtual void print()const = 0;

	void setForRentOrForSell(const bool);
	
	virtual propertyForSale* clone()const = 0;
	
	virtual const size_t getRooms()const = 0;

	void getPropertyFromCity(const char*)const;
	void getPropertyInPriceRange(const int , const int)const;
	void getPropertyInSquaringRange(const double, const double)const;
	
	friend class propertyCatalog;
private:
	void copy(const propertyForSale&);
	void free();
};
