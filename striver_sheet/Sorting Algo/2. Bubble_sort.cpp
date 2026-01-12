/*
what bubble sort does is after every outer loop iteration it moves largest element to the last available position

time complexity: O(n^2) ---> O(n) in the best case
*/

#include<bits/stdc++.h>
using namespace std;

void printarr(const vector<int>&nums) {
    for(int i=0;i<nums.size();i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void sortarr(vector<int>&nums) {
    //we can optimise this code by stopping the outer loop when no swaps take place in the inner loop
    //we can keep a count;
    int count = 0;
    for(int i=0;i<nums.size();i++) {
        for(int j=1;j<nums.size() - i;j++) {
            if (nums[j-1] > nums[j]) {
                swap(nums[j-1], nums[j]);
                count = 1;
            }
        }
        if (count == 0) {
            break;
        }
    }
}

int main() {
    vector<int>nums;
    int n;
    cout<<"Enter the size of the array:  ";
    cin>>n;

    for(int i=0;i<n;i++) {
        int m;
        cout<<"Enter --->";
        cin>>m;
        nums.push_back(m);
    }

    cout<<"Original array---> ";
    printarr(nums);
    cout<<endl;


    cout<<"Sorted array---> ";
    sortarr(nums);
    printarr(nums);
    cout<<endl;


    return 0;

}
