class LRUCache {
public:
//vector<pair<int,int>>cache;
list<int>dll;
map<int,pair<list<int>::iterator,int>>mp;
int n;
    LRUCache(int capacity) {
        n=capacity;
    }

    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key); //peeche se hi delete hoga , freshers aage rhenge
        mp[key].first=dll.begin(); //storing new address
    }
    
    int get(int key) {
        //iterate on your vector, find out, erase it and move it back since fresh use must not be deleted
        /*for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                int val=cache[i].second;
                pair<int,int>temp=cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                return val;
            }

        }
        return -1;*/

        if(mp.find(key)==mp.end())
            return -1;

        makeRecentlyUsed(key);
        return mp[key].second;    
    }
    
    void put(int key, int value) {
       /* for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                return;
            }
        }

        if(cache.size()==n){
            cache.erase(cache.begin());
            cache.push_back({key,value});
        }
        else{
            cache.push_back({key,value});
        }*/

        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            makeRecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            mp[key]={dll.begin(), value};
            n--;
        }

        if(n<0){
            int key_del=dll.back();
            mp.erase(key_del);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */