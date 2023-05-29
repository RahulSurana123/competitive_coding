

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Design a parking system for a parking lot. 
The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.

Implement the ParkingSystem class:

ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. 
The number of slots for each parking space are given as part of the constructor.
bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot. 
carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. 
A car can only park in a parking space of its carType. If there is no space available, return false, 
else park the car in that size space and return true.
 
 


    ***********************************************************
*/


class ParkingSystem {
public:
static constexpr auto fast_io =  [](){  std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); };
    vector<int> c;
    ParkingSystem(int big, int medium, int small) {
        c = { big, medium, small };
    }
    
    bool addCar(int carType) {
        return c[carType-1]? c[carType-1]--:0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */