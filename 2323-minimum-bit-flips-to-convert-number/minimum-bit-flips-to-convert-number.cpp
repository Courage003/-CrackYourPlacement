class Solution {
public:
    int minBitFlips(int start, int goal) {
        int p=start^goal;
        int cnt=0;
        while(p){
            p&=(p-1);
            cnt++;
        }
        return cnt;
    }
};