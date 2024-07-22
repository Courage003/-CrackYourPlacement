class Solution {
public:
    typedef pair<int,string>p;
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        int m=heights.size();

        priority_queue<p>pq;

        
        for(int i=0;i<n;i++){
            pq.push({heights[i],names[i]});
        }

        vector<string>res;
        for(int i=0;i<n;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;

        
       
       
        
    }
};