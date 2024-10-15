#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int findTargetSumWays(vector<int>& nums,int sum,int n){
    int t[n+1][sum+1];
    t[0][0] = 1;
    int k = 1;
    // intialization
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=sum; j++){
            if(i == 0 && j >= 1) t[i][j] = 0;
            if(j == 0 && i >= 1){
                // if 0 is present in array(check constraints to see that is 0 is part of array element or not) it take part in subset who give sum equal to target sum
                // adding 0 does not effect subset sum
                // how many ways to represent the k zero it is 2^k(power set algorithm)
                if(nums[i-1] == 0){
                    t[i][j] = pow(2,k);
                    k++;
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(nums[i-1] <= j){
                t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
            }
            else if(nums[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }
    int target;
    cin >> target;
    int sumOfArray = 0;
    for(int i  = 0; i<n; i++){
        sumOfArray += nums[i];
    }
    if((sumOfArray + target) % 2 != 0) 
    {
        cout << 0;
        return 0;
    }
    int subsetSum = (sumOfArray + target)/2;
    //check whether sumOFArray+target is valid sum or not 
    if(subsetSum < 0){
        cout << 0;
        return 0;
    }
    // if sum of array is less than subset sum then there is no subset whose sum is equal to taget sum
    if(subsetSum > sumOfArray)
    { 
        cout << 0;
        return 0;
    }
    cout << findTargetSumWays(nums,subsetSum,n);
    return 0;
}

// Time complexity: O(n*sum)
// Space complexity: O(n*sum