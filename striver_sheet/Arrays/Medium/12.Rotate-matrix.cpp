/*
Problem:  Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise. 
          The rotation must be done in place, meaning the input 2D matrix must be modified directly..


Optimal approach: Take transpose and then rotate the matrix

Time Complexity: O(mn)
Space Complexity: O(1)


*/

//optimal approach
class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n; j++){
                if(i < j){
                    swap(nums[i][j], nums[j][i]);
                }
            }
        }

        for(int i = 0; i < n; i++){
            reverse(nums[i].begin(), nums[i].end());
        }
    }
};a
