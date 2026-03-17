/*
Linked List intro lec 1
*/


#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    ~node() {
        int temp = this->data;
        if (this->next != nullptr) {
            delete this->next;
            this->next = nullptr;
        }
        cout <<"Deleted element: " << temp << endl;
    }
};

void printlinkedlist(node *head) {
    node *temp = head;
    while (temp->next != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

node* convertarrtoLL(vector<int>&arr) {
    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthofll(node *&head) {
    int length = 0;
    node *temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

bool checkeleminLL(node *&head,int value) {
    node *temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}


int main() {
    /*
    // node y = node(arr[0],nullptr);

    //cout << y; this is not valid as y here now is a node
    cout << y.data << endl;
    cout << y.next << endl;
    cout << &(y.next) << endl;
    cout << &y << endl;
    //creating x as a ptr,pting to the new node
    //now we use it and access its values as a ptr

    vector<int>nums = {1,5,8,9};
    printlinkedlist(convertarrtoLL(nums));
    */

    int arr[4] = {2, 5, 6, 9};
    node *head = new node(arr[0]);
    node *n1 =   new node(arr[1]);
    head->next = n1;
    node *n2 =   new node(arr[2]);
    n1->next = n2;
    node *n3 =   new node(arr[3]);
    n2->next = n3;
    //before deletion
    printlinkedlist(head);

    //deleting the node
    n1->next = n3;
    n2->next = nullptr;
    delete n2;

    printlinkedlist(head);

    cout << lengthofll(head) << endl;

    if (checkeleminLL(head, 11)) cout << "found" << endl;
    else cout << "not found" << endl;


    return 0;
}

