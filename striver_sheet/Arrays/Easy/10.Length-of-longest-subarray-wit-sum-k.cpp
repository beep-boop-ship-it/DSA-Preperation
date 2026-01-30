/*
Approach ---> 
Brute Force Approach :
          O(n^3) two loop to take care of the subarray indices and one loop to calculate the sum in between;


optimal Approach {works for both negative and positive}-->
utilises the hashmap: what we do is we store the sum of subarray uptil the index and the index together, we check if our subarray sum - target exists in our array
if yes, the the subarray with sum k will be the one from that prestored index till the current index, 
to deal with negatives a correction factor is introduced where, if 2 0 0 3 or 2 -1 1 3 type condition is there and subarraysum will 
be 2 for index = 0 and index = 2, so the mapping occurs only when the subarray sum does not alrady exist and is mapped to some other number
this ensures that the largest subarray exists still
Time Complexity: O(n + logn(?))
Space COmplexity: O(n)


Better Approach [sliding window approach wokrs only for non negatives] --->
in this approach what we do is we take two pointers and keep updating the sum, 
if sum exceeds we move the eft pointer untill sum comes in range, 
if sum is equal we update our max len acc to max condition
if sum is less than target, then we add it to our sum and increment the right pointer


*/
//Optimal approach:
int main() {
    int k;
    cout<<"No of entries in your array: "<<endl;
    cin>>k;

    vector<int>nums;

    for(int i=0;i<k;i++) {
        int n;
        cout<<"Enter"<<":  ";
        cin>>n;
        nums.push_back(n);
    }

    int c;
    cout<<"Target: "<<endl;
    cin>>c;

   map<long long, int> mp;
    long long sum = 0;
    int maxLen = 0;
    for (int i=0;i<nums.size();i++) {
        sum += nums[i];
        if (sum == c) {
            maxLen = i+1;
        }
        long long rem = sum - c;
        if (mp.find(rem) != mp.end()) {
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    printarr(nums);
    cout<<maxLen<<endl;

    return 0;
}



// Better approach

int main() {
    vector<int>nums = inputarray();

    int c;
    cout<<"Target: "<<endl;
    cin>>c;

    int L = 0, R = 0;
    int maxLen = 0;
    long long sum = nums[0];

    while ( R < nums.size() ) {
        while ( L <= R && sum > c) {
            sum -= nums[L];
            L++;
        }
        if ( sum == c) {
            maxLen = max(maxLen,R-L+1);
        }
        R++;
        if ( R < nums.size() ) {
            sum += nums[R];
        }
    }

    cout<<"Max length: "<<maxLen<<endl;


    return 0;
}
