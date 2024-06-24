#include<bits/stdc++.h>
using namespace std;

int Recursive(vector<int> &arr){
    int max = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
  return max;
}

/*int BruteForce(vector<int>& arr){
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}*/

int main()
{
    vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    //cout<<"The Largest element in the array is: "<<BruteForce(arr1)<<endl;
    //cout<<"The Largest element in the array is: "<<BruteForce(arr2);
    cout<<"The Largest element in the array is: "<<Recursive(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<Recursive(arr2);
    return 0;
}

