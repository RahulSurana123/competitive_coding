



/* 
    Solution by Rahul Surana
    
    ***********************************************************


A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.



    ***********************************************************
*/




// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node*head){
        if(head==NULL)
        return NULL;
        Node*pre=NULL;
        Node*temp=head;
        while(head){
            temp=head;
            head=head->next;
            temp->next=pre;
            pre=temp;
        }
        return pre;
    }
    
    Node* addOne(Node *head) 
    {
        Node* r = reverse(head);
        
        Node*p=r;
        int carry=1;
        Node*end;
        while(p){
            if(carry==0)
            break;
            if(p->next==NULL)
            end=p;
            carry=(p->data+1)/10;
            p->data=(p->data+1)%10;
            p=p->next;
        }
       if(carry!=0){
       Node*temp=new Node(carry);
       end->next=temp;
       temp->next=NULL;
       }
       head=reverse(r);
       return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends