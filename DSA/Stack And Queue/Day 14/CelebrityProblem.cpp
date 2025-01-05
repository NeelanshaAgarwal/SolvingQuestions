#include<bits/stdc++.h>

using namespace std;

// brute force approch

/*int Celebrity(vector<vector<int>& matrix){
    int n = matrix.size();
    int know[n];
    int iKnow[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                know[i]++;
                iKnow[j]++;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        if(know[i]==n-1 && iKnow[i]==0){
            return i;
        }
    return -1;
}*/

// optimized approch

int Celebrity(vector<vector<int>>& matrix){
    int top = 0;
    int down = matrix.size()-1
    while(top<down){
        if(matrix[top][down]){
            top++;
        }else if(matrix[down][top]){
            down--;
        }else{
            top++;
            down--;
        }
    }
    if(top>down){
        return -1;
    }
    for(int i=0;i<matrix.size()-1;i++){
        if(i==top){
            continue;
        }
        if(matrix[top][i]==0 && matrix[i][top]==1){
            return i;
        }
        else{
            return -1;
        }
    }
    return top;
}

int main(){
    vector<vector<int>> matrix = {{0,1,0},{0,0,0},{0,1,0}};
    cout<<Celebrity(matrix)<<endl;
    return 0;
}