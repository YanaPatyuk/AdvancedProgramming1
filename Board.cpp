//
// Created by Ori Cohen
// ID: 207375783
//

#include "Board.h"
#include <iostream>
#define NUM_OF_ROWS 8
#define NUM_OF_COLS 8

/**
 * Constructor for board, which initialize the board to E (Empty)
 * cells.
 */
Board::Board() {
// num of rows
  this->board_.resize(NUM_OF_ROWS);
  // num of cols
  for (int i = 0; i < NUM_OF_ROWS; ++i) {
    this->board_[i].resize(NUM_OF_COLS);
  }
}

/**
 * Print method which prints the board as requested.
 */
void Board::Print() const {
  cout << " ";
  for (int i = 0; i < NUM_OF_COLS; i++) {
    cout << "|" << i + 1;
  }
  cout << "|" << endl << "------------------" << endl;
  for (int i = 0; i < NUM_OF_ROWS; i++) {
    cout << i + 1 << "|";
    for (int j = 0; j < NUM_OF_COLS; j++) {
      //cout << j+1 << "|";
      if (board_[i][j] == EnumDeclration::E) {
        cout << " |";
      }
      if (board_[i][j] == EnumDeclration::O) {
        cout << "O|";

      }
      if (board_[i][j] == EnumDeclration::X) {
        cout << "X|";
      }
    }
    cout << endl << "------------------" << endl;
  }
}

/**
 * @param xLocation to get
 * @param yLocation to get
 * @return the status of the given cell (Empty, O, X)
 */
int Board::GetCellStatus(int xLocation, int yLocation) const {
  if (xLocation >= 1 && xLocation <= this->NumOfRows()
      && yLocation >= 1 && yLocation <= this->NumOfCols()) {
    // -1 because array starting from 0
    return this->board_[xLocation - 1][yLocation - 1];
  }
  cout << "Illegal row or col" << endl;
  return -1;
}

/**
 * Set the given cell new status.
 * (if given (4,4) location set new status to board[3][3] location
 * since we print from 1,1 and not 0,0).
 * @param xLocation of the cell
 * @param yLocation of the cell
 * @param status - the new status to set (E, O, X)
 */
void Board::SetCellStatus(int xLocation, int yLocation, EnumDeclration::CellStatus status) {
  // if X or O add it to the vectors which holds list of X/O Slots
  if (status == EnumDeclration::X) {
    this->x_slots_.push_back(Slot(xLocation, yLocation, status));
  } else if (status == EnumDeclration::O) {
    this->o_slots_.push_back(Slot(xLocation, yLocation, status));
  }
  // -1 because array starting from 0
  this->board_[xLocation - 1][yLocation - 1] = status;
}

/**
 * @return number of rows
 */
int Board::NumOfRows() const {
  return this->board_.size();
}
/**
 * @return number of cols
 */
int Board::NumOfCols() const {
  return this->board_[0].size();
}
/**
 * @return vector which contains all the O slots
 */
vector<Slot> Board::GetOSlots() const {
  return this->o_slots_;
}
/**
 * @return vector which contains all the X slots
 */
vector<Slot> Board::GetXSlots() const {
  return this->x_slots_;
}
/**
 * @param row
 * @param col
 * @return if its legal place in board
 */
bool Board::LegalPlaceInBoard(int row, int col) {
  return (row <= NumOfRows() && row > 0
      && col <= NumOfCols() && col > 0);
}
/**
 * @param set new o_slots vector
 */
void Board::SetOSlots(vector<Slot> o_slots) {
  this->o_slots_ = o_slots;
}
/**
 * @param set new x_slots vector
 */
void Board::SetXSlots(vector<Slot> x_slots) {
  this->x_slots_ = x_slots;
}

