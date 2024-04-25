#include <iostream>
#include "splashkit.h"

struct MykiCard {
    int id;
    double balance;
    bool status;
};


void check_balance(const MykiCard &card) {
    write_line("Current Balance:");
    write_line(card.balance);
}

void top_up(MykiCard &card) {
    check_balance(card);
    write_line("How much to top up (in dollars)");
    card.balance += convert_to_double(read_line());
    write_line("New Balance");
    check_balance(card);
}

void touch_card(MykiCard &card) {
    if (card.status == true){
        write_line("Card touched on already");
        card.status = false;
        write_line("Touching off... Card touched off now...");
    }
    else
    {
        write_line("Card has not been touched yet...");
        card.status = true;
        write_line("Touching on... Card touched on now...");
    }
}

void show_menu(){
    write_line("---Welcome to myki system---");
    write_line("1.Check Balance");
    write_line("2.Top Up");
    write_line("3.Touch on/off");
}


int main() {
    MykiCard card;
    card.id = 1;
    card.balance = 20.0;
    card.status = false;

    show_menu();
    write_line("select from the menu");
    int choice = convert_to_integer(read_line());
    switch (choice)
    {
    case 1:
        check_balance(card);
        break;
    case 2:
        top_up(card);
        break;
    case 3:
        touch_card(card);
        break;
    default:
        break;
    }
    return 0;
}