// 96. Unique Binary Search Trees


class Solution {
public:
    vector<int> dp;
    
    int does(int n){
        if (n <= 1) return n;
        if (dp[n]) return dp[n];

        int sum = 0;
        for (int i = 1; i <= n; i++){
            int left = max(1, does(i-1));
            int right = max(1, does(n-i));
            sum += left * right;
        }
        dp[n] = sum;
        return sum;
    }
    int numTrees(int n) {
        dp.resize(n+1);
        return does(n);   
    }
};