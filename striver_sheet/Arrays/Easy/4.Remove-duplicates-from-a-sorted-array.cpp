/*
  Problem: . Remove Duplicates from Sorted Array
  Platform: Leetcode - 26
  Level: Easy

  I/P ---> [0 0 1 1 1 2 2 3 3 4]
  O/P ---> 5, [0 1 2 3 4]

  Approach: Two pointer approach where one iterates and check if adjacent items are same the other which counts the unique elements and update values in first places for the unique elements

  Time Complexity: O(n)
  space Complexity: O(1)
  
*/



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        while(i < nums.size() - 1) {
            if (nums[i] != nums[i+1]) {
                 nums[j] = nums[i + 1];
                j++;
            }
            i++;
        }
    return j;
    }
};
