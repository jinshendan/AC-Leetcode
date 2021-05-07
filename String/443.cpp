// 443. String Compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        
        int k = 0;
        while(i < n){
            int j = i;
            int num = 0;
            while (j < n and chars[j] == chars[i]) {
                j++;
                num++;
            }
            
            chars[k++] = chars[i];
            if (num > 1) {
                string s;
                while(num){
                    s = to_string(num % 10) + s;
                    num /= 10;
                }
                for (auto& c: s){
                    chars[k++] = c;
                }
            }
            
            i = j;
        }
        return k;
    }
};