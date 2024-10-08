// https://leetcode.com/problems/partition-equal-subset-sum/
#include <iostream>
using namespace std;
// bottom up approach

bool isSubsetPossible(int arr[],int n, int sum){
    int dp[n+1][sum+1]; //dp matrix
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
        }
    }
    
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

// This problem is related to subset sum problem
bool canPartition(int arr[], int n){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    if(sum % 2 != 0) return false; //when sum is odd not possible to make equal sum partition 
    return isSubsetPossible(arr,n,sum/2); // when sum is even it is possible to make equal sum partition 
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    canPartition(arr,n) ? cout << "true\n" : cout << "false\n";
    return 0;
}

// Time complexity : O(n*sum)  -> O(n) + O(n * sum/2) = O(n*sum)
// space complexity : O(n*sum) -> space complexity primarilt determined by 2D table which as dimension (n+1)*(sum/2+1)
