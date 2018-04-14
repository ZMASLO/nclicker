#include "game.h"
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

Window::Window(){
	//WINDOW SIZE IS DEFAULT 45X145
	main_menu=newwin(38,90,0,0);
	stats = newwin(38,53,0,90);
	money = newwin(3,143,38,0);
	bottom_bar = newwin(3,143,41,0);
	menu_type=0;
	menu_headlight=0;
	keypad(main_menu, TRUE);		//keypad F1 keys etc
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
void Window::draw_menu(){ //function responsible for drawing menu and it's options
	wclear(main_menu);
	box(main_menu,0,0);
	if(menu_type==0){ //main_menu
		mvwprintw(main_menu,4,10,"Alchemist");
		mvwprintw(main_menu,5,10,"Shop");
		mvwprintw(main_menu,6,10,"Upgrades");
		mvwprintw(main_menu,7,10,"Tavern");
		mvwprintw(main_menu,8,10,"Bank");
		mvwprintw(main_menu,9,10,"Quit");
	}
	if(menu_type>0) mvwprintw(main_menu,4,10,"<-- Back");
	if(menu_type==1){
	    for(int i=0; i<mshop->size_potion(); ++i){
		mvwprintw(main_menu,5+i,10,mshop->print_potion(i).c_str()); //printing potions
	    }
	}
	if(menu_type==2){ //shop
	    for(int i=0; i<mshop->size_food(); ++i){
		mvwprintw(main_menu,5+i,10,mshop->print_food(i).c_str()); //printing food
	    }
	}
	if(menu_type==3){ //upgrades
	    for(int i=0; i<mshop->size_upgrade(); ++i){
		mvwprintw(main_menu,5+i,10,mshop->print_upgrade(i).c_str());
	    }
	}
	if(menu_type==4){
		mvwprintw(main_menu,5,10,"Buy Worker for: %d",mplayer->get_worker_price());
		mvwprintw(main_menu,6,10,"Buy Upgrade for: %d",mplayer->get_worker_upgrade_price());
	}
	if(menu_type==5){ //bank
		mvwprintw(main_menu,5,10,"Buy upgrade for: %d$",mplayer->get_money_max()/5);
	}
	if(menu_type==6){ //quit
		ngame_quit();
	}
	draw_headlight();
}

void Window::ngame_quit(){ //quit menu
	mvwprintw(main_menu,5,10,"Exit without save:",mplayer->get_game_quit());
	mvwprintw(main_menu,6,10,"Exit with save:",mplayer->get_game_quit());
}

void Window::draw_headlight(){
/*	for(int i=4; i<9; ++i){
		mvwprintw(main_menu,i,6,"   ");
	}*/
	attron(A_BOLD);
	mvwprintw(main_menu,menu_headlight+4,6,"-->");
	attroff(A_BOLD);

}

void Window::draw_stats(Player *mplayer){
	wclear(stats);
	wclear(bottom_bar);
	box(stats,0,0);
	box(bottom_bar,0,0);
	mvwprintw(stats,4,10,"Level: %d",mplayer->get_level());
	mvwprintw(stats,5,10,"Exp: %d / %d",mplayer->get_exp(),mplayer->get_exp_level());
	mvwprintw(stats,6,10,"Stamina: %d / %d",mplayer->get_strength(),mplayer->get_strength_max());
	mvwprintw(stats,7,10,"Money Per Click: %d",mplayer->get_upgrade());
	mvwprintw(stats,8,10,"Game Time: %d",mplayer->get_game_time());
	//bottom bar
	mvwprintw(bottom_bar,1,4,"Workes: %d",mplayer->get_worker());
	mvwprintw(bottom_bar,1,66,"Workes Level: %d",mplayer->get_worker_upgrade());
	mvwprintw(bottom_bar,1,120,"Shop refresh in: %d",mplayer->get_shop_time());
	refresh_stats();
	refresh_bottom_bar();
}

void Window::draw_popup(std::string information){
	char ch;
	popup=newwin(10,100,22,22);
	box(popup,0,0);	
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
    draw_menu();
    refresh_main_menu();
}

void Window::draw_money(Player *mplayer){
	box(money,0,0);
	attron(A_BOLD);
	mvwprintw(money,1,65,"Money: %d$ / %d$ ",mplayer->get_money(),mplayer->get_money_max());	
	//attroff(A_BOLD);
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

void Window::menu_up(){ //moves headlight up
    if(menu_headlight>0){
	--menu_headlight;
    }
}

void Window::menu_down(){ //moves headlight down
    if(menu_type==0 && menu_headlight<5){
	++menu_headlight;
    }
    if(menu_type==1 && menu_headlight<mshop->size_potion()){
	++menu_headlight;
    }
    if(menu_type==2 && menu_headlight<mshop->size_food()){
	++menu_headlight;
    }
    if(menu_type==3 && menu_headlight<mshop->size_upgrade()){
	++menu_headlight;
    }
    if(menu_type==4 && menu_headlight<3){
	++menu_headlight;
    }
    if(menu_type==5 && menu_headlight<2){
	++menu_headlight;
    }
    if(menu_type==6 && menu_headlight<2){ //to quit menu
	++menu_headlight;
    }
}

void Window::selected(){
	/*
	 *	Menu types:
	 *	0 - main menu
	 *	1 - Alchemist
	 *	2 - Shop
	 *	3 - Upgrades
	 *	4 - Tavern
	 *	5 - Bank
	 *	6 - Quit
	 */
	int *data; //declaring pointer (of array)
	if(menu_type==0){ //options from main menu
	    menu_type=menu_headlight+1;
	    menu_headlight=0;
	}
	else{
	    if(menu_type!=0 && menu_headlight+1==1) menu_type=0; //BACK TO MAIN MENU
	    if(menu_type>0 && menu_type<5){ //options for shop
		if(menu_type==1) data=mshop->get_potions(menu_headlight-1); //assigning pointer to array
		if(menu_type==2) data=mshop->get_food(menu_headlight-1); //assigning pointer to array
		if(menu_type==3) data=mshop->get_upgrades(menu_headlight-1); //assigning pointer to array
		if(data[1]>0){ //if quantity is > 0 that means item is aviliable
		   if(mplayer->get_money()>data[0]){ // if player can afford this
	               mplayer->add_money(data[0]*-1); //price * -1 to substract money
		       if(menu_type==1){ //if in alchemist
			   mshop->buy_potion(menu_headlight-1);
			   mplayer->add_strength_max(data[2]);
		       }
		       if(menu_type==2){ //if in shop
	    		    mshop->buy_food(menu_headlight-1);
			    mplayer->add_strength(data[2]);
		       }
		       if(menu_type==3){ //if in Upgrades
			    mshop->buy_upgrade(menu_headlight-1);
			    mplayer->add_upgrade(data[2]);
			    mplayer->add_exp(data[3]);
			    for(int i=0; i<data[4]; ++i){
				mplayer->add_level();
			    }
		       }
		   }
		   else{
		       draw_popup("You don't have enough money!");
		   }
		}
		else{
		draw_popup("Item is not available yet!");
		}

	    }
	    if(menu_type==4){
		if(menu_headlight==1){
		    if(mplayer->get_money()>=mplayer->get_worker_price()){
			//mplayer->buy_worker();
		    }
		    else{
			draw_popup("You don't have enough money!");
		    }
		}
		if(menu_headlight==2){
		    if(mplayer->get_worker()>=0){
			if(mplayer->get_money()>=mplayer->get_worker_upgrade_price()){
			    //mplayer->buy_worker_upgrade();
			}
			else{
			    draw_popup("You don't have enough money!");
			}
		    }
		    else{
			draw_popup("Buy worker first!");
		    }
		}
	    }
	    if(menu_type==5){
		if(mplayer->get_money()>=mplayer->get_money_max()/5){
		    if(menu_headlight==1){
			mplayer->add_money(mplayer->get_money_max()/5*-1);
			mplayer->upgrade_bank();
		    }
		}
		else{
		    draw_popup("You don't have enough money!");
		}
	    }
	    if(menu_type==6){
		if(menu_headlight==1){ //exit without save
			mplayer->add_end(1);
		}
		if(menu_headlight==2){ //exit with save
			fstream save_file;
			save_file.open("./saves/save",ios::out);

			save_file<<"_Welcome in the save file!_"<<endl;
			save_file<<"============================"<<endl;
			save_file<<mplayer->get_upgrade()<<endl;
			save_file<<mplayer->get_strength()<<endl;
			save_file<<mplayer->get_strength_max()<<endl;
			save_file<<mplayer->get_money()<<endl;
			save_file<<mplayer->get_money_max()<<endl;
			save_file<<mplayer->get_level()<<endl;
			save_file<<mplayer->get_exp()<<endl;
			save_file<<mplayer->get_exp_level()<<endl;
			save_file<<mplayer->get_game_time()<<endl;
			save_file<<mplayer->get_shop_time()<<endl;
			save_file<<mplayer->get_worker()<<endl;
			save_file<<mplayer->get_worker_upgrade()<<endl;
			save_file<<mplayer->get_worker_upgrade_price()<<endl;
			save_file<<mplayer->get_worker_price()<<endl;
			save_file<<"_____END_OF_SAVE_FILE_____"<<endl;
			save_file.close();
			save_file.clear();
			mplayer->add_end(1);
		}
	    }
	}
	wclear(main_menu); //clear menu to avoid mistakes in render
	draw_menu();
	refresh_main_menu();
}

