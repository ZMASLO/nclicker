#include <iostream>

class Player{
	protected:
		std::string name;
		unsigned int upgrade; //money per click
		unsigned int strength; // current value of how many hits can perfform without resting
		unsigned int strength_max; //how many times can hit without resting
		unsigned int exp;
		unsigned int exp_level;
		unsigned int level;
		unsigned int money; //current money
		unsigned int money_max; //maximal balance of account
		unsigned int worker; //number of workers
		unsigned int worker_upgrade; //money per second
		unsigned int worker_upgrade_price;
		unsigned int worker_price;
		unsigned int game_time;
		unsigned int shop_time;

	public:
		Player();
		void set_name(std::string name);
		void add_money(int ammount);
		void add_exp(int ammount) { exp=exp+ammount; };
		void add_level() { ++level; exp_level=exp_level*level; exp=0; };
		void add_strength(int ammount);
		void add_strength_max(int ammount);
		void add_upgrade(unsigned int ammount) { upgrade=upgrade+ammount; };
		void add_game_time() { ++game_time; };
		void add_shop_time();
		void buy_worker() { ++worker; worker_price=worker_price*3; };
		void buy_worker_upgrade();
		unsigned int get_upgrade() { return upgrade; } ;
		unsigned int get_strength() { return strength; };
		unsigned int get_strength_max() { return strength_max; };
		unsigned int get_money() { return money; };
		unsigned int get_money_max() { return money_max; };
		unsigned int get_level() { return level; };
		unsigned int get_exp() { return exp; };
		unsigned int get_exp_level() { return exp_level; };
		unsigned int get_game_time() { return game_time; };
		unsigned int get_shop_time() { return shop_time; };
		unsigned int get_worker() { return worker; };
		unsigned int get_worker_upgrade() { return worker_upgrade; };
		unsigned int get_worker_upgrade_price() { return worker_upgrade_price; };
		unsigned int get_worker_price() { return worker_price; };
		void upgrade_bank() { money_max=money_max*6; }; 

};


