bool check(vector<int> arr,int e){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==e)
            return true;
    } 
    return false; 
}

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int i=0;
    int j=0;
    vector <int> uni;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            if(!check(uni,a[i]))
                uni.push_back(a[i++]);
        }
        else if(a[i]>b[j]){
            if(!check(uni,b[j]))
                uni.push_back(b[j++]);
        }
        else{
            if(!check(uni,a[i])){
                uni.push_back(a[i++]);
                j++;
            }
        }
    }
    for(;i<a.size();i++){
        uni.push_back(a[i]);
    }
    for(;j<b.size();j++){
        uni.push_back(b[j]);
    }
    return uni;
}