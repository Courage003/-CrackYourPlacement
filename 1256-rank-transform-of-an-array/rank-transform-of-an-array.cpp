class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        set<int>s(begin(arr),end(arr)); //stored in sorted order and unique
        int rank=1;
        for(auto it:s){
            mp[it]=rank;
            rank++;

        }

        int n=arr.size();
        for(int i=0;i<n;i++){
            arr[i]=mp[arr[i]];
        }

        return arr;

        
    }
};