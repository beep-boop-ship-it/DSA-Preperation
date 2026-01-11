/*
  Problem: Move zeroes to right
  Platform: Leetcode 283
  level: Easy

  Approach: Two pointer approach, both incremented until they reach the zero element, then one stays at zero while th other seac=rches for the non zero element and then swaps
  
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j =0;
        while(i < nums.size()){
            if ( nums[i] == 0) i++;
            else if( nums[j] != 0 && nums[i] != 0){
                 j++;
                 i++;
            }
            else{
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};
