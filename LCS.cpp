#include<bits/stdc++.h>
using namespace std;
void LCS(string x1 ,string x2)
{
    int n = x1.length();
    int m = x2.length();
    vector<vector<int >> lcs(n+1, vector<int> (m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x1[i-1] == x2[j-1])
            {
                lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else
            {
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    string lcs_str = " ";
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(x1[i-1] == x2[j-1])
        {
            lcs_str = x1[i-1] + lcs_str;
            i--;
            j--;
        }
        else if(lcs[i-1][j] > lcs[i][j-1])
        {
            i--;
        }
        else{
            j--;
        }
    }
    cout << "LCS length: " << lcs[n][m] << endl;
    cout << "LCS string: " << lcs_str << endl;


}
int main()
{
    string x1;
    cout << "Enter string one: ";
    cin >> x1;
    string x2;
    cout << "Enter string two: ";
    cin >> x2;
    LCS(x1,x2);
    return 0;

}