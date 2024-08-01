class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        // age-> 11 and 12
        int cnt=0;
        for(auto &it: details){
            int p=stoi(it.substr(11,2));
            if(p>60) cnt++;
        }

        return cnt;

        
    }
};