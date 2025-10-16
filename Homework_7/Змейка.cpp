#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <ctime>

class SnakeGame {
    int width = 0;
    int height = 0;
    std::deque<std::pair<int, int>> snake;
    std::pair<int, int> food;
    bool hasFood = false;
    bool gameOver = false;
    
    bool isInside(int y, int x) {
        return y >= 0 && x >= 0 && y < height && x < width;
    }
    
    void move(int dy, int dx) {
        if (gameOver) return;

        int newY = snake.front().first + dy;
        int newX = snake.front().second + dx;

        if(!isInside(newY, newX)) {
            std::cout << "\nGame over! Snake hit the wall.\n";
            gameOver = true;
            return;
        }

        for (auto& seg : snake) {
            if (seg.first == newY && seg.second == newX) {
                std::cout << "\nGame over! Snake hit itself.\n";
                gameOver = true;
                return;
            }
        }

        snake.push_front({newY, newX});

        if (hasFood && newY == food.first && newX == food.second) {
            hasFood = false;
            spawnFood(); 
        } else {
            snake.pop_back(); 
        }
    }
    
public:
    SnakeGame(int width, int height, int startY, int startX) 
        : width(width)
        , height(height) {
            if(!isInside(startY, startX)) {
                throw std::invalid_argument("Invalid start position!");
            }
            std::srand(std::time(nullptr));
            snake.push_back({startY, startX});
            spawnFood();
        }
        
    void moveUp() { move(-1, 0); }
    void moveDown() { move(1, 0); }
    void moveLeft() { move(0, -1); }
    void moveRight() { move(0, 1); }    
    
    bool isGameOver() const { return gameOver; }
        
    void spawnFood() {
        std::vector<std::pair<int, int>> emptyCells;

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                bool occupied = false;
                for (auto& seg : snake) {
                    if (seg.first == y && seg.second == x) {
                        occupied = true;
                        break;
                    }
                }
                if (!occupied) emptyCells.push_back({y, x});
            }
        }

        if (emptyCells.empty()) {
            hasFood = false;
            std::cout << "You win! Snake filled the board.\n";
            gameOver = true;
            return;
        }

        food = emptyCells[std::rand() % emptyCells.size()];
        hasFood = true;
    }
    
    void print() const {
        std::vector<std::vector<char>> board(height, std::vector<char>(width, '.'));

        if (hasFood) board[food.first][food.second] = '*';

        for (int i = 0; i < snake.size(); ++i) {
            int y = snake[i].first;
            int x = snake[i].second;
            board[y][x] = (i == 0 ? '@' : 'O');
        }
        
        std::cout << std::endl;
        for(auto& line : board) {
            for(char el : line) {
                std::cout << el << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    SnakeGame game(7, 7, 3, 3);
    char cmd;
    
    while (!game.isGameOver()) {
        game.print();
        std::cout << "Move (w/a/s/d): ";
        std::cin >> cmd;

        switch (cmd) {
            case 'w': game.moveUp(); break;
            case 's': game.moveDown(); break;
            case 'a': game.moveLeft(); break;
            case 'd': game.moveRight(); break;
            default: std::cout << "Invalid move!\n";
        }
    }
    return 0;
}

