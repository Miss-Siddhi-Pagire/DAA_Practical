#include<iostream>
#include<algorithm>
using namespace std;
struct Item{
    int weight;
    int val;
};
bool compare(Item a,Item b){
    double r1=(double)a.val/a.weight;
    double r2=(double)b.val/b.weight;
    return r1>r2;
}
int main(){
    
    Item arr[]={{10,60},{20,100},{30,120}};
    
    int w=50;
    
    int n=3;
    sort(arr,arr+n,compare);
    double totalVal=0.0;
    int currWeight=0;
    for(int i=0;i<n;i++){
        if(currWeight+arr[i].weight<=w){
            currWeight+=arr[i].weight;
            totalVal+=arr[i].val;

        }
        else{
            int remain=w-currWeight;
            totalVal+=arr[i].val*((double)remain/arr[i].weight);
        }
    }
    cout<<totalVal;
}