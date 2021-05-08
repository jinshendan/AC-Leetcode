class Solution {
public:
    vector<vector<int>> ch;
    vector<string> val;
    int sz;
    
    void init(){
        ch.resize(1);
        ch[0].resize(26);
        sz = 1;
        val.resize(1);
        val[0] = "";
    }
    
    void add(string s){
        int cur = 0;
        for (auto& c: s){
            int j = c - 'a';
            if (!ch[cur][j]){
                ch.push_back(vector<int>(26, 0));
                val.push_back("");
                ch[cur][j] = sz++;
            }
            cur = ch[cur][j];
        }
        val[cur] = s;
    }
    
    string get(string s){
        int cur = 0;
        for (auto& c: s){
            int j = c - 'a';
            if (!ch[cur][j]) return s;
            cur = ch[cur][j];
            if (val[cur] != "") return val[cur]; 
        }
        return s;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        init();
        for (auto& s: dictionary)
            add(s);
        istringstream iss(sentence);
        string s;
        string ans;
        while(iss >> s){
            ans += get(s) + " ";
        }
        ans.pop_back();
        return ans;
    }
};