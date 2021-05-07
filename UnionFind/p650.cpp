// 650. 2 Keys Keyboard

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, -1);
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j < n; j++)
                if (i % j == 0){
                    if (dp[i] == -1)
                        dp[i] = dp[j] + i / j;
                    else dp[i] = min(dp[i], dp[j] + i / j);
                }
        return dp[n];
    }
};