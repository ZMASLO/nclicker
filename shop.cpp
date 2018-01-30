#include "shop.h"
#include <fstream>



void Shop::generate_items(int level){
    foods.clear();
    potions.clear();
    upgrades.clear();
    Food food_tmp;
    Potion potion_tmp;
    Upgrade upgrade_tmp;
    std::string name,type;
    int quantity,price,at1,at2,at3;
    std::ifstream file;
    file.open("items.dat");
    if(file.is_open()){
    while(file){
       file>>type;
       file>>name;
       file>>price;
       file>>quantity;
       file>>at1;
       if(type=="food"){
	    food_tmp.set(name,price*level,quantity,at1*level);
	    foods.push_back(food_tmp);
	}
	if(type=="potion"){
	    potion_tmp.set(name,price*level,quantity,at1*level);
	    potions.push_back(potion_tmp);
	}
	if(type=="upgrade"){
	    file>>at2;
	    file>>at3;
	    upgrade_tmp.set(name,price*level,quantity,at1*level*level,at2*level,at3*level);
	    upgrades.push_back(upgrade_tmp);
	}

    }
    file.close();
    }
    else{
	throw "Unable to open file with items";
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
    int* tab = new int[3];
    //int tab[3];
    //pointer=tab;
    tab[0]=foods[id].get_price();
    tab[1]=foods[id].get_quantity();
    tab[2]=foods[id].get_strength();

    return tab;
}

int* Shop :: get_potions(int id){
    int* tab = new int[3];
    //int tab[3];
    //pointer=tab;
    tab[0]=potions[id].get_price();
    tab[1]=potions[id].get_quantity();
    tab[2]=potions[id].get_stamina();

    return tab;
}

int* Shop :: get_upgrades(int id){
    int* tab = new int[5];
    //int tab[3];
    //pointer=&tab[0];
    tab[0]=upgrades[id].get_price();
    tab[1]=upgrades[id].get_quantity();
    tab[2]=upgrades[id].get_pc();
    tab[3]=upgrades[id].get_exp();
    tab[4]=upgrades[id].get_level();

    return tab;
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
