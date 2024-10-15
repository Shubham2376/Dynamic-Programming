#include<iostream>
#include<climits>
using namespace std;
int minimumNoOfCoins(int coins[],int sum,int n){
    int t[n+1][sum+1];
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=sum; j++){
            if(j == 0) t[i][j] = 0;
            if(i == 0) t[i][j] = INT_MAX-1;
        }
    }
    for(int j = 1; j<=sum; j++){
        if(j % coins[0] == 0){
            t[1][j] = j/coins[0];
        }
        else{
            t[1][j] = INT_MAX -1;
        }
    }
    for(int i = 2; i<=n; i++){
        for(int j = 2; j<=sum; j++){
            if(coins[i-1] <= j){
                t[i][j] = min(1+t[i-1][j-coins[i-1]],t[i-1][j]);
            }
            else if(coins[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){
    int n;
    cin >> n;
    int coins[n];
    for(int i = 0; i<n; i++){
        cin >> coins[i];
    }
    int sum;
    cin >> sum;
    cout << minimumNoOfCoins(coins,sum,n) << endl;
    return 0;
}