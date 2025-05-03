#include <string>
#include "Threeaimode.h"
#include "game.h"
#include "menu.h"
#include <iostream>
#include <time.h>

using namespace std;

stastic const int score[3][6] = {
        {0,0,0,0,0,10000},
	{0,0,20,100,3000,10000},
	{0,25,125,500,2500,10000}
};

static const int inX[] = {1,0,1,1};
static const int inY[] = {0,1,1,-1};

void random_role(char &ai){
     srand((unsigned)time(NULL));
    cout << "Your order of play is being randomly generated..." << endl;
    int order = rand()%2 + 1;
    if (order == 1){
        cout << "You are in the first-order, please make a move FIRST." << endl;
        ai = '2';
    }
    else{
        cout << "You are in the second-order, please make a move AFTER." << endl;
        ai = '1';
    }
}

//direct searching method
int AI_Cal_Score(vector<vector<char>> p, int x, int y, char chess){
    int r = 0;
    for (int i = 0; i < 4; i++){                                                //search for four direction
        int s = 0;                                                              //record the space
        int count = 0;                                                          //record the chess
        for (int j = -1; j < 2; j+=2){                                          //opposite direction of four direction
            int dx = x + j * inX[i];
            int dy = y + j * inY[i];
            while (dx >= 0 && dx < p.size() && dy >= 0 && dy < p[0].size()){
                if (p[dx][dy] == chess)                                         //count +1 if same colour
                    count++;
                else{
                    if (p[dx][dy] == ' ')
                        s++;                                                   //s+1 if null
                    break;
                }
                dx += j * inX[i];
                dy += j * inY[i];
            }
        }
        if (count > 5) count = 5;
        r += Score[s][count];                                                   //sum the score for each direction
    }
    return r;
}

//scores to judge ai's move, idea from essay and internet
//Thanks for them and this function has been used in difficult and master
void Ai_best_move(int &x, int &y, vector<vector<char>> p){
    int max_score = -1;
    srand((unsigned)time(NULL));
    int rxy;
    vector<int> X;
    vector<int> Y;
    for (int i = 0; i < p.size(); i++){                         //search for row
        for (int j = 0; j < p[i].size(); j++){                  //search for column
            if (p[i][j] == ' '){
                int score = max(AI_Cal_Score(p, i, j, '1'), AI_Cal_Score(p, i, j, '2'));    //find the best position for chess of two colour
                if (score >= max_score){                    //same score
                    if (score > max_score){                 //if better
                        X.clear();
                        Y.clear();
                        max_score = score;                  //use better one
                    }
                    X.push_back(i);                         //push_back the position of all same best positions
                    Y.push_back(j);
                }
            }
        }
    }
    rxy = rand()% X.size();                     //in case more than one best place.
    x = X[rxy];
    y = Y[rxy];
}

