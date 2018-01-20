#include "shop.h"
#include <sstream>


Food :: Food(std::string mname,unsigned int mprice, unsigned int mquantity, unsigned int mstrength){
   name=mname;
   price=mprice;
   quantity=mquantity;
   strength=mstrength;
}

Food Food :: operator=(const Food& current){
    name = current.name;
    price=current.price;
    quantity=current.quantity;
    strength=current.strength;
    return *this;
}

std::string Food :: print_data(){
    std::stringstream buff;
    buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Recoveres "<<strength<< " strength";
    std::string tmp = buff.str();
    return tmp;
}

void Food :: set(std::string mname, int mprice, int mquantity, int mstrength){
    name=mname;
    price=mprice;
    quantity=mquantity;
    strength=mstrength;
}



Potion :: Potion(std::string mname,unsigned int mprice, unsigned int mquantity, unsigned int mstamina){
   name=mname;
   price=mprice;
   quantity=mquantity;
   stamina=mstamina;
}


void Shop::generate_items(){
    //Food test[3] = { ("Bread",1,1,1), ("Apple",5,5,5), ("Meat",10,10,10) };
    /*
    test[0]("Bread",1,1,1);
    test[1]("Apple",5,5,5);
    test[2]("Meat",10,10,10);
    */
    Food test;
    for(int i=0; i<3; ++i){
	test.set("Bread",1,1,i);
	foods.push_back(test);
    }

}
std::string Shop::print_item(int id){
    return foods[id].print_data();
}

int Shop::number_of_items(){
    return foods.size();
}
