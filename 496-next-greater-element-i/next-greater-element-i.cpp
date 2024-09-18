class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        unordered_map<int,int>mp;
        
        stack<int>st;
        for(auto it:nums2){
            while(!st.empty() && st.top()<it){
                mp[st.top()]=it;  //storing next greater element
                st.pop();

            }
            st.push(it);
        }

        vector<int>res;
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }

        for(auto i:nums1){
            res.push_back(mp[i]);
        }
        return res;

        
    }
};