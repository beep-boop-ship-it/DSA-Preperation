/*
Problem:  Check if Array Is Sorted and Rotated
Platform: Leetcode Easy 1752

Approach --> we apply check over (a,b) elements in our array, a<=b is allowed always
a>b  is allowed once
if the a>b is not present even once, then also its true as our array is already sorted
if a>b once, we have to ensure that the first element of the array is greater than the last element to ensure the sorted nature of the array
Test Case where i failed initially [2,1,3,4]

Time Complexity: O(n)
space complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int i = 0, j = 0;

        while(i < nums.size() - 1){
            if (nums[i+1] > nums[i]) i++;
            else if(nums[i+1] == nums[i]) i++;
            else{
                i++;
                j++;
            }
        }
        if ( j == 0) return true;
        else if( j== 1 && nums[0] >= nums[nums.size() - 1]) return true;
        else return false;
    }
};
