class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& ninv) {
        int i=0;
        vector<vector<int>>res;
        int n=inv.size();
        while(i<n){
            if(inv[i][1]<ninv[0]){
                res.push_back(inv[i]);
            }
            else if(inv[i][0]>ninv[1]){
                break;
            }
            else{
                //merge
                ninv[0]=min(ninv[0],inv[i][0]);
                ninv[1]=max(ninv[1],inv[i][1]);

            }
            i++;
        }
        res.push_back(ninv);
        while(i<n){
            res.push_back(inv[i]);
            i++;
        }
        return res;
    }
};