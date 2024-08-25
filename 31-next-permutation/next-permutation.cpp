class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int gola_id=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                gola_id=i-1;
                break;
            }
        }
        if(gola_id!=-1){
            int swap_id=gola_id;
            for(int j=n-1;j>=gola_id+1;j--){
                if(nums[j]>nums[gola_id]){
                    swap_id=j;
                    break;
                }
            }
            swap(nums[gola_id],nums[swap_id]);
        }

        reverse(nums.begin()+gola_id+1,nums.end());
        
        
    }
};