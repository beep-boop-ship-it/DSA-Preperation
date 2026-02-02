/*
Problem Statement: Given an integer array nums, find the subarray with the largest sum and
  return the sum of the elements present in that subarray.
  A subarray is a contiguous non-empty sequence of elements within an array.


Kadane's Algorithm:
> Initialize two variables: maxSum and currentSum. Set both variables to the first element of the array.
-> Iterate through the array starting from the second element:
    Update currentSum by adding the current element to it.
    If currentSum becomes negative, reset it to 0. This step ensures that we consider only the subarrays with positive sums.
    Update maxSum by taking the maximum value between maxSum and currentSum. This keeps track of the maximum subarray sum encountered so far.
-> After the iteration, the maxSum variable will hold the largest sum of any subarray.
-> Return the maxSum as the result.

Time Complexity: O(n)
Space Complexity: O(1) + O(n)
*/

int main() {

    vector<int>nums = inputarray();
    vector<int>sumarr;
    int st = 0;
    int arrst = -1;
    int arred = -1;
    long long sum = 0, maxsum = LONG_LONG_MIN;
    for(int i=0;i<nums.size();i++) {
        if (sum == 0) st = i;
        sum += nums[i];
        if(sum > maxsum) {
            maxsum = sum;
            arrst = st;
            arred = i;
        }
        if(sum < 0) {
            sum = 0;
        }
    }

    printarr(nums);
    for(int i=arrst;i<=arred;i++) {
        sumarr.push_back(nums[i]);
    }
    cout<<maxsum<<endl;
    printarr(sumarr);



    return 0;
}
