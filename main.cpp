#include <iostream> // allows players to interact with gameboard
#include <string> //data to fill contailer
#include <vector> //container for set pieces
#include "connect4.hpp"
//#include <cstdlib> //used for clearing the terminal

void print_board (int column, int row, std::string **board);
bool check_win(int column, int row, std::string **board, std::string player1_token, std::string player2_token);

//global objects for player 1 & 2
player player1; 
player player2; 

int main() {
  int column = 7;
  int row = 6;
    //Self explanatory variables. decidedes how many rows and columns the board will have. 
    //allocate space for 2D array
    std::string **board = new std::string*[row];
    for (int i = 0; i < row; i++) {         //fill board with "white space" or "blank spaces";
     board[i] = new std::string[column];
    }

    for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
        board[i][j] = " - ";
      }
    }
    print_board(column, row, board);
    
    int swap_counter = 0; //counter that counts how many tokens have been places. currently used to end the game, but will 
    //determine ties in the future
    int column_number; //variable player uses to decide which column to pick
    std::string token;  //string that determines which token will be used

    //ask for player input for tokens here instead
    std::string Token_One = " X ";  //player one token, " X " is a place holder for now
    std::string Token_Two = " O ";  //same as above, but for player 2 and also a place holder;


    while (swap_counter != row * column) { //when swap counter is equal to the number of rows and columns, the game is over since there are no more tokens at play
      int row_minus_one = row - 1;  //used for the zero-based arrya
      int row_counter = 0; //used to naviate through the rows
      std::cout << "Enter a valid column number \n";
      std::cin >> column_number;
        while(column_number > column || column_number < 0){  //ensure that the player can't pick a column that doesn't exist. forces them to pick a column;
          std::cout << "Invalid Number. Please enter a valid column number \n";
          std::cin >> column_number;
        }
        
        //system("cls"); //clears the terminal to display key info (board, text, etc.)

        if (swap_counter % 2 == 0){  //since there is only two players,
          token = Token_One;         //we can use % to alternate between
        } else {                     //player 1 and player 2 tokens
          token = Token_Two;
        }
        
        if(board[0][column_number - 1] == Token_One || board[0][column_number - 1] == Token_Two) { //logic to make sure the player the token can be placed in a valid spot

          std::cout << "Column " << column_number << " is full. Please Select a different column \n"; //ensures player can't replace top value
          swap_counter--;
        } else {
          while(board[row_counter][column_number - 1] != Token_One || board[row_counter][column_number - 1] != Token_Two){
          if(row_counter == row_minus_one) { //ensure the while loop does not run forever by placing the last token at the bottom of the row;
            board[row - 1][column_number - 1] = token;
            break;
          } else {
            if(board[row_counter + 1][column_number -1] == Token_One || board[row_counter + 1][column_number - 1] == Token_Two){ //checks one space below
            board[row_counter][column_number - 1] = token; //places token on top the token below it.
            break;
            }
            row_counter++;
      }
          }
      }

  
  print_board(column, row, board);
  
  swap_counter++;
  std::cout << "There are " << (row * column) - swap_counter << " tokens left\n";
  }
  //deallocate board
  for(int i = 0; i < row; i++){
    delete[] board[i];
  }
  delete[] board;
  
  return 0;
}

void print_board (int column, int row, std::string **board){
  for (int i = 0; i < row; i++) {          //print board
        for (int j = 0; j < column; j++) { 
            std::cout << board[i][j]; 
        }
        std::cout << "\n"; 
        int column_num = 1;
      if(i == row - 1){
        for(int k = 0; k < column; k++){
          std::cout << " " << column_num << " ";
          column_num++;
        }
        std::cout << "\n";
      }
  }
  return;
}

bool check_win(int column, int row, std::string **board, std::string player1_token, std::string player2_token){
  int matches = 0;
  std::string winning_token = " ";
  //check rows 
  for(int i = row - 1; i >= 0; i--){ //check from bottom up
    for(int j = 0; j < column; j++){  //check row from left to right
      if(board[i][j] == board[i][j+1]){  //checking pairs adjecent
        matches += 1;
        if(matches == 3){  // need to match 3 pairs to see four in a row
        winning_token = board[i][j+1]; //assign winning_token to last token checked
        break; 
      }
      }
      else{
        matches = 0; //reset matches if one doesnt match
      }
    }
  }
  //check comulmns
  //code

  //check diagnol
  //code

  //if after row, column and diagnol checks if token winning token still empty return false
  if(winning_token == " "){
    return false;  
  }
  else{ // check which player won and print winning statement
    if(winning_token == player1_token){
      player1.print_won();
    }
    else{
      player2.print_won();
    }

    return true; //return true

  }
}
