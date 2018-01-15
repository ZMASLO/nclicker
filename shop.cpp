#include "shop.h"

Shop::Shop(){
}

void Item::set(std::string mname, int mprice, int mquantity){
    name=mname;
    price=mprice;
    quantity=mquantity;
}


void Food::set(std::string mname,unsigned int mprice, unsigned int mquantity, unsigned int mstrength){
   name=mname;
   price=mprice;
   quantity=mquantity;
   strength=mstrength;
}
