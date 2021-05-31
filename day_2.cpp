//Given an array of integers, return a new array such that each element at index i of
// the new array is the product of all the numbers in the original array except the one at i.
//For example, if our input was [1, 2, 3, 4, 5], 
//the expected output would be [120, 60, 40, 30, 24].
// If our input was [3, 2, 1], the expected output would be [2, 3, 6].

#include<bits/stdc++.h>

using namespace std;

void result(int arr[] , int n , int mul){
    int res=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        res = mul/arr[i];
        v.push_back(res);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mul = 1;
    for(int i=0;i<n;i++){
        mul *= arr[i];
    }
    result(arr,n,mul);
    
  return 0;
}