#include <iostream>

using namespace std;

void ReverseArray(int arr[], int n){
    int temp;
    for(int i=0; i<n/2;i++){
        temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
}

int main(){
    
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    ReverseArray(arr, n);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;


    return 0;
}