/*
Implementation using array
printing
Insertion
Deletion
*/

#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node* prev;

    node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ~node() {
        int value = this->data;

        if (this->next != nullptr) {
            delete next;
            next = nullptr;
        }

        cout << value << " deleted" << endl;
    }
};


void printDLL(node*head) {
    if (head == nullptr) {
        cout << "empty linked list " << endl;
        return;
    }
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next)cout << "<->";
        temp = temp->next;
    }
    cout << endl;

}

node* implementdllusingarr(vector<int>&arr) {
    if (arr.empty()) {
        return nullptr;
    }
    node *head = new node(arr[0]);
    node *temp = head;
    for (int i = 1; i < arr.size(); i++) {
        node *n = new node(arr[i]);
        temp->next = n;
        n->prev = temp;
        temp = n;
    }
    return head;
}

void printinreverse(node*head) {
    node* temp = head;
    cout << "In Normal order: " << endl;
    while (temp->next != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
    cout << "In Reverse Order: " << endl;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->prev) cout << "->";
        temp = temp->prev;
    }
    cout << endl;
}


//insertioninlinkedlist
node* insertathead(node*&head,int data) {
    if (head == nullptr) {
        head = new node(data);
        return head;
    }
    node* temp = new node(data);
    head->prev = temp;
    temp->next = head;
    head = temp;
    return head;
}

node* insertattail(node*&head, int data) {
    if (head == nullptr) {
        head = new node(data);
        return head;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    node* newnode = new node(data);
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

node* insertatposition(node*&head, int data, int pos) {
    if (head == nullptr) {
        head = new node(data);
        return head;
    }
    node* temp = head;
    int ct = 1;
    while (temp != nullptr) {
        if (ct == pos) {
            break;
        }
        ct++;
        temp = temp->next;
    }
    if (temp == nullptr) {
        if (ct == pos)return insertattail(head,data);
        else {
            cout << "Position out of range" << endl;
            return head;
        }
    }
    else if (ct == 1) {
        return insertathead(head,data);
    }
    node* back = temp->prev;
    node* insertnode = new node(data);
    back->next = insertnode;
    temp->prev = insertnode;
    insertnode->next = temp;
    insertnode->prev = back;
    return head;

}

node* insertbeforevalue(node*&head,int data, int value) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->data == value) {
        return insertathead(head,data);
    }
    node* curr = head->next;
    node* prev = head;
    while (curr != nullptr) {
        if (curr->data == value) {
            node * temp = new node(data);
            prev->next = temp;
            temp->prev = prev;
            temp->next = curr;
            curr->prev = temp;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

//deletion
node* deletehead(node*&head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

node* deletetail(node*&head) {
    if (head == nullptr) {
        return nullptr;
    }
    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }
    node* temp = head->next;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

node* deleteposition(node*&head, int position) {
    if (head == nullptr) {
        return nullptr;
    }
    int ct = 0;
    node* temp = head;
    while (temp != nullptr) {
        ct++;
        if (ct == position) break;
        temp = temp->next;
    }
    if (ct != position) {
        return head;
    }
    node* front = temp->next;
    node* back = temp->prev;
    if (front == nullptr && back == nullptr) {
        delete temp;
        return nullptr;
    }
    else if (front == nullptr) {
        return deletetail(head);
    }
    else if (back == nullptr) {
        return deletehead(head);
    }
    back->next = front;
    front->prev = back;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

node* deletebyvalue(node*&head,int x) {
    if (head == nullptr) {
        return nullptr;
    }
    node* temp = head;
    while (temp != nullptr) {
        if (temp->data == x) break;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "NOT FOUND " << x << endl;
        return head;
    }
    node* front = temp->next;
    node* back = temp->prev;
    if (front == nullptr && back == nullptr) {
        delete temp;
        return nullptr;
    }
    else if (front == nullptr) {
        return deletetail(head);
    }
    else if (back == nullptr) {
        return deletehead(head);
    }
    back->next = front;
    front->prev = back;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

void deletebynode(node*&n) {
    if (n == nullptr) {
        return;
    }
    node* front = n->next;
    node* back = n->prev;
    if (front == nullptr && back == nullptr) {
        delete n;
        return;
    }
    else if (front == nullptr) {
        back->next = nullptr;
        n->prev = nullptr;
        delete n;
        return;
    }
    else if (back == nullptr) {
        node* temp = n;
        front->prev = nullptr;
        temp->next = nullptr;
        n = front;
        delete temp;
        return;
    }
    back->next = front;
    front->prev = back;
    n->next = nullptr;
    n->prev = nullptr;
    delete n;
}

node* returntail(node*&head) {
    if (head == nullptr) {
        return nullptr;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp;
}

int main() {

    vector<int>arr = {1,2,3,4,5,6,7,8,9};
    node* head = implementdllusingarr(arr);
    printDLL(head);
    // printDLL(deletehead(head));
    // printDLL(deletetail(head));
    // printDLL(deleteposition(head,7));
    printDLL(deletebyvalue(head,9));
    node* n1 = returntail(head);
    deletebynode(n1);
    printDLL(head);
    printDLL(insertathead(head,0));
    printDLL(insertattail(head,8));
    printDLL(insertatposition(head,9,14));

    return 0;
}
