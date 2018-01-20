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
	     unsigned int get_price() { return price; };
	     unsigned int get_quantity() { return quantity; };
	     unsigned int get_strength() { return strength; };
	     void set(std::string mname, int mprice, int mquantity, int mstrength);
};

class Potion : public Item{
    private:
	unsigned int stamina;
    public:
	Potion() {};
	void set(std::string mname, unsigned int mprice, unsigned int mquantity, unsigned int mstamina);
	std::string print_data(); //return data of object as a string
	
};


class Shop{
    private:
	std::vector < Food > foods;
	std::vector < Potion > potions;
    public:
	Shop() {};
	~Shop() {};
	void buy_food(int id) { foods[id].buy(); }; 
	std::string print_item(int id); //obsolete function to display all items at once
	std::string print_potion(int id);
	std::string print_food(int id);
	void generate_items();
	unsigned int* get_food(int id); //returns array 0 - price, 1 - quantity, 2 - strength
	int size_food() { return foods.size(); };
	int size_potion() { return potions.size(); };
	int number_of_items();
};


