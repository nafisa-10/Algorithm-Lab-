#include<iostream>
using namespace std;
void merge(int A[],int l,int m,int h)
{
    int a = m -l+1;
    int b = h-m;
    int L[a],R[b];
    for(int i=0;i<a;i++)
    {
        L[i] = A[l+i];
    }
    for(int j=0;j<b;j++)
    {
        R[j] = A[m+1+j];
    }
    int i =0,j=0,k=l;
    while(i<a && j<b)
    {
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        while(i < a) {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < b) {
        A[k] = R[j];
        j++;
        k++;
    }
    }
    
}
void mergesort(int A[],int l,int h)
{
    if(l<h)
    {
        int m = (l+h)/2;
        mergesort(A,l,m);
        mergesort(A,m+1,h);
        merge(A,l,m,h);
    }
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    int l = 0;
    int h = n-1;
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    mergesort(A,l,h);
    for(int i =0;i<n;i++)
    {
        cout <<  A[i] << " ";
    }
    cout << endl;
    return 0;

}
