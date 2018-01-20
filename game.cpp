#include "game.h"
#include <ncurses.h>

Window::Window(){
	//WINDOW SIZE IS DEFAULT 45X145
	main_menu=newwin(38,90,0,0);
	stats = newwin(38,53,0,90);
	money = newwin(3,143,38,0);
	menu_type=0;
	menu_headlight=0;
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
void Window::draw_menu(){
	box(main_menu,0,0);
	if(menu_type==0){ //main_menu
		mvwprintw(main_menu,4,10,"Inventory");
		mvwprintw(main_menu,5,10,"Shop");
		mvwprintw(main_menu,6,10,"Builders");
		mvwprintw(main_menu,7,10,"Tavern");
		mvwprintw(main_menu,8,10,"Bank");
	}
	if(menu_type==2){ //shop
	    mvwprintw(main_menu,4,10,"<-- Back");
	    for(int i=0; i<mshop->number_of_items(); ++i){
		mvwprintw(main_menu,5+i,10,mshop->print_item(i).c_str()); //printing generated items
	    }
	}
	if(menu_type==5){ //bank
		mvwprintw(main_menu,4,10,"<-- Back");
		mvwprintw(main_menu,5,10,"Buy upgrade!");
	}
}

void Window::draw_headlight(int headlight){
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

void Window::menu_up(){
    if(menu_headlight>0){
	--menu_headlight;
    }
}

void Window::menu_down(){
    if(menu_type==0 && menu_headlight<5){
	++menu_headlight;
    }
    if(menu_type==2 && menu_headlight<mshop->number_of_items()){
	++menu_headlight;
    }
    if(menu_type==5 && menu_headlight<1){
	++menu_headlight;
    }
}

void Window::selected(int headlight){
	/*
	 *	Menu types:
	 *	0 - main menu
	 *	1 - inventory
	 *	2 - Shop
	 *	3 - Builders
	 *	4 - Tavern
	 *	5 - Bank
	 */
	if(menu_type==0){ //options from main menu
		if(headlight+1==1) menu_type=1;
		if(headlight+1==2) menu_type=2;
		if(headlight+1==5) menu_type=5;
	}
	if(menu_type!=0 && headlight+1==1) menu_type=0; //BACK TO MAIN MENU
	wclear(main_menu); //clear menu to avoid mistakes in render
	draw_menu();
	refresh_main_menu();
}

Player::Player(){
	money=0;
	money_max=5000;
	strength=100;
	strength_max=500;
	upgrade=1;
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
	strength=strength+ammount;
}

void Player::add_strength_max(int ammount){
	strength_max=strength_max+ammount;
}

void Upgrade::bank(){
    ++bank_lvl;
    money_max=money_max*bank_lvl; 
}


