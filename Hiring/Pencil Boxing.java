


/* 

    Solution by Rahul Surana
    
    ***********************************************************


Sorry Question not available. This was asked for wallmart challenge and was able to pass 100% testcases



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
        String name = s.nextLine();                 // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        */
 
        // Write your code here
        Scanner s = new Scanner(System.in);
        String l = s.nextLine();
        int k = s.nextInt();
        // System.out.println("Hi, " + l + ". "+k);
        int ans = 0;
        ArrayList<Integer> b = new ArrayList<>();
        ArrayList<Integer> u = new ArrayList<>();
        for(int i = 0; i < l.length(); i++){
            if(l.charAt(i) == 'U'){
                if(b.size()>0){
                    if((i - b.get(b.size()-1)<=k) ){
                        ans++;
                        b.remove(b.size()-1);
                    }
                    else{
                        u.add(i);
                    }
                }
                else{
                    u.add(i);
                }
            }
            else{
                if(u.size()>0){
                    if( (i - u.get(u.size()-1))<=k){
                        ans++;
                        u.remove(u.size()-1);
                    }
                    else{
                        b.add(i);
                    }
                }
                else{
                    b.add(i);
                }
            }
        }
        System.out.println(ans);
    }
}