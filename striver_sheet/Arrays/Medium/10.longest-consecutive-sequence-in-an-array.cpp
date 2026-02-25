/*
Problem --> Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Approach:
//better approach - 2
sort the array and keep the accoring checks keeping duplicates in mind
Time Complexity: O(nlogn) 
Space Complexity: O(1)

//better approach - 1
insert all elements in a ordered set, do a count according to lookup(lookup is O(logn))
and do a maxcount check
Time Complexity: O(nlogn)
Space Complexity: O(n)


//optimal approach
insert all elements in an unordered set, do a count according to lookup(lookup is O(1))
and do a maxcount check
Time Complexity: O(n)
Space Complexity: O(n)



*/



//optimal
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        int ct = 1, mxct = 0;
        for(int x : s){
            if (!s.count(x-1)){
                int curr = x;
                while(s.count(curr+1)){
                    curr++;
                    ct++;
                }
                mxct = max(ct,mxct);
                ct = 1;
            }
        }
        return mxct;
    }
};


//better approach 1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        int ct = 1, mxct = 0;
        for(auto x : s){
            if(s.find(x+1) != s.end()){
                ct++;
        }
            else{
                mxct = max(ct, mxct);
                ct = 1;
            }
        }
        return mxct;
    }
};
