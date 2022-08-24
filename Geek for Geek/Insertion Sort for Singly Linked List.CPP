

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.



    ***********************************************************
*/


// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}




 // } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        Node* temp = head_ref;
        Node* limit = NULL;
        while(temp != limit){
            Node* t1 = temp;
            Node* t2 = temp->next;
            while(t2 != limit){
                if(t1->data > t2->data){
                    int t = t1->data;
                    t1->data = t2->data;
                    t2->data = t;
                }
                t1 = t1->next;
                t2 = t2->next;
            }
            limit = t1;
        }
        return head_ref;
    }
    
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;

        head = ob.insertionSort(head);
        printList(head);

        cout << "\n";



    }
    return 0;
}  // } Driver Code Ends