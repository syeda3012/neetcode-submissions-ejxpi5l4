class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int p  = prices.size();
       int hold = -prices[0];
       int sold = INT_MIN;
       int rest = 0;
       for(int i = 1; i < p; i++){
        int prevhold = hold;
        int prevsold = sold;
        int prevrest = rest;

        hold = max(prevhold, prevrest-prices[i]);
        sold = prevhold + prices[i];
        rest = max(prevrest, prevsold);
       }
       return max(rest, sold);
    }
};
