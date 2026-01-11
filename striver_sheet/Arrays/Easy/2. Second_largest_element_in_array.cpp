/*
  I/P ---> {1,4,5,6,7}
  O/p ----> 6

  Time Complexity: O(n)
  Space Complexity: O(1) --> O(n) is used for storing the input vector so im not counting that here
  
*/

#include<bits/stdc++.h>
using namespace std;

void printarr(const vector<int>&nums) {
    for(int i=0;i<nums.size();i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int maxerel(const vector<int>&nums) {
    int bans = nums[0], ans = -1;
    for(int i=1;i<nums.size();i++) {
        if (bans < nums[i]) {
            ans = bans;
            bans = nums[i];
        }
    }
    return ans;
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

    cout<<"Second Largest element is ---> "<<maxerel(nums)<<endl;

    return 0;

}
