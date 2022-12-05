//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// class Solution{
//     public:
//     // arr : given array
//     // l : starting index of the array i.e 0
//     // r : ending index of the array i.e size-1
//     // k : find kth smallest element and return using this function
//     int kthSmallest(int arr[], int l, int r, int k) {
//         priority_queue<int> pq;
//         for(int i = 0; i < k; i++) {
//             pq.push(arr[i]);
//         }
        
//         for(int i = k; i <= r; i++) {
//             if(arr[i] < pq.top()) {
//                 pq.pop();
//                 pq.push(arr[i]);
//             }
//         }
        
//         return pq.top();
//     }
// };

class Solution{
    public:
    
    int partition(int* &arr, int l, int r) {
        int pivot = arr[r];
        int i = l-1;
        for(int j = l; j < r; j++) {
            if(arr[j] <= pivot) {
                swap(arr[++i],arr[j]);
            }
        }
        swap(arr[++i],arr[r]);
        return i;
    }
    
    int quick(int* &arr, int l, int r, int k) {
        if(k > 0 && k <= r - l + 1) {
            
            int pivot = partition(arr,l,r);
            
            if(pivot-l == k-1)
                return arr[pivot];
                
            if(pivot-l > k-1)
                return quick(arr,l,pivot-1,k);
                
            return quick(arr,pivot+1,r,k-pivot+l-1);
        }
        return INT_MAX;
    }
    
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        return quick(arr,l,r,k);
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends