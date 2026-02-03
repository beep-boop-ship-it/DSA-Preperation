/*
Problem Statement: There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
        Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.
Approach:
Brute Force Approach:
          create two arrays, to store orderwise postive and negative elements
          then rearrange the original arr, accordingly using them
        Time Complexity: O(n + n/2)
        Space Complexity: O(n)


Optimal Approach:  Create a vector, and create two ptr to be kept on this new array, to store the postives and negatives and increment by 2.
                   iterating over the original array, we store the elements on according index.
            Time Complexity: O(n)
            Space Complexity: O(n)
*/

//Optimal Approach
int main() {
    vector<int>nums = inputarray();

    int i = 0, j = 1;
    vector<int>ans(nums.size());
    for (int k = 0; k < nums.size(); k++) {
        if (nums[k]<0) {
            ans[j] = nums[k];
            j += 2;
        }
        else {
            ans[i] = nums[k];
            i += 2;
        }
    }
    printarr(nums);
    printarr(ans);
}


//brute force approach
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    vector<int>posarr;
    vector<int>negarr;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]<0) {
            negarr.push_back(nums[i]);
        }
        else {
            posarr.push_back(nums[i]);
        }
    }

    for(int i=0;i<nums.size();i++) {
        if (i % 2 == 0) {
            nums[i] = posarr[i/2];
        }
        else {
            nums[i] = negarr[i/2];
        }
    }
    return nums;
    }
};
