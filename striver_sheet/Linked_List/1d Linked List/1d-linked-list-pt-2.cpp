/*

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
    node(int data, node *next) {
        this->data = data;
        this->next = next;
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
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
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

//insertion of linked list
node* insertathead(node *&head, int data) {
    node *temp = new node(data);
    if (head == nullptr) {
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
    cout << "element inserted at head: " << data << endl;
    return head;
}

node* insertathead1(node *&head,int data) {
    node *temp = new node(data,head);
    cout << "element inserted at head: " << data << endl;
    head = temp;
    return head;
}

node* insertattail(node *&head, int data) {
    node *temp = head;
    if (head == nullptr ) {
        head = new node(data);
        return head;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new node(data);
    cout << "element inserted at tail: " << data << endl;
    return head;
}

node* insertatposition(node *&head, int position, int data) {
    //assuming indexing for position starts from 1 to n + 1
    if (position == 1 ) {
        return insertathead(head,data);

    }
    int ct = 0;
    node *temp = head;
    while (temp != nullptr) {
        ct++;
        if (ct == position - 1) {
            node *temp2 = new node(data);
            temp2->next = temp->next;
            temp->next = temp2;
            cout << "element inserted at position: " << position <<" with data: " << data << endl;
            break;

        }
        temp = temp->next;
    }
    return head;
}

node* insertbeforevalue(node *&head, int data, int value) {
    node *temp = head;
    if (head == nullptr) {
        return head;
    }
    if (head->data == value) {
        node *temp2 = new node(data);
        temp2->next = head;
        head = temp2;
        return head;
    }
    node *prev = head;
    head = head->next;
    while (temp != nullptr) {
        if ( temp->data == value ) {
            node *temp2 = new node(data);
            prev->next = temp2;
            temp2->next = temp;
            cout << "node inserted before " << value << endl;
            break;

        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

//deletion of linked list
node* deleteathead(node *&head) {
    if (head == nullptr) {
        return head;
    }
    node *temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
    return head;
}

node* deleteattail(node *&head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return head;
    }
    node *temp = head;
    node *prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
    return head;
}

node* deleteatposition(node *&head, int position) {
    if (head == nullptr) return head;
    if (position == 1) {
        return deleteathead(head);
    }
    int len = lengthofll(head);
    if (position == len) {
        return deleteattail(head);
    }
    if (position > len) {
        return head;
    }

    int count = 0;
    node *temp = head;
    node *prev = nullptr;
    while (temp != nullptr) {
        count++;
        if (count == position) {
            prev->next = temp->next;
            temp->next = nullptr;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;

}

node* deletebyvalue(node *&head, int value) {
    if (head == nullptr) {
        return head;
    }
    if (head->data == value) {
        node *temp = head;
        head = head->next;
        temp -> next = nullptr;
        delete temp;
        return head;
    }
    node *temp = head;
    node *prev = nullptr;
    while (temp != nullptr) {
        if (temp->data == value) {
            prev->next = temp->next;
            temp->next = nullptr;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
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

    vector<int> arr = {1,3,5,7,9,11, 13};
    node* head = convertarrtoLL(arr);
    printlinkedlist(head);
    printlinkedlist(deletebyvalue(head,1));
    printlinkedlist(deleteatposition(head,2));

    printlinkedlist(insertathead(head,1));
    printlinkedlist(insertathead1(head,5));

    printlinkedlist(insertattail(head,15));
    printlinkedlist(insertatposition(head,5,19));

    printlinkedlist(insertbeforevalue(head,12,15));





    return 0;
}
