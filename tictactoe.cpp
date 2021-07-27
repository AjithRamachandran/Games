/**
 * Tic Tac Toe Game Implemented in C++
 * Copyright 2018, Ajith Ramachandran, ajithar204@gmail.com
 *
 * This software is released under the terms of the
 * GNU LGPL license. See http://www.gnu.org/licenses/lgpl.html
 * for more information.
 *
 * */

#include <iostream>

const char empty = '-';
char ttt[3][3];

bool checkHorizontal() {
    if(((ttt[0][0]==ttt[0][1])&&(ttt[0][1]==ttt[0][2])&&(ttt[0][1]!=empty))||((ttt[1][0]==ttt[1][1])&&(ttt[1][1]==ttt[1][2])&&(ttt[1][1]!=empty))||((ttt[2][0]==ttt[2][1])&&(ttt[2][1]==ttt[2][2])&&(ttt[2][2]!=empty)))
        return true;
    else
        return false;
}

bool checkVertical() {
    if(((ttt[0][0]==ttt[1][0])&&(ttt[1][0]==ttt[2][0])&&(ttt[0][0]!=empty))||((ttt[0][1]==ttt[1][1])&&(ttt[1][1]==ttt[2][1])&&(ttt[0][1]!=empty))||((ttt[0][2]==ttt[1][2])&&(ttt[1][2]==ttt[2][2])&&(ttt[0][2]!=empty)))
        return true;
    else
        return false;
}

bool checkDiagonal() {
    if(((ttt[0][0]==ttt[1][1])&&(ttt[1][1]==ttt[2][2])&&(ttt[0][0]!=empty))||((ttt[0][2]==ttt[1][1])&&(ttt[1][1]==ttt[2][0])&&(ttt[1][1]!=empty)))
        return true;
    else
        return false;
}

bool checkWin() {
    if(checkHorizontal() || checkVertical() || checkDiagonal())
        return true;
    else
        return false;
}

void showVector() {
    system("clear");
    for(int t=0;t<3;t++) {
        std::cout<<ttt[t][0]<<" | "<<ttt[t][1]<<" | "<<ttt[t][2]<<std::endl;
    }
}

void user() {
    int userx, usery;
    std::cout << "Enter the coordinate to put 'X'";
    std::cin >> userx >> usery;
    if ((userx < 0 || userx > 2) || (usery < 0 || usery > 2)) {
        std::cout << "Please enter a valid input!!" << std::endl;
        user();
    }
    else if(ttt[userx][usery] != empty) {
        std::cout << "Cell is not empty!" << std::endl;
        user();
    }
    else {
        ttt[userx][usery] = 'X';
        if(checkWin()) {
            showVector();
            std::cout<<"You won!"<<std::endl;
            exit(EXIT_SUCCESS);
        } else
        showVector();
    }
}

void comp() {
    int compx, compy;
    compx = rand() % 3;
    compy = rand() % 3;
    if(ttt[compx][compy] != empty)
        comp();
    else {
        ttt[compx][compy] = 'O';
        if(checkWin()) {
            showVector();
            std::cout<<"Computer won!"<<std::endl;
            exit(EXIT_SUCCESS);
        } else
        showVector();
    }
}

int main() {
    int count=0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            ttt[i][j] = empty;
        }
    }
    showVector();
    while(true) {
        if(count%2==0) {
            std::cout<<"Your Turn"<<std::endl;
            user();
            count++;
        }
        else {
            std::cout<<"Computer Turn"<<std::endl;
            comp();
            count++;
        }
    }
    return 0;
}
