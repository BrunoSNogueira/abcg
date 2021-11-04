#include "tic_tac_toe.hpp"

#include <cstdio>
#include <cstdlib>

#include "fmt/core.h"

void TicTacToe::Restart() {
    board.fill(' ');
    turn = 'X';
    win = 0;
    draw = false;
    inPlay = true;
}

void TicTacToe::Select(int counter) {
    if(counter < 0 || countr > 8) return;
    if(!inPlay) return;
    if(board.at(counter) != ' ') return;

    board.at(counter) = turn;
    turn = turn == 'X' ? 'O' : 'X';
    /*
    same as:
    if(turn == 'X') turn = 'O';
    else turn = 'X';
    */

   checkWin();
}

char TicTacToe::getTurn() const { return turn; }
bool TicTacToe::isInPlay() const { return inPlay; }
bool TicTacToe::isDraw() const { return draw; }
char TicTacToe::getWinner() const { return win; }
char TicTacToe::getValueAt(int counter) const { return board.at(counter); }

void checkWin() {
  if (board.at(0) != ' ' && board.at(0) == board.at(1) &&
      board.at(1) == board.at(2)) {
    winner = board.at(0);
    playing = false;
    return;
  }

  if (board.at(3) != ' ' && board.at(3) == board.at(4) &&
      board.at(4) == board.at(5)) {
    winner = board.at(3);
    playing = false;
    return;
  }

  if (board.at(6) != ' ' && board.at(6) == board.at(7) &&
      board.at(7) == board.at(8)) {
    winner = board.at(6);
    playing = false;
    return;
  }

  if (board.at(0) != ' ' && board.at(0) == board.at(3) &&
      board.at(3) == board.at(6)) {
    winner = board.at(0);
    playing = false;
    return;
  }

  if (board.at(1) != ' ' && board.at(1) == board.at(4) &&
      board.at(4) == board.at(7)) {
    winner = board.at(1);
    playing = false;
    return;
  }

  if (board.at(2) != ' ' && board.at(2) == board.at(5) &&
      board.at(5) == board.at(8)) {
    winner = board.at(2);
    playing = false;
    return;
  }

  if (board.at(0) != ' ' && board.at(0) == board.at(4) &&
      board.at(4) == board.at(8)) {
    winner = board.at(0);
    playing = false;
    return;
  }

  if (board.at(2) != ' ' && board.at(2) == board.at(4) &&
      board.at(4) == board.at(6)) {
    winner = board.at(2);
    playing = false;
    return;
  }

  if (board.at(0) != ' ' && board.at(1) != ' ' && board.at(2) != ' ' &&
      board.at(3) != ' ' && board.at(4) != ' ' && board.at(5) != ' ' &&
      board.at(6) != ' ' && board.at(7) != ' ' && board.at(8) != ' ') {
    draw = true;
    playing = false;
    return;
  }
}