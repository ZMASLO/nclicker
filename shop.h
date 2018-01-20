#include <iostream>
#include <vector>

class Item{
	protected:
		std::string name;
		unsigned int price;
		unsigned int quantity;
	public:
		Item(){};
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
	     void set(std::string mname, int mprice, int mquantity, int mstrength);
};

class Potion : public Item{
    private:
	unsigned int stamina;
    public:
	Potion(std::string mname,unsigned int mprice, unsigned int mquantity, unsigned int mstamina); //basic constructor
	
};


class Shop{
    private:
	std::vector < Food > foods;
    public:
	Shop() {};
	~Shop() {};
	std::string print_item(int id);
	void generate_items();
	int number_of_items();
};


