class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int lmax = 0;
        int rmax = 0;
        int n = height.size()-1;
        int l = 0;
        int r = n-1;
        while(l < r){
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);
            if(lmax < rmax){
                ans += lmax - height[l];
                l++;
            }
            else{
                ans += rmax-height[r];
                r--;
            }
        }
        return ans;
    }
};
