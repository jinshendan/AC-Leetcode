// 5. Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        vector<vector<int>> dp(n, vector<int>(n,0));
        string ans = s.substr(0, 1);
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]){
                dp[i][i+1] = 1;
                ans = s.substr(i, 2);
            }
        }    
        
        int ans_i = -1;
        int ans_L = -1;
        for (int L = 3; L <= n; L++)
            for (int i = 0; i <= n - L; i++){
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                    if (dp[i][j]) {
                        ans_i = i;
                        ans_L = L;
                    }
                }
            }
        if (ans_L != -1) ans = s.substr(ans_i, ans_L);
        return ans;
    }
};