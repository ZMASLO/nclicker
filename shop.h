#include <iostream>
#include <vector>

class Item{
	protected:
		std::string name;
		unsigned int price;
		unsigned int quantity;
	public:
		Item(){};
		virtual void buy() { --quantity; };
		virtual unsigned int get_price() { return price; };
		virtual unsigned int get_quantity() { return quantity; };
		~Item(){};
};

class Food : public Item{
	private:
		unsigned int strength; //ammount of strenght recovered
	public:
	     Food() {};
	     Food(std::string mname,unsigned int mprice, unsigned int mquantity, unsigned int mstrength); //basic constructor
	     Food operator=(const Food& current); // = operator
	     std::string print_data(); //return data of object as a string
	     unsigned int get_strength() { return strength; };
	     void set(std::string mname, int mprice, int mquantity, int mstrength);
};

class Potion : public Item{
    private:
	unsigned int stamina;
    public:
	Potion() {};
	void set(std::string mname, unsigned int mprice, unsigned int mquantity, unsigned int mstamina);
	unsigned int get_stamina() { return stamina; };
	std::string print_data(); //return data of object as a string
	
};

class Upgrade : public Item{
    private:
	unsigned int pc; //money per click
	unsigned int exp;
	unsigned int level;
    public:
	Upgrade() {};
	void set(std::string mname, unsigned int mprice, unsigned int mquantity, unsigned int mpc, unsigned int mexp,unsigned int mlevel);
//	void set(std::string mname, unsigned int mprice, unsigned int mquantity, unsigned int mpc);
	std::string print_data();
	unsigned int get_pc() { return pc; };
	unsigned int get_exp() { return exp; };
	unsigned int get_level() { return level; };

};


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
	void generate_items();
	int* get_food(int id); //returns array 0 - price, 1 - quantity, 2 - stamina recovery
	int* get_potions(int id); //returns array 0 - price, 1 - quantity, 2 - max stamina increase
	int* get_upgrades(int id); //returns array 0 - price, 1 - quantity, 2 - money per click, 3 - exp, 4 - level
	int size_food() { return foods.size(); };
	int size_potion() { return potions.size(); };
	int size_upgrade() { return upgrades.size(); };
	int number_of_items();
};


