/*
Problem: Single Number
Platform: Leetcode ~ 136
Level: Easy

Appoach: xord all the elements

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto it: nums){
            ans^=it;
        }
        return ans;
    }
};
