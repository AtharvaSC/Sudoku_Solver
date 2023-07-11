#include <bits/stdc++.h>
using namespace std;

bool canBePlaced(vector<vector< char >> & board, char val, int row, int col) 
{
    for (int i = 0; i < 9; i++) 
    {
        if (board[i][col] == val)
            return false;

        if (board[row][i] == val)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool sudokuSolver(vector<vector< char >> & board) 
{
    for (int i = 0; i < board.size(); i++) 
    {
        for (int j = 0; j < board[0].size(); j++) 
        {
            if (board[i][j] == '.') 
            {
                for (char val = '1'; val <= '9'; val++) 
                {
                    if (canBePlaced(board, val, i, j)) 
                    {
                        board[i][j] = val;

                        if (sudokuSolver(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    if(sudokuSolver(board)){
        cout<<"Here is the solved sudoku board : \n";
        for(int i= 0; i< 9; i++){
            for(int j= 0; j< 9; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    
    return 0;
}
