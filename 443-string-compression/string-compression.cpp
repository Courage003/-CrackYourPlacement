class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int id=0;
        int i=0;
        while(i<n){
            char c=chars[i];
            int cnt=0;
            while(i<n && chars[i]==c){
                cnt++;
                i++;
            }
            //assign
            chars[id]=c;
            id++;

            if(cnt>1){
                string s=to_string(cnt);
                for(auto &a:s){
                    chars[id]=a;
                    id++;
                }
            }
        }
        return id;
        
    }
};