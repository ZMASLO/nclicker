#include <ncurses.h>
#include "game.h"
int main(void){
	char ch=0;
	bool run=1; //boolean to determine wheter game should run or not
	int menu_option=0;
	initscr();			/* Start curses mode 		  */
	noecho();			//do not display getch()
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);		//keypad F1 keys etc
	Window game;
	Player mplayer;
	while(run==1){
		game.draw_money(&mplayer);
		game.draw_stats(&mplayer);
		//game.draw_player_strenght(mplayer.get_strength(),mplayer.get_strength_max());
		//game.draw_player_perclick(mplayer.get_upgrade());
		ch = getch();
		if(ch == 32 && mplayer.get_strength()>0){ //minig (aka clicking)
			if(mplayer.get_money()+mplayer.get_upgrade()<mplayer.get_money_max()){
				mplayer.add_money(mplayer.get_upgrade());
			}
			else{
				mplayer.add_money(mplayer.get_money_max()-mplayer.get_money());
			}
			mplayer.add_strength(-1);
			if(mplayer.get_strength()==0){
				game.draw_popup("You're exausted and cannot mine anymore. Buy food to recover strength!");
			}
		}
		if(ch==107 || getch()==KEY_UP){ //k
			if(menu_option>0){
				--menu_option;
				game.draw_menu(menu_option);
				game.refresh_main_menu();
			}
		}
		if(ch==106){ //j
			if(menu_option<4){
				++menu_option;
				game.draw_menu(menu_option);
				game.refresh_main_menu();
			}
		}
		if(ch=='x'){
			mplayer.add_upgrade(5);	
		}
		if(ch=='o'){
			game.draw_popup("supertest");
			game.draw_menu(menu_option);
			game.refresh_main_menu();
		}
		//napms(5); //little slowdown for program
		//mplayer.add_money(1);
		//refresh();			/* Print it on to the real screen */
	}
	endwin();
	return 0;
}
