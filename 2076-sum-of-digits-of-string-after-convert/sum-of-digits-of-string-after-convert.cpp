class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.size();
        string num="";
        for(char i:s){
            num+=to_string(i-'a'+1);
        }

        //Converting each character into corr number

        while(k){
            int temp=0;
            for(char i:num){
                temp+=i-'0';
            }
            num=to_string(temp);
            k--;
        }
        return stoi(num);
        
    }
};