/*
Problem: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return 
        an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

Brute approach: 3 loops and a set to handle duplicates
Time Complexity: O(n^3)
Space Complexity: O(1)

Better approach: sorting arrays-two loops, using a set to check if the required compliment exists or not;
if it does handling duplicates appropriately

Time Complexity: O(nlogn) + O(n^2)
Space Complexity: O(n)

Optimal Approach: Sorting and using a two ptr approach
Time Complexity: O(nlogn) + O(n^2)
Space Complexity: O(n)
*/

//optimal approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};

//better approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { 
     vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {

        // Skip duplicate fixed elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        unordered_set<int> seen;

        for (int j = i + 1; j < nums.size(); j++) {

            int needed = -nums[i] - nums[j];

            if (seen.count(needed)) {

                ans.push_back({nums[i], needed, nums[j]});

                // Skip duplicate j values
                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++;
            }

            seen.insert(nums[j]);
        }
    }
    return ans;
    }
};

//brute force
//lets not
