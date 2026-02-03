/*

Problem ---> You are given an array prices where prices[i] is the price of a given stock on the ith day.
              You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
              Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Approach:
two variable, maxelem and minelem
an iteration in loop which checks for minimum element, if found updates the value of both minelem and maxelem to that value
if minelem not found it checks and updates the maxelem wrt the last minelem found
it checks for another variable profit, if in this possible buy sell sequence, profit is less than previous then we dont update, if it is greater, than we do update


Time Complexity: O(n)
Space Complexity: O(1)
*/

int main() {

    vector<int>nums = inputarray();

    int ptr = 1;
    int maxelem = nums[0], minelem = nums[0];
    int profit = 0;
    while(ptr<nums.size()) {
        if (nums[ptr] < minelem) {
            minelem = nums[ptr];
            maxelem = nums[ptr];
        }
        else if (nums[ptr] > maxelem) {
            maxelem = nums[ptr];
            if (maxelem - minelem > profit) {
                profit = maxelem - minelem;
            }
        }
        ptr++;
    }
    printarr(nums);
    cout<<"Profit: "<<profit<<endl;


    return 0;
}

