#include<iostream>
using namespace std;
int partision(int arr[],int l,int h)
{
    int pivot = arr[l];
    int i = l +1;
    int j = h;
    while(i<=j)
    {
        while(i<= h && arr[i]<=pivot)
        {
            i++;
        }
        while(j>l && arr[j]>=pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[l];
    arr[l] = arr[j];
    arr[j]=temp;
    return j;
}
void quicksort(int arr[],int l,int h)
{
    if(l<h){
        int p = partision(arr,l,h);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,h);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int l = 0,h =n-1;
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }
    quicksort(arr,0,n-1);
    for(int i =0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
