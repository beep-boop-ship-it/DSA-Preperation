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


int main() {

    vector<int>nums = inputarray();
    set<vector<int>>solution;

    for (int i = 0; i < nums.size(); i++) {
        set<int>store;
        for (int j = i + 1; j < nums.size(); j++) {
            int third = -(nums[i] + nums[j]);
            if (store.count(third)) {
                vector<int>temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                solution.insert(temp);
            }
            store.insert(nums[j]);
        }
    }

    vector<vector<int>>ans = {solution.begin(), solution.end()};

    cout<<"required triplets: "<<endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//brute force
//lets not
