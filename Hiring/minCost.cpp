

/* 
    Solution by Rahul Surana
    
    ***********************************************************



Given a directed graph, find the minimum path from node <em>1</em> to node <em>g_nodes</em>
 

 Given a directed graph with weighted edges, determine the minimum weighted path from node <em>1</em> to the last node. 

  

 A directed graph is defined <em>g</em> such that: 

 
     The total number of nodes in the graph is <em>g_nodes</em>. 
     The nodes are numbered sequentially as <em>1, 2, 3, …, g_nodes</em>. 
     The total number of edges in the graph is <em>g_edges</em>. 
     Each edge connects two distinct nodes (i.e., no edge connects a node to itself). 
     The edge connecting nodes <em>g_from[i]</em> and <em>g_to[i]</em> is directed. In other words, it describes a path only in the direction <em>g_from[i] → g_to[i]</em>. 
     The weight of the edge connecting nodes <em>g_from[i]</em> and <em>g_to[i]</em> is <em>g_weight[i]</em>. 
 

  

 The <em>weight</em> of a path from node <em>1</em> to node <em>g_nodes</em> is defined to be the sum of all edges traversed on that path. 

  

 Find the path from node <em>1 </em>to node <em>g_nodes </em>having the minimum possible weight. Extra directed edges having weight <em>1 </em>(one) can be added between any two distinct nodes that are not already connected by an edge. 

  

<p class="section-title">Example 

 The following list of edges in a <em>4 </em>note graph is given: 

<pre>From   To  Weight
1   2   3
1   3   2
2   1   3
1   4   5
</pre>

  

 In the graph below, an additional edge has been added from <em>3</em> to <em>4</em>. The minimum total cost to get from node <em>1</em> to node <em>4</em> is <em>3</em>, <em>1 →<sub>2</sub> 3 →<sub>1</sub> 4</em>. 

  

 <img height="270" src="https://hrcdn.net/s3_pub/istreet-assets/SH_Lf1Y6yY5uUND3ftWByA/minimum_weight_path_in_a_directed_graph_example.svg" width="193"> 

  

<p class="section-title">Function Description 

 Complete the function <em>minCost</em> in the editor below. 

  

 <em>minCost</em> has the following parameter(s): 

    <em>g_nodes:</em> an integer representing the number of nodes in graph <em>g</em> 

    <em>g_from[n-1]:</em> an array of integers representing edge origin nodes 

    <em>g_to[n-1]:</em> an array of integers representing edge target nodes 

    <em>g_weight[n-1]:</em> an array of integers representing edge weights 

  

 Returns: 

    <em>int: </em>the minimum possible weight of any path from node <em>1 </em>to node <em>g_nodes</em> 

  

<p class="section-title">Constraints 

 
     <em>3 ≤ g_nodes ≤ 10<sup>3</sup></em> 
     <em>1 ≤ g_edges ≤ <em>min</em>(10<sup>4</sup>, <sup>(g_nodes × (g_nodes − 1))</sup> ⁄ <sub>2</sub>)</em> 
     <em>1 ≤ g_weight[i] ≤ 10<sup>6</sup></em> 
 
<!--       <StartOfInputFormat> DO NOT REMOVE THIS LINE-->

 <summary class="section-title">Input Format for Custom Testing</summary>

<div class="collapsable-details">
 Input from stdin will be processed as follows and passed to the function. 

  

 The first line contains two space-separated integers, <em>g_nodes</em> and <em>g_edges</em>. 

 Each of the next <em>g_edges</em> lines contains three space-separated integers, <em>g_from, g_to</em> and <em>g_weight</em>. 
 
 

<details open="open"><summary class="section-title">Sample Case 0</summary>

<div class="collapsable-details">
<p class="section-title">Sample Input 

<pre>STDIN     Function
-----     -----
2 1    →  g_nodes = 2, g_edges = 1
1 2 3  →  g_from = 1, g_to = 2, g_weight = 3
</pre>

  

<p class="section-title">Sample Output 

<pre>3
</pre>

  

<p class="section-title">Explanation 

 <img height="150" src="https://hrcdn.net/s3_pub/istreet-assets/V4dYVst8zqwx9C0H_AmwNA/minimum_weight_path_in_a_directed_graph_sample_0.svg" width="241"> 

  

 A directed edge already exists from node <em>1</em> to node <em>2</em> and the path <em>1 → 2</em> is the minimum cost path, so the function returns <em>3</em>. 
 
 

 <summary class="section-title">Sample Case 1</summary>

<div class="collapsable-details">
<p class="section-title">Sample Input 

<pre>STDIN     Function
-----     -----
3 1    →  g_nodes = 3, g_edges = 1
1 2 3  →  g_from = 1, g_to = 2, g_weight = 3</pre>

  

<p class="section-title">Sample Output 

<pre>1</pre>

  

<p class="section-title">Explanation 

  

 <img height="200" src="https://hrcdn.net/s3_pub/istreet-assets/wvwwSJG9zbf2QZ5fn21uAA/minimum_weight_path_in_a_directed_graph_sample_1.svg" width="206"> 

 As graph <em>g</em> has no edge between node <em>1</em> and node <em>3</em>, an extra edge can be added from node <em>1</em> to node <em>3</em> having weight <em>1</em>. Thus, the path <em>1 → 3</em> is the minimum weight path and the function returns <em>1</em>. 
 
 

 <summary class="section-title">Sample Case 2</summary>

<div class="collapsable-details">
<p class="section-title">Sample Input 

<pre>STDIN     Function
-----     -----
4 4    →  g_nodes = 4, g_edges = 4
1 2 3  →  g_from = 1, g_to = 2, g_weight = 3
1 3 3  →  g_from = 1, g_to = 3, g_weight = 3
1 4 3  →  g_from = 1, g_to = 4, g_weight = 3
2 1 3  →  g_from = 2, g_to = 1, g_weight = 3</pre>

  

<p class="section-title">Sample Output 

<pre>3</pre>

  

<p class="section-title">Explanation 

  

 <img height="280" src="https://hrcdn.net/s3_pub/istreet-assets/Ub2A_2h_gDdpuCo0tYd2KA/minimum_weight_path_in_a_directed_graph_sample_2.svg" width="233"> 

 A directed edge already exists from node <em>1</em> to node <em>4</em> and the path <em>1 → 4</em> is the minimum cost path, so the function returns <em>3</em>. 




    ***********************************************************
*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'minCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int minCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<vector<pair<int,int>>> adj(g_nodes+1,vector<pair<int,int>>());
    // vector<int> cg;
    for(int i = 0; i < g_from.size(); i++){
        // if(g_to[i] == g_nodes) cg.push_back(g_from[i]);
        adj[g_from[i]].push_back({g_weight[i],g_to[i]});
    }
    bool f = false,d = false;
    for(int i = 0; i < adj[1].size(); i++){
        if(adj[1][i].second == g_nodes) f = true;
        // if(find(cg.begin(),cg.end(),adj[1][i].second) != cg.end()){
        //     d = true;
        // }
    }
    if(!f) return 1;
    for(int i = 2; i < g_nodes; i++){
        bool n = false;
        // if(adj[1][i].second == g_nodes) f = true;
        for(int j = 0; j < adj[1].size(); j++){
            if(adj[1][j].second == i) n = true;
        }
        for(int j = 0; j < adj[g_nodes].size(); j++){
            if(adj[g_nodes][j].second == i) n = true;
        }
        if(!n) return 2;
    }
    priority_queue<pair<int,int>> x;
    x.push({0,1});
    int ans = 1e9;
    while(!x.empty()){
        pair<int,int> z = x.top();
        x.pop();
        if(z.first > ans) continue;
        if(z.second == g_nodes) ans = min(z.first,ans);
        for(int i = 0; i < adj[z.second].size(); i++){
            x.push({z.first+adj[z.second][i].first,adj[z.second][i].second});
        } 
    }
    if(ans == 1e9) return 1;
    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int result = minCost(g_nodes, g_from, g_to, g_weight);

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
