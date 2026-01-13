/*
Problem: Move Zeroes
Platform: Leetcode ~ 283
Level ~ Easy


Approach: a two pointer approach, where initally both pointers are initialised at first element, one pointer moves always,
          while the other pointer moves until it discovers a zero and stops there
          when the first pointer discovers a non zero element and swaps them;
          by the nature of this problem, first pointer always stays ahead of the second pointer;
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j =0;
        while(i < nums.size()){
            if( nums[j] != 0 && nums[i] != 0){
                 j++;
            }
            else if (nums[i] != 0 && nums[j] == 0){
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
    }
};
