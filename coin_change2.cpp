#include<bits/stdc++.h>
using namespace std;
int min_coins(vector<int>& coins,int n,int tar)
{
    vector<vector<int> >dp(n+1, vector<int>(tar+1,INT_MAX-1));
    for(int i=0;i<n;i++)
    {
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=tar;j++)
        {
           dp[i][j] = dp[i-1][j];
           if(coins[i-1] <= j)
           {
               dp[i][j] = min(dp[i-1][j],1 + dp[i][j-coins[i-1]]);
           }
        }
    }
    return dp[n][tar];
}
int main()
{
    int n,tar;
    cout << "Enter coin types: ";
    cin >> n;
    cout << "Enter the amount: ";
    cin >> tar;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
    {
        cin >> coins[i];
    } 
    cout  << "total combination: "<< min_coins(coins,n,tar) << endl;
    return 0;   
}