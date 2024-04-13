#include <bits/stdc++.h>
using namespace std;

int cross_sum(vector <int> &arr,int low,int mid,int high,int *l,int*h){
    int leftsum = INT_MIN,sum=0,rightsum=INT_MIN;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        if(sum>leftsum){
            leftsum=sum;
            *l=i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        if(sum>rightsum){
            rightsum=sum;
            *h=i;
        }
    }
    return (leftsum+rightsum);
}

int findSum(vector <int> &arr , int low ,int high,int *indH,int*indL){
    int l,h,mid,leftSum,rightSum,crossSum,maxs;
    if(low==high)  return arr[low];
    mid = low + (high-low)/2 ;
    leftSum = findSum(arr,low,mid,indH,indL);
    rightSum = findSum(arr,mid+1,high,indH,indL);
    crossSum = cross_sum(arr,low,mid,high,&l,&h);
    if(crossSum > max(rightSum, leftSum)){
        maxs=crossSum;
        *indL=l;
        *indH=h;
    }else{
        maxs=max(leftSum,rightSum);
    }
    return maxs ;
}

void maxSubArraySum(vector <int> &arr){
    int indH,indL;
    int maxSum = findSum(arr,0,arr.size(),&indH,&indL);
    cout<<"Maximum Subarray Sum is : "<<maxSum<<endl;
    cout<<"Subarray : "<<endl;
    cout<<"[ ";
    for(int i=indL;i<=indH;i++)
        cout<<arr[i]<<", ";
    cout<<"]"<<endl;
}

int main(){
    vector <int> arr; int n;
    cout<<"Enter the elements (-100 for stop) :\n";
    while(n!=-100){
        cin>>n;
        if(n!=-100) arr.push_back(n);
    }
    maxSubArraySum(arr);
}