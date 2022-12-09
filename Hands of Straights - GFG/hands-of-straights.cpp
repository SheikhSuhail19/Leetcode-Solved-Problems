//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int groupSize, vector<int> &hand) {
        if (n%groupSize) 
            return false;
        
        map<int,int> mp;
        for(auto it : hand) {
            mp[it]++;
        }

        while(mp.size()) {
            int first = mp.begin()->first;
            for(int i = 0; i < groupSize; i++) {
                if(mp[first+i] == 0)
                    return false;
                else if(--mp[first+i] == 0)
                    mp.erase(first+i);
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends