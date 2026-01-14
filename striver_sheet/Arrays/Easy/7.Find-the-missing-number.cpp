/*

Problem: Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
Platform: Leetcode ~ 268
Level: Easy

Brute Approach(initial): a new vector created of arr.size() + 1, mapped the count of each value in given array, in another loop returned the value which had 0 count

Time Complexity: O(n)
Space Complexity: O(n) ---> as a new vector was being created


Better Approach: a variable is used to create an int that is xor'd ^ with all the integers in the given range;
                then this variable is xor'd with all the elements in the given array, all duplicates get cancelled and only the missing element 
                remains
Time Complexity: O(n) --->Same/slightly less
Space Complexity: O(1) ----> optimised
                    


*/

//better approach

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorA = 0;
        int n = nums.size();

        for(int i = 1; i <= nums.size(); i++){
            xorA^=i;
        }

        for(auto it: nums){
            xorA = xorA^it;
        }
        return xorA;
    }
};


//brute force approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>ans(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++){
            int index = nums[i];
            ans[index]++;
        }
        int missingans;
        for (int i = 0; i < ans.size(); i++){
            if (ans[i] == 0){
            missingans = i;
            break;
            }
        }
        return missingans;
    }
};
