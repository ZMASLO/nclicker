#include <iostream>
#include <ncurses.h>
#include "shop.h"
/*
TO DO:
- DRAWING STATS
- DRAWING MONEY
- DRAWING BOTTOM INFO
*/
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
		unsigned int game_time;

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
		unsigned int get_upgrade() { return upgrade; } ;
		unsigned int get_strength() { return strength; };
		unsigned int get_strength_max() { return strength_max; };
		unsigned int get_money() { return money; };
		unsigned int get_money_max() { return money_max; };
		unsigned int get_level() { return level; };
		unsigned int get_exp() { return exp; };
		unsigned int get_exp_level() { return exp_level; };
		unsigned int get_game_time() { return game_time; };
		void upgrade_bank() { money_max=money_max*6; }; 

};

class Window{
	private:
		int menu_type; //determines whitch menu should be displayed
		int menu_headlight; //determines whitch option should be headlighted
		Shop *mshop; //pointer to shop data
		Player *mplayer; //pointer to player data
		WINDOW *main_menu;
		WINDOW *stats;
		WINDOW *money;
		WINDOW *popup;
	public:
		Window();
		void draw_borders();
		void draw_menu(); //draws menu and determine whitch one should be displayed
		void draw_headlight(); //draws headlight -->
		void draw_stats(Player *mplayer);
		void draw_money(Player *mplayer);
		void draw_workers();
		void draw_popup(std::string information);
		void draw_player_strenght(unsigned int strenght,unsigned int strength_max);
		void draw_player_perclick(unsigned int perclick);
		void menu_up();
		void menu_down();
		void refresh_main_menu() { wrefresh(main_menu); };
		void refresh_stats() { wrefresh(stats); };
		void refresh_popup() { wrefresh(popup); };
		void refresh_money() { wrefresh(money); };
		void refresh_all();
		void selected(); //selected option form menu is executed
		void set_shop(Shop &s) { mshop=&s; };
		void set_player(Player &p) { mplayer=&p; };
		void set_main_menu() { menu_type=0; menu_headlight=0; };

		
};


