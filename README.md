# Cities-C
I have created this program at my first year of the university. This program is coded with C programming language. I made an arrow menu for interface in terminal. The whole of program is written in English. 

# Nature of My Program
I have used a doubly linked list to storage cities and other data. User can add a new city, update/delete the cities which is already exist after finding that city by name or plate, listing cities and sorting them based 
plate, name and region name. The cities are always added with plate order.

# Functions List
- clearTerminal(); Controls the operating system and sets the terminal clear command accordingly.(Due to works uncorrectly, reorganized according to Windows)(If you use Linux or MacOS change the 'system("cls")' with 'system("clear")'.
- addCity(CitiesList* citiesList, char* cityName, char* regionName, int plate); Adds a new city to linked list with plate order.
- findCitybyPlate(CitiesList* citiesList, int plate); Finds the city with plate in the linked list. If there is no city with this plate this prints an error message and returns to main menu.
- findCitybyName(CitiesList* citiesList, char* name); Finds the city with name in the linked list. If there is no city with this name this prints an error message and returns to main menu.
- delCitybyPlate(CitiesList* citiesList, int plate); Deletes the city with plate in the linked list.
- delCitybyName(CitiesList* citiesList, char* name); Deletes the city with name in the linked list.
- swap(CitiesNode* prev, CitiesNode* current); Changes the data of two consecutive nodes. When I am using bubble sort algorithm, I use this function instead of changing the nodes.
- sortbyPlate(CitiesList* citiesList); Sorts the cities based on plate. It uses bubble sort algorithm.
- sortbyName(CitiesList* citiesList); Sorts the cities based on name. It uses bubble sort algorithm.
- sortbyRegion(CitiesList* citiesList); Sorts the cities based on region name. It uses bubble sort algorithm.
- updateCitybyPlate(CitiesList* citiesList, char* name, char* region, int plate); Updates a city by using 'findCitybyPlate' function.
- printingCities(CitiesList* citiesList); Prints all the cities with sort by plate(as a default order).
- arrowHere(int realPos, int arrowpos); Interface arrow function. Make the color of the arrow line green and others are white.
- mainMenu(); Main menu interface.
- findMenubyName(char* name, char* region, int plate); Find Menu by name interface.
- findMenubyPlate(char* name, char* region, int plate); Find Menu by plate interface.
- listMenu(CitiesList* citiesList); List Menu interface

# Author
- Berat Türk - [GitHub](https://www.github.com/berattrk)
