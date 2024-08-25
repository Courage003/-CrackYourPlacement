class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*unordered_map<int, int> m;
        for (int i : nums) {
            if (++m[i] > nums.size() / 2) {
                return i;
            }
        }
        return 0;*/

        //approach using linear TC and O(1) space 
        //Booyers Moore Voting Algorithm
        int n=nums.size();
        int cnt=1;
        int maj=nums[0];
        for(int i=1;i<n;i++){
            if(cnt==0){
                maj=nums[i];
                cnt=1;
            }
            else if(nums[i]==maj){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return maj;
    }
};