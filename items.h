#include <iostream>

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


