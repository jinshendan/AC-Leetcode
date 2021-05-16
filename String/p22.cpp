// 22. Generate Parentheses

class Solution {
public:
    vector<string> ans;
    void dfs(int dep, int close, int n, string s){
        if (dep == n){
            for (int i = close+1; i <= n; i++)
                s.push_back(')');
            ans.push_back(s);
            return;
        }
        
        if (close < dep)
            dfs(dep, close+1, n, s + ")");
        dfs(dep+1, close, n, s+"(");
    }
    
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n, "");
        return ans;
    }
};