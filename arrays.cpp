#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"length of the array"<<"\n";
    int len;
    cin>>len;
    int arr[len];
    for(int i = 0;i<len;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    int sum = 0;
    for(int i = 0;i<len;i++){
        sum = sum + arr[i];
    }
    cout<<endl;
    cout<<sum;
    cout<<endl;
    for(int j = len - 1;j>=0;j--){
       cout<<arr[j]<<" ";
    }
    
    return 0;
}