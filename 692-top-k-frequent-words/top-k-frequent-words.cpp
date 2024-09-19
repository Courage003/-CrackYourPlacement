class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //store word and its frequency
        unordered_map<string,int>mp;
        for(auto &word: words){
            mp[word]++;
        }

        //storing pair of string and frequency in vector
        vector<pair<string,int>>v;
        for(auto &it:mp){
            v.push_back({it.first,it.second});
        }
        //sort lexicographically and on the basis of frequency
        auto lambda=[](pair<string,int>p1, pair<string,int>p2){
            if(p1.second==p2.second){
                return p1.first<p2.first;
            }
            return p1.second>p2.second;

        };
        sort(begin(v),end(v),lambda);

        //now pick top k elements
        int i=0;
        vector<string>res(k);
        while(i<k){
            res[i]=v[i].first;
            i++;
        }

        return res;
        
    }
};