

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given K sorted linked lists of different sizes. 
The task is to merge them in such a way that after merging they will be a single sorted linked list.



    ***********************************************************
*/


#include <bits/stdc++.h>

// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        Node* root = new Node(-1);
        Node* temp = root;
        bool f  = true;
        while(f){
            int z = -1;
            int m = INT_MAX;
            f = false;
            for(int i = 0; i < K; i++){
                if(arr[i] != NULL) {
                    f = true;
                    if(m > arr[i]->data){
                        m = arr[i]->data;
                        z = i;
                    }
                }
            }
            if(z == -1) break;
            temp->next = arr[z];
            temp = temp->next;
            arr[z] = arr[z]->next;
        }
        return root->next;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int N;
       cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr,N);
        printList(res);

   }

    return 0;
}
  // } Driver Code Ends