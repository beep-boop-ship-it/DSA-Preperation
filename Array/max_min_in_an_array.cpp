/*
Problem: finding max and min in an array
Level:easy
Platform: Geekforgeeks

Approach:Single traversal of the array, checking every element and updating max and min value accordingly
Time Complexity: O(n)
Space Complexity: O(1) -- > as i only created some variables which take up constant space complexity


*/

#include<bits/stdc++.h>
using namespace std;

void printarr(const vector<int>&nums) {
    for(int i=0;i<nums.size();i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

pair<int,int> maxminelem(const vector<int>&nums) {
    int maxer = nums[0];
    int miner = nums[0];
    for(int i=1;i<nums.size();i++) {
        if (maxer < nums[i]) {
            maxer = nums[i];
        }
        if (miner > nums[i]) {
            miner = nums[i];
        }
    }
    return {maxer,miner};
}



int main() {
    int k;
    cout<<"No of entries in your array: "<<endl;
    cin>>k;

    vector<int>nums;

    for(int i=0;i<k;i++) {
        int n;
        cout<<"Enter"<<":  ";
        cin>>n;
        nums.push_back(n);
    }

    cout<<"original array:  "<<endl;
    printarr(nums);

    pair<int,int>result = maxminelem(nums);
    cout<<"Max Element--->"<<result.first<<endl;
    cout<<"Min Element--->"<<result.second<<endl;
    return 0;
}
