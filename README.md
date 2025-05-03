# COMP2113-Group-Project_Group51
This is a game based on five in a row and created by Yu Hanshiyang and Ma Jinhao. We try to combine the game and AI to make this game more fun.

![](https://img.shields.io/badge/Language-C%2B%2B11-blue.svg)

> The only limit is your own imagination.
>
> -Ready Player One

[Team_Member_contribution](#Team_Member_contribution)

[Game Description](#Game_Description)

[Game_Rules](#Game_Rules)

[Game Feature](#Game_Feature)

[Additional Explanation](#Additional_Explanation)

Demonstration Video:


https://github.com/user-attachments/assets/14f765e2-bbf7-4efe-ab30-36d93b41d314



## Team_Member_contribution

* **Yu Hanshiyang (Implemention of main.cpp; Design and Implemention of game method; Code improvement and makefile coding)**

* **Ma Jinhao (Desigh and Implemention of game menu; Design and Implemention of save/load part)**

## Game_Description
	   _____  ____  ____          _   _  _____ 
	  / ____|/ __ \|  _ \   /\   | \ | |/ ____|
	 | |  __| |  | | |_) | /  \  |  \| | |  __ 
	 | | |_ | |  | |  _ < / /\ \ | . ` | | |_ |
	 | |__| | |__| | |_) / ____ \| |\  | |__| |
	  \_____|\____/|____/_/    \_\_| \_|\_____|
                                           
Gobang, also called Five in a Row, is an abstract strategy board game. 
The goal is to line up 5 pieces of the same color as quickly as possible on the board
## Game_Rules
1 Players (Or AI) will take turn to place a piece of the corresponding color(or chess) in the board, and the first player who makes 5 in a line( whether vertical, horizonal, or diagnosal) will win the game,
2. If you enter an invalid game ( including out of the board), your turn will automatically pass.
3. After eache game is completed, save.dat will exist in the current folder.
4.If you choose to match with our AI, you will receive points. There are three mode, easy(10points)，hard(100points), master(200 points).
p.s. Don't be afraid of fogetting the rules, it will be shown agian when you are experiencing our game.

## Game_Feature
Code requirements:
1. Generation of random events:
   	These are including in the AI mode of our game, all three modes are random movements by ai.
   	Player who starts is random
2. Data structures of storing data:
   	Chess board/position is stored as vector
   	Row and column number are stored in array
3. Dynamic memory management
	Customizable Boardsize using new and delete
	Board is in vector
4. File input/output
   	Data is saved in save.dat (other file)
   	Load file(without the first time) to have user score
5. Program codes in multiple files
   	Functions( different functions to be involved in the game, such as welcome page, ai mode, and others) are stored in different files
6. Multiple Difficulty Levels:
   	Different ai modes: Easy , Hard and Master

## Additional Explanation
### Defined Global Variables
```cpp
#define black_chess "\xe2\x97\x8f"
#define white_chess "\xe2\x97\x8e"
typedef int	LENGTH;
LENGTH column = 13;    //default column
LENGTH row = 6;		//default row

char gamemode = 'x';
char player = '1';
char ai = '0';
unsigned step_count = 0;
int game_score = 0;
```

### Game_flow
1. Board is a 2d vector defined by:
```cpp
vector<vector<char>> board;
```
2. Every time the game starts, it will first check if there is save.dat, if any, load the score in save.dat
```cpp
InitialLoadFunc(tut)
```
if user is first into game, optional provide tutorial.

3. Call ```select_mode``` function defined in menu.cpp
```cpp
void select_mode(char &gamemode)
```
this function changed the gamemode(global variable) which entered by users

4. call ```BoardSize``` fuction to let user define board size.
```cpp
void BoardSize(LENGTH &r, LENGTH &c)
```
this function accept global variable row and column, and the value using pass by reference.

**We assume player input valid number here.**


5. call ```construct_board``` function defined in main to construct a board.
```cpp
void construct_board(vector<vector<char>>& p)
```
this function accept global variable board, and assign ```' '``` to the board until the size needed.

6. According to the game mode entered by the user, the corresponding mode is called
```
player_vs_player()

player_vs_ai1()

player_vs_ai2()
```
mode are encapsulated in three different functions


7. Inside the mode function, ```print_board``` is called after every valid move.
```cpp
//print_board
char *row_arr = new char[26]();            //MAX = 26
char *col_arr = new char[26]();            //MAX = 26
```
Create the corresponding array according to the required number of rows and columns, after printing, delete it to release memory.
```cpp
delete [] row_arr;
delete [] col_arr;
```

8. After game is completed, call ```save_file``` function to save won board in save.dat.

**All game records will be saved to save.dat**

save.dat format example:
```
=====================================================
GameTime: Fri May  6 01:55:33 2022


Gamemode: Player VS Player
Winner: Player 1
Board Size :12x14

| |A|B|C|D|E|F|G|H|I|J|K|L|M|N|
|A|●| | | | | | | | | | | | | |
|B| |●| | | | | | | | | | | | |
|C| | |●| | | | | | | | | | | |
|D| | | |●| | | | | | | | | | |
|E| | | | |●| | | | | | | | | |
|F| | | | | | | | | | | | | | |
|G| | | | | | | | | | | | | | |
|H| | | | | | | | | | | | | | |
|I| | | | | | | | | | | | | | |
|J| | | | | | | | | | | | | | |
|K| | | | | | | | | | | | | | |
|L| | | | | | | | | | | | | | |

0
```

8. Ask the user if he wants to play again.

## AI_explaination
1. Easy mode.

Basically use the random function to generate two numbers within the range of row and column.
Use if there is no chess in the generated position, regenerate if there is.


2. Hard mode

Hardmode AI scores each position and then determines the best position.

*Idea from internet

Score table in defined as:
```cpp
static const int Score[3][6] = {
        { 0, 0,  0,  0,   0,10000 },
        { 0, 0, 20,100, 3000,10000 },
        { 0,25,125,500,2500,10000 }
};
```
corresponding pattern:
| 0 chess | 1 chess | 2 chess | 3 chess | 4 chess | 5 chess |
|---------|---------|---------|---------|---------|:-------:|
|    xx   |   xox   |   xoox  |  xooox  |  xoooox | xooooox |
|    x_   |   xo_   |   xoo_  |  xooo_  |  xoooo_ | xooooo_ |
|    _    |    o    |    oo   |   ooo   |   oooo  |  ooooo  |

```AI_Cal_Score``` function Calculate the score for the corresponding position.

```Ai_best_move``` function pass all location in board to ```AI_Cal_Score``` and find the location of the largest score, put it into vector, if there are same score position, using random function to pick any one of it.



## Compile Instructions

Run ```make game``` to compile the game.

Do ```./game``` to start the game.

Run ```make clean``` to clean all the generated fil
 
