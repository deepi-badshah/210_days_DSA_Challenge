//CPP DSA CN Lec 19 Love Babbar 450
#include<iostream>
#include<cstring>
using namespace std;

int editDistance(string s1, string s2, int **output){
    int m = s1.size();
    int n = s2.size(); 
    if(s1.size()==0||s2.size()==0){
        int ans = max(m,n);
        output[m][n]=ans;
        return ans;
    }
    if(output[m][n]!=-1)
        return output[m][n];
    int ans=0;
    if(s1[0]==s2[0]){
        ans = editDistance(s1.substr(1),s2.substr(1),output);
    }
    else{
        int a = 1+editDistance(s1.substr(1),s2,output);
        int b = 1+editDistance(s1,s2.substr(1),output);
        int c = 1+editDistance(s1.substr(1),s2.substr(1),output);
        ans = min(a,min(b,c));
    }
    output[m][n]=ans;
    return ans;
}

int editDistance(string s1, string s2){
    int m=s1.size();
    int n=s2.size();
    int **output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]= new int[n+1];
        for(int j=0;j<=n;j++){
            output[i][j]=-1;
        }
    }
    return editDistance(s1,s2,output);
}
