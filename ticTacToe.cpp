#include <iostream>
#include <string>

#define grid_size 3

class Game {

    private:

        char grid[grid_size][grid_size];

    public:

        void greet() {
            std::string player1;
            std::string player2;
            std::cout << "\nx-x-x-x-x-x-x-x-x-x-    TIC TAC TOE    -x-x-x-x-x-x-x-x-x-x" << std::endl;
        }

        void make_grid() {
            int elem = 1;
            for (int i = 0; i < grid_size; i++) {
                for (int j = 0; j < grid_size; j++) {
                    grid[i][j] = std::to_string(elem).c_str()[0];
                    elem++;
                }
            }
        }

        void print_grid() {
            std::cout << std::endl;
            for (int i = 0; i < grid_size; i++) {
                for (int j = 0; j < grid_size; j++) {
                    if (j == 2) {
                        std::cout << grid[i][j];
                    }
                    else {
                        std::cout << grid[i][j] << " | ";
                    }
                }
                std::cout << std::endl;
                if (i != 2) {
                    std::cout << "__  __  __" << std::endl;
                }
            }
            std::cout << std::endl;
        }

        void ask_turn(char ch) {
            std::string input;
            
            // checks if there are any moves left or not
            int counter = 0;
            for (int i = 0; i < grid_size; i++) {
                for (int j = 0; j < grid_size; j++) {
                    if (grid[i][j] == 'X' || grid[i][j] == 'O') {
                        counter++;
                        if (counter == 9) {
                            std::cout << "Sorry out of moves!" << std::endl;
                            quitFN();
                        }
                    }
                }
            }

            while(1) {
                std::cout << "Player " << ch << "'s turn. Which position would you like to play?\n-> ";
                getline(std::cin, input);
                if (input == "quit") {
                    quitFN();
                }
                if (input != "") {
                    char entered = input.c_str()[0];
                    if (entered >= '1' && entered <= '9') {
                        int entered_number = entered - '1'; // converting char to int from range 0-8
                        int row = entered_number/grid_size;
                        int col = entered_number%grid_size;
                        char grid_position = grid[row][col];                        
                        if (grid_position == 'X' || grid_position == 'O') {
                            std::cout << "Sorry, position taken!" << std::endl;
                        }
                        else {
                            grid[row][col] = ch;
                            break;
                        }
                    }
                    else {
                        std::cout << "Please enter a valid position!" << std::endl;
                    }
                }  
                else {
                    std::cout << "Please enter something!" << std::endl;
                }
            }  
        }

        void check_wins() {
            const char *winning_moves[8] = {
                "123", "456", "789",
                "147", "258", "369",
                "159", "753"
            };
            for (int i = 0; i < 8; i++) {
                bool winner = true;
                char previous_grid = '0';
                const char *winning_move = winning_moves[i];
                for (int j = 0; j < grid_size; j++) {
                    char character = winning_move[j];
                    int digit = character - '1';
                    int row = digit/grid_size;
                    int col = digit%grid_size;
                    char grid_char = grid[row][col];
                    if (previous_grid == '0') {
                        previous_grid = grid_char;
                    }
                    else if (previous_grid == grid_char) {
                        continue;
                    }
                    else {
                        winner = false;
                        break;
                    }
                }
                if (winner) {
                    std::cout << "Congratulations! " << previous_grid << " has won!" << std::endl;
                    quitFN();
                }
            }
        }

        void quitFN() {
            std::string play_again;

            while (1) {
                std::cout << "Do you want to play again? (Y/n)? -> ";
                getline(std::cin, play_again);
                if (play_again == "Y") {
                    Game();
                } 
                else if (play_again == "n") {
                    std::cout << "\nThank you for playing!\n" << std::endl;
                    std::cout << "Designed by Nayan Man Singh Pradhan\n" << std::endl;
                    exit(0);
                }
                else {
                    std::cout << "Please enter Y for 'Yes' and n for 'No'. ";
                    continue;
                }
            }

        }

        Game() {

            greet();
            make_grid();

            while (1) {
                print_grid();
                check_wins(); 
                ask_turn('X');
                print_grid();
                check_wins();
                ask_turn('O');
            }
        }
};

int main() {
    Game game ;
}