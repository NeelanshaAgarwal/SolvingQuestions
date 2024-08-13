#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert a vector to a linked list
Node* convertArrToLinkedList(vector<int>& arr){
    // Create a dummy node to serve
    // as the head of the linked list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Iterate through the vector and
    // create nodes with vector elements
    for(int i = 0; i < arr.size(); i++){
        // Create a new node with the vector element
        temp->next = new Node(arr[i]); 
        // Move the temporary pointer
        // to the newly created node
        temp = temp->next; 
    }
    // Return the linked list starting
    // from the next of the dummy node
    return dummyNode->next; 
}

// Function to merge two sorted linked lists
/*Node* sortTwoLinkedLists(Node* list1, Node* list2) {
    vector<int> arr;
    Node* temp1 = list1;
    Node* temp2 = list2;

    // Storing elements of both lists into a vector
    
    // Add elements from list1 to the vector
    while(temp1 != NULL){
        arr.push_back(temp1->data); 
        // Move to the next node in list1
        temp1 = temp1->next; 
    }
    
     // Add elements from list2 to the vector
    while(temp2 != NULL){
        arr.push_back(temp2->data);
        // Move to the next node in list2
        temp2 = temp2->next; 
    }
    
    // Sorting the vector in ascending order
    sort(arr.begin(), arr.end());

    // Converting the sorted vector
    // back to a linked list
    Node* head = convertArrToLinkedList(arr); 
    
    // Return the head of the
    // merged sorted linked list
    return head; 
}*/

Node* sortTwoLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node to serve
    // as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}


// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}

int main() {
    // Example Linked Lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node* mergedList = sortTwoLinkedLists(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}
    