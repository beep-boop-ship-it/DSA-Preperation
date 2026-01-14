/*
Problem: Union of two sorted arrays

Approach, a two pointer approach where each ptr iterates over a single array and checks which is small and if it is not already in the new vector
and then adds it

Time Complexity: O(n1+n2)
Space Complexity: O(n1+n2) ---> for returning the answer not used in the algo

*/


vector<int>unionarr(const vector<int>&nums1,const vector<int>&nums2) {
    vector<int>nums3;
    int i = 0, j = 0;
    while(i<nums1.size()  && j<nums2.size()) {
        if (nums1[i] <= nums2[j]) {
            if (nums3.empty()|| nums1[i] != nums3.back()) {
                nums3.push_back(nums1[i]);
            }
            i++;
        }
        else {
            if (nums3.empty()|| nums2[j] != nums3.back()) {
                nums3.push_back(nums2[j]);
            }
            j++;
        }

    }

    while (i < nums1.size()) {
        if (nums3.empty()||nums1[i] != nums3.back()) {
            nums3.push_back(nums1[i]);
        }
        i++;
    }
    while (j < nums2.size()) {
        if (nums3.empty()||nums2[j] != nums3.back()) {
            nums3.push_back(nums2[j]);
        }
        j++;
    }

    return nums3;
}
