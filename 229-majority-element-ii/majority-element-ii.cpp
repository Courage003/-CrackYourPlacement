class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*int n=nums.size();
        vector<int>res;
        
        unordered_map<int,int>m;
        for(auto it:nums)
            m[it]++;

        for(auto &it:m){
            if(it.second>n/3)
                res.push_back(it.first);
        }        

        return res;*/

        //Booyer's Moore Voting Algorithm
        int n=nums.size();
        int cnt1=0;
        int maj1=INT_MIN;
        int cnt2=0;
        int maj2=INT_MIN;

        for(int i=0;i<n;i++){
            if(nums[i]==maj1){
                cnt1++;
            }
            else if(nums[i]==maj2){
                cnt2++;
            }
            else if(cnt1==0){
                maj1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                maj2=nums[i];
                cnt2=1;
            }
            
            else{
                cnt1--;
                cnt2--;
            }
        }

        //Verification
        vector<int>res;
        int freq1=0;
        int freq2=0;
        for(auto it:nums){
            if(it==maj1){
                freq1++;
            }
            else if(it==maj2){
                freq2++;
            }
        }

        if(freq1>floor(n/3)){
            res.push_back(maj1);
        }
        if(freq2>floor(n/3)){
            res.push_back(maj2);
        }

        return res;
        
    }
};