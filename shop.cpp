#include "shop.h"
#include <sstream>
#include <fstream>

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
    buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<pc<<"$ per click";
    /*if(pc>=0 && exp==0 && level==0) buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<pc<<"$ per click";
    if(pc==0 && exp>=0 && level==0) buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<exp<<" exp";
    if(pc==0 && exp==0 && level>=0) buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Increases level by: "<<level;
    if(money>=0 && exp>=0 && level==0) buff<<name<<", Price: "<<price<<"$, Quantity: "<<quantity<<", Adds "<<pc<<"$per click and "<<exp<<" exp";*/
    std::string tmp = buff.str();
    return tmp;
}

void Upgrade :: set(std::string mname, unsigned int mprice,unsigned int mquantity,unsigned int mpc){
    name=mname;
    price=mprice;
    quantity=mquantity;
    pc=mpc;
    //exp=mexp;
    //level=mlevel;
}



void Shop::generate_items(){
    //Food test[3] = { ("Bread",1,1,1), ("Apple",5,5,5), ("Meat",10,10,10) };
    /*
    test[0]("Bread",1,1,1);
    test[1]("Apple",5,5,5);
    test[2]("Meat",10,10,10);
    */
    Food food_tmp;
    Potion potion_tmp;
    Upgrade upgrade_tmp;
    std::string name,type;
    int quantity,price,at;
    std::ifstream file;
    file.open("items.dat");
    while(file){
       file>>type;
       file>>name;
       file>>price;
       file>>quantity;
       file>>at;
       if(type=="food"){
	    food_tmp.set(name,price,quantity,at);
	    foods.push_back(food_tmp);
	}
	if(type=="potion"){
	    potion_tmp.set(name,price,quantity,at);
	    potions.push_back(potion_tmp);
	}
	if(type=="upgrade"){
	    upgrade_tmp.set(name,price,quantity,at);
	    upgrades.push_back(upgrade_tmp);
	}

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

int* Shop :: get_food(int id){
    int* pointer;
    int tab[3];
    pointer=tab;
    tab[0]=foods[id].get_price();
    tab[1]=foods[id].get_quantity();
    tab[2]=foods[id].get_strength();

    return pointer;
}

int* Shop :: get_potions(int id){
    int* pointer;
    int tab[3];
    pointer=tab;
    tab[0]=potions[id].get_price();
    tab[1]=potions[id].get_quantity();
    tab[2]=potions[id].get_stamina();

    return pointer;
}

int* Shop :: get_upgrades(int id){
    int* pointer;
    int tab[3];
    pointer=tab;
    tab[0]=upgrades[id].get_price();
    tab[1]=upgrades[id].get_quantity();
    tab[2]=upgrades[id].get_pc();
    //tab[3]=upgrades[id].get_exp();
    //tab[4]=upgrades[id].get_level();

    return pointer;
}

std::string Shop::print_food(int id){
    return foods[id].print_data();
}

std::string Shop::print_potion(int id){
    return potions[id].print_data();
}

std::string Shop::print_upgrade(int id){
    return upgrades[id].print_data();
}

int Shop::number_of_items(){
    return foods.size()+potions.size()+upgrades.size();
}
