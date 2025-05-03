
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "save_load_game.h"
#include "game.h"
using namespace std;
using std::endl;
using std::cout;
using std::ios;
using std::vector;

bool load_file(int& gs) {
	string line, last_line;
	std::ifstream load("save.dat",ios::in);
	if (!load.is_open()) {
		return false; //check if the file fail to open
	}
	while (getline(load, line)) {
		last_line = line;
	}
	gs = stoi(last_line);
	load.close();
	return true;
}//load_file(success)

void save_file(vector<vector<char>>p) {
	time_t now = time(0);
	char* dt = ctime(&now);
	std::ofstream save("save.dat", ios::out | ios::app);
	char* row_arr = new char[26](); //Gameboard( with maximum 26* 26)
	char* col_arr = new char[26]();

	for (size_t i = 0; i != row; i++) {
		row_arr[i] = 65 + i;			//ACSII of A-Z(the for loop in the folllowing is the same)

	}
	for (size_t i = 0; i != column; i++) {
		col_arr[i] = 65 + i;
	}
	save << "============================================================" << endl;
	save << "GameTime: " << dt << endl;
	if (gamemode == '0') {
		save << endl;
		save << "Gamemode : Player VS Player" << endl;
		save << "Wineer : Player" << player << endl;

	}
	else if (gamemode == '1') {
		save << "Gamemode: Player VS AI(Easy)" << endl;
		{
			if (player == ai) {
				save << "Winner: AI (Easy mode)" << endl;

			}
			else {
				save << "Winner: Player" << endl;
			}
		}
	}
	else if (gamemode == '2') {
		save << "Gamemoade: Player VS AI(Difficult)" << endl;
		if (player == ai) {
			save << "Winner: AI(Difficult moade)" << endl;
		}
		else {
			save << "Winner:Player" << endl;

		}
	}
	else if (gamemode == '3') {
		save << "Gamemoade: Player VS AI(Master)" << endl;
		if (player == ai) {
			save << "Winner : AI (MasterMode)" << endl;
		}
		else {
			save << "Winner: Player" << endl;
		}
	}
	save << "Board Size:" << row << "x" << column << endl << endl;
	save << "|	|";
	for (size_t i = 0; i != column; i++) {
		save << col_arr[i] << "|";
	}
	save << endl;
	for (size_t i = 0; i != row; i++) {
		save << "|" << row_arr[i] << "|";
		for (size_t j = 0; j != column; j++) {
			if (p[i][j] == '1') {
				save << black_chess << "|";
			}
			else if (p[i][j] == '2') {
				save << white_chess << "|";
			}
			else {
				save << p[i][j] << "|";
			}
			save << endl;
		}
	}// save the file (figuring out saved as which mode)
	save << endl;
	save << game_score << endl;
	delete[] row_arr;
	delete[] col_arr;
	save.close(); //end_save
	}
