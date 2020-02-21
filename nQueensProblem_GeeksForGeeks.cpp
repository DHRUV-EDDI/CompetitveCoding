#include <bits/stdc++.h>
using namespace std;

void addQueenPositions(vector<vector<int>> chessBoard, int n, vector<vector<int>> &queenPositions)
{
    vector<int> positions(n);
    for (int i = 0; i < n; i++) //for columns
    {
        for (int j = 0; j < n; j++) //for rows
        {
            if (chessBoard[i][j] == 1)
            {
                positions[i] = j + 1;
            }
        }
    }
    queenPositions.push_back(positions);
}
bool isValidQueenPosition(vector<vector<int>> chessBoard, int n, int row, int column)
{
    if (row == -1 && column == -1)
    {
        return true;
    }
    for (int i = row - 1; (i >= 0); i--)
    {
        if (chessBoard[i][column] != 1)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    for (int i = row - 1, j = 1; i >= 0 && column + j < n; i--, j++)
    {
        if (chessBoard[i][column + j] != 1)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    for (int i = row - 1, j = 1; i >= 0 && column - j >= 0; i--, j++)
    {
        if (chessBoard[i][column - j] != 1)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool findQueenPositions(vector<vector<int>> chessBoard, int row, int col, int n, vector<vector<int>> &queenPositions)
{
    /**
     * this is a funcitions which returns true when a safe position is found for the queens and 
     * this 'true' is used not to make unnecessary calls
     * */
    if (row == n)
    {
        // adding in vector
        addQueenPositions(chessBoard, n, queenPositions);
        return true;
    }
    if (isValidQueenPosition(chessBoard, n, row, col))
    {
        if (row != -1 && col != -1)
        {
            chessBoard[row][col] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (row != -1)
            {
                if (row < n - 1)
                {
                    if (abs(i - col) > 1)
                    {
                        if (findQueenPositions(chessBoard, row + 1, i, n, queenPositions) == true)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    if (findQueenPositions(chessBoard, row + 1, i, n, queenPositions) == true)
                    {
                        break;
                    }
                }
            }
            else
            {
                if (findQueenPositions(chessBoard, row + 1, i, n, queenPositions) == true)
                {
                    break;
                }
            }
        }
    }
    if (row != -1 && col != -1)
    {
        chessBoard[row][col] = 0;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> chessBoard(n, vector<int>(n, 0));
        vector<vector<int>> queenPositions;
        findQueenPositions(chessBoard, -1, -1, n, queenPositions);
        if(queenPositions.size() != 0)
        {
            for (auto x : queenPositions)
            {
                cout << "[";
                for (auto y : x)
                {
                    cout << y << " ";
                }
                cout << "] ";
            }
        }
        else 
        {
            cout<<"-1";
        }
        cout << "\n";
    }
}
