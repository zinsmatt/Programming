class UndergroundSystem {
    vector<pair<string, int>> arr;
    unordered_map<string, pair<int, double>> times;
public:
    UndergroundSystem() {
        arr.resize(1000001);
        
    }
    
    void checkIn(int id, string stationName, int t) {
        arr[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto key = arr[id].first + "_" + stationName;
        if (times.find(key) == times.end())
            times[key] = {1, t - arr[id].second};
        else {
            times[key].second = (times[key].first * times[key].second + t - arr[id].second) / (times[key].first+1);
            times[key].first++;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return times[startStation + "_" + endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
