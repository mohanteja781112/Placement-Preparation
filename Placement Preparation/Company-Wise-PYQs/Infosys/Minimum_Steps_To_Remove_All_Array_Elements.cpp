// Find the minimum number of steps required to make all elements of an array equal, where each step consists of replacing an element with any value. The constraint is that the absolute difference between the final equal value and any other element must not exceed 1.
// O(n)
#include <bits/stdc++.h>
using namespace std;

int minimumSteps(int arr[], int n)
{
    unordered_map<int, int>u;
    int mxFreq = 0;
    for (int i = 0; i < n; i++){
    u[arr[i]]++;
        mxFreq = max(mxFreq,u[arr[i]]);
    }
    return max(mxFreq, (n + 1) / 2);
}
int main()
{
    int n; cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << minimumSteps(arr, n);
    return 0;
}

// O(n logn)
#include <bits/stdc++.h>
using namespace std;

int minimumSteps(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size() - 1;
    int ans = 0;
    while (i <= j){
        if (arr[i] != arr[j]){
            i++;
            j--;
        }
        else{
            i++;
        }
        ans++;
    }
    return ans;
}
int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << minimumSteps(arr);
    return 0;
}