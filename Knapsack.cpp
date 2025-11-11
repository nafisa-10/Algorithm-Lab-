#include<bits/stdc++.h>
using namespace std;
int knapsack(int W,vector<int>& wt, vector<int>& p,int n, vector<int> & chosen)
{
    vector<vector<int > > dp(n+1, vector<int>(W+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int w = 0;w<=W;w++)
        {
            if(wt[i-1] <= w)
            {
               dp[i][w] = max(dp[i-1][w],p[i-1] + dp[i-1] [w- wt[i-1]]);
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    int w = W;
    for(int i = n;i>0;i--)
    {
        if(dp[i][w] != dp[i-1][w])
        {
            chosen.push_back(i);
            w -= wt[i-1]; 
        }
    }
    return dp[n][W];
}
int main()
{
    int n,c;
    cout << "Enter no of items: " << endl;
    cin >> n;
    vector<int> w(n+1),p(n+1); 
    cout << "Enter items weight: " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> w[i];
    }
    cout << "Enter items price: " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
    }
    cout << "Enter Maximum Capacity: " << endl;
    cin >> c;
    vector<int>chosen;
    int maxvalue = knapsack(c,w,p,n,chosen);
    cout << "Max value in knapsack: " << maxvalue << endl;
    cout << "Item picked: ";
    for(int i = chosen.size()-1;i>=0;i--)
    {
        cout << chosen[i] << " ";
    }
    return 0;
}