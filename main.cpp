#include <iostream>
#include <string>
#include <vector>
#include "game.h"
#include "save_load_game.h"
#include "Threeaimode.h"
#include "menu.h"

using namespace std;


vector<vector<char>> board;                    //define a 2D vector board to store chess position.
LENGTH column= 13;
LENGTH row = 6;

char gamemode = 'x';
char player = '1';
char ai = '0';
unsigned step_count = 0;
int game_score = 0;

void build_board(vector<vector<char>>& p) // define an empty board
{
    vector<char> board_temp;
    for (size_t i = 0; i != column; i++)
        board_temp.push_back(' ');            //row
    for (size_t i = 0; i != row; i++)
        p.push_back(board_temp);              //column
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

int make_move(vector<vector<char>>& p, string move)
{
    size_t row_location_letter, column_location_letter;
    if (move.size() == 2 )           //valid move
    {
        if (toupper(move[0]) >= 65 && toupper(move[0]) <= 65+row && toupper(move[1]) >= 65 && toupper(move[1]) <= 65+column)
        {
            //covert alphabet to number
            row_location_letter = toupper(move[0]) - 65;    //row
            column_location_letter = toupper(move[1]) - 65; //column
        }
        else
            return -1;      // make no change, i.e. PASS
    }
    else
        return -1;          // make no change, i.e. PASS
    if (p[row_location_letter][column_location_letter] == ' ')
    {
        p[row_location_letter][column_location_letter] = player;
        return 0;           // make change success
    }
    else
        return -1;          // make no change, i.e. PASS
}

int judge(vector<vector<char>> b, int n)
{
    char c = '1';
    for (int chess = 1; chess != 3; chess++) //                     chess = 1 for player 1 ; chess = 2 for player 2
    {
        for (size_t i = 0; i <= row-1; i++)
        {
            for (size_t j = 0; j <= column - 5; j++)
            {
                if (b[i][j] == c && b[i][j + 1] == c && b[i][j + 2] == c && b[i][j + 3] == c && b[i][j + 4] == c) //check row
                    return chess;
            }
        }
        for (size_t i = 0; i <= row-5; i++)
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
                if (b[i][j] == c && b[i + 1][j + 1] == c && b[i + 2][j + 2] == c && b[i + 3][j + 3] == c && b[i + 4][j + 4] == c) // check diagonal1
                    return chess;
            }
        }
        for (size_t i = 0; i <= row - 5; i++)
        {
            for (size_t j = 4; j <= column - 1; j++)
            {
                if (b[i][j] == c && b[i + 1][j - 1] == c && b[i + 2][j - 2] == c && b[i + 3][j - 3] == c && b[i + 4][j - 4] == c) // check diagonal2
                    return chess;
            }
        }
        c = '2'; // check player '2'.
                                        // 'return 1' indicates player '1' wins while 'return 2' indicates player '2' wins.
    }
    if (n == row*column)
        return 3; // the board if full and no win, end in a draw
    else
        return 0; //unfinished
}

void swap_player(char& p)
{
    if (p == '1')
        p = '2'; // X -> 0
    else p = '1';// 0 -> X
}

int p_v_p(){
    string move;
    instruction();
    print_board(board);
    while (judge(board, step_count) == 0)
    {
        cout << "Player " << player << ", move: ";
        cin >> move;
        if (make_move(board, move) == 0)
        {
            cout << endl;
            print_board(board);
            step_count++;
        }
        else
            cout << "Player " << player << " PASS." << endl;
        swap_player(player);
    }
    switch (judge(board, step_count))
    {
        case 1:
            cout << "player 1 win" << endl;
            break;
        case 2:
            cout << "player 2 win" << endl;
            break;
        case 3:
            cout << "draw" << endl;
            break;
        default:
            break;
    }
    return 0;
}

void BoardSize(LENGTH &r, LENGTH &c)
{
    LENGTH tempr, tempc;
    cout << "Enter Board size you want with format XX YY, please make sure both XX and YY are between 5 - 26" << endl;
    cout << "XX = row, YY = column" << endl;
    cin >> tempr >> tempc;
    while ((tempr < 5 || tempr > 26) || (tempc < 5 || tempc > 26)){
        cout << "Your input is invalid, Please input again" << endl;
        cout << "Enter Board size you want with format XX YY please make sure both XX and YY are between 5 - 26" <<endl;
        cout << "XX = row, YY = column" << endl;
        cin >> tempr >> tempc;
    }
    r = tempr;
    c = tempc;
}


void InitialLoadFunc(bool &tutorial){
    string yn;
    if (load_file(game_score))
        cout << "Players, welcome back, your current score is " << game_score << endl;
    else{
        cout << "Found that you have no save (new players), do you need to tutorial? (Y/N): ";
        cin >> yn;
        while (yn != "YES" && yn != "Y" && yn != "NO" && yn != "N" && yn != "yes" && yn != "no" && yn != "y" && yn != "n"){
            cout << "Invalid input, please input again" << endl;
            cout << "Do you need to tutorial? (Y/N): ";
            cin >> yn;
        }
        if (yn == "YES" || yn == "Y" || yn == "y" || yn == "yes")
            tutorial = true;
        else if (yn == "NO" || yn == "N" || yn == "n" || yn == "no")
            tutorial = false;
    }
}

bool start_new_game(){
    string yn;
    cout << "Do you want to play again? (Y/N): ";
    cin >> yn;
    while (yn != "YES" && yn != "Y" && yn != "NO" && yn != "N" && yn != "yes" && yn != "no" && yn != "y" && yn != "n"){
        cout << "Invalid input, please input again" << endl;
        cout << "Do you want to play again? (Y/N): ";
        cin >> yn;
    }
    if (yn == "YES" || yn == "Y" || yn == "y" || yn == "yes")
        return true;
    else if (yn == "NO" || yn == "N" || yn == "n" || yn == "no")
        return false;
    return false;
}

int main() {
    bool tutorial = false;
    Welcome();

    //************* BE CAREFUL!!!!!
    New_game:
    //************* BE CAREFUL!!!!!

    InitialLoadFunc(tutorial);
    if (tutorial){
        tut_func();
    }

    select_mode(gamemode);
    BoardSize(row, column);
    build_board(board);

    if (gamemode == '1'){
        cout << "You are playing with PLAYER" << endl << endl;
        p_v_p();
    }

    else if (gamemode == '2'){
        cout << "You are playing with AI (EASY)" << endl << endl;
        p_v_a1(game_score);
    }

    else if (gamemode == '3'){
        cout << "You are playing with AI (HARD)" << endl << endl;
        p_v_a2(game_score);
    }
    else{
        cout << "You are playing with AI (HARD)" << endl << endl;
        p_v_a3(game_score);
    }

    congratulations();
    swap_player(player);
    save_file(board);

    //************* BE CAREFUL!!!!!
    if (start_new_game()){
        board.clear();          //construct new board to avoid bugs
        goto New_game;
    }
    //************* BE CAREFUL!!!!!

    return 0;
}
