// 305. Number of Islands II

class Solution {
public:
    vector<int> father;
    int sum;
    int find(int x){
        return father[x] = (x == father[x])?x:find(father[x]);
    }
    
    void merge(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if (fx != fy){
            father[fx] = fy;
            sum--;
        }
    }
    

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        father.resize(n * m);
        for (int i = 0; i < n *m ; i++) father[i] = i;
        
        sum = 0;
        vector<int> ans;
        unordered_set<int> ss;
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        
        for (auto& p: positions){
            if (ss.find(p[0] * n + p[1]) != ss.end()) {
                ans.push_back(sum);
                continue;
            }
            ss.insert(p[0] * n + p[1]);
            sum++;
            for (int i = 0; i < 4; i++){
                int xx = p[0] + dx[i];
                int yy = p[1] + dy[i];
                if (xx >= 0 and xx < m and yy >= 0 and yy < n and ss.find(xx * n + yy) != ss.end()){
                    merge(p[0] * n + p[1],  xx * n + yy);
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};