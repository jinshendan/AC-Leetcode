// 85. Maximal Rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        
        vector<vector<int>> up(n, vector<int>(m, 0));
        
        for (int j = 0; j < m; j++) up[0][j] = (matrix[0][j]=='1')?1:0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                up[i][j] = (matrix[i][j]=='1')?(up[i-1][j]+1):0;
        
        int ans = 0;
      
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == '0') continue;
                int v = n;
                int k = j;
                while(k >=0 and matrix[i][k] == '1'){
                    if (up[i][k] < v)
                        v = up[i][k];
                    ans = max(ans, (j-k+1) * v);
                    k--;
                }
            }
        return ans;
    }
};