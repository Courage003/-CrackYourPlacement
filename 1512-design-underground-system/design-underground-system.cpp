class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>checkIn_mp; //id -> {entrystation, entrytime}
    unordered_map<string,pair<int,int>>checkOut_mp; // route -> {total time, total count}
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIn_mp[id]={stationName, t};

        
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation= checkIn_mp[id].first;
        int entrytime = checkIn_mp[id].second;
        string endStation = stationName;
        int endTime = t;
        string route = startStation + "-" + stationName;
        int totaltime=t-entrytime;
        checkOut_mp[route].first+=totaltime;
        checkOut_mp[route].second+=1;

        checkIn_mp.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "-" + endStation;

        auto &it=checkOut_mp[route];

        int totalTime=it.first;
        int count=it.second;
        return (double)totalTime/count;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */