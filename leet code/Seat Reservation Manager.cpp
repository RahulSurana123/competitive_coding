

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Design a system that manages the reservation state of n seats that are numbered from 1 to n.

Implement the SeatManager class:

SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. 
All seats are initially available.
int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.


    ***********************************************************
*/

class SeatManager {
public:

    int s;
    priority_queue<int> x;

    SeatManager(int n) {
        s = 1;
    }
    
    int reserve() {
        if(!x.empty()) {
            int a = x.top();
            x.pop();
            return -a;
        }
        return s++;
    }
    
    void unreserve(int seatNumber) {
        x.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */