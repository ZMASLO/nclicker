#include <iostream>
class Item{
	protected:
		std::string name;
		unsigned int price;
		unsigned int quantity;
	public:
		Item();
		~Item();
		void set(std::string mname, int mprice, int mquantity);
};

class Food : public Item{
	private:
		unsigned int strength; //ammount of strenght recovered
	public:
	    Food();
	    void set(std::string mname,unsigned int mprice, unsigned int mquantity, unsigned int mstrenght);
	    ~Food();

};


class Shop{
    private:
    public:
	Shop();
	~Shop();
};


