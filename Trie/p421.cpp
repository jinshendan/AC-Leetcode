// 421. Maximum XOR of Two Numbers in an Array

class Solution {
public:
    
    vector<vector<int>> ch;
    vector<int> val;
    int sz;
    
    void init(){
        sz = 1;
        ch.resize(1);
        ch[0].resize(2);
        val.resize(1);
        val[0] = -1;
    }

    void add(int num){
        vector<int> a(32, 0);
        int i = 0;
        int x = num;
        while(x){
            a[i] = x % 2;
            x /= 2;
            i++;
        }
        
        int cur = 0;
        for (int i = 31; i>= 0; i--){
            if (!ch[cur][a[i]]){
                ch.push_back(vector<int>(2,0));
                val.push_back(0);
                ch[cur][a[i]] = sz++;
            }
            cur = ch[cur][a[i]];
        }
        val[cur] = num ;
    }
    
    
    int check(int num){
        vector<int> a(32, 0);
        int i = 0;
        int x = num;
        while(x){
            a[i] = x % 2;
            x /= 2;
            i++;
        }
        
        int cur = 0;
        
        for (int i = 31; i>=0; i--){
            if (a[i] == 1)
                cur = ch[cur][0]?ch[cur][0]:ch[cur][1];
            else
                cur = ch[cur][1]?ch[cur][1]:ch[cur][0];
        }
        if (val[cur] != -1)
            return num ^ val[cur];
        else return 0;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        init();
        for (int& x: nums){
            add(x);
        }  
        
        int ans = 0;
        
        for (auto& x: nums){
            int y = check(x);
            if (y > ans) ans = y;
        }
        return ans;
    }
};