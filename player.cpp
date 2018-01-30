#include <iostream>
#include "player.h"


Player::Player(){
	money=0;
	money_max=5000;
	strength=100;
	strength_max=500;
	level=1;
	exp=0;
	upgrade=1;
	exp_level=30;
	game_time=0;
	shop_time=60;
	worker=0;
	worker_upgrade=1;
	worker_upgrade_price=30;
	worker_price=50;
}

void Player::add_money(int ammount){
	if((money+ammount) < money_max){
		money=money+ammount;	
	}
	else{
		money=money_max; //to not override maximum ammount
	}
}

void Player::add_strength(int ammount){
	if((strength+ammount) < strength_max){
		strength=strength+ammount;
	}
	else{
	    strength=strength_max;
	}
}

void Player::add_strength_max(int ammount){
	strength_max=strength_max+ammount;
}

void Player::buy_worker_upgrade(){
     ++worker_upgrade;
     worker_upgrade_price=worker_upgrade_price*3;
}

void Player::add_shop_time(){
    if(shop_time==0){
	shop_time=60;
    }
    if(shop_time>0){
	--shop_time;
    }
}
