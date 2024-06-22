#include<iostream>
using namespace std;

void selectionSort(int arr[],int size){
    for(int i=0;i<=size-2;i++){
        int mini = i;
        for(int j = i; j <= size-1; j++){
            if(arr[j]<=arr[mini]){
                mini = j;
            }
        }
        swap(arr[mini],arr[i]);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}