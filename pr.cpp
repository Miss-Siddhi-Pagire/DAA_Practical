#include <iostream>
using namespace std;
#define N 8
bool isSafe(int b[N][N], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (b[i][c])
        {
            return false;
        }
        if (c - r + i >= 0 && b[i][c - r + i])
        {
            return false;
        }
        if (c + r - i < N && b[i][c + r - i])
        {
            return false;
        }
    }
    return true;
}
bool solve(int b[N][N], int r)
{
    if (r == N)
    {
        return true;
    }
    for (int c = 0; c < N; c++)
    {
        if (isSafe(b, r, c))
        {
            b[r][c] = 1;
            if (solve(b,r+1))
                return true;
            b[r][c] = 0;
        }
    }
    return false;
}
int main()
{
    int b[N][N] = {0};
    if (solve(b, 0))
    {
        cout << "N Queen :"<<endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << b[i][j] << " ";
            cout << endl;
        }
    }
}