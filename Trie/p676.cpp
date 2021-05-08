// 676. Implement Magic Dictionary

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> ch;
    vector<int> val;
    int sz;
    MagicDictionary() {
        sz = 1;
        ch.resize(1);
        ch[0].resize(26);
        val.resize(1);
    }
    
    void buildDict(vector<string> dictionary) {
        for (auto& s: dictionary){
            int cur = 0;
            for (auto& c: s){
                int j = c - 'a';
                if (!ch[cur][j]){
                    ch.push_back(vector<int>(26, 0));
                    val.push_back(0);
                    ch[cur][j] = sz++;
                }
                cur = ch[cur][j];
            }
            val[cur] = 1;
        }
    }
    
    bool dfs(string s, int m, int root){
        int cur = root;
        for (int i = 0; i < s.length(); i++){
            if (i != m){
                int j = s[i] - 'a';
                if (!ch[cur][j]) return false;
                cur = ch[cur][j];
            }
            else{
                for (int j = 0; j < 26; j++){
                    if (s[m] - 'a' == j) continue;
                    if (!ch[cur][j]) continue;
                    if (dfs(s.substr(i+1, s.length()), -1, ch[cur][j]))
                        return true;
                }
                return false;
            }
        }
        return val[cur] == 1;
    }
    
    bool search(string searchWord) {
        for (int i = 0; i < searchWord.length(); i++){
            if(dfs(searchWord, i, 0)) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */