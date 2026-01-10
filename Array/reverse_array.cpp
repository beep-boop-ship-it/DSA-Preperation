/*
 reversing an array after mth index
problem : reversing an array after the mth index
platform: CodeStudio
difficulty: easy

Approach: two pointer approach, one pointer at m + 1th index and the other at the end, an you keep swapping until they meet
time complexity: O(n) 
space complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void printarr(const vector<int>&nums) {
    for(int i=0;i<nums.size();i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void reversearr(vector<int>&nums, int m) {
    int s = m + 1, e = nums.size()-1;
    while(s<=e) {
        swap(nums[s], nums[e]);
        s++, e--;
    }
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

    int m;
    cout<<"Reverse from where? "<<" ";
    cin>>m;

    cout<<"original array:  "<<endl;
    printarr(nums);
    reversearr(nums, m);

    cout<<"Reversed array:  "<<endl;
    printarr(nums);
    return 0;
}
