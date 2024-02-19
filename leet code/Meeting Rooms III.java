

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that 
a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. 
The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, 
return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.


    ***********************************************************
*/


class Solution {

    TreeSet<Integer> ar= new TreeSet<>();
    PriorityQueue<long[]> pq = new PriorityQueue<>( (a,b)->compare(a,b));

    int compare(long[] a, long[] b){
        if(a[0]==b[0]) return ((a[1] - b[1])<0?-1:1);
        return (a[0]-b[0] < 0?-1:1);
    }

    public int mostBooked(int n, int[][] meetings) {
        int m = meetings.length;
        int lt = 0;
        Arrays.sort(meetings,(a,b)->a[0]-b[0]);
        int[] c = new int[n];
        for(int i = 0; i < n; i++) ar.add(i);
        Arrays.fill(c,0);
        for(int i = 0;i < m; i++){
            while(!pq.isEmpty() && ((pq.peek())[0]) <= meetings[i][0]){
                long[] x = pq.poll(); 
                ar.add((int)x[1]);
            }
            if(ar.isEmpty()){
                long[] x = pq.poll();
                c[(int)x[1]]++;
                long[] q = {(meetings[i][1] + x[0] - meetings[i][0]),x[1]};
                pq.offer(q);
            }
            else{
                int a = ar.pollFirst(); 
                c[a]+=1;
                long[] q = {meetings[i][1],a};
                pq.offer(q);
            }
        }
        int ans = 0;
        for(int i = 1 ; i < n; i++){
            if(c[i] > c[ans]) ans = i; 
        }
        return ans;
    }
}