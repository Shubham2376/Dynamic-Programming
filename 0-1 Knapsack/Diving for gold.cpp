// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=367&page=show_problem&problem=931
#include<iostream>
#include<vector>
using namespace std;
struct Treasures{
    int depth;
    int gold;
};
int main(){
    int t,w;
    bool first = true;
    while(cin >> t >> w){
        // t acts as a weight of knapsack 
        if(!first) cout << endl;
        first = false;
        int n;
        cin >> n;
        // make treasures array to store depth of treasures and quantity of gold -> this acts as a value array in 0-1 knapsack
        vector<Treasures> treasures(n);
        for(int i = 0; i<n; i++){
            cin >> treasures[i].depth >> treasures[i].gold;
        }
        // make time needed array to store time needed to recover treasure -> this acts as a weight array in 0-1 knapsack
        vector<int> Time_needed(n);
        for(int i = 0; i<n; i++){
            Time_needed[i] = 3 * w * treasures[i].depth;
        }
        // make a 2D dp array to store the maximum value of the gold that can be recover
        int dp[n+1][t+1];
        for(int i  = 0; i<=n; i++){
            for(int j = 0; j<=t; j++){
                if(i == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=t; j++){
                dp[i][j] = dp[i-1][j];
                if(Time_needed[i-1] <= j){
                    dp[i][j] = max(treasures[i-1].gold + dp[i-1][j-Time_needed[i-1]],dp[i-1][j]);
                }
                
            }
        }
        int maxGold = dp[n][t];

        vector<Treasures> recovered_treasures;
        int remainingTime = t;
        // here i do backtracking 
        for(int i = n; i>0; i--){
            // if up to i and at specific remaining time there was maximum gold recovered then it was not possible to recover maximum gold in same remaining time up to i-1
            if(dp[i][remainingTime] != dp[i-1][remainingTime]){
                recovered_treasures.push_back(treasures[i-1]);
                remainingTime -= Time_needed[i-1];
            }
        }
        // print the maximum gold that can be recovered and the number of treasures that can be recovered
        cout << maxGold << endl;
        cout << recovered_treasures.size() << endl;
        
        // print the depth and amount of gold of each recovered treasure
        for(int i = recovered_treasures.size()-1; i>=0; i--){
            cout << recovered_treasures[i].depth << " " << recovered_treasures[i].gold << endl; 
        }

        // To handle blank line between outputs of different datasets
        string blank;
        getline(cin, blank); // To consume the newline after the last input
        getline(cin, blank);
    }
    return 0;
}