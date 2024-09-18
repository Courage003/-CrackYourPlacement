class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        stringstream ss(s);
        string token="";
        string res="";
        while(ss>>token){
            res=token+" "+res; //prepend each word
            
        }
        if (!res.empty()) {
            res.pop_back();  // Remove the trailing space
        }
        return res;
    }
};