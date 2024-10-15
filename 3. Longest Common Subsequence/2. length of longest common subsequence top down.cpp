#include<bits/stdc++.h>
using namespace std;
int t[1002][1002];
int lengthLCS(string x, string y, int n, int m){
    if(n == 0 || m == 0){
        t[n][m] = 0;
    }
    if(t[n][m] != -1){
        return t[n][m];
    }
    if(x[n-1] == y[m-1]){
        t[n][m] =  1 + lengthLCS(x,y,n-1,m-1);
    }
    else{
        t[n][m] = max(lengthLCS(x,y,n-1,m),lengthLCS(x,y,n,m-1));
    }
    return t[n][m];
}
int main(){
    string x,y;
    cin >> x >> y;
    int n = x.length();
    int m = y.length();
    memset(t,-1,sizeof(t));
    cout << lengthLCS(x,y,n,m) << endl;
    return 0;
}