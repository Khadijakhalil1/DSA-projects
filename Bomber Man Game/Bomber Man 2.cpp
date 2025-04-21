#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

const int GRID_SIZE = 10;

enum CellType { EMPTY, WALL, PLAYER, BOMB, EXPLOSION };

struct Cell {
    CellType type;
};

class GameGrid {
private:
    vector<vector<Cell>> grid;
public:
    GameGrid() {
        grid.resize(GRID_SIZE, vector<Cell>(GRID_SIZE, {EMPTY}));
    }

    void printGrid() {
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                char display = ' ';
                switch (grid[i][j].type) {
                    case EMPTY: display = '.'; break;
                    case WALL: display = '#'; break;
                    case PLAYER: display = 'P'; break;
                    case BOMB: display = 'B'; break;
                    case EXPLOSION: display = 'X'; break;
                }
                cout << display << " ";
            }
            cout << endl;
        }
    }

    void setCell(int x, int y, CellType type) {
        grid[x][y].type = type;
    }

    CellType getCell(int x, int y) {
        return grid[x][y].type;
    }
};

class Player {
private:
    int x, y;
public:
    Player(int startX, int startY) : x(startX), y(startY) {}

    void move(char direction, GameGrid &grid) {
        int newX = x, newY = y;
        switch (direction) {
            case 'w': newX--; break;
            case 's': newX++; break;
            case 'a': newY--; break;
            case 'd': newY++; break;
        }

        if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE) {
            if (grid.getCell(newX, newY) == EMPTY) {
                grid.setCell(x, y, EMPTY);  // Clear old position
                x = newX;
                y = newY;
                grid.setCell(x, y, PLAYER); // Set new position
            }
        }
    }

    void placeBomb(GameGrid &grid) {
        grid.setCell(x, y, BOMB);
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

class Bomb {
private:
    int x, y;
public:
    Bomb(int posX, int posY) : x(posX), y(posY) {}

    void explode(GameGrid &grid) {
        grid.setCell(x, y, EXPLOSION);
        if (x > 0) grid.setCell(x-1, y, EXPLOSION);
        if (x < GRID_SIZE-1) grid.setCell(x+1, y, EXPLOSION);
        if (y > 0) grid.setCell(x, y-1, EXPLOSION);
        if (y < GRID_SIZE-1) grid.setCell(x, y+1, EXPLOSION);

        grid.printGrid();

        this_thread::sleep_for(chrono::seconds(1));

        // Clear explosion after showing it
        grid.setCell(x, y, EMPTY);
        if (x > 0) grid.setCell(x-1, y, EMPTY);
        if (x < GRID_SIZE-1) grid.setCell(x+1, y, EMPTY);
        if (y > 0) grid.setCell(x, y-1, EMPTY);
        if (y < GRID_SIZE-1) grid.setCell(x, y+1, EMPTY);
    }
};

int main() {
    GameGrid grid;
    Player player(1, 1);
    grid.setCell(1, 1, PLAYER);

    char input;
    while (true) {
        grid.printGrid();
        cout << "Move (WASD) or Place Bomb (B): ";
        cin >> input;

        if (input == 'b' || input == 'B') {
            player.placeBomb(grid);
            Bomb bomb(player.getX(), player.getY());
            bomb.explode(grid);
        } else {
            player.move(input, grid);
        }
    }

    return 0;
}

