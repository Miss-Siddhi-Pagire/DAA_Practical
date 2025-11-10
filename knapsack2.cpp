#include <iostream>
using namespace std;
int knapsack(int w, int wt[], int val[], int n)
{
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}
int main()
{
    int val[] = {2, 3, 1, 4};
    int wt[] = {3, 4, 6, 5};
    int w = 8, n = 3;
    cout << "Maximum Value:" << knapsack(w, wt, val, n);
}