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

        Game () {
            make_grid();
            print_grid();
        }
};





int main() {
    Game game ;
}