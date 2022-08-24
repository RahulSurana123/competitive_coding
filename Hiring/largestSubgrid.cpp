


/* 
    Solution by Rahul Surana
    
    ***********************************************************



Given a square grid of integers and an integer value,  maxSum , 
determine the maximum size of the square sub-grid where for all such sub-grids, the sum of all its elements' values is less than or equal to the value  maxSum . 

   

  Example: 
 grid =[[2, 2, 2], [3, 3, 3], [4, 4, 4]] 

  maxSum: different scenarios shown below  

   

  maxSum:  The maximum sum of all square sub-grids of a size must be less than or equal to this integer value 

1. The maximum 1x1 grid has a sum of 4.  If  maxSum &lt; 4  there is no size square sub-grid that satisfies the condition. The answer is 0. 


2. The maximum 2x2 grid has a sum of 14.  If  4 ≤ maxSum &lt; 14 , the maximum size of the square sub-grid is 1. 


3. The maximum 3x3 grid has a sum of 27.  If  14 ≤ maxSum &lt; 27 , the maximum size of the square sub-grid is 2.


4. If  maxSum  ≥  27 , the entire grid satisfies the condition so the answer is  3 .
 

   

   

  Function Description  

 Complete the function  largestSubgrid  in the editor below. 

   

 largestSubgrid has the following parameter(s): 

      int grid[n][n]:  an  n × n  array where  grid[i][j]  is the value of the cell in the  i<sup>th</sup>  row and  j<sup>th</sup>  column 

      int maxSum:   an integer, the maximum acceptable sum of any sub-grid 

 Returns: 

     int:  an integer that denotes the largest integer k such that there is no  k × k  sub-grid with a total value greater than  maxSum . If all square sub-grids have value greater than  maxSum , the function should return 0. 

   

Constraints 

 
    <li> 1 ≤ n ≤ 1550  
    <li> 1 ≤ maxSum ≤ 10<sup>9</sup>  
    <li> 1 ≤ grid[i][j] ≤ 10<sup>7</sup>  
    <li>the sum of any entire grid is ≤ 10<sup>9</sup>
 
 

   
<!--       <StartOfInputFormat> DO NOT REMOVE THIS LINE-->

 <summary class="section-title">Input Format for Custom Testing</summary>

<div class="collapsable-details">
 Input from stdin will be processed as follows and passed to the function .  

   

 In the first line, there is a single integer  n  representing the number of rows in  grid . 

 In the second line, the integer  n  is repeated and represents the number of columns in  grid . 

 Each of the next  n  lines contains a row,  grid[i] , containing  n  space-separated integers, each representing a value of  grid[i][j] . 

 In the last line, there is a single integer  maxSum . 

   
 
 
<!--        </StartOfInputFormat> DO NOT REMOVE THIS LINE-->

Sample Case 0

<div class="collapsable-details">
<p class="section-title">Sample Input 0 

 STDIN     Function 
 -----     -------- 
</strong>3      →   grid[n][n]  n = 3  
3        </strong>
1 1 1  →   grid = [[1,1,1], [1,1,1], [1,1,1]] 
1 1 1
1 1 1
4      →   </strong> maxSum = 4 
 

<p class="section-title">Sample Output 0 

 2
 

<p class="section-title">Explanation 0 

  n  = 3 

  grid = [[1,1,1], [1,1,1], [1,1,1]]  

  maxSum = 4 . 

   

 
    <li>Square grid of 3 rows and 3 columns : 
    <li>Each square sub-grid of size 1 has a sum of values = 1 
    <li>Each square sub-grid of size 2 has a sum of values = 4 
    <li>The square sub-grid of size 3 has a sum of values = 9 
 

   

 The maximum size of the appropriate sub-grid ( 4 &lt;= 4). 

   
 
 

 <summary class="section-title">Sample Case 1</summary>

<div class="collapsable-details">
<p class="section-title">Sample Input 1 

 STDIN       Function
 -----       -------- </strong>
4        →    grid[n][n] n = 4 
4     
1 1 1 1  →    grid = [[1,1,1,1], [2,2,2,2], [3,3,3,3], [4,4,4,4]] 
2 2 2 2
3 3 3 3
4 4 4 4
39       →   </strong>maxSum = 39
 

<p class="section-title">Sample Output 1 

 3
 

<p class="section-title">Explanation 1 

  n = 4  

  grid = [[1,1,1,1], [2,2,2,2], [3,3,3,3], [4,4,4,4]]  

  maxSum = 39 . 

   

 
    <li>Square grid of 4 rows and 4 columns : 
    <li>A square sub-grid of size 1 has a maximum sum of values = 4 
    <li>A square sub-grid of size 2 has a maximum sum of values = 14 
    <li>A square sub-grid of size 3 has a maximum sum of values = 27 
    <li>A square sub-grid of size 4 has a maximum sum of values = 40 
 

   

 The maximum size of appropriate sub-grid is 3, (27 &lt; 39). 
 
 

 <summary class="section-title">Sample Case 2</summary>

<div class="collapsable-details">
<p class="section-title">Sample Input 2 

 STDIN     Function
 -----     -------- </strong>
2      →   grid[n][n] n = 2 
2    </strong>
4 5    →   grid = [[4,5], [6,7]]  
6 7
2      →   </strong> maxSum = 2 
 

<p class="section-title">Sample Output 2 

 0
 

<p class="section-title">Explanation 2 

  n = 2  

  grid = [[4,5],[6,7]]  

  maxSum = 2  

   

 
    <li>Square grid of 2 rows and 2 columns : 
    <li>A square sub-grid of size 1 has a maximum sum of 7. 
    <li>A square sub-grid of size 2 has a maximum sum of 22. 
 

   

 Any size sub-grid has a maximum sum &gt; 2. 
 
 
 



    ***********************************************************
*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'largestSubgrid' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY grid
 *  2. INTEGER maxSum
 */

