// 128. Longest Consecutive Sequence

class Solution {
public:
    unordered_map<int, int> father;
    unordered_map<int, int> sz;
    
    int find(int u) {
        return father[u] = (u == father[u])?u:find(father[u]);
    }
    
    void merge(int x, int y){
        if (father.find(x) == father.end() or father.find(y) == father.end())
            return;
        int fx = find(x);
        int fy = find(y);
        if (fx != fy){
            father[fx] = fy;
            sz[fy] += sz[fx];
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
    
        int n = nums.size();
        for (int i = 0; i < n; i++){
            father[nums[i]] = nums[i];
            sz[nums[i]] = 1;
        }
        
        for (int i = 0 ; i < n ; i++){
            merge(nums[i], nums[i]-1);
            merge(nums[i], nums[i]+1);
        }
        
        int ans = 0;
        for (int i = 0 ; i < n; i++){
            int x = find(nums[i]);
            if (sz[x] > ans) ans = sz[x];
        }
        return ans;
        
        
    }
};