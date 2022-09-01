/*统计swr出现的次数，输出对1000000007取模输出*/
#include<iostream>
#include<vector>
using namespace std;
int getNum(string input){
    if(input.size()<=2) return 0;
    //记录到位置i的时候，存在多少swr
    int s_num=0;
    int w_num=0;
    int result=0;
    for(int i=0; i<input.size(); i++){
        if(input[i]=='s') s_num++;
        if(input[i]=='w') w_num+=s_num;
        if(input[i]=='r') result += w_num; 
        result = result%1000000007;
    }
    return result;
}
int main(void){
    int n=0;
    cin>>n;
    vector<string> record(n);
    for(int i=0; i<n; i++){
        string cur;
        cin>>cur;
        record[i] = cur;
    }
    //处理
    vector<int> result(n);
    for(int i=0; i<n; i++){
        result[i] = getNum(record[i]);
    }
    for(int i=0; i<n; i++){
        cout<<result[i]<<endl;
    }
    return 0;
}