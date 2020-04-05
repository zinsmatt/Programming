class UndergroundSystem {
    
    unordered_map<string, pair<double, int>> avg_times;
    unordered_map<int, pair<int, string>> customers;
    
    
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        customers[id] = make_pair(t, stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto key = customers[id].second + stationName;
        double travel_time = t - customers[id].first;

        if (avg_times.find(key) != avg_times.end())
        {
            auto& ref = avg_times[key];
            ref.second++;
            ref.first = ref.first + (1.0 / ref.second) * (travel_time - ref.first);
        }
        else
        {
            avg_times[key] = make_pair(travel_time, 1);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto key = startStation + endStation;
        return avg_times[key].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
