#include<iostream>
using namespace std;
int lengthLCS(string x, string y, int n, int m){
    if(n == 0 || m == 0) return 0;
    if(x[n-1] == y[m-1]) return 1 + lengthLCS(x,y,n-1,m-1);
    else return max(lengthLCS(x,y,n-1,m),lengthLCS(x,y,n,m-1));
}
int main(){
    string x,y;
    cin >> x >> y;
    int n = x.length();
    int m = y.length();
    cout << lengthLCS(x,y,n,m) << endl;
    return 0;
}