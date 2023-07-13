#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
const int MAXN = 1000;
int dp[MAXN];

int minCost(int cost[][MAXN], int n) {
    memset(dp, 0, sizeof(dp));
    dp[1] = 0;
    for (int j = 2; j <= n; j++) {
        dp[j] = INT_MAX;
        for (int i = 1; i < j; i++) {
            dp[j] = min(dp[j], dp[i] + cost[i][j]);
        }
    }
    return dp[n];
}

int main() {
    int n = 5; // change this value to match the number of stopping points
    int cost[MAXN][MAXN] = { {0, 0, 0, 0, 0, 0},
                            {0, 0, 10, 5, 0, 0},
                            {0, 0, 0, 0, 1, 0},
                            {0, 0, 0, 0, 3, 9},
                            {0, 0, 0, 0, 0, 4},
                            {0, 0, 0, 0, 0, 0} }; // change these values to match the costs
    cout << "Minimum rental cost from point 1 to point " << n << " is: " << minCost(cost, n) << endl;
    return 0;
}
