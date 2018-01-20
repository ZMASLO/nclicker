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
    buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Recoveres "<<strength<< " stamina";
    std::string tmp = buff.str();
    return tmp;
}

void Food :: set(std::string mname, int mprice, int mquantity, int mstrength){
    name=mname;
    price=mprice;
    quantity=mquantity;
    strength=mstrength;
}



void Potion :: set(std::string mname,unsigned int mprice, unsigned int mquantity, unsigned int mstamina){
   name=mname;
   price=mprice;
   quantity=mquantity;
   stamina=mstamina;
}
std::string Potion :: print_data(){
    std::stringstream buff;
    buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<stamina<< " maxium stamina";
    std::string tmp = buff.str();
    return tmp;
}



void Shop::generate_items(){
    //Food test[3] = { ("Bread",1,1,1), ("Apple",5,5,5), ("Meat",10,10,10) };
    /*
    test[0]("Bread",1,1,1);
    test[1]("Apple",5,5,5);
    test[2]("Meat",10,10,10);
    */
    Food tmp;
    for(int i=0; i<7; ++i){
	tmp.set("Bread",5*i,1,i*4);
	foods.push_back(tmp);
    }
    Potion ptmp;
    for(int i=0; i<5; ++i){
        ptmp.set("Light Potion",30,i,15);
        potions.push_back(ptmp);
    }

}

std::string Shop::print_item(int id){
    if(id<foods.size()){
	return foods[id].print_data();
    }
    if(id>foods.size()-1 && id<foods.size()+potions.size()){
	return potions[id-foods.size()].print_data();
    }
}

unsigned int* Shop :: get_food(int id){
    unsigned int* pointer;
    unsigned int tab[3];
    pointer=tab;
    tab[0]=foods[id].get_price();
    tab[1]=foods[id].get_quantity();
    tab[2]=foods[id].get_strength();

    return pointer;
}

unsigned int* Shop :: get_potions(int id){
    unsigned int* pointer;
    unsigned int tab[3];
    pointer=tab;
    tab[0]=potions[id].get_price();
    tab[1]=potions[id].get_quantity();
    tab[2]=potions[id].get_stamina();

    return pointer;
}


std::string Shop::print_food(int id){
    return foods[id].print_data();
}

std::string Shop::print_potion(int id){
    return potions[id].print_data();
}

int Shop::number_of_items(){
    return foods.size()+potions.size();
}
