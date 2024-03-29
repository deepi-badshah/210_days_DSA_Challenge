// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    bool isPalin( int n ){
        string str = to_string(n);
        int i = 0;
        int j = str.length() - 1;
        
        while( i<j ){
            if( str[i]!=str[j] )
                return false;
            i++;
            j--;
        }
        return true;
    }
    int PalinArray(int a[], int n){
        for( int i=0; i<n; i++ ){
            if( !isPalin(a[i]) ){
            return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends
