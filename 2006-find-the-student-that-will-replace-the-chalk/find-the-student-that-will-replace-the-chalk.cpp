class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Calculate the total amount of chalk needed for one complete round
        long long sum = accumulate(begin(chalk), end(chalk), 0LL);

        // Reduce k to the remainder when divided by the total chalk
        k %= sum;

        // Iterate through each student and reduce k by the amount of chalk each student uses
        for(int i = 0; i < chalk.size(); i++) {
            // If k is less than the current student's chalk usage, return that student's index
            if(chalk[i] > k) {
                return i;
            }
            // Otherwise, subtract the current student's chalk usage from k
            else {
                k -= chalk[i];
            }
        }

        // If the loop completes, return -1 (though by problem constraints this should never happen)
        return -1;
    }
};
