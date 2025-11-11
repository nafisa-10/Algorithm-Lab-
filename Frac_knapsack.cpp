#include<bits/stdc++.h>
using namespace std;
double Frac_knap(vector<int>& weight,vector<int>& value,int n,int cap)
{
    vector<pair<double, pair<int, int>>> item(n);
    for(int i=0;i<n;i++)
    {
       item[i] = {(double)value[i] / weight[i] , {value[i] , weight[i]}};
    }
        sort (item.rbegin(),item.rend());
        double total_V = 0.0;
        int rem_cap = cap;
        for(int i=0;i<n;i++)
        {
            int val = item[i].second.first;
            int wt = item[i].second.second;
            if(wt <= rem_cap)
            {
                total_V += val;
                rem_cap -= wt;
            }
            else{
                total_V += val * ((double)rem_cap / wt);
                break;
            }
        }
        return total_V; 
}
int main()
{
    int n;
    cout << "Enter No of items: " << endl;
    cin >> n;
    vector<int> weight(n),value(n);
    cout << "Enter items weights: " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> weight[i];
    }
    cout << "Enter items values: " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> value[i];
    }
    int cap;
    cout << "Enter maximum capacity: ";
    cin >> cap;
    double Max_V = Frac_knap(weight,value,n,cap);
    cout << "MAX PROFIT = " << Max_V << endl;
    return 0;
}