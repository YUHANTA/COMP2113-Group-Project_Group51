#include <iostream>
#include <string>
#include <vector>
#include <math>
#include "main.h"

using namespace std;

vector<vector<char>> board;
LENGTH colomn = 13;         //Basis setting
LENGTH row = 6;             //define a vector board

char gamemode = 'x';
char player = '1';
char ai = '0';
int game_score = 0;
unsighed step_count = 0;

void build_ board(vector<vector<vhar>>&p){
     vector<char> board_temp;
     for (int i = 0; i < column; i++) 
         board_temp.push_back(' ');
     for (int i = 0; i < row; i++0
         p.push_back(board_temp);
}

void print_board(vector<vector<vhar>>&p){
     char *row_air = new char[26]();
     char *col_arr = new char[26]();
     for (int i = 0; i < column; i+=)
         col_arr[i] = 65 + i;
     for (int i = 0; i < row; i++)
         row_arr[i] = 65 + i;
     cout << "| |"
     for (int i = 0; i < colmn; i++)
         cout << col_aor[i] << "|";
     cout << endl;
     for (int i = 0; i < row; i++){
         cout << "|" << row_arr[i] << "|";
	 for (int j = 0; j < column; j++){
	     if (p[i][j] == '1')
	        cout << black_chess << '|';
	     else if (p[i][j] == '2')
	        cout << white_chess << '|';
	     else
	        cout << p[i][j] << '|';
	     cout << endl;
	 } cout << endl;
	 delete [] row_arr;
	 delete [] col_arr;
}

void BoardSize(LENGTH &r, LENGTH &c){
     LENGTH a, b;
     cout << "Enter Board size you want with format XX YY, please make sure both XX and YY are between 5 - 26" << endl;
     cout << "It's recommented to make XX = YY, but anyway you can use what you like. Just like ths saying 'This Game is Your World!'" << endl;
     cout << "Hint: XX = row, YY = column" << endl;
     cin >> a >> b;
     while ((a < 5 || b > 26) || (b < 5 || b > 26){
        cout << "Your input is invalid. Please input again." << endl;
	cout << "Enter Board size you want with formats XX YY, please make sure  both XX and YY are between 5 - 26" << endl;
        cout << "It's recommented to make XX = YY, but anyway you can use what you like. Just like ths saying 'This Game is Your World!'" << endl;
        cout << "Hint: XX = row, YY = column" << endl;
        cin >> a >> b;
     }
     r = a;
     c = b;
}

void swap_player(char& p){
    if (p == '1')
        p = '2'; // X -> 0
    else p = '1';// 0 -> X
}

int make_move(vector<vector<char>>& p, string move){
    size_t row_location_letter, column_location_letter;
    if (move.size() == 2){
       if (toupper(move[0]) >= 65 && toupper(move[0]) <= 65+row && toupper(move[1]) >= 65 && toupper(move[1]) <= 65 + column){
           row_location_letter = toupper(move[0]) - 65; // change A-Z to real row number;
           column_location_letter = toupper(move[1]) - 65;//also same with above-Real column number
       }
       else retuern -1; //no change
    }
    else return -1;
    if (p[row_location_letter][column_location_letter] == ' '){//judge is it a empty place to put this step
        p[row_location_letter][column_location_letter] = player;
	return 0;
    }
    else return -1;
}
int judge(vector<vector<char>> b, int n)
{
    char c = '1';
    for (int chess = 1; chess != 3; chess++)
    {
        for (size_t i = 0; i <= row - 1; i++)
        {
            for (size_t j = 0; j <= column - 5; j++)
            {
                if (b[i][j] == c && b[i][j + 1] == c && b[i][j + 2] == c && b[i][j + 3] == c && b[i][j + 4] == c) //check row
                    return chess;
            }
        }
        for (size_t i = 0; i <= row - 5; i++)
        {
            for (size_t j = 0; j <= column - 1; j++)
            {
                if (b[i][j] == c && b[i + 1][j] == c && b[i + 2][j] == c && b[i + 3][j] == c && b[i + 4][j] == c) // check column
                    return chess;
            }
        }
        for (size_t i = 0; i <= row - 5; i++)
        {
            for (size_t j = 0; j <= column - 5; j++)
            {
                if (b[i][j] == c && b[i + 1][j + 1] == c && b[i + 2][j + 2] == c && b[i + 3][j + 3] == c && b[i + 4][j + 4] == c)
                    return chess;
            }
        }
        for (size_t i = 0; i <= row - 5; i++)
        {
            for (size_t j = 4; j <= column - 1; j++)
            {
                if (b[i][j] == c && b[i + 1][j - 1] == c && b[i + 2][j - 2] == c && b[i + 3][j - 3] == c && b[i + 4][j - 4] == c)
                    return chess;
            }
        }
        c = '2'; 
    }
    if (n == row * column)
        return 3;
    else
        return 0;
}

int main(){
    welcome() //code in menu
    New_game:

    bool hongkong = false;
    InitialLoadFunc(hongkong); //bool transfer value
    if (hongkong){
       tnt_func();
    }

    select_mode(gamemode);
    Boardsize(row,column);
    build_board(board);

    if (gamemode == "0"){
       cout << "You are playing with Player" << endl;
       cout << endl;
       p_v_p()
    }
    else if (game mode == '1'){
       cout << "You are playing with Ai - Easy method" << endl;
       cout << endl;
       p_v_a1(game_score);
    }
    else if (game mode == '2'){
       cout << "You are playing with Ai - Difficult method" << endl;
       cout << "Wish you lucky!" << endl;
       cout << endl;
       p_v_a2(game_score);
    }
    else{
       cout << "You are playing with Ai - Master  method" << endl;
       cout << "Don't lose heart anymore. You can win him" << endl;
       cout << endl;
       p_v_a3(game_score);
    }
    //Assume that game mode cannont be other intput other than 0/1/2/3.

    congratulations();
    swap_player(player);
    save_file(board);

    if (start_new_game()){
       board.clear();
       goto New_game;
    }
     return 0;
}
