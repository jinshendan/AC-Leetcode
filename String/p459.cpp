class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int len = 1; len < n; len++){
            if (n % len != 0) continue;
            string t = s.substr(0, len);
            string ss;
            for (int i = 0; i < n / len; i++)
                ss += t;
            if (ss == s) return true;
        }  
        return false;
    }
};

