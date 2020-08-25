#include <iostream>
#include <string>

#define grid_size 3

class Game {

    private:

        char grid[grid_size][grid_size];

    public:

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

        void ask_turn() {
            std::string input;
            while(1) {
                std::cout << "Which position would you like to play?\n-> ";
                getline(std::cin, input);
                if (input == "quit") {
                    quitFN();
                }
                if (input != "") {
                    char entered = input.c_str()[0];
                    if (entered >= '1' && entered <= '9') {
                        int entered_number = entered - '1'; // converting char to int from range 0-8
                        int row = entered_number/3;
                        int col = entered_number%3;
                        char grid_position = grid[row][col];                        
                        if (grid_position == 'X' || grid_position == 'O') {
                            std::cout << "Sorry, position taken!" << std::endl;
                        }
                        else {
                            grid[row][col] = 'X';
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

        void quitFN() {
            std::cout << "Thank you for playing!" << std::endl;
            exit(-1);
        }

        Game() {
            make_grid();

            while (1) {
                print_grid();
                ask_turn();
            }
        }
};

int main() {
    Game game ;
}