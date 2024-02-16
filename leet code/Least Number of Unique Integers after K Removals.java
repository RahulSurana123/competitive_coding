

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.


    ***********************************************************
*/


class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Arrays.sort(arr);
        ArrayList<Integer> x = new ArrayList<>();
        int l = 1;
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] == arr[i-1]) l++;
            else { x.add(l); l = 1; }
        }
        x.add(l);
        Collections.sort(x);
        int ans = 0;
        for(int i = 0; i < x.size(); i++){
            if(k >= x.get(i)) {
                k -= x.get(i);
            }
            else { return x.size() - i; }
        }
        return 0;
    }
}