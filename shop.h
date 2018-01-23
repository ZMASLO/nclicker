#include <iostream>
#include <vector>
#include "items.h"


class Shop{
    private:
	std::vector < Food > foods;
	std::vector < Potion > potions;
	std::vector < Upgrade > upgrades;
    public:
	Shop() {};
	~Shop() {};
	void buy_food(int id) { foods[id].buy(); }; 
	void buy_potion(int id) { potions[id].buy(); }; 
	void buy_upgrade(int id) { upgrades[id].buy(); };
	std::string print_item(int id); //obsolete function to display all items at once
	std::string print_potion(int id);
	std::string print_food(int id);
	std::string print_upgrade(int id);
	void generate_items(int level);
	int* get_food(int id); //returns array 0 - price, 1 - quantity, 2 - stamina recovery
	int* get_potions(int id); //returns array 0 - price, 1 - quantity, 2 - max stamina increase
	int* get_upgrades(int id); //returns array 0 - price, 1 - quantity, 2 - money per click, 3 - exp, 4 - level
	int size_food() { return foods.size(); };
	int size_potion() { return potions.size(); };
	int size_upgrade() { return upgrades.size(); };
	int number_of_items();
};


