// 2113-five in a row group 51
#ifndef COMP2113_Goup_Project_Group51
#define COMP2113_Goup_Project_Group51
#include <vector>
#include <string>
using namespace std;
using std::vector;
using std::string;

typedef int LENGTH;

#define black_chess "\xe2\x97\x8f"
#define white_chess "\xe2\x97\x8e"

extern LENGTH column;
extern LENGTH row;

extern char gamemode;
extern char player;
extern char ai;
extern unsigned step_count;
extern int game_score;

extern vector<vector<char>> board;

void swap_player(char& p);
int judge(vector<vector<char>> b, int n);
void print_board(vector<vector<char>> p);
int make_move(vector<vector<char>>& p, string move);
void BoardSize(LENGTH &r, LENGTH &c);
#endif
