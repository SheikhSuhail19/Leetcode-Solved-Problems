//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str) {
        int n = str.size();
        
        if(n==0)
            return "";
            
        vector<int> freq(26,0);
        for(int i = 0; i < n; i++) {
            freq[str[i]-'a']++;
        }
        
        int maxFreq = 0;
        char maxChar;
        for(int i = 0; i < 26; i++) {
            if(maxFreq < freq[i]) {
                maxFreq = freq[i];
                maxChar = i + 'a';
            }
        }
        
        if(maxFreq > (n+1)/2)
            return "-1";
            
        string res(n,' ');
        
        int i = 0;
        while(maxFreq) {
            res[i] = maxChar;
            i += 2;
            maxFreq--;
        }
        
        freq[maxChar - 'a'] = 0;
        
        for(int j = 0; j < 26; j++) {
            while(freq[j] > 0) {
                i = (i >= n) ? 1 : i;
                res[i] = j + 'a';
                i += 2;
                freq[j]--;
            }
        }
        
        return res;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends