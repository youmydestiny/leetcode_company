#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> cal(vector<int> record, int k){
    vector<vector<int>> result;
    if(record.size()==0) return result;
    //check
    //最大配对一定是一个奇数配对一个偶数
    //检查奇偶数目
    int evenNum=0;
    int oddNum=0;
    vector<int> visited_even;
    vector<int> visited_odd;
    for(int i=0; i<record.size(); i++){
        if(record[i]%2==0) //偶数
        {
            evenNum++;
            visited_even.push_back(record[i]);
        }
        else{
            oddNum++;
            visited_odd.push_back(record[i]);
        } 
    }
    bool flag = false; //如果是奇数则为false
    if(k%2==0) flag = true; //如果是偶数则为true
    int length = min(evenNum, oddNum);
    cout<<"length" <<length<<endl;
    int extra_len = (max(evenNum, oddNum)-length)/2;
    result=vector<vector<int>>(length+extra_len, vector<int>(2));
    int count = 0;
    int end = 1;
    for(int i=0; i<record.size(); i++){
        if(record[i]%2==(int)(flag==false? 0:1)) continue;
        count++;
        if(length>0 && count<=length){
            cout<<"i: "<<i<<" "<<record[i]<<endl;
            result[count-1] = {record[i], flag==false? visited_even[count-1]:visited_odd[count-1]};
        }
        else if(extra_len>0){
            result[count-1] = {record[i], flag==false? visited_odd[visited_odd.size()-end]:visited_even[visited_even.size()-end]};
            end++;
        }
        //比较剩余可以记录的数目
        if(count>=length+extra_len) break;
    }
    return result;
}
int main(void){
    int n=7;
    int k=5;
    //cin>>n>>k;
    vector<int> record={2,2,2,2};
    //for(int i=0; i<n; i++){
    //    cin>>record[n];
    //}
    vector<vector<int>> result=cal(record, k);
    int result_num = result.size();
    cout<<result_num<<endl;
    for(int i=0; i<result_num; i++){
        cout<<result[i][0]<<" "<<result[i][1]<<endl;
    }
    return 0;
}