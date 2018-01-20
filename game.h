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
		unsigned int money; //current money
		unsigned int money_max; //maximal balance of account
	public:
		Player();
		void set_name(std::string name);
		void add_money(int ammount);
		void add_strength(int ammount);
		void add_strength_max(int ammount);
		void add_upgrade(int ammount) { upgrade=upgrade+ammount; };
		unsigned int get_upgrade() { return upgrade; } ;
		unsigned int get_strength() { return strength; };
		unsigned int get_strength_max() { return strength_max; };
		unsigned int get_money() { return money; };
		unsigned int get_money_max() { return money_max; };
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

		
};

class Upgrade : public Player{
    protected:
	int bank_lvl=1;
    public:
	void bank();
};

