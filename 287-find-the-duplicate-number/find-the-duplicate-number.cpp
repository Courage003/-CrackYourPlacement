class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Duplicacy or array traversal (1 to n)
        //Hare and Tortoise Problem

        int slow=nums[0];
        int fast=nums[0];

        slow=nums[slow];
        fast=nums[nums[fast]]; //do baar move
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }//cycle detected

        //now get to repeating number or starting point of cycle
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        /*unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }

        for(auto it:mp){
            if(it.second>1) return it.first;
        }

        return -1;*/
        
        
    }
};