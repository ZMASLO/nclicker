#include <iostream>
#include <ncurses.h>
#include "shop.h"
#include "player.h"

class Window{
	private:
		
		int menu_type; //determines whitch menu should be displayed
		int menu_headlight; //determines whitch option should be headlighted
		Shop *mshop; //pointer to shop data
		Player *mplayer; //pointer to player data
		WINDOW *main_menu;
		WINDOW *stats;
		WINDOW *bottom_bar;
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
		void refresh_bottom_bar() { wrefresh(bottom_bar); };
		void refresh_popup() { wrefresh(popup); };
		void refresh_money() { wrefresh(money); };
		void refresh_all();
		void selected(); //selected option form menu is executed
		void set_shop(Shop &s) { mshop=&s; };
		void set_player(Player &p) { mplayer=&p; };
		void set_main_menu() { menu_type=0; menu_headlight=0; };
		void ngame_quit();

		
};


