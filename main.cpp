#include <iostream> // allows players to interact with gameboard
#include <string> //data to fill contailer
#include <vector> //container for set pieces
#include <cstdlib> //used for clearing the terminal
#include <chrono> //used to allow messages to display for a short amount of time
#include <thread> //

void print_row(std::vector<std::string> row) {
  for(int i = 0; i < row.size(); i++){
  std::cout << "|" <<row.at(i) << "|";
  }
  std::cout <<"\n";
}

void insert_token(std::vector<std::string> row, int column_number, std::string token_piece) {
  row.erase(row.begin() + column_number);
  row.insert(row.begin() + column_number, token_piece);
}

int main() {
  std::vector<std::string> row_1,row_2,row_3,row_4,row_5,row_6;
  for(int i = 0; i < 7; i++){
    row_1.push_back(" - ");
  }

  for(int i = 0; i < 7; i++){
    row_2.push_back(" - ");
  }

  for(int i = 0; i < 7; i++){
    row_3.push_back(" - ");
  }

  for(int i = 0; i < 7; i++){
    row_4.push_back(" - ");
  }

  for(int i = 0; i < 7; i++){
    row_5.push_back(" - ");
  }

  for(int i = 0; i < 7; i++){
    row_6.push_back(" - ");
  }
  system("clear");
  print_row(row_6);
  print_row(row_5);
  print_row(row_4);
  print_row(row_3);
  print_row(row_2);
  print_row(row_1);
  std::cout << "  1    2    3    4    5    6    7\n";
  
  int swap_counter = 0;
  int column_number;
  std::string token;
  std::string Token_One = " X ";
  std::string Token_Two = " O ";

  while (swap_counter != 42) {
    std::cout << "Enter a valid column number \n";
    std::cin >> column_number;
      while(column_number > 7 || column_number < 0){
        std::cout << "Invalid Number. Please enter a valid column number \n";
        std::cin >> column_number;
      }
      int column_number_minus = column_number - 1;
      
     
      if (swap_counter % 2 == 0){
        token = Token_One;
      } else {
        token = Token_Two;
      }

      if(column_number >= 1 && column_number <= 7) {
          if (row_6.at(column_number - 1) == Token_One || row_6.at(column_number - 1) == Token_Two){ 
          std::cout << "Column is full. Please pick a different column number \n";
          std::this_thread::sleep_for(std::chrono::seconds(3));

          } else if (row_5.at(column_number - 1) == Token_One || row_5.at(column_number - 1) == Token_Two) {
                row_6.erase(row_6.begin() + column_number_minus);
                row_6.insert(row_6.begin() + column_number_minus, token);
                swap_counter++;
          } else if(row_4.at(column_number - 1) == Token_One || row_4.at(column_number - 1) == Token_Two) {
                row_5.erase(row_5.begin() + column_number_minus);
                row_5.insert(row_5.begin() + column_number_minus, token);
                swap_counter++;
          } else if(row_3.at(column_number - 1) == Token_One || row_3.at(column_number - 1) == Token_Two) {
                row_4.erase(row_4.begin() + column_number_minus);
                row_4.insert(row_4.begin() + column_number_minus, token);
                swap_counter++;
          } else if(row_2.at(column_number - 1) == Token_One || row_2.at(column_number - 1) == Token_Two) {
                row_3.erase(row_3.begin() + column_number_minus);
                row_3.insert(row_3.begin() + column_number_minus, token);
                swap_counter++;
          } else if(row_1.at(column_number - 1) == Token_One || row_1.at(column_number - 1) == Token_Two) {
                row_2.erase(row_2.begin() + column_number_minus);
                row_2.insert(row_2.begin() + column_number_minus, token);
                swap_counter++;
          } else {
                row_1.erase(row_1.begin() + column_number_minus);
                row_1.insert(row_1.begin() + column_number_minus, token);
                swap_counter++;
          }
    }
  
  system("clear");
  print_row(row_6);
  print_row(row_5);
  print_row(row_4);
  print_row(row_3);
  print_row(row_2);
  print_row(row_1);
  std::cout << "  1    2    3    4    5    6    7\n";

  std::cout << "There are " << 42 - swap_counter << " tokens left\n";
  }
}
