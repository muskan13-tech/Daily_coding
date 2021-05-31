//Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
//For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool check = false;
    int arr[n] , k=17;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum = arr[i]+arr[j];
            if(sum == k){
                check = true;
            }
        }
    }
    if(check==true){
        cout<<"true"<<endl;
    }
    else
      cout<<"false"<<endl;
    return 0;
}