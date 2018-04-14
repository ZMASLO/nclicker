#include <iostream>
#include "player.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

Player::Player(){
	fstream open_file; //open save file if exist
	open_file.open("./saves/save",ios::in);
	if(open_file.good()==false){ //if not exist
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
	string lines; //if exist
	int nr_lines=1;
	while(getline(open_file,lines)){
		switch(nr_lines){
			case 3: upgrade=atoi(lines.c_str()); break;
			case 4: strength=atoi(lines.c_str()); break;
			case 5: strength_max=atoi(lines.c_str()); break;
			case 6: money=atoi(lines.c_str()); break;
			case 7: money_max=atoi(lines.c_str()); break;
			case 8: level=atoi(lines.c_str()); break;
			case 9: exp=atoi(lines.c_str()); break;
			case 10: exp_level=atoi(lines.c_str()); break;
			case 11: game_time=atoi(lines.c_str()); break;
			case 12: shop_time=atoi(lines.c_str()); break;
			case 13: worker=atoi(lines.c_str()); break;
			case 14: worker_upgrade=atoi(lines.c_str()); break;
			case 15: worker_upgrade_price=atoi(lines.c_str()); break;
			case 16: worker_price=atoi(lines.c_str()); break;
		}
		nr_lines++;
	}
	open_file.close();
}

void Player::add_end(int ammount){
	in_end=in_end+ammount;
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
