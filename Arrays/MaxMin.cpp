#include <iostream>

using namespace std;

struct Pair{
    int max;
    int min;
};

struct Pair TournamentMaxMin(int arr[], int low, int high){
    struct Pair maxMin,mml,mmr;
    int mid;

    if(low==high){
        maxMin.max=arr[low];
        maxMin.min=arr[low];
        return maxMin;
    }

    if(high==low+1){
        if(arr[low]<arr[high]){
            maxMin.max=arr[high];
            maxMin.min=arr[low];
            return maxMin;
        } else {
            maxMin.max=arr[low];
            maxMin.min=arr[high];
            return maxMin;
        }
    
    }
    mid = (low+high)/2;
    mml = TournamentMaxMin(arr, low, mid);
    mmr = TournamentMaxMin(arr, mid+1, high);

    if(mml.min<mmr.min) maxMin.min=mml.min; else maxMin.min=mmr.min;
    if(mml.max>mmr.max) maxMin.max=mml.max; else maxMin.max=mmr.max;

    return maxMin;
}

int main(){
    
    int n;cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++) cin>>arr[i];

    struct Pair result = TournamentMaxMin(arr, 0, n-1);
    cout<<"Max = "<<result.max<<"\nMin = "<<result.min<<endl;

    return 0;
}