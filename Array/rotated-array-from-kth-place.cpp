/*
Problem:  rotated array from the kth place
Platform: Leetcode 189
Level: medium

better Approach: Created a new array of equal size where
new_arr[ i + k % n ] = arr[i];
Time Complexity: O(n)
space complexity: O(n) ---> new vector created;

brute force approach:
an outer loop that runs k times, and inner loop that swaps the first element until it reaches the last position.
Time complexity: O(n^2)
Space Complexity: O(1)

Approach: 
*/


//better approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>temp(nums.size());
        for (int i = 0; i < nums.size(); i++){
            temp[(i + k )% nums.size()] = nums[i];
        }
        nums = temp;
        
    }
};


//brutal force approach
#include<bits/stdc++.h>
using namespace std;

void printarr(const vector<int>&nums) {
    for(int i=0;i<nums.size();i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void rotatedarray(vector<int>&nums, int k) {
    for (int i=0;i<k;i++) {
        for (int j=0;j<nums.size() - 1;j++) {
            swap(nums[j],nums[j+1]);
        }
    }
}

int main() {
    vector<int> nums;
    int s;
    cout<<"Enter the size of array:  ";
    cin>>s;

    for (int i=0;i<s;i++) {
        int num;
        cout<<"Enter the number:  ";
        cin>>num;
        nums.push_back(num);
    }

    int m;
    cout<<"Rotate from where";
    cin>>m;

    cout<<"original array: "<<endl;
    printarr(nums);
    cout<<"Rotated array: "<<endl;
    rotatedarray(nums,m + 1);
    printarr(nums);
}
