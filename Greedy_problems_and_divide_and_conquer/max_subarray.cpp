#include <iostream>
using namespace std;

void max_subarray_sum(int arr[], int n){

    int max=INT16_MIN;
    int sum=0;
    int start,end;
    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum>max){
            max=sum;
            end=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout<<"Maximum subarray sum is "<<max<<endl;
    cout<<"Maximum subarray :"<<endl;
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter length of array :\n";
    cin>>n;
    int arr[n];
    cout<<"enter array elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    max_subarray_sum(arr,n);
    return 0;
}