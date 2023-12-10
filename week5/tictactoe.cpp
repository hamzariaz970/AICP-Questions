#include <iostream>
#include <stdlib.h>
using namespace std;

class TicTacToe{

    private:
    char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; //grid to hold and display player inputs

    string input;
    int playerChoice; // variable to use for taking player input
    int row, column; // used to determine which row and column in grid will be used for the current turn

    char winningPlayer;
    bool player1_turn = true;
    bool draw = false;
    int moveCounter;
    
    public:
    // initializing the game
    TicTacToe()
    {   cout << "\t\t    TIC TAC TOE" << endl;
        cout <<"\n\n\tPlayer 1 = X\tPlayer 2 = O\n" << endl;
        moveCounter = 0;
    }

    // function to display grid 
    void displayGrid()
    {
        cout << "\t\t|\t\t|\t\t\n";
        cout << "\t"<< grid[0][0] << "\t|" << "\t" << grid[0][1] << "\t|" << "\t" << grid[0][2] << "\t\n";
        cout << "________________|_______________|____________\n";
        cout << "\t\t|\t\t|\t\t\n";
        cout << "\t"<< grid[1][0] << "\t|" << "\t" << grid[1][1] << "\t|" << "\t" << grid[1][2] << "\t\n";
        cout << "________________|_______________|____________\n";
        cout << "\t\t|\t\t|\t\t\n";
        cout << "\t"<< grid[2][0] << "\t|" << "\t" << grid[2][1] << "\t|" << "\t" << grid[2][2] << "\t\n";

    }

    void playerTurn()
    {   
        // checking if player 1 has to take next turn based on boolean value
        if (player1_turn)
        {
            while (true)
            {
                cout << "\n\nPlayer 1 please enter the position where you would like to place 'X': ";
                cin >> input;
                if (input.length() == 1 && isdigit(input[0]))
                {
                    playerChoice = stoi(input);
                    break;
                }
                else
                {
                    cout << "\nError! Please enter only 1 digit between 0-9" << endl;
                    cin.clear();
                }
            }
        }
        // otherwise the turn is of player 2
        else 
        {
            while (true)
            {
                cout << "\n\nPlayer 2 please enter the position where you would like to place 'O': ";
                cin >> input;
                if (input.length() == 1 && isdigit(input[0]))
                {
                    playerChoice = stoi(input);
                    break;
                }
                else
                {
                    cout << "\nError! Please enter only 1 digit between 0-9" << endl;
                    cin.clear();
                }
            }
        }

        // Checking whether input is from 1-9 and is not invalid
        switch(playerChoice)
        {
            case 1:
                row = 0; 
                column = 0;
                break;
            case 2:
                row = 0; 
                column = 1;
                break;
            case 3:
                row = 0; 
                column = 2;
                break; 
            case 4:
                row = 1; 
                column = 0;
                break; 
            case 5:
                row = 1; 
                column = 1;
                break;
            case 6:
                row = 1; 
                column = 2;
                break;
            case 7:
                row = 2; 
                column = 0;
                break;
            case 8:
                row = 2; 
                column = 1;
                break;
            case 9:
                row = 2; 
                column = 2;
                break;
            default:
                cout << "Invalid move! Please try again" << endl;
                playerTurn();
                //system("clear");                                  
        }

        // checking whether the position is not already filled and placing 'X' or 'Y' in its position
        if (player1_turn && grid[row][column] != 'X' && grid[row][column] != 'O')
        {
            grid[row][column] = 'X';
            player1_turn = !player1_turn;
            moveCounter++;
        }

       
        else if (!player1_turn && grid[row][column] != 'X' && grid[row][column] != 'O')
        {
            grid[row][column] = 'O';
            player1_turn = !player1_turn;
            moveCounter++;
        }

        // if position is already filled then player is to enter their choice again
        else
        {
            cout << "Location in grid already filled. Please enter another location" << endl;
            
            playerTurn();
        }
    }    

        bool checkForWin()
        {
            // checking for horizontal rows first
            for (int i = 0; i < 3; i++)
            {
                if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
                {   
                    winningPlayer = grid[i][0];
                    return true;
                }
            }

            // checking for columns
            for (int j = 0; j < 3; j++)
            {
                if (grid[0][j] == grid[1][j] && grid[0][j] == grid[2][j])
                {
                    winningPlayer = grid[0][j];
                    return true;
                }
            }

            // checking diagonals
           if ((grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) || (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]))
           {    
                winningPlayer = grid[1][1];
                return true;
           }



           return false;
        }

    // getter function to return winning player
    char getWinningPlayer()
    {
        return winningPlayer;
    }

    bool checkForDraw()
    {
        if(moveCounter == 9)
        {   
            draw = true;
            return true;
        }
        return false;
    }

};

int main()
{
    TicTacToe t;

    while (!(t.checkForWin()) && !(t.checkForDraw()))
    {
        t.displayGrid();
        t.playerTurn();
        t.checkForWin();
        t.checkForDraw();
    }

    int winner;
    if (t.checkForDraw())
    {
        cout << "\n\nGame drawn!" << endl;
    }
    else
    {
        if (t.getWinningPlayer() == 'X')
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }
        cout << "\n\nGame ended. Player " << winner << " wins!" << endl;
    }

    return 0;
}