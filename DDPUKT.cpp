#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int SIZE = 3;

// Function prototypes
void InitializeBoard(char gameBoard[][SIZE]);
void Display(char gameBoard[][SIZE]);
bool BoardIsFull(char gameBoard[][SIZE]);
bool Assign(char gameBoard[][SIZE], int x, int y, char p);
char CheckWon(char gameBoard[][SIZE]);

int main()
{
    char turn;
    int x, y;
    char gameBoard[SIZE][SIZE];

    // Call the function InitializeBoard to Initialize the game board pieces to blanks
    InitializeBoard(gameBoard);

    // Prompt players to enter their names
    string Player1, Player2;
    cout << "Let's play Tic-Tac-Toe!\nPlayer 1 enter your name: ";
    cin >> Player1;
    cout << Player1 << ", you are X's! You will also have the first turn.\n";

    cout << "Player 2, enter your name: ";
    cin >> Player2;
    cout << Player2 << ", you are O's!\n\n";

    // Randomly determine who is to start the game
    int t = rand() % 2;
    turn = (t == 1) ? 'X' : 'O';
    cout << "Game Starts!" << endl;

    // Display the initial game board on screen
    Display(gameBoard);

    // The game is played between two players until one of two cases occurs:
    // (1) the board is completely filled with pieces from the player, and no winner is determined.
    // (2) one player wins the game
    while (!BoardIsFull(gameBoard) && (CheckWon(gameBoard) == 'n'))
    {
        // Prompt the player to enter the position to play the next move
        // The move is validated in the inner loop.
        // Only if a move is valid, it will be assigned to the game board
        do
        {
            cout << "Player " << turn << " makes the next move." << endl;
            cout << "To choose a position enter in the row number [SPACE] then the column number: ";
            cin >> x >> y;
        } while (x > 2 || x < 0 || y > 2 || y < 0 || !Assign(gameBoard, x, y, turn));

        // Show the updated game board
        Display(gameBoard);

        // Determines the player for the next move
        turn = (turn == 'X') ? 'O' : 'X';
    }

    // Display the result of the game
    if (CheckWon(gameBoard) == 'X')
        cout << "Player X (" << Player1 << ") wins!" << endl;
    else if (CheckWon(gameBoard) == 'O')
        cout << "Player O (" << Player2 << ") wins!" << endl;
    else
        cout << "This is a Draw game!" << endl;

    return 0;
}

// This function initializes all the elements of the game board to blank characters ' '
void InitializeBoard(char gameBoard[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            gameBoard[i][j] = ' ';
        }
    }
}

// This function displays the game board as a 3 by 3 board with coordinates
void Display(char gameBoard[][SIZE])
{
    cout << "     0   1   2";
    cout << endl << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << " " << i << "  ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << gameBoard[i][j];
            if (j < SIZE - 1)
                cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1)
            cout << "   ___|___|___\n";
    }
    cout << "      |   |" << endl;
}

// This function checks to see if all the elements of the game board have been filled
bool BoardIsFull(char gameBoard[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (gameBoard[i][j] == ' ')
            {
                return false; // If any cell is empty, board is not full
            }
        }
    }
    return true; // All cells are filled
}

// This function assigns character p to location (x, y) on the game board
bool Assign(char gameBoard[][SIZE], int x, int y, char p)
{
    if (gameBoard[x][y] == ' ')
    {
        gameBoard[x][y] = p;
        return true; // Move successfully assigned
    }
    else
    {
        cout << "Invalid move. Cell already occupied. Try again." << endl;
        return false; // Move not assigned, cell already occupied
    }
}

// Check if the game is won by checking rows, columns, and diagonals
char CheckWon(char gameBoard[][SIZE])
{
    char won = 'n';

    // Check rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ')
        {
            won = gameBoard[i][0]; // Row win
            break;
        }

        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ')
        {
            won = gameBoard[0][i]; // Column win
            break;
        }
    }

    // Check diagonals
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != ' ')
    {
        won = gameBoard[0][0]; // Diagonal win
    }
    else if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != ' ')
    {
        won = gameBoard[0][2]; // Diagonal win
    }

    return won;
}

