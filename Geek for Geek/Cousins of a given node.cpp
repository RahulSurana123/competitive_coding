

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given a binary tree and a node, 
print all cousins of given node in order of their appearance. Note that siblings should not be printed.



    ***********************************************************
*/


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* pointer(Node* root, int n)
{
    if (root == NULL)
        return NULL;

    if (root->data == n)
        return root;

    Node* l = pointer(root->left, n);
    if (l != NULL && l->data == n)
        return l;

    Node* r = pointer(root->right, n);
    return r;

}


 // } Driver Code Ends
//User function Template for C++

/*
// A Binary Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

class Solution
{
    
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        vector<int> ans;
        vector<pair<Node*,Node*>> q;
        q.push_back({root,NULL});
        Node* p = NULL;
        bool f = false;
        while(!q.empty()){
            int s = q.size();
            vector<pair<Node*,Node*>> replace;
            while(s--){
                auto z = q[s];
                if(z.first == node_to_find){
                    p = z.second;
                    f = true;
                    break;
                }
                if(z.first->left) replace.push_back({z.first->left,z.first});
                if(z.first->right) replace.push_back({z.first->right,z.first});
            }
            if(f) break;
            q = replace;
            replace.clear();
        }
        if(f){
            for(int i = 0; i< q.size(); i++){
                if(q[i].second != p) ans.push_back(q[i].first->data);
            }
        }
        if(ans.size() == 0) return vector<int>(1,-1); 
        sort(ans.begin(),ans.end());
        return ans;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);
        
        struct Node* root = buildTree(inp);

        Node* p = pointer(root, n);

        Solution ob;
        vector<int> ans = ob.printCousins(root, p);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";


    }

    return 0;
}

  // } Driver Code Ends