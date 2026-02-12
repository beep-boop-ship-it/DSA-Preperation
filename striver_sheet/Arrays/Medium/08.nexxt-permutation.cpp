/*
next_permutation : find next lexicographically greater permutation

Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

Brute Force Approach: 
Find all the possible permutations and then find the current array and return the next in the sorted order
Time Complexity: O(n! * n)

Optimal approach:
you follow the following three steps: 
               ------> you find the index of the pivot element, where the element is smaller than the previous element and break it
              -------> you find the smallest no. which is greater than the indexed element from the index + 1 to end of array but from reverse, so you can break it the first occurance of it only
              -------> you swap it with the indexed element and reverse the array from indexed + 1 to the end

Time Complexity: O(3N)
Space Complexity: O(1) + modifying the current array 


*/


//optimal approach


int main() {

    vector<int>nums = inputarray();
    printarr(nums);
    int index = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        reverse(nums.begin(), nums.end());
    }
    else {
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }

    printarr(nums);



    return 0;
}
 



*/
