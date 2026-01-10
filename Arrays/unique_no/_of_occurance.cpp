/*
  Problem: Unique Number of occurance
  Platform: Leetcode - 1207
  Level: Easy

Approach 1(10/1/26):
  created a function to create a vector storing the frequency of each no.
  looped over the new vector to ensure no duplicates present
  Time Complexity: Not Optimised/ Brute Force solution

  Will learn the concept of mapping and redo it within a week

*/

//Brute Force Solution
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>ans;
        sort(arr.begin(), arr.end());
        int count = 1;
        for (int i = 0; i < (arr.size()-1); i++){
           if ( arr[i+1] == arr[i]){
            count++;
           }
           else{
            ans.push_back(count);
            count = 1;
           }
        }
        ans.push_back(count);
        sort(ans.begin(), ans.end());
        bool finans = true;
        for (int j = 0; j < (ans.size() - 1); j++){
            if (ans[j+1] == ans[j]){
                finans = false;
                break;
            }
        }
        return finans;
    }
};
