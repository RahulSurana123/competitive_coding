

/* 
    Solution by Rahul Surana
    
    ***********************************************************


An underground railway system is keeping track of customer travel times between different stations. 
They are using this data to calculate the average time it takes to travel from one station to another.

Implement the UndergroundSystem class:

void checkIn(int id, string stationName, int t)
A customer with a card ID equal to id, checks in at the station stationName at time t.
A customer can only be checked into one place at a time.
void checkOut(int id, string stationName, int t)
A customer with a card ID equal to id, checks out from the station stationName at time t.
double getAverageTime(string startStation, string endStation)
Returns the average time it takes to travel from startStation to endStation.
The average time is computed from all the previous traveling times from startStation to endStation that happened directly, 
meaning a check in at startStation followed by a check out from endStation.
The time it takes to travel from startStation to endStation may be different from the 
time it takes to travel from endStation to startStation.
There will be at least one customer that has traveled from startStation to endStation before getAverageTime is called.
You may assume all calls to the checkIn and checkOut methods are consistent. 
If a customer checks in at time t1 then checks out at time t2, then t1 < t2. All events happen in chronological order.



    ***********************************************************
*/



#include <bits/stdc++.h>

class UndergroundSystem {
public:
void checkIn(int id, string stationName, int t) {
    ID_to_time[id] = make_pair(make_pair(t, -1), make_pair(stationName, NULL));
}

void checkOut(int id, string stationName, int t) {
    pair<int, int> &info_time = ID_to_time[id].first;
    pair<string, string> &info_name = ID_to_time[id].second;
    info_time.second = t;
    info_name.second = stationName;
    int interval = info_time.second - info_time.first;
    station_to_time[make_pair(info_name.first, info_name.second)].push_back(interval);
}

double getAverageTime(string startStation, string endStation) {
    int count = 0;
    double sum = 0;
    for (auto a : station_to_time[make_pair(startStation, endStation)]) {
        sum += (double) a;
        count++;
    }
    return sum / count;
}

map<int, pair<pair<int, int>, pair<string, string>>> ID_to_time;
map<pair<string, string>, vector<int>> station_to_time;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */