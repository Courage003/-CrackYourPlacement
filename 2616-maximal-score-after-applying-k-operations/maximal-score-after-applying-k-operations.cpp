class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum=0;
        int n=nums.size();
        priority_queue<int>pq(begin(nums),end(nums));

        while(k-- && !pq.empty()){
            int top=pq.top();
            sum+=top;
            pq.pop();
            pq.push((top + 2) / 3);
        }
        return sum;
        
    }
};