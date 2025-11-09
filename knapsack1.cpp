#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    int weight,value;
};
int main(){
    int w=50;
    int n=3;
    Item arr[]={{10,60},{20,100},{30,120}};
    double totalValue=0.0;
    int currWeight=0;
    for(int i=0;i<n;i++){
        if(currWeight+=arr[i].weight<=w){
            currWeight+=arr[i].weight;
            totalValue+=arr[i].value;
        }
        else{
            int remain=w-currWeight;
            totalValue+= arr[i].value*((double)remain/arr[i].weight);
            break;
        }
    }
    cout<<"Maximum Value "<<totalValue;
}
