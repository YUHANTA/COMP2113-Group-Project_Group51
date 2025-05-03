#include<iostream>
#include<string>
#include "menu.h"
#include "game.h"
#include "save_load_game.h"
using std::cout;
using std::endl;
using std::string;
using std::cin;

void Welcome() {
    cout << "Welcome to gobang!" << endl;
    cout << "Hope you will have a great time" << endl;
    cout << "Be sure not to be destroyed by out Master AI" << endl;
        }

void instruction() {
    cout << "please make a balid move, else PASS" << endl;
    cout << "Please enter moves by instructions like AA , AB , BC , where the first letter indicates row number and the second indicates the column";
}
void tut_func() {
    cout << "Here is the basic rules" << endl;
    cout << "Players (you) and your opponent (wether human or ai) take turns to put a chess in an empty spot" << endl;
    cout << "Once there are 5 pieces of the same color in a line(vertical,horizonal, or even diagonal)!" << endl;
    cout << "Please be aware that if the entered position is invalid, your turn will be automatically skipped(PASS)" << endl;
    cout << "save.dat will exist in the current folder as soon as your gaame ends" << endl;
    cout << "We have AI for your, beat them and have respective scores!" << endl;
    cout << "Easy : 10 points , Hard : 100 Master : 200" << endl;
}

void select_mode(char& gamemode) {
    string temp = "0";
    cout << "╔═══════════════════════════════════════" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                                    GOBANG !                                  ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                      1. Player vs Player                                     ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                      2. Gamemode 1: Player vs AI (Easy)                      ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                      3. Gamemode 2: Player vs AI (Hard)                      ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                      4. Gamemoade 3:Player vs AI (Master)                    ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "╚═══════════════════════════════════════" << endl;   
    cout << "Please select gamemode(1 / 2 / 3 / 4):";
    cin >> temp;
   
    while (temp != "1" && temp !="2" && temp!="3" && temp !="4") {
        cout << "Not valid gamemode, we can tell us if you want to add, please eneter a gamemode in the list above" << endl;
        cin >> temp;
    }
    temp = std::to_string(std::stoi(temp) -1);
    }
void congratulations() {
    cout << R"( _____                                   _           _         _    _                      _ )" << endl;
    cout << R"(/  __ \                                 | |         | |       | |  (_)                    | |)" << endl;
    cout << R"(| /  \/  ___   _ __    __ _  _ __  __ _ | |_  _   _ | |  __ _ | |_  _   ___   _ __   ___  | |)" << endl;
    cout << R"(| |     / _ \ | '_ \  / _` || '__|/ _` || __|| | | || | / _` || __|| | / _ \ | '_ \ / __| | |)" << endl;
    cout << R"(| \__/\| (_) || | | || (_| || |  | (_| || |_ | |_| || || (_| || |_ | || (_) || | | |\__ \ |_|)" << endl;
    cout << R"( \____/ \___/ |_| |_| \__, ||_|   \__,_| \__| \__,_||_| \__,_| \__||_| \___/ |_| |_||___/ (_))" << endl;
    cout << R"(                       __/ |                                                                 )" << endl;
    cout << R"(                      |___/                                                                  )" << endl << endl;
}
