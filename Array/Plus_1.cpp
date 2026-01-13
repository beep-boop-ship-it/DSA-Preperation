/*
Problem: You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Platform: Leetcode 66
Level: Easy

Approach: a similar approach as to sum of two arrays, i add a 1 on first iteration, and i handle carry accordingly,
could be a cleaner approach but time complexity is optimised

time complexity: O(n)
space complexity: O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int carry = 0;
        vector<int>ans;
        while(i>=0){
            int sum = digits[i] + carry;
            if ( i == digits.size() - 1) sum = sum + 1;
            int rem = sum % 10;
            carry = sum / 10;
            ans.push_back(rem);
            i--;
        }
        if(i < 0 && carry != 0) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
