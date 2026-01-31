/*
Problem Statement: Given an array of integers arr[] and an integer target.
Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Brute Force approach ---> take a loop, iterate over the remaining loop and check when the sum becomes equal to target
                        and afterwards, if it does become that, then store the indices and break the inner loop
                        to avoid multiple sums of same indices, make inner loop run from i + 1

                    Time Complexity: O(n^2)
                    Space Complexity: O(1)  ---> it stores oly two elements always 


Better approach(2) ----> Uses a multimap to store the keys and values as arr elements and their indices
                         iterates over the multimap keys{as they're in the sorted order} via two pointer approach and pushes the values 
                         when the sum of the keys of both pointer is target and breaks the iterations
                  Time Complexity: O(nlogn)
                  Space Complexity: O(n)

                  Learnt: Multimaps can store multiple keys and values;
                  to iterate over map, map<key_type,value_type>::iterator it = mp.begin(); or prev(mp.end());

better approach(1) ---->  use an unordered map, it stores the values and indices but not in sorted order,
                        Time Complexity: O(n)
                        Space Complexity: O(n) ---> only for storing the answer


Optimal approach ----> what it does is it stores the value and indices pair in a vector in form of (nums[i],i)
                      then it sorts the new vector, then applies the two pointer approach on it, 
                      and stores the second value of each pair when it encounters the ideal conditions
                  Time Complexity: O(n) + O(nlogn)-->for sorting
                  Space Complexity: O(n)
                          

*/
//optimal approach

int main() {
    vector<int>nums = inputarray();

    int target;
    cout<<"Target: "<<endl;
    cin>>target;

    vector<int>ans;

    vector<pair<int,int>>nums2;
    for(int i=0;i<nums.size();i++) {
        nums2.push_back({nums[i], i});
    }
    sort(nums2.begin(), nums2.end());
    int L = 0, R = nums2.size() - 1;
    while(L < R) {
        if(nums2[L].first + nums2[R].first < target) {
            L++;
        }
        else if(nums2[L].first + nums2[R].first > target) {
            R--;
        }
        else {
            ans.push_back(nums2[L].second);
            ans.push_back(nums2[R].second);
            break;
        }
    }
    printarr(ans);

    return 0;
}

//better solution(1)
int main() {
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>ans;
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++) {
        if(mp.find(target - nums[i]) != mp.end()){
            ans.push_back(mp[target - nums[i]]);
            ans.push_back(i);
        }
        mp[nums[i]] = i;
    }

    printarr(ans);

    return 0;
}


//better solution(2)

int main() {
    vector<int>nums = inputarray();

    int target;
    cout<<"Target: "<<endl;
    cin>>target;

    vector<int>ans;
    multimap<int,int>mp;
    for(int i=0;i<nums.size();i++) {
        mp.insert({nums[i],i});
    }

    multimap<int,int>::iterator L = mp.begin();
    multimap<int,int>::iterator E = prev(mp.end());

    while(L != E) {
        if(L->first + E->first < target) {
            L++;
        }
        else if (L->first + E->first > target) {
            E--;
        }
        else {
            ans.push_back(L->second);
            ans.push_back(E->second);
            break;
        }

    }

    printarr(ans);



    return 0;
}



//brute force approach

vector<int>ans;

    for(int i=0;i<nums.size();i++) {
        for(int j=i+1;j<nums.size();j++) {
            if(nums[i]+nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }


