# Property

Клас propertyForSell (абстрасктен)
  •	type – (garage,house,apartment)
  •	city – градът, в който е имотът
  •	region – регион или квартал ако е в град
  •	price – цена на имота
  •	squaring – квадратура на имота
  •	forRent – дали се продава или се дава под наем

Клас house (наследява propertyForSell)
  •	amountOfRooms – брой на стаите
  •	yearOfConstruction – година, в която имотът е построен
  • houseNumber – номер на къщата

Клас garage (наследява propertyForSell)
  •	yearOfConstruction – година, в която имотът е построен\

Клас apartment.h (наследява propertyForSell)
  •	amountOfRooms – брой на стаите
  •	yearOfconstruction – година, в която имотът е построен
  •	blockNumber – номер на блока
  •	floor – етажа, на който е апартаментът

Клас propertyCatalog.h (контейнер)
  •	list – списък от имоти
 - функционалности:
  •	addProperty – добавя имот
  •	removeProperty – премахва имот
  •	printGarages – извежда всички гаражи
  •	printApartments – извежда всички апартаменти
  •	printHouses – извежда всички къщи 
  •	print – извежда всички имоти
  •	getPropertiesFromCity – извежда всички имоти, които са в даден град
  •	getPropertiesInPriceRange – извежда всички имоти, които са в даден ценови диапазон
  •	getPropertiesInSquaringRange – извежда всички имоти, които са в дадена квадратура
  •	getPropertiesInRoomsRange – извежда всички имоти, които имат определен брой стаи
  •	sortByCity – сортира имотите по град
  •	sortByPrice – сортира имотите по цена
  •	sortBySquaring – сортира имотите по квадратура
