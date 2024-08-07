class Solution {
public:
    void sum(int ind, int target, vector<int>&arr, vector<vector<int>>&ans, vector<int>&v){
        int n=arr.size();
            if(target==0){
                ans.push_back(v);
                return;
            }
        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1])
            continue;
            if(arr[i]>target)
            break;

            v.push_back(arr[i]);
            sum(i+1,target-arr[i],arr,ans,v);
            v.pop_back();
        }


    }
public:    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        sum(0,target,candidates,ans,v);
        return ans;
        
    }
};