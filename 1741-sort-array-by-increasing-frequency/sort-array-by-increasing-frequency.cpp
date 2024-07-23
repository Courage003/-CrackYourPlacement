class Solution {
public:
    typedef pair<int, int> p;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        for (auto it : mp) {
            pq.push({it.second, -it.first});  // Use -it.first for descending order of value
        }

        vector<int> res;
        while (!pq.empty()) {
            int freq = pq.top().first;
            int val = -pq.top().second;  // Convert back to the original value
            pq.pop();
            for (int i = 0; i < freq; ++i) {
                res.push_back(val);
            }
        }

        return res;

        
    }
};