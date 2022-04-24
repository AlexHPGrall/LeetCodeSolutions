class UndergroundSystem {
    unordered_map<int, pair<int, string>> checkInMap;
    unordered_map<string, pair<double, int>> travelTimeMap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id]={t, stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto[checkInTime, checkInStation]=checkInMap[id];
        auto[currAverage, travelCount] =travelTimeMap[checkInStation+"_"+stationName];

        currAverage+=(t-checkInTime);
        
        travelTimeMap[checkInStation+"_"+stationName] ={currAverage,travelCount+1};   
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto[currAverage, travelCount] =travelTimeMap[startStation+"_"+endStation];
        return currAverage/travelCount;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */