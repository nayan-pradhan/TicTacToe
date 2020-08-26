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
                        int row = entered_number/grid_size;
                        int col = entered_number%grid_size;
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
                    std::cout << "Congradulations! " << previous_grid << " has won!" << std::endl;
                    quitFN();
                }

            }
        }

        void quitFN() {
            std::cout << "\nThank you for playing!\n" << std::endl;
            exit(0);
        }

        Game() {
            make_grid();

            while (1) {
                print_grid();
                check_wins(); 
                ask_turn();
            }
        }
};

int main() {
    Game game ;
}