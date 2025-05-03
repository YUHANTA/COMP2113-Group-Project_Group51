# COMP2113-Group-Project_Group51
This is a game based on five in a row and created by Yu Hanshiyang and Ma Jinhao. We try to combine the game and AI to make this game more fun.

![](https://img.shields.io/badge/Language-C%2B%2B11-blue.svg)

> The only limit is your own imagination.
>
> -Ready Player One

[Team_Member_contribution](#Team_Member_contribution)

[Game Description](#Game_Description)

[Game Rules](#Game_Rules)

[Game Features](#Game_Feature)

[Explanation](#Explanation)

Demonstration Video:

## Team_Member_contribution

* **Yu Hanshiyang (Implemention of menu and main codes; Design and Implemention of game method 3 and 4; Code improvement and makefile coding)**

* **Ma Jinhao (Desigh and Implemention of game method 1 and 2; Design and Implemention of save/load part)**

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

## Game_Feature (Reaching the requirements of the project)
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
