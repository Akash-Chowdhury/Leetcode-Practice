//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
public:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    Node* middle(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Adjust middle node for even-length linked list
        if (fast != NULL) {
            slow = slow->next;
        }

        // Disconnect the first and second halves
        prev->next = NULL;

        return slow;
    }

    // Function to check whether the list is palindrome.
    bool isPalindrome(Node* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        Node* mid = middle(head);
        Node* last = reverse(mid);
        Node* curr = head;

        // Compare elements
        while (last != NULL) {
            if (curr->data == last->data) {
                curr = curr->next;
                last = last->next;
            } else {
                return false;
            }
        }

        // Restore the original list by reversing the second half again
        mid->next = reverse(mid->next);

        return true;
    }
};




//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends