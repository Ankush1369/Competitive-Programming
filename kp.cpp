#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int knapsack_recursive(int w[], int v[], int n, int total_W)
{
    if(n==0 || total_W==0)
    {
        return 0;
    }
    int a = knapsack_recursive(w, v, n-1, total_W);
    if(total_W>=w[n-1])
    {
        a = max(a, (v[n-1]+knapsack_recursive(w, v, n-1, total_W-w[n-1])));
    }

    return a;
}

int knapsack_dp(int w[], int v[], int n, int total_W)
{
    vector<vector<int> > dp(total_W+1, vector<int>(n+1, 0));
    for(int i=1; i<=total_W; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j] = dp[i][j-1];
            if(w[j-1]<=i)
            {
                dp[i][j] = max(dp[i][j], v[j-1]+dp[i-w[j-1]][j-1]);
            }
        }
    }

    return dp[total_W][n];

}

int main()
{
    int n;
    cin >> n;
    int w[n], v[n];
	for(int i=0; i<n; i++)
	{
		cin >> w[i] >> v[i];
	}
    int total_W = 8;
    cout << "Using recursive knapsack: " << knapsack_recursive(w, v, n, total_W) << '\n';
    cout << "Using knapsack dp: " << knapsack_dp(w, v, n, total_W) << '\n';
}


