#include <iostream>
#include <vector>
using namespace std;

//funtions
bool isSafe(vector<vector<int>> &, int, int, int);
bool solveSudoku(vector<vector<int>> &);
void display(vector<vector<int>> &);


int main()
{
    //Default Sudoku Grid
    vector<vector<int>> grid{
        {3,0,4,1,0,8,2,5,9},
        {5,0,9,4,2,7,6,8,3},
        {2,8,6,3,9,0,7,1,4},
        {6,9,8,0,4,1,3,7,2},
        {1,2,3,7,8,0,9,4,5},
        {4,5,7,0,3,2,1,0,8},
        {9,0,0,8,7,0,5,3,1},
        {8,3,5,6,1,9,4,2,7},
        {7,4,1,0,5,3,8,9,6}
    };
    
    solveSudoku(grid);
    display(grid);
    
    return 0;
}

bool isSafe(vector<vector<int>> &board, int row, int col, int val)
{
    //check for the val in row, column and 3x3 block
    for (int i = 0; i < 9; i++)
    {
        if ((board[row][i] == val) || (board[i][col] == val) 
        || (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == val))
        {
            return false;
        }
        
    }

    return true;
}

bool solveSudoku(vector<vector<int>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(board, row, col, val))
                    {
                        board[row][col] = val;

                        bool nextSolution = solveSudoku(board);     //recursion
                        if (nextSolution)
                            return true;

                        else
                            board[row][col] = 0;    //backtrack   
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void display(vector<vector<int>> &board){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}