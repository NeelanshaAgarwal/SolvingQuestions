#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class ListNode {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    ListNode* next;      

    // Constructor with both data and
    // next node as parameters
    ListNode(int data1, ListNode* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    ListNode(int data1) {
        data = data1;
        next = nullptr;
    }
};

ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy, * nex = dummy, * pre = dummy;
        int count = 0;
        while(curr!=NULL){
            curr=curr->next;
            count++;
        }
        while(count>=k){
            curr=pre->next;
            nex = curr->next;
            for(int i = 1; i < k; i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            count-=k;
        }
        return dummy->next;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 5, 4, 3, 7, 9 and 2
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseKGroup(head, 4);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}