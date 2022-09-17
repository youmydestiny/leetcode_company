/*完全背包与装满的情况*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void getMaxValue(vector<int> space, vector<int> value, int n, int V, 
                 int& maxValue, int& finalMaxValue){
    if(V==0) {maxValue=0; finalMaxValue=0; return;}
    vector<int> recordV(V+1); //记录空间为V的背包可以装多少价值的物品
    for(int i=0; i<n; i++){
        //对于前i个物体，背包能够获得的最大价值
        for(int j=1; j<V+1; j++){
            if(j<space[i]) continue;
            //比较价值
            //cout<<j-space[i]<<" "<<recordV[j-space[i]]<<endl;
            if(j-space[i]!=0 && recordV[j-space[i]]==0) continue; 
            recordV[j] = max(recordV[j], recordV[j-space[i]] + value[i]);
            if(j==V) finalMaxValue = max(finalMaxValue, recordV[j]);
        }
    }
    //遍历最大价值和装满的价值
    for(int i=0; i<V+1; i++){
        maxValue = max(maxValue, recordV[i]);
    }
    
    return;
}
int main(void){
    int n,V;
    cin>>n>>V;
    vector<int> space(n);
    vector<int> value(n);
    for(int i=0; i<n; i++){
        cin>>space[i]>>value[i];
    }
    int maxValue=0;
    int finalMaxValue=0;
    getMaxValue(space, value, n, V, maxValue, finalMaxValue);
    cout<<maxValue<<endl;
    cout<<finalMaxValue<<endl;
    return 0;
}