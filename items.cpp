#include "items.h"
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
    buff<<name<<" potion, Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<stamina<< " maxium stamina";
    std::string tmp = buff.str();
    return tmp;
}

std::string Upgrade :: print_data(){
    std::stringstream buff;
    //buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<pc<<"$ per click";
    if(pc>0 && exp==0 && level==0) buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<pc<<"$ per click";
    if(pc>0 && exp>0) buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<pc<<"$ per click and "<<exp<<" exp";
    if(pc==0 && exp>0 && level==0) buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<exp<<" exp";
    if(pc==0 && exp==0 && level>0) buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Increases level by: "<<level;
    //if() buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<pc<<"$per click and "<<exp<<" exp";
    std::string tmp = buff.str();
    return tmp;
}

void Upgrade :: set(std::string mname, unsigned int mprice,unsigned int mquantity,unsigned int mpc, unsigned int mexp, unsigned int mlevel){
    name=mname;
    price=mprice;
    quantity=mquantity;
    pc=mpc;
    exp=mexp;
    level=mlevel;
}


