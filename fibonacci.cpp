#include<bits/stdc++.h>
using namespace std;
int Fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    return (Fibonacci(n - 1) + Fibonacci(n - 2));
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci of n: " << Fibonacci(n) << endl;
    return 0;
}
