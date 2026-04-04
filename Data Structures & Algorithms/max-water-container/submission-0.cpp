class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxwater = 0;
        int lp = 0;
        int rp = heights.size()-1;
        while(lp < rp){
            int width = (rp - lp);//taking the max capacity
            int  height = min(heights[lp],heights[rp]);//comparing heights as the container having min height stores the water upto that level
            int area = (width * height);//storage 
            maxwater = max(maxwater,area);
            if(heights[lp] < heights[rp]){
                lp++;
            }
            else{
                rp--;
            }
        }
        return maxwater;
    }
};
