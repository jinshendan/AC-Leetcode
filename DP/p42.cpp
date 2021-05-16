// 42. Trapping Rain Water

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if (n == 0) return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int x = height[0];
        for (int i = 1; i < n - 1; i++){
            if (height[i] > x) {
                x = height[i];
            }    
            left[i] = x;
        }
        
        x = height[n-1];
        for(int i = n - 2; i >= 1; i--){
            if (height[i] > x)
                x = height[i];
            right[i] = x;
        }
        
        for (int i = 1; i < n - 1; i++){
            if (min(left[i], right[i]) > height[i])
                ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    
    }
};