class Solution {
public:
    string reverseWords(string s) {
        /*int i=0;
        int j=0;
        while(i<s.size()){
        while(j<s.size() && s[j]!=' ')
            
            j++;
            reverse(s.begin()+i,s.begin()+j);
            i=j+1;
            j=i;
        
        }
        return s;*/
        int n=s.size();
        //using the concept of tokenizer
        stringstream ss(s);
        string token="";
        string res="";
        while(ss>>token){
            reverse(begin(token),end(token));
            res+=token+" ";
        }
        return res.substr(0,n);
        
    }
};