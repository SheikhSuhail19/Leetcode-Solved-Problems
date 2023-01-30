//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int binarysearch(int arr[], int n, int target) {
        int s = 0, e = n;
        int mid = s + (e-s)/2;
        while(s <= e){
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] > target)
                e = mid - 1;
            else s = mid + 1;
            mid = s + (e-s)/2;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends