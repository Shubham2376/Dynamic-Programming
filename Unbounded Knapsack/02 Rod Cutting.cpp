#include<iostream>
using namespace std;
int maxProfit(int length[], int price[],int L, int n){
    int t[n+1][L+1];
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=L; j++){
            if(i == 0 || j == 0) // base case
            {
                t[i][j] = 0;
            }
            else if(length[i-1] <= j){ //cutted piece length is less than length of rod
                t[i][j] = max(price[i-1] + t[i][j-length[i-1]],t[i-1][j]);
            }
            else if(length[i-1] > j) // cutted piece length is greater than length of rod
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][L];
}
int main(){
    int n;
    cin >> n;
    int length[n],price[n];
    for(int i = 0; i<n; i++){
        cin >> length[i];
    }
    for(int i = 0; i<n; i++){
        cin >> price[i];
    }
    int L;
    cin >> L;
    cout << maxProfit(length,price,L,n) << endl;
    return 0;
}

// Time complexity : O(n*L) -> O(n^2) or O(L^2) where n is the size of array(length or price) and L is length of the rod
// Space complexity : O(n*L) -> O(n^2) or O(L^2)