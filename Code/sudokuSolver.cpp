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
        {'2', '.', '.', '8', '.', '1', '.', '6', '.'},
        {'.', '.', '9', '7', '.', '.', '4', '3', '.'},
        {'5', '.', '8', '.', '4', '.', '.', '.', '2'},
        {'.', '1', '.', '.', '7', '.', '8', '.', '9'},
        {'4', '.', '.', '6', '.', '.', '1', '.', '.'},
        {'.', '2', '5', '.', '3', '9', '.', '4', '.'},
        {'6', '.', '.', '.', '.', '.', '.', '7', '5'},
        {'.', '.', '3', '4', '.', '7', '.', '.', '.'},
        {'.', '8', '.', '2', '.', '.', '6', '.', '4'}
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
