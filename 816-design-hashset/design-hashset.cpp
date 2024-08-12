class MyHashSet {
public:
//vector<int>v;
vector<list<int>>bucket;
int M;
    int getIndex(int key){
        return key%M;
    }
    MyHashSet() {
        //v.resize(1000001,false);
        M=15000;
        bucket=vector<list<int>>(M,list<int>{});
        
    }
    
    void add(int key) {
        //v[key]=true;
        int idx=getIndex(key);
        auto itr=find(bucket[idx].begin(),bucket[idx].end(),key);

        if(itr==bucket[idx].end())
            bucket[idx].push_back(key);

    
        
    }
    
    void remove(int key) {
        //v[key]=false;
        int idx=getIndex(key);
        auto itr=find(bucket[idx].begin(),bucket[idx].end(),key);

        if(itr!=bucket[idx].end())
            bucket[idx].erase(itr);
    }
    
    bool contains(int key) {
        //return v[key]==true;
        int idx=getIndex(key);
        auto itr=find(bucket[idx].begin(),bucket[idx].end(),key);

        return itr!=bucket[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */