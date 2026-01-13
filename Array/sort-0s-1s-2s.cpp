/*

Problem: Sort Colors
Platform: Leetcode 75
level: medium

approach:
3 ptr approach, 1 ptr to stop at 0, 3rd ptr at the end till it reaches two, 2nd ptr to iterate till 1 and swap accordingly with 0 and 2

time complexity : O(n)
space complexity : O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1, mid = 0;

    while(mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;

        }
        else if (nums[mid] == 2) {
            swap(nums[high], nums[mid]);
            high--;
        }
        else {
            mid++;
        }
    }
    }
};
