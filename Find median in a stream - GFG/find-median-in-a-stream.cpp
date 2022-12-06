//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    double median = 0.0;
    
    int signum(int a, int b) {
        if (a == b) {
            return 0;
        }
        else if (a > b) {
            return 1;
        }
        else {
            return -1;
        }
    }
    
    void insertHeap(int& element)
    {
        switch(signum(maxheap.size(),minheap.size())) {
            case 0:
                if (element > median) {
                    minheap.push(element);
                    median = minheap.top();
                }
                else {
                    maxheap.push(element);
                    median = maxheap.top();
                }
                break;
                
            case 1:
                if (element > median) {
                    minheap.push(element);
                }
                else {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(element);
                }
                median = (double)( ((double)minheap.top() + (double)maxheap.top()) / 2 );
                break;
                
            case -1:
                if (element > median) {
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(element);
                }
                else {
                    maxheap.push(element);
                }
                median = (double)( ((double)minheap.top() + (double)maxheap.top()) / 2 );
                break;
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        return median;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends