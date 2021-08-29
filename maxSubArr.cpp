#include<iostream>
#include<vector>
using namespace std;

int minLeftEle(vector<int> &array,int l, int u){
    int min = INT32_MAX;
    for(int i=l;i<=u;i++){
        if(array[i]<min){
            min = array[i];
        }
    }
    return min;
}

int maxRightEle(vector<int> &array,int l, int u){
    int max = INT32_MIN;
    for(int i = l;i<=u;i++){
        if(array[i]>max){
            max = array[i];
        }
    }
    return max;
}

int maxSubArr(vector<int> &array,int l,int u){
    // cout<<"lower->"<<l<<" "<<"upper->"<<u<<endl;
    if(l==u){
        return 0;
    }
    else if(u==l+1){
        // cout<<"when 2 ele->"<<max(array[u]-array[l],0)<<endl;
        return max(array[u]-array[l],0);
    }
    int mid = (u+l)/2;
    // cout<<"mid->"<<mid<<endl;
    int leftBest = maxSubArr(array,l,mid);
    // cout<<"leftBest->"<<leftBest;
    int rightBest = maxSubArr(array,mid+1,u);
    // cout<<"rightBest->"<<rightBest<<endl;
    int crossLeftBest = minLeftEle(array,l,mid);
    // cout<<"clb->"<<crossLeftBest<<endl;
    int crossRightBest = maxRightEle(array,mid+1,u);
    // cout<<"crb->"<<crossRightBest<<endl;

    int mas = max(leftBest,rightBest);
    // cout<<"mas->"<<mas<<endl;
    return max(mas,crossRightBest-crossLeftBest);
}

int main(){
    vector<int> array = {2,5,3,4,8,0,-1,6,4,9};
    // cout<<"array size"<<array.size()-1<<endl;
    cout<<maxSubArr(array,0,array.size()-1);    
}