#include<iostream>
using namespace std;
int un_knapsack(int wt[],int val[],int w, int n){
    int dp[n+1][w+1]; //dp matrix
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=w; j++){
            if(i == 0 || j == 0){ //base case
                dp[i][j] = 0;
            }
            else if(wt[i-1] <= j){ //current weight can fit in knapsack(bag)
                int take = val[i-1] + dp[i][j-wt[i-1]]; //take current weight
                int not_take = dp[i-1][j]; //skip current weight
                dp[i][j] = max(take,not_take);
            }
            else if(wt[i-1] > j){ //current weight can't fit in kanpsack(bag)
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
    int n, w;
    cin >> n;
    int wt[n],val[n];
    for(int i = 0; i<n; i++){ //weight array
        cin >> wt[i];
    }
    for(int i = 0; i<n; i++){ //value array
        cin >> val[i];
    }
    cin >> w; //capacity of knapsack(bag)
    cout << un_knapsack(wt,val,w,n) << endl;
    return 0;
}

// Time complexity : O(n*w) -> where n is size of the array and w is the capacity(weight) of knapsack
// Space complexity : O(n*w)