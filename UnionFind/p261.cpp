// 261. Graph Valid Tree

class Solution {
public:
    vector<int> father;
    vector<int> sz;
    int find(int x){
        return father[x] = (x == father[x])?x:find(father[x]);
    }
    
    int merge(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return false;
        father[fx] = fy;
        sz[fy] += sz[fx];
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        father.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) { 
            father[i] = i;
            sz[i] = 1;
        }
        for (auto& e: edges){
            int ok = merge(e[0], e[1]);
            if (!ok) return false;
        }
        
        return sz[find(0)] == n;
    }
};