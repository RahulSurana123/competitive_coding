



/* 


    Solution by Rahul Surana
    
    ***********************************************************



Timestamp
CleverTap’s users can access the platform via a website and a mobile app. Every time the user visits the website/mobile app, we store a timestamp of the visit.
 
Most of our users access the platform via the website only, however, there are a few who use both mediums to access it. Given the visit history for a particular user, our product manager would like to know how many times the user switched devices.

Example 1:
9 am, 1 Apr - Website #1
7 pm, 2 Apr - Website #2
8 pm, 2 Apr - Website #3
8 am, 7 Apr - App #4
9 am, 7 Apr - Website #5
 
In the example above, the user switched devices twice - once from the Website to the App (#3 to #4), and then from the App back to the Website (#4 to #5).
 
Example 2:
1 am, 10 Apr - App #1
7 pm, 18 Apr - Website #2
8 pm, 28 Apr - Website #3
8 am, 29 Apr - App #4
9 am, 29 Apr - Website #5
 
In this example, the user switched devices thrice - once from the App to the Website (#1 to #2), and then from the Website to the App (#3 to #4), and finally from the App to the Website (#4 to #5).

Function Description 
You will be given the timestamps of website visits and the app visits. You’ll have to write a function computeDeviceCrossovers in the editor below. The function must return an integer denoting the number of times the given user has switched devices.
 
computeDeviceCrossovers has the following parameters:

websiteVisits:  an array of n integers, where each websiteVisits[i] is the timestamp at which a user visited the website (sorted in ascending order)
appVisits:  an array of m integers, where each appVisits[j] is the timestamp at which a user visited the app (sorted in ascending order)





    ***********************************************************

*/


#include<bits/stdc++.h>
using namespace std;

int computeDeviceCrossovers (int n, vector<int> websiteVisits, int m, vector<int> appVisits) {
   int j = 0, i = 0,ans = 0;
   int f = 0;
   // if(websiteVisits[i] < appVisits[j]) f = 1;
   while(j < m && i < n){
      if(websiteVisits[i] < appVisits[j]){
         if(f)
         ans++;
         f = 0;
         i++;
      }
      else if(websiteVisits[i] > appVisits[j]){
         if(f == 0) ans++;
         f = 1;
         j++;
      }
      else{ 
         i++; 
         j++;
      }
      // if(j >= m || i >= n) break;
   } 
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> websiteVisits(n);
    for(int i_websiteVisits = 0; i_websiteVisits < n; i_websiteVisits++)
    {
    	cin >> websiteVisits[i_websiteVisits];
    }
    int m;
    cin >> m;
    vector<int> appVisits(m);
    for(int i_appVisits = 0; i_appVisits < m; i_appVisits++)
    {
    	cin >> appVisits[i_appVisits];
    }

    int out_;
    out_ = computeDeviceCrossovers(n, websiteVisits, m, appVisits);
    cout << out_;
}