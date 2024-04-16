#include <bits/stdc++.h>
using namespace std;

int Low=0,High=0;
int Cross_Sum(vector<int> &arr,int low,int mid,int high,int *l,int *h){
    int leftsum = INT_MIN,rightsum=INT_MIN,sum=0;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        if(leftsum<sum){
            leftsum=sum;
            *l=i;
        }
    }
    sum=0;
    for(int i =(mid+1);i<=high;i++){
        sum+=arr[i];
        if(rightsum<sum){
            rightsum=sum;
            *h=i;    
        }
    }
    return (leftsum+rightsum);
}

int max_sub_sum(vector<int> &arr, int low,int high){

    int l,h;
    if(low==high)
        return arr[low];
    int mid = low + (high-low)/2;
    int left_sum = max_sub_sum(arr,low,mid);
    int right_sum = max_sub_sum(arr,mid+1,high);
    int cross_sum = Cross_Sum(arr,low,mid,high,&l,&h);

    if(cross_sum >max(left_sum,right_sum)){
        Low=l;High=h;
        return cross_sum;
    }
    return max(left_sum,right_sum);
}

int main(){

    int n;
    cout<<"Enter the size of array :\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements :\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sum = max_sub_sum(arr,0,n-1);
    cout<<"Maximum subarray sum is : "<<sum<<endl;

    cout<<"Maximum Subarray is :\n";
    cout<<"[ ";
    for(int i=Low;i<=High;i++)
        cout<<arr[i]<<" ";
    cout<<"]\n";

    return 0;
}