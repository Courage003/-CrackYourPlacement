class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int res=1,cnt=1;

        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                cnt++;
                res=max(res,cnt);
            }
            else{
                cnt=1;
            }
            
        }
        return res;
        
    }
};