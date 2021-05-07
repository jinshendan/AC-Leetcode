// 200. Number of Islands

class Solution {
public:
    vector<int> father;
    
    int find(int x){
        return father[x] = (x == father[x])?x:find(father[x]);
    }
    
    void merge(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if (fx != fy){
            father[fx] = fy;
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        father.resize(n * m);
        for (int i = 0; i < n * m; i++) father[i] = i;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            if (grid[i][j] == '1') {
                if (i > 0 and grid[i-1][j] == '1')
                    merge(i * m + j, (i-1) *m + j);
                if (j > 0 and grid[i][j-1] == '1')
                    merge(i * m + j, i * m + j-1);
            }
        
        set<int> ss;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1')
                    ss.insert(find(i * m + j));
        return ss.size();
    }
};