class Solution {
public:
    string reorganizeString(string S) {
        vector<int> v(26, 0);
        for (auto& c: S){
            v[c- 'a']++;
        }
        int n = S.length();
        string ans;
        for (int i = 0; i < n; i++ ){
            int mx_i = -1, mx = 0;
            for (int j = 0; j < 26; j++)
                if (v[j] > mx){
                    if (ans.size() == 0 or (ans.size() and ans[ans.size()-1] - 'a' != j)){
                        mx = v[j];
                        mx_i = j;    
                    }
                }
            if (mx_i == -1) return "";
            ans.push_back(char('a' + mx_i));   
            v[mx_i]--;
        }
        return ans;
    }
}; 