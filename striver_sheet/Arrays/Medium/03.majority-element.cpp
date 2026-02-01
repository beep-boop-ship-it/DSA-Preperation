/*
Problem Statement: Given an integer array nums of size n, return the majority element of the array.

The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.

better approach ----> I create a hashmap to count the frequencies of each element and then i iterate over the maps' values to see which is the largest =, then store its corresponding key accordingly

time complexity: O(nlogn) + O(n) ----> depends on what map you use
space complexity: O(n)


optimal approach --> Moore's voting algorithm
-> Initialize two variables: candidate and count. Set candidate to the first element of the array, and count to 1.
-> Iterate through the array starting from the second element:
    If the current element is equal to the candidate, increment the count by 1.
    If the current element is different from the candidate, decrement the count by 1.
    If the count becomes 0, update the candidate to the current element and set the count to 1 again.
-> After the iteration, the candidate variable will hold the majority element.
Return the candidate as the result.

Time Complexity: O(n)
Space Complexity: O(1)
*/


//optimal approach

int main() {

    vector<int>nums = inputarray();

    int elem = 0, ct = 0;

    for(int i=0;i<nums.size();i++) {
        if(ct == 0) {
            elem = nums[i];
            ct++;
        }
        else if(nums[i] == elem) {
            ct++;
        }
        else {
            ct--;
        }
    }

    printarr(nums);
    cout<<"Majority element in the subarray: "<<elem<<endl;



    return 0;
}


//better approach
int main() {

    vector<int>nums = inputarray();
    unordered_map<int,int>mp;
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }
    int maxfreq = 0;
    int ans = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > maxfreq) {
            maxfreq = it->second;
            ans = it->first;
        }
    }

    cout<<"Majority Element: "<<ans<<endl;

    return 0;
}
