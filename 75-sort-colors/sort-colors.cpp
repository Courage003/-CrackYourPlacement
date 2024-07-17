#include <vector>
#include <algorithm> // For std::swap

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int s = 0; // Start index
        int e = n - 1; // End index
        int mid = 0; // Middle index
        
        while (mid <= e) {
            switch (nums[mid]) {
                case 0: // Red
                    swap(nums[s], nums[mid]);
                    s++;
                    mid++;
                    break;
                case 1: // White
                    mid++;
                    break;
                case 2: // Blue
                    swap(nums[mid], nums[e]);
                    e--;
                    break;
            }
        }
    }
};
