/*
Problem: You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

Approach: 
created two ptrs to iterate over the given two linked list and store the sum % 10 ; and keep the carry for next node sum / 10;

1st) handled the two loops together by creating conditional within the single loop;
2nd) handled cases diffrently but visually more complicated

Time Complexity:  O(n)
Space Complexity: O(1)
*/

//1st handles better with dummynode 
ListNode* addTwoNumbers(ListNode*l1, ListNode*l2) {
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    ListNode* dummyListNode  = new ListNode(-1);
    ListNode* curr = dummyListNode;
    int carry = 0;
    while (temp1 != nullptr || temp2 != nullptr) {
        int sum = carry;
        if (temp1)sum += temp1->val;
        if (temp2)sum += temp2->val;

        ListNode* newListNode = new ListNode(sum % 10);
        carry = sum / 10;

        curr->next = newListNode;
        curr = curr->next;

        if (temp1) temp1 = temp1->next;
        if (temp2) temp2 = temp2->next;
    }
    if (carry) curr->next = new ListNode(carry);
    return dummyListNode->next;
}


//2nd
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        int carry = sum / 10;
        int digit = sum % 10;
        ListNode* anshead = new ListNode(digit);
        ListNode* mover = anshead;
        ListNode *temp1 = l1->next, *temp2 = l2->next;
        while (temp1 != nullptr && temp2 != nullptr) {
            sum = temp1->val + temp2->val + carry;
            carry = sum / 10;
            digit = sum % 10;
            ListNode* temp3 = new ListNode(digit);
            mover->next = temp3;
            mover = temp3;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1 == nullptr && temp2 == nullptr) {
            if (carry != 0) {
                ListNode* lastel = new ListNode(carry);
                mover->next = lastel;
            }
            return anshead;
        } else if (temp1 == nullptr && temp2 != nullptr) {
            while (temp2 != nullptr) {
                sum = temp2->val + carry;
                carry = sum / 10;
                digit = sum % 10;
                ListNode* temp3 = new ListNode(digit);
                mover->next = temp3;
                mover = temp3;
                temp2 = temp2->next;
            }
            if (carry != 0) {
                ListNode* lastel = new ListNode(carry);
                mover->next = lastel;
            }
            return anshead;
        }
        while (temp1 != nullptr) {
            sum = temp1->val + carry;
            carry = sum / 10;
            digit = sum % 10;
            ListNode* temp3 = new ListNode(digit);
            mover->next = temp3;
            mover = temp3;
            temp1 = temp1->next;
        }
        if (carry != 0) {
            ListNode* lastel = new ListNode(carry);
            mover->next = lastel;
        }
        return anshead;
    }
