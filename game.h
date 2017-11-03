#include <iostream>
#include <ncurses.h>
/*
TO DO:
- DRAWING STATS
- DRAWING MONEY
- DRAWING BOTTOM INFO
*/
class Player{
	private:
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
		WINDOW *main_menu;
		WINDOW *stats;
		WINDOW *popup;
	public:
		Window();
		void draw_borders();
		void draw_menu(int headlight); //draws menu on screen headlight determine witch option has -->
		void draw_stats(Player *mplayer);
		void draw_popup(std::string information);
		void draw_money(unsigned int money,unsigned  int money_max);
		void draw_player_strenght(unsigned int strenght,unsigned int strength_max);
		void draw_player_perclick(unsigned int perclick);
		void refresh_main_menu() { wrefresh(main_menu); };
		void refresh_stats() { wrefresh(stats); };
		void refresh_popup() { wrefresh(popup); };

		
};

class Shop{
	private:
	public:
		void item_list();
};

class Item{
	private:
		std::string name;
		unsigned int price;
		int function;
	public:
		Item();
		Item(std::string name, int price, int function);
		~Item();
		void print_name();
		unsigned int get_price() { return price; };
};

class Worker{
};

