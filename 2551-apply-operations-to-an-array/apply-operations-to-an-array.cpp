class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1] && nums[i]!=0)
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }

        int ni=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=0){
                nums[ni++]=nums[j];
            }
        }

        while(ni<n){
            nums[ni++]=0;
        }

        return nums;
        
    }
};