#include "Board.cpp"
#include <iostream>

using namespace std;

class Game
{
private:
    Board board;

public:
    void start()
    {
        cout << "2048 Game Started! Use 0 (Left), 1 (Right), 2 (Up), 3 (Down) to move.\n\n";
        board.printBoard();

        while (true)
        {
            int move;
            cout << "Enter your move (0-3): ";
            cin >> move;

            if (!board.makeMove(move))
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            board.printBoard();

            if (board.hasWon())
            {
                cout << "Congratulations! You've won the game!\n";
                break;
            }

            if (!board.hasMovesLeft())
            {
                cout << "Game Over! No more moves left.\n";
                break;
            }
        }
    }
};