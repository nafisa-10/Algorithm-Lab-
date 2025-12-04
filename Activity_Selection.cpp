#include<bits/stdc++.h>
using namespace std;
int activitySelection(vector<int>& start, vector<int>& finish, int n)
{
    vector<pair<int,int>> act(n);
    for(int i = 0; i < n; i++)
    {
        act[i] = make_pair(finish[i], start[i]);
    }
    sort(act.begin(), act.end());
    int count = 1;
    int last_finish = act[0].first;
    for(int i=1;i<n;i++)
    {
        if((act[i].second) >= (last_finish))
        {
            count++;
            last_finish = act[i].first;
        }
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter activities: ";
    cin >> n;
    vector<int> start(n),finish(n);
    cout << "Start Time: ";
    for(int i=0;i<n;i++)
    {
        cin >> start[i];
    }
    cout << "Finish Time: ";
    for(int i=0;i<n;i++)
    {
        cin >> finish[i];
    }
    cout << "Total number of Activities: ";
    cout << (activitySelection(start,finish,n));
    return 0;
}
