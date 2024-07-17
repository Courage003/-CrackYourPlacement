class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*int maxi=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(prices[j]-prices[i]>maxi){
                    maxi=prices[j]-prices[i];
                }
            }
        }
        return maxi;*/
        int n=prices.size();
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            int diff=prices[i]-mini;
            profit=max(diff,profit);
            mini=min(mini,prices[i]);
        }
        return profit;
        
        
    }
};