/*
Problem Statement: Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.
                    The sorting must be done in-place, without making a copy of the original array.

Optimal approach: 
three pointer approach, one to traverse the array, the other two at the both extremes to put the 0s and 2s discovered by the first ptrs traversal

Time Complexity: O(n)
Space Complexity: O(1) --> no new variables created

*/
int main() {
    vector<int>nums = inputarray();

    cout<<"Original array: "<<endl;
    printarr(nums);

    int L = 0,M = 0, R = nums.size() - 1;
    while (M <= R) {
        if (nums[M] == 0) {
            swap(nums[L], nums[M]);
            L++;
        }
        else if (nums[M] == 2) {
            swap(nums[M], nums[R]);
            R--;
        }
        else {
            M++;
        }
    }
    cout<<"Sorted array: "<<endl;
    printarr(nums);

    return 0;
}
