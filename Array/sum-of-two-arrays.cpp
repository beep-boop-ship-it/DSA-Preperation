/*
Problem: You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively,
where each array element represents a digit.
You need to find the sum of these two numbers and return this sum in the form of an array.
Platform:  Code360

Approach: a simple cary forward approach implemented in reverse order to reverse it again
Time Complexity: O(n)
space complexity: O(1)

*/

#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	vector<int>ans;
    if (n<m){
        vector<int>temp = a;
        int t = n;
        a = b;
        n = m;
        b = temp;
        m = t;
    }
    int i = n - 1, j = m - 1;
    int carry = 0;
    while(i >= 0 || j >= 0) {
        if (j>=0) {
            int sum = a[i] + b[j] + carry;
            int rem = sum % 10;
            carry = sum / 10;
            ans.push_back(rem);
            i--;
            j--;
            if (i< 0 && j < 0 && carry != 0) {
                ans.push_back(carry);
            }
        }
        else {
            int sum = a[i] + carry;
            int rem = sum % 10;
            carry = sum / 10;
            ans.push_back(rem);
            i--;
            if (carry != 0 && i < 0) {
                ans.push_back(carry);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;

}
