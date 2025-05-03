#include <iostream>
#include <string>
#include <vector>
#include "main.h"
#include "Threeaimode.h"
#include "menu.h"
#include "save_load_game.h"

using namespace std;

vector<vector<char>> board;
LENGTH colomn = 13;         //Basis setting
LENGTH row = 6;             //define a vector board

char gamemode = 'x';
char player = '1';
char ai = '0';
int game_score = 0;
unsigned step_count = 0;

void build_board(vector<vector<char>>&p){
     vector<char> board_temp;
     for (size_t  i = 0; i < column; i++) 
         board_temp.push_back(' ');
     for (size_t i = 0; i < row; i++)
         p.push_back(board_temp);
}

void print_board(vector<vector<char>> p)
{
    char *row_arr = new char[26]();            //MAX = 26
    char *col_arr = new char[26]();            //MAX = 26

    for (size_t i = 0; i != row; i++)
    {
        row_arr[i] = 65 + i;                    // A-Z = 65-90 (ASCII)
    }

    for (size_t i = 0; i != column; i++)
    {
        col_arr[i] = 65 + i;                    // A-Z = 65-90 (ASCII)
    }

    //output part
    cout << "| |";
    for (size_t i = 0; i != column; i++)
    {
        cout << col_arr[i] << '|';
    }
    cout << endl;

    for (size_t i = 0; i != row; i++)
    {
        cout << '|' << row_arr[i] << '|';
        for (size_t j = 0; j != column; j++)
            if (p[i][j] == '1')
                cout << black_chess << '|';
            else if (p[i][j] == '2')
                cout << white_chess << '|';
            else
                cout << p[i][j] << '|';
        cout << endl;
    }
    cout << endl;
    //release memory
    delete [] row_arr;
    delete [] col_arr;
}

void BoardSize(LENGTH &r, LENGTH &c){
     LENGTH a, b;
     cout << "Enter Board size you want with format XX YY, please make sure both XX and YY are between 5 - 26" << endl;
     cout << "It's recommented to make XX = YY, but anyway you can use what you like. Just like ths saying 'This Game is Your World!'" << endl;
     cout << "Hint: XX = row, YY = column" << endl;
     cin >> a >> b;
     while ((a < 5 || b > 26) || (b < 5 || b > 26)){
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
       else return -1; //no change
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

int p_v_p(){
    string move;
    print_board(board);
    while (judge(board, step_count) == 0){
          cout << "Player " << player << ",move: ";
	  cin >> move;
	  if (make_move(board, move) == 0){
	     cout << endl;
	     print_board(board);
	     step_count++;
	  }
	  else{
	  cout << "Player " << player << "PASS." << endl;
	  }
	  swap_player(player);
    }
    switch (judge(board, step_count)){
           case 1: 
	      cout << "player 1 win" << endl;
	   case 2:
	      cout << "player 2 win" << endl;
	   case 3:
	      cout << "draw" << endl;
	   default:
	      break;
    }
    return 0;
}

bool start_new_game(){
     string x;
     cout << "Your performance is perfect! How about playing another game? (Y/N):";
     cout << endl << "Pay attention please: You should input Y or N;" << endl;
     cout << "Now, your choice:";
     cin >> x;
     if (x == "Y") return true;
     else return false;
     return false;
}

void InitialLoadFunc(bool &hongkong){
     string y;
     if (load_file(game_score))
     {   cout << "Players, welcome back,your current score is " << game_score << endl;
     }
     else{
         cout << "You have new players and no save, do you need our tutorial class. Don't worry it will not occupy too much time.(Y/N): ";
	 cin >> y;
	 if (y == "Y") hongkong = true;
	 else if (y == "N") hongkong = false;
	 else{ 
	    cout << "Invalid intput and we will begin our tutorial clss automatically.";
            hongkong = true;
	 }
	}
}

int main(){
    Welcome() //code in menu
    //******
    New_game:
    //*****

    bool hongkong = false;
    InitialLoadFunc(hongkong); //bool transfer value
    if (hongkong){
       tut_func();
    }

    select_mode(gamemode);
    BoardSize(row,column);
    build_board(board);

    if (gamemode == "0"){
       BoardSize(row, column);
       build_board(board);
       cout << "You are playing with Player" << endl;
       cout << endl;
       instruction();
       p_v_p()
    }
    else if (gamemode == '1'){
       BoardSize(row, column);
       build_board(board);
       cout << "You are playing with Ai - Easy method" << endl;
       cout << endl;
       p_v_a1(game_score);
    }
    else if (gamemode == '2'){
       BoardSize(row, column);
       build_board(board);
       cout << "You are playing with Ai - Difficult method" << endl;
       cout << "Wish you lucky!" << endl;
       cout << endl;
       p_v_a2(game_score);
    }
    else{
       cout << "In this method, you will fight master ai in 15 x 15 standard board" << endl;
       row = 15;
       column = 15;
       build_board(board);
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
