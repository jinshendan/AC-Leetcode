// 211. Design Add and Search Words Data Structure

class WordDictionary {
public:
    vector<vector<int>> ch;
    vector<int> val;
    int sz;
    /** Initialize your data structure here. */
    WordDictionary() {
        sz = 1;
        ch.resize(1);
        ch[0].resize(26);
        val.resize(1);
    }
    
    void addWord(string word) {
        int cur = 0;
        for (auto& c: word){
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
    
    bool search_helper(string& word, int idx, int r){
        int cur = r;
        for(int i = idx; i < word.length(); i++){
            if (word[i] == '.'){
                for (int j = 0; j < 26; j++){
                    if (!ch[cur][j]) continue;
                    if (search_helper(word, i+1, ch[cur][j]))
                        return true;
                }
                return false;
            }
            else{
                int j = word[i] - 'a';
                if (!ch[cur][j]) return false;
                cur = ch[cur][j];
            }
        }
        return val[cur] == 1;
    }
    
    bool search(string word) {
        return search_helper(word, 0, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */