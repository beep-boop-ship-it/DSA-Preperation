/*
Problem: Max Consecutive ones count
Platform: Leetcode 485
Level: Easy

Approach: Creates two variables one to count the current consecutive ones, one to keep track which was the largest count

Time COmplexity: O(n)
Space Complexity: O(1)

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int  finans = 0, count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1){
                count++;
            }
            else{
                if(finans < count){
                    finans = count;
                }
                count = 0;
            }
        }
        if(count > finans) finans = count;
        
        return finans;
    }
};
