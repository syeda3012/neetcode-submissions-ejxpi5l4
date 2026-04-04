class Solution {
public:
    int findMax(vector<int>&piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0;i < n; i++){
            maxi = max(maxi,piles[i]);

        }
        return maxi;
    }
    int calculateTotalHours(vector<int> &piles, int hourly){
        int total = 0;
        int n = piles.size();
        for(int i =0; i < n; i++){
            total += ceil((double)piles[i]/(double)hourly);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while(low <= high){
            int mid = (low + high)/2;
            int total = calculateTotalHours(piles,mid);
            if(total <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        
    }
};
