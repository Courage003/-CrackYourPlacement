class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=haystack.find(needle);
        if(i<=haystack.size()){
            return i;
        }
        return -1;
        
        
    }
};