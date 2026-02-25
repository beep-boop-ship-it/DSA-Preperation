/*
Make your work easy
*/


vector<int>inputarray(){
    cout<<"No. of elements: "<<endl;
    int n;
    cin>>n;
    vector<int>v;
    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    return v;
}

void printarr(vector<int>v) {
    cout<<"--->   ";
    for (int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

vector<vector<int>> inputmatrix() {
    vector<vector<int>> nums;

    cout << "For A(mxn), enter m and n: ";
    int m, n;
    cin >> m >> n;

    // resize matrix first
    nums.resize(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];   // store values directly
        }
    }

    return nums;   // IMPORTANT
}

void printmatrix(const vector<vector<int>>& nums) {
    cout << "--->\n";
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}
