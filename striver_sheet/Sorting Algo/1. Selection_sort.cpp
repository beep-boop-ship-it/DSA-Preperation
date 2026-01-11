/*
  Selection sort algo works on following theory
  you select first element, then you traverse the remaining array to check if any is smaller than it, if yes, you swap them
  you select second element, then you do the same thing with remaining array
  you keep doing this until you reach the last element

  time complexity: O(n)
  
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
    for(int i=0;i<nums.size();i++) {
        int miner = i;
        for(int j=i+1;j<nums.size();j++) {
            if(nums[j]<nums[miner]) {
                miner = j;
            }
        }
        swap(nums[i],nums[miner]);
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
