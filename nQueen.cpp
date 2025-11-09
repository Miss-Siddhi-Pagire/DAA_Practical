#include <iostream>
using namespace std;
#define N 4
bool isSafe(int b[N][N], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        // same column
        if (b[i][c])
            return false;
        // upper left diagonal
        if (c - r + i >= 0 && b[i][c - r + i])
            return false;
        // upper right diagonal
        if (c + r - i < N && b[i][c + r - i])
            return false;
    }
    return true;
}
bool solve(int b[N][N], int r)
{
    if (r == N)
        return true; // all queens placed
    for (int c = 0; c < N; c++)
    {
        if (isSafe(b, r, c))
        {
            b[r][c] = 1;         // place queen
            if (solve(b, r + 1)) // recursive call
                return true;     // solution found
            b[r][c] = 0;         // backtrack
        }
    }
    return false; // no valid position
}
int main()
{
    int b[N][N] = {0};
    if (solve(b, 0))
    {
        cout << "Solution for " << N << "-Queens:\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << b[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "❌ No solution exists";
    }
    return 0;
}
