/*
QUESTION:-

Given an array A of positive integers. Your task is to find the leaders in the array. An element of the array is a leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader.

Example 1:
Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 as it is greater than all the elements to its right. Similarly, the next leader is 5. The rightmost element is always a leader, so it is also included.

*/

/*
APPROACH:-

To find the leaders in the array, we can follow these steps:

1. Initialize a variable `maxRight` with the rightmost element of the array.
2. Iterate the array from right to left:
   - If the current element is greater than or equal to `maxRight`, it is a leader. Print the current element and update `maxRight` to the current element.
3. Finally, print `maxRight` as it is always a leader.

*/

// CODE:
int main() {
    vector<int>nums = inputarray();
    printarr(nums);
    vector<int>ans;
    int max = nums[nums.size()-1];
    ans.push_back(max);
    int i = nums.size() - 2;

    while (i >= 0) {
        if (nums[i] > max) {
            max = nums[i];
            ans.push_back(max);
        }
        i--;
    }
    reverse(ans.begin(), ans.end());
    printarr(ans);
}
