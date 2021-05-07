// 165. Compare Version Numbers

class Solution {
public:
    
    void does(string version, vector<int>& ans){
        int x = 0;
        int n = version.length();
        for (int i = 0; i < n; i++){
            if (version[i] == '.'){
                ans.push_back(x);
                x = 0;
            }
            else x = x * 10 + version[i] - '0';
        }
        ans.push_back(x);
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        does(version1, v1);
        vector<int> v2;
        does(version2, v2);
        
        int n = max(v1.size(), v2.size());
        while (v1.size() < n) v1.push_back(0);
        while (v2.size() < n) v2.push_back(0);
        
        for (int i = 0; i < n ; i++){
            if (v1[i] > v2[i]) return 1;
            if (v1[i] < v2[i]) return -1;
        }
        return 0;
    }
};