#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

class Board
{
private:
    vector<vector<int>> grid;
    int size;

    void addRandomTile()
    {
        vector<pair<int, int>> emptyCells;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (grid[i][j] == 0)
                {
                    emptyCells.push_back({i, j});
                }
            }
        }
        if (!emptyCells.empty())
        {
            int index = rand() % emptyCells.size();
            grid[emptyCells[index].first][emptyCells[index].second] = 2;
        }
    }

    void slideAndMerge(vector<int> &row)
    {
        // First, remove zeros and slide numbers to the left
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            if (row[i] != 0)
            {
                temp.push_back(row[i]);
            }
        }

        // Merge adjacent equal numbers
        for (int i = 0; i < temp.size() - 1; i++)
        {
            if (temp[i] != 0 && temp[i] == temp[i + 1])
            {
                temp[i] *= 2;
                temp[i + 1] = 0;
            }
        }

        // Remove zeros created by merging and prepare final row
        vector<int> merged;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] != 0)
            {
                merged.push_back(temp[i]);
            }
        }

        // Clear the input row and fill with new values
        row = vector<int>(size, 0);
        for (int i = 0; i < merged.size(); i++)
        {
            row[i] = merged[i];
        }
    }

    // Why Rotate the Board?
    // Sliding and merging tiles is easy when moving left.
    // Other directions (right, up, down) can be transformed into a left movement by rotating the board.
    // After processing the move, we rotate the board back to its original orientation.
    // How the Rotation Works
    // Moving left (0) → No rotation needed.
    // Moving right (1) → Rotate twice, process, then rotate twice back.
    // Moving up (2) → Rotate left once, process, then rotate right once.
    // Moving down (3) → Rotate right once, process, then rotate left once.

    void rotateClockwise()
    {
        vector<vector<int>> newGrid(size, vector<int>(size));
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                newGrid[j][size - 1 - i] = grid[i][j];
            }
        }
        grid = newGrid;
    }

public:
    Board(int size = 4)
    {
        this->size = size;
        grid.resize(size, vector<int>(size, 0));
        srand(time(0));
        addRandomTile();
        addRandomTile();
    }

    void printBoard()
    {
        for (auto &row : grid)
        {
            for (auto &cell : row)
            {
                cout << (cell ? to_string(cell) : "-") << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool makeMove(int direction)
    {
        if (direction < 0 || direction > 3)
            return false;

        for (int i = 0; i < direction; i++)
            rotateClockwise();

        bool moved = false;

        for (int i = 0; i < size; i++)
        {
            vector<int> oldRow = grid[i];
            slideAndMerge(grid[i]);
            if (oldRow != grid[i])
                moved = true;
        }

        if (moved)
            addRandomTile();

        for (int i = 0; i < (4 - direction) % 4; i++)
            rotateClockwise();

        return moved;
    }

    bool hasWon()
    {
        for (auto &row : grid)
        {
            for (auto &cell : row)
            {
                if (cell >= 2048)
                    return true;
            }
        }
        return false;
    }

    bool hasMovesLeft()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (grid[i][j] == 0)
                    return true;
                if (i > 0 && grid[i][j] == grid[i - 1][j])
                    return true;
                if (j > 0 && grid[i][j] == grid[i][j - 1])
                    return true;
            }
        }
        return false;
    }
};
