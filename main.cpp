#include <iostream> // allows players to interact with gameboard
#include <string> //data to fill contailer
#include <vector> //container for set pieces
#include <cstdlib> //used for clearing the terminal

int main() {
  int column = 7;
  int row = 6;

  //Self explanatory variables. decidedes how many rows and columns the board will have. 

  std::string board[row][column]; //initalization of board

  for (int i = 0; i < row; i++) {         //fill board with "white space" or "blank spaces";
    for (int j = 0; j < column; j++) {
      board[i][j] = " - ";
    }
  }

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
  
  int swap_counter = 0; //counter that counts how many tokens have been places. currently used to end the game, but will 
  //determine ties in the future
  int column_number; //variable player uses to decide which column to pick
  std::string token;  //string that determines which token will be used
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
      
      system("clear"); //clears the terminal to display key info (board, text, etc.)

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

  
    for (int i = 0; i < row; i++) {          //prints board
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
  swap_counter++;
  std::cout << "There are " << (row * column) - swap_counter << " tokens left\n";
  }
}
