class Solution {
public:
    /*int n;
    //int dp[n+1][n+1][4];

    bool solve(vector<int>& nums, int id, int prev, int cnt) {
        n=nums.size();
        
        // Base case: if we have found a triplet
        if (cnt == 3) {
            return true;
        }
        
        if (id >= n) {
            return false;
        }
        
        
        if (dp[id][prev + 1][cnt] != -1) {
            return dp[id][prev + 1][cnt];
        }
        
        // Recurrence relations
        bool take = false;
        if (prev == -1 || nums[prev] < nums[id]) {
            take = solve(nums, id + 1, id, cnt + 1);
        }
        
        bool skip = solve(nums, id + 1, prev, cnt);
        
        return dp[id][prev + 1][cnt] = take || skip;
    }*/

    bool increasingTriplet(vector<int>& nums) {
        // Initialize the memoization array with -1
        /*memset(dp, -1, sizeof(dp));
        
        return solve(nums, 0, -1, 0);*/
        int one=INT_MAX;
        int two=INT_MAX;
        for(auto it:nums){
            if(it<=one){
                one=it;
            }
            else if(it<=two){
                two=it;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
