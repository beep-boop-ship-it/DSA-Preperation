/*
  problem:   Merge Sorted Array
  platform : Leetcode~88
  level : Easy

  Approach:
  a three pointer approach 
  ptr 1 at end of the larger array, ptr 2 at the end of the non zero element array in larger arr, ptr 3 at the end of smaller arr
  that runs till the pointer at the smaller array does not get less than zero

  time approach: O(n + m)
  space approach: inplace, O(1)
*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    int i = m - 1;
    int j = n - 1;
    int k = (m+n) - 1;
    while(j >= 0) {
        if ( i >= 0) {
            if(nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        else {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
    }
};
