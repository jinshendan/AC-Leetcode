#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        string ans;
        if (n == 0) return ans;
        for (int i = 0; i < n; i++) 
            dp[i][i] = true;
        ans = s.substr(0, 1);
        
        for (int i = 0; i < n-1; i++){
            if (s[i] == s[i+1]){
                dp[i][i+1] = true;
                ans = s.substr(i, 2);
            }
        }

        for (int len = 3; len <= n; len++)
            for (int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                if (len == 4) cout << "4: " << i << " " << j << endl;
                if (i+1 > j-1 or s[i] != s[j]) continue;
                dp[i][j] = dp[i+1][j-1];
                if (dp[i][j]) ans = s.substr(i, len);
                cout << len << "  " << i << " " <<  ans << endl;
            }
        return ans;
    }
};



int main(){
    Solution* sol = new Solution();
    cout << sol->longestPalindrome("aaaa") << endl;
    return 0;
}