int largestSubgrid(vector<vector<int>> grid, int maxSum) {
    int z = 0;
    int ans = 0;
    vector<vector<int>> ss(grid.size(),vector<int>(grid[0].size(),0));
    ss[0][0] = grid[0][0];
    for(int i = 1 ; i < grid.size(); i++){
        ss[0][i] = grid[0][i] + ss[0][i-1];
    }
    for(int i = 1 ; i < grid[0].size(); i++){
        ss[i][0] = grid[i][0] + ss[i-1][0];
    }
    for(int i = 1; i < grid.size(); i++){
        for(int j = 1; j < grid[0].size(); j++){
            ss[i][j] = grid[i][j]+ss[i-1][j]+ss[i][j-1]- ss[i-1][j-1];
        }
    }
    int f = 0;
    while(z < maxSum && f < min(grid.size(),grid[0].size())){
        for(int i = 0 ; i < grid.size()-f; i++){
            for(int j = 0 ; j < grid[0].size()-f; j++){
                int q = ss[i+f][j+f];
                if(i+f < grid.size()) q -= ss[i+f][j];
                if(j+f <grid[0].size()) q -= ss[i][j+f];
                if(i+f <grid.size() && j+f <grid[0].size()) q+= ss[i][j];
                z = max(z,q);
                if(z>maxSum) break;
            } 
        }
        if(z > maxSum) return f-1;
        if(z == maxSum) return f;
        ans++;
        // cout << z <<" "<<f <<"\n";
        f++;
    }
    return min(grid.size(),grid[0].size())-1;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grid_rows_temp;
    getline(cin, grid_rows_temp);

    int grid_rows = stoi(ltrim(rtrim(grid_rows_temp)));

    string grid_columns_temp;
    getline(cin, grid_columns_temp);

    int grid_columns = stoi(ltrim(rtrim(grid_columns_temp)));

    vector<vector<int>> grid(grid_rows);

    for (int i = 0; i < grid_rows; i++) {
        grid[i].resize(grid_columns);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < grid_columns; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }

    string maxSum_temp;
    getline(cin, maxSum_temp);

    int maxSum = stoi(ltrim(rtrim(maxSum_temp)));

    int result = largestSubgrid(grid, maxSum);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
