class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        unordered_map<int, int> mp;
        int n = arr.size();
        long long int cnt = 0;
        
        // Populate the frequency of remainders
        for (int i = 0; i < n; i++) {
            int rem = ((arr[i] % k) + k) % k; // Handling negative values of `arr[i]`
            mp[rem]++;
        }

        // Check pairs
        for (int i = 0; i < n; i++) {
            int rem = ((arr[i] % k) + k) % k;

            if (rem == 0) {
                // If remainder is zero, we need even occurrences
                if (mp[rem] % 2 != 0) {
                    return false;
                }
            } else {
                // If remainder is not zero, we need corresponding pairs
                if (mp[rem] != mp[k - rem]) {
                    return false;
                }
            }
        }

        return true;
    }
};
