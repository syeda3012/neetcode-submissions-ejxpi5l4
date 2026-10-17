class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];

        for(int i = 1; i < n; i++){
            int oldmax = maxProduct;
            int oldmin = minProduct;
            
            maxProduct = max(nums[i], max(nums[i] * oldmax, nums[i] * oldmin));

            minProduct = min(nums[i], min(nums[i] * oldmax, nums[i] * oldmin));

            result = max(result, maxProduct);
        }
        return result;
      
    }
};
