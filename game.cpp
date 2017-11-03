#include <iostream>
#include "game.h"
#include <ncurses.h>
#include <string>

Window::Window(){
	//WINDOW SIZE IS DEFAULT 45X145
	main_menu=newwin(38,90,0,0);
	stats = newwin(38,53,0,90);
	money = newwin(3,143,38,0);
}

void Window::draw_borders(){
	for(int i=0; i<45; ++i){ //pion
		for(int j=0; j<146; ++j){ //poziom
			if(i==0 || i==38 || i==40 || i==44){
				mvprintw(i,j,"-");
			}
			if((i>0 && i<44) && (j==0 || (j==100 && i<38) || j==145)){
				mvprintw(i,j,"|");
			}
		}
	}
}
void Window::draw_menu(int headlight){
	box(main_menu,0,0);
	mvwprintw(main_menu,4,10,"Items");
	mvwprintw(main_menu,5,10,"Shop");
	mvwprintw(main_menu,6,10,"Builders");
	mvwprintw(main_menu,7,10,"Tavern");
	mvwprintw(main_menu,8,10,"Bank");
	for(int i=4; i<9; ++i){
		mvwprintw(main_menu,i,6,"   ");
	}
	attron(A_BOLD);
	mvwprintw(main_menu,headlight+4,6,"-->");
	attroff(A_BOLD);
}

void Window::draw_stats(Player *mplayer){
	box(stats,0,0);
	mvwprintw(stats,4,10,"Stamina: %d / %d",mplayer->get_strength(),mplayer->get_strength_max());
	mvwprintw(stats,5,10,"Money per click: %d",mplayer->get_upgrade());
	refresh_stats();
}

void Window::draw_popup(std::string information){
	char ch;
	popup=newwin(10,100,22,22);
	box(popup,0,'=');	
	mvwprintw(popup,0,45,"INFORMATION");
	mvwprintw(popup,2,2,information.c_str());
	mvwprintw(popup,8,38,"Press ENTER to continue...");
	refresh_popup();
	while(ch=getch()){
		if(ch==10){
			wborder(popup, ' ', ' ', ' ',' ',' ',' ',' ',' ');
			wrefresh(popup);
			delwin(popup);
			break;
		}
	}
	refresh_all();
}

void Window::draw_money(Player *mplayer){
	box(money,0,0);
	attron(A_BOLD);
	mvwprintw(money,1,65,"Money: %d$ / %d$ ",mplayer->get_money(),mplayer->get_money_max());	
	attroff(A_BOLD);
	refresh_money();
}

void Window::draw_player_strenght(unsigned int strength, unsigned int strength_max){
	mvprintw(5,107,"Strenght: %d / %d",strength,strength_max);
}

void Window::draw_player_perclick(unsigned int perclick){
	mvprintw(4,107,"Money per click: %d",perclick);
}

void Window::refresh_all(){
	refresh_main_menu();
	refresh_stats();
}

Player::Player(){
	money=0;
	money_max=5000;
	strength=100;
	strength_max=500;
	upgrade=1;
}

void Player::add_money(int ammount){
	money=money+ammount;	
}

void Player::add_strength(int ammount){
	strength=strength+ammount;
}

void Player::add_strength_max(int ammount){
	strength_max=strength_max+ammount;
}



