/*
Concept implementing O(n) for searching for an element in an array
*/

int searcharr(vector<int>&nums, int k) {
    int ans = -1;
    for(int i=0;i<nums.size();i++) {
        if (nums[i] == k) {
            ans = i;
        }
    }
    return ans;
}
