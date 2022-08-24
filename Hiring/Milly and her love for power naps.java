


/* 

    Solution by Rahul Surana
    
    ***********************************************************


    Sorry Question not available. This was asked for wallmart challenge and was missing a edge case so got only 40% success  



    ***********************************************************
*/






import java.util.*;
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        /* Sample code to perform I/O:
         * Use either of these methods for input
 
        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();                // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        //Scanner
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();                 // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        */
        Scanner s = new Scanner(System.in);
        String a = s.nextLine();
        int k = s.nextInt();
        String[] sa = a.split(" ");
        int[] ar = new int[sa.length];
        for(int i = 0 ; i < sa.length; i++){
            ar[i] = Integer.parseInt(sa[i]);
            // System.out.println(k + " "+ar[i]);
        }
        int l = 1, r = 1000000009,ans = -1; 
        while(l<=r){
            int m = l + (r-l)/2;
            int c = k;
            for(int i = 0; i < ar.length; i++){
                int z = ar[i];
                while(z>m) { c--; z -= m; }
                if(z <= m) { c--; }
            }
            if(c < 0){
                l = m+1;
            }
            else if(c >0){
                r = m-1;
                ans = m;
            }
            else{
                ans = m;
                break;
            }
            // System.out.println(m);
        }
        System.out.println(ans);
    }
}