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
	game.set_player(mplayer);
	Shop mshop;
	game.set_shop(mshop);
	mshop.generate_items(mplayer.get_level()); //generating items for shop
	clock_t start,end;
	time(&start);
	while(run==1){
		if(kbhit()){
		ch = getch();
		napms(100);
		if(ch == 32 && mplayer.get_strength()>0){ //minig with SPACE
			mplayer.add_money(mplayer.get_upgrade());
			mplayer.add_strength(-1);
			mplayer.add_exp(1);
			if(mplayer.get_strength()==0){
				game.draw_popup("You're exausted and cannot mine anymore. Buy food to recover strength!");
			}
			game.draw_money(&mplayer);
			game.draw_stats(&mplayer);
		}
		if(ch==107 || ch==KEY_UP){  //menu up
		    game.menu_up();
		    game.draw_menu();
		    game.refresh_main_menu();
		}
		if(ch==106){ //j menu down
		    game.menu_down();
		    game.draw_menu();
		    game.refresh_main_menu();
		}
		if(ch=='x'){
			mplayer.add_upgrade(5);	
		}
		if(ch==10){ //enter select option
		    game.selected();
		    game.draw_money(&mplayer);
		    game.draw_stats(&mplayer);
		}
		if(ch==27){ //escape pause menu
		    game.set_main_menu();
		    game.draw_menu();
		    game.refresh_main_menu();
		}
		if(ch=='o'){
		    game.draw_popup("Refreshing shop!");
		    mshop.generate_items(mplayer.get_level());
		}
		if(mplayer.get_exp()>=mplayer.get_exp_level()){ //leveling up
		    mplayer.add_level();
		    game.draw_popup("You are working hard. LEVEL UP!");
		}
		}
		else{
		    napms(50); //if key is not presed its stoping program fo 50ms
		}
		time(&end);
		if(difftime(end,start) > 1){  //tickrate
			mplayer.add_money(mplayer.get_worker()*mplayer.get_worker_upgrade()); //ammonut money per second
			mplayer.add_strength(1*mplayer.get_level()); //adds stamina per second
			mplayer.add_game_time();
			mplayer.add_shop_time();
			if(mplayer.get_shop_time()==1){
			    mshop.generate_items(mplayer.get_level());
			}
			game.draw_stats(&mplayer);
			game.draw_money(&mplayer);
			game.draw_menu();
			game.refresh_main_menu();
			time(&start);
		}
		if(mplayer.get_money()>=1000000){
		    game.draw_popup("Congratulations! You won game!");
		    return 0;
		}
	}
	endwin();
	return 0;
}
