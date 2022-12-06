//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        for(auto it : nums) {
            ump[it]++;
        }
        priority_queue<pair<int,int>> maxheap;
        for(auto it : ump) {
            maxheap.push({it.second,it.first});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends