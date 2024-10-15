#include<iostream>
using namespace std;
int getMaxNumberOfWays(int coins[], int sum, int n){
    int t[n+1][sum+1];
    // Intialization 
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=sum; j++){
            if(i == 0) t[i][j] = 0;
            if(j == 0) t[i][j] = 1;
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(coins[i-1] <= j){
                // if denominations of coins is less than sum then we have choice to select that denominations of coin 
                // As we required no of ways so we add all the choices that we have 
                t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
            }
            // if denomination of coins is greater than sum
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
    cout << getMaxNumberOfWays(coins,sum,n) << endl;
    return 0;
}