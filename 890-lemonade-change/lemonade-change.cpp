class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for(auto i:bills){
            if(i==5) five++;
            else if(i==10) five--,ten++;
            else if(ten>0 && five>=1) ten--,five--;
            else five-=3;

            if(five<0) return false;
        
        }
            return true;
        
    }
};