//fantastic work! Master method - the most difficult one in a standard board
int p_v_a3(int &gs){
    string move, saw, step2;
    srand((unsigned)time(NULL));
    instruction();
    cout << "It's the master method, so you will move after the ai. Wish you lcuky!" << endl;
    ai = 1;                                //ai = 1 for AI moves first
    print_board(board);
    turnnumber = 0;
    while (judge(board, step_count) == 0)
    {
        if (turnnumber == 0){
	   move = "HH"
	   cout << "AI, move: " << move << endl;
	   cout << endl;
	   if (make_move(board, move) == 0{
	      print_board(board);
	      step_count++;
	   }
	   else cout << "AI pass." << endl;
	}
	
	if (turnnumber == 2){
	   if (saw == "GG" || saw == "GH" || saw == "HG"){
	     move = "II"
	     cout << "AI, move: " << move << endl;
             cout << endl;
	     make_move(board, move);
             print_board(board);
	     step_count++;
           }
	   else if (saw == "II" || saw == "HI" || "IH"){
	     move = "GG";
	     cout << "AI, move: " << move << endl;
	     cout << endl;
	     make_move(board, move);
	     print_board(board);
	     step_count++;
	   }
	   else if (saw == "IG"){
	     move = "GI";
	     make_move(board, move);
             cout << "AI, move: " << move << endl;
             cout << endl;
             print_board(board);
             step_count++;
	   }
	   else if (saw == "GI"){
	     move = "IG";
	     make_move(board, move);
             cout << "AI, move: " << move << endl;
             cout << endl;
             print_board(board);
             step_count++;
	   }
	   else{
	     move = "GG";
	     make_move(board, move);
             cout << "AI, move: " << move << endl;
             cout << endl;
             print_board(board);
             step_count++;
	   }
	   step2 = move;
	}
	
	if (turnnumber == 4){
	  if (step2 == "II"){
	        if (saw != "IH" && saw != "IG" && sawa != "IH" && sawa != "IG"){
		  move = "IG";
		  make_move(board, move);
		  cout << "AI, move: " << move << endl;
		  cout << endl;
		  print_board(board);
		  step_count++;
		}
		else if (saw != "GI" && saw != "HI" && sawa != "GI" && sawa != "HI"){
		  move = "GI";
		  make_move(board, move);
		  cout << "AI, move: " << move << endl;
		  cout << endl;
		  prin_board(board);
		  step_count++;
		}
		else if (saw != "GG" && sawa != "GG")
		{ move = "II";
	          cout << "AI, move: " << move << endl;
	          cout << endl;
	          make_move(board, move);
	          print_board(board);
	          step_count++;
		}
		else{
		    int x = 0,y = 0;
                    Ai_best_move(x, y, board);
                    move = x + 65;                                      //convert move to alphabet
                    move += y + 65;
                    make_move(board, move);
                    cout << "AI, move: " << move << endl;
                    cout << endl;
                    print_board(board);
                    step_count++;
		 }
          }
	  else if(step2 == "GG") {
	        if (saw != "IG" && saw != "HG" && sawa != "IG" && sawa != "HG"){
		  move = "IG";
		  make_move(board, move);
		  cout << "AI, move: " << move << endl;
		  cout << endl;
		  print_board(board);
		  step_count++;
		}
		else if (saw != "GI" && saw != "GH" && sawa != "GI" && sawa != "GH"){
		  move = "GI";
		  make_move(board, move);
		  cout << "AI, move: " << move << endl;
		  cout << endl;
		  prin_board(board);
		  step_count++;
		}
		else if (saw != "II" && sawa != "II")
		{ move = "II";
	          cout << "AI, move: " << move << endl;
	          cout << endl;
	          make_move(board, move);
	          print_board(board);
	          step_count++;
		}
		else{
		    int x = 0,y = 0;
                    Ai_best_move(x, y, board);
                    move = x + 65;                                      //convert move to alphabet
                    move += y + 65;
                    make_move(board, move);
                    cout << "AI, move: " << move << endl;
                    cout << endl;
                    print_board(board);
                    step_count++;
		 }
          }
	 else if(step2 == "IG") {
	        if (saw != "GG" && saw != "HG" && sawa != "GG" && sawa != "HG"){
		  move = "GG";
		  make_move(board, move);
		  cout << "AI, move: " << move << endl;
		  cout << endl;
		  print_board(board);
		  step_count++;
		}
		else if (saw != "IH" && saw != "II" && sawa != "II" && sawa != "IH"){
		  move = "II";
		  make_move(board, move);
		  cout << "AI, move: " << move << endl;
		  cout << endl;
		  prin_board(board);
		  step_count++;
		}
		else if (saw != "GI" && sawa != "GI")
		{ move = "GI";
	          cout << "AI, move: " << move << endl;
	          cout << endl;
	          make_move(board, move);
	          print_board(board);
	          step_count++;
		}
		else{
		    int x = 0,y = 0;
                    Ai_best_move(x, y, board);
                    move = x + 65;                                      //convert move to alphabet
                    move += y + 65;
                    make_move(board, move);
                    cout << "AI, move: " << move << endl;
                    cout << endl;
                    print_board(board);
                    step_count++;
		 }
          }
	 else if(step2 == "GI") {
	        if (saw != "GH" && saw != "GG" && sawa != "GH" && sawa != "GG"){
		  move = "GG";
		  make_move(board, move);
		  cout << "AI, move: " << move << endl;
		  cout << endl;
		  print_board(board);
		  step_count++;
		}
		else if (saw != "HI" && saw != "II" && sawa != "HI" && sawa != "II"){
		  move = "II";
		  make_move(board, move);
		  cout << "AI, move: " << move << endl;
		  cout << endl;
		  prin_board(board);
		  step_count++;
		}
		else if (saw != "IG" && sawa != "IG")
		{ move = "IG";
	          cout << "AI, move: " << move << endl;
	          cout << endl;
	          make_move(board, move);
	          print_board(board);
	          step_count++;
		}
		else{
		    int x = 0,y = 0;
                    Ai_best_move(x, y, board);
                    move = x + 65;                                      //convert move to alphabet
                    move += y + 65;
                    make_move(board, move);
                    cout << "AI, move: " << move << endl;
                    cout << endl;
                    print_board(board);
                    step_count++;
		 }
          }
	  else {
	        if (saw != "GG" && saw != "HG" && sawa != "GG" && sawa != "HG"){
		  move = "GG";
		  make_move(board, move);
		  cout << "AI, move: " << move << endl;
		  cout << endl;
		  print_board(board);
		  step_count++;
		}
		else if (saw != "IH" && saw != "II" && sawa != "IH" && sawa != "II"){
		  move = "II";
		  make_move(board, move);
		  cout << "AI, move: " << move << endl;
		  cout << endl;
		  prin_board(board);
		  step_count++;
		}
		else if (saw != "GI" && sawa != "GI")
		{ move = "GI";
	          cout << "AI, move: " << move << endl;
	          cout << endl;
	          make_move(board, move);
	          print_board(board);
	          step_count++;
		}
		else{
		    int x = 0,y = 0;
                    Ai_best_move(x, y, board);
                    move = x + 65;                                      //convert move to alphabet
                    move += y + 65;
                    make_move(board, move);
                    cout << "AI, move: " << move << endl;
                    cout << endl;
                    print_board(board);
                    step_count++;
		 }
          }
        }

        if (player != ai){
            cout << "Player move: ";
            cin >> move;
            if (turnnumber == 1 || turnnumber == 3 || turnnumber == 5){
	       saw = move;
	       if (turnnumber == 1) sawa = move;
	    }
            if (make_move(board, move) == 0)
            {
                cout << endl;
                print_board(board);
                step_count++;
            }
            else
                cout << "Player PASS." << endl;
        }

        else if (player == ai){
            int x = 0,y = 0;
            Ai_best_move(x, y, board);
            move = x + 65;                                      //convert move to alphabet
            move += y + 65;
            make_move(board, move);
            cout << "AI, move: " << move << endl;
            cout << endl;
            print_board(board);
            step_count++;
        }
        swap_player(player);
	turnnumber++;
    }
    switch (judge(board, step_count))
    {
        case 1:
            if (ai == '1')
                cout << "player AI win" << endl;
            else{
                cout << "player win" << endl;
                gs += 100;
            }
            break;
        case 2:
            if (ai == '2')
                cout << "player AI win" << endl;
            else{
                cout << "player win" << endl;
                gs += 100;
            }
            break;
        case 3:
            cout << "draw" << endl;
            break;
        default:
            break;
    }
    return 0;
}

int p_v_a2(int &gs){
    string move;
    srand((unsigned)time(NULL));
    instruction();
    random_role(ai);                                //ai = 1 for AI moves first, = 2 for player moves first
    print_board(board);
    while (judge(board, step_count) == 0)
    {
        if (player != ai){
            cout << "Player move: ";
            cin >> move;

            if (make_move(board, move) == 0)
            {
                cout << endl;
                print_board(board);
                step_count++;
            }
            else
                cout << "Player PASS." << endl;

        }

        else if (player == ai){
            int x = 0,y = 0;
            Ai_best_move(x, y, board);
            move = x + 65;                                      //convert move to alphabet
            move += y + 65;
            make_move(board, move);
            cout << "AI, move: " << move << endl;
            cout << endl;
            print_board(board);
            step_count++;
        }
        swap_player(player);
    }
    switch (judge(board, step_count))
    {
        case 1:
            if (ai == '1')
                cout << "player AI win" << endl;
            else{
                cout << "player win" << endl;
                gs += 100;
            }
            break;
        case 2:
            if (ai == '2')
                cout << "player AI win" << endl;
            else{
                cout << "player win" << endl;
                gs += 100;
            }
            break;
        case 3:
            cout << "draw" << endl;
            break;
        default:
            break;
    }
    return 0;
}

int p_v_a1(int &gs){
    string move;
    srand((unsigned)time(NULL));
    instruction();
    random_role(ai);                                    //ai = 1 for AI moves first, = 2 for player moves first
    print_board(board);
    while (judge(board, step_count) == 0)
    {
        if (player != ai){
            cout << "Player move: ";
            cin >> move;

            if (make_move(board, move) == 0)
            {
                cout << endl;
                print_board(board);
                step_count++;
            }
            else
                cout << "Player  PASS." << endl;
        }

        else if (player == ai){
            move = rand()%row + 65;                                    //convert move to alphabet
            move += rand()%column + 65;
            while (make_move(board, move) != 0){                    //if not a valid move
                move = rand()%6 + 65;                                 //regenerate
                move += rand()%13 + 65;
            }
            cout << "AI, move: " << move << endl;
            cout << endl;
            print_board(board);
            step_count++;
        }
        swap_player(player);
    }
    switch (judge(board, step_count))
    {
        case 1:
            if (ai == '1')
                cout << "player AI win" << endl;
            else{
                cout << "player 1 win" << endl;
                gs += 10;
            }
            break;
        case 2:
            if (ai == '2')
                cout << "player AI win" << endl;
            else{
                cout << "player 2 win" << endl;
                gs += 10;
            }
            break;
        case 3:
            cout << "draw" << endl;
            break;
        default:
            break;
    }
    return 0;
}
