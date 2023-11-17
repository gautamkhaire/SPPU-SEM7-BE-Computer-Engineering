/*
    Problem Statement: Design n-Queens matrix having first Queen placed. Use backtracking to place remaining Queens to generate the final n-queen's matrix.
*/

#include <bits/stdc++.h>
using namespace std;

/* 
    N-Queens solved using BackTracking Technique 
    
    Time Complexity: O(N!)
    Space Complexity: O(N^2) + Call Stack
*/
bool isPossible(vector<string> &board, int row, int col, int x)
{
    // Checking the same column
    for (int i = row - 1; i >= 0; i--) // Checking upwards cells of the column
    {
        if (board[i][col] == 'Q')
            return false;
    }

    for (int i = row + 1; i < board.size(); i++) // Checking downwards cells of the column
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Checking the Upper Left Diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Checking the Upper Right Diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Checking the Lower Left Diagonal
    for (int i = row + 1, j = col - 1; i < board.size() && j >= 0; i++, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Checking the Lower Right Diagonal
    for (int i = row + 1, j = col + 1; i < board.size() && j < board.size(); i++, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void solveNQueens(vector<string> &board, int &n, int &x, int &y, int row, vector<vector<string>> &result)
{
    if (row == n)
    {
        result.push_back(board);
        return;
    }

    if (row == x) // Skipping the current row if the first queen is placed on that row
    {
        solveNQueens(board, n, x, y, row + 1, result);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isPossible(board, row, col, x))
        {
            board[row][col] = 'Q';
            solveNQueens(board, n, x, y, row + 1, result);
            board[row][col] = '.';
        }
    }
}
void solveNQueens(int &n, int &x, int &y, vector<vector<string>> &result)
{
    vector<string> board(n, string(n, '.'));
    x--, y--; // (x,y) are 1-based indexing that's why subtracting -1
    board[x][y] = 'Q';

    solveNQueens(board, n, x, y, 0, result);

    cout << endl;

    // Displaying all the possible n-Queen's matrix solutions
    if (result.size() == 0)
    {
        cout << "After placing the 1st Queen at (" << (x + 1) << "," << (y + 1) << ") co-ordinate there exists NO final n-Queen's matrix Solution." << endl;
    }
    else
    {
        cout << "After placing the 1st Queen at (" << (x + 1) << "," << (y + 1) << ") co-ordinate the following the are final n-Queen's matrix Solutions:- " << endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout << "Solution-" << (i + 1) << endl;
            for (string row : result[i])
                cout << row << endl;
            cout << endl;
        }
    }
}

int main()
{
    try
    {
        int n;
        cout << "Enter the n-Queens board size: ";
        while (!(cin >> n))
        {
            cout << "Invalid input. Please enter a positive number" << endl;

            cout << "Enter the n-Queens board size: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int x, y;
        cout << "Enter the (x,y) co-ordinate of the first Queen placed: ";
        while (!(cin >> x >> y))
        {
            cout << "Invalid input. Please enter a positive number" << endl;

            cout << "Enter the (x,y) co-ordinate of the first Queen placed: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        vector<vector<string>> result;
        solveNQueens(n, x, y, result);
    }
    catch (string errorMessage)
    {
        cout << errorMessage << endl;
    }

    return 0;
}