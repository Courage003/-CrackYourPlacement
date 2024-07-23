//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        unordered_map<int, int> countMap;
        
        // Count the occurrences of each element
        for (int num : arr) {
            countMap[num]++;
        }
        
        // Find the first element with a count of 1
        for (int num : arr) {
            if (countMap[num] == 1) {
                return num;
            }
        }
        
        // If there is no non-repeating element, return a special value
        // (assuming all elements are positive, we can return -1 to indicate this)
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.firstNonRepeating(nums) << endl;
    }
}

// } Driver Code Ends