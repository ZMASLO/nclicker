#include <ncurses.h>
#include <time.h>
#include "game.h"
#include <sys/ioctl.h> // for my own kbhit
#include <termios.h> //for my own kbhit

bool kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}


int main(void){
	char ch=0;
	bool run=1; //boolean to determine wheter game should run or not
	initscr();			/* Start curses mode 		  */
	noecho();			//do not display getch()
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);		//keypad F1 keys etc
	curs_set(0);
	Window game;
	Player mplayer;
	Shop mshop;
	game.set_shop(mshop);
	mshop.generate_items(); //generating items for shop
	Upgrade mupgrade;
	clock_t start,end;
	time(&start);
	while(run==1){
		if(kbhit()){
		ch = getch();
		napms(100);
		if(ch == 32 && mplayer.get_strength()>0){ //minig with SPACE
			mplayer.add_money(mplayer.get_upgrade());
			mplayer.add_strength(-1);
			if(mplayer.get_strength()==0){
				game.draw_popup("You're exausted and cannot mine anymore. Buy food to recover strength!");
			}
			game.draw_money(&mplayer);
			game.draw_stats(&mplayer);
		}
		if(ch==107 || getch()==KEY_UP){ //k menu down
		    game.menu_up();
		    game.draw_menu();
		    game.refresh_main_menu();
		}
		if(ch==106){ //j menu up
		    game.menu_down();
		    game.draw_menu();
		    game.refresh_main_menu();
		}
		if(ch=='x'){
			mplayer.add_upgrade(5);	
		}
		if(ch==10){ //enter select option
		    game.selected();
		    game.refresh_main_menu();
		}
		if(ch==27){ //escape pause menu
		    game.draw_popup("Game is paused!");
		}
		if(ch=='o'){
			//Food chleb("Bread",10,1,5);
			game.draw_popup(mshop.print_item(2));
			game.draw_menu();
			game.refresh_main_menu();
		}
		//napms(5); //little slowdown for program
		}
		time(&end);
		if(difftime(end,start) > 1){  //tickrate
			mplayer.add_money(1);
			game.draw_stats(&mplayer);
			game.draw_money(&mplayer);
			time(&start);
		}
	}
	endwin();
	return 0;
}
