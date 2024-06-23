// File Name: GameState.cpp
//
// Author: Kusum Bhattarai Sharma
// Date: 04/29/2024
// Assignment Number: 4
// Instructor: Xiaomin Li
//
// GameState represents the current state of a tic tac toe game that allows
// players to undo the most recent of their opponents moves.
// It maintains the current game board and a stack of the currently active
// moves in the game.  It can record a move, and undo a move, and it
// can return the number current player (0 or 1), and also determine
// if the player who made the most recent move has won the game.
#include <iostream>
using namespace std;

#include "GameState.h"
#include "GameState.h"

GameState::GameState() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            boardState[i][j] = '_';
        }
    }
}

int GameState::getCurrentPlayer() {
    return moveStack.getSize() % 2;
}

int GameState::addMove(Move move) {
    int x = move.x;
    int y = move.y;

    if (boardState[x][y] != '_') {
        return -1; // Invalid move
    }

    boardState[x][y] = getCurrentPlayer() ? 'x' : 'o';
    moveStack.push(move);

    if (moveStack.getSize() == 9) {
        return 0; // Draw
    }

    return 1; // Valid move
}

bool GameState::undoLast() {
    if (moveStack.getSize() == 0) {
        return false; // No moves to undo
    }

    Move lastMove = moveStack.top();
    moveStack.pop();

    int x = lastMove.x;
    int y = lastMove.y;
    boardState[x][y] = '_';

    return true;
}

void GameState::displayBoardState(std::ostream& out) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out << boardState[i][j];
        }
        out << std::endl;
    }
}

bool GameState::checkLastPlayerWin() {
    char targetSymbol = getCurrentPlayer() ? 'o' : 'x'; // Swap the target symbol
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i){
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j){
            sumHorizontal += boardState[i][j] == targetSymbol;
            sumVertical += boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i){
        sumDiagonal1 += boardState[i][i] == targetSymbol;
        sumDiagonal2 += boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}