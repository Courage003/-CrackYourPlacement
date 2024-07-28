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
        int cnt=0;
        int cand=0;

        for(int it:nums){
            if(cnt==0){
                cand=it;
            }

            if(it==cand){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
        return cand;
    }
};