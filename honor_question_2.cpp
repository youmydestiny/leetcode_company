#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
void extract_date(vector<string> record_input, vector<string>& record_date){
    for(int i=0; i<record_input.size(); i++){
        cout<<" i "<<i<<endl;
        for(int j=0; j<record_input[i].size()-18; j++){
            cout<<" j "<<j<<endl;
            if(record_input[i][j]>'9' || record_input[i][j]<'0') continue;
            if(record_input[i][j+4]!='-' || record_input[i][j+7]!='-' || 
               record_input[i][j+10]!='T' || record_input[i][j+13]!=':' || 
               record_input[i][j+16]!=':') continue;
            int flag = true;
            for(int cur_index=1; cur_index<19; cur_index++){
                if(cur_index==4 || cur_index==7 || cur_index==10 || cur_index==13 || cur_index==16)
                    continue;
                if(record_input[i][j+cur_index]<'0' || record_input[i][j+cur_index]>'9')
                    flag=false;
            }
            if(flag==false) continue;
            //record
            record_date[i] = record_input[i].substr(j,19);
            cout<<record_date[i]<<endl;
            break;
        }
    }
    return;
}
void swap(string& a, string & b, string& date_a, string& date_b){
    string temp = b;
    b = a;
    a = temp;
    temp = date_b;
    date_b = date_a;
    date_a = temp;
    return;
}
bool compare(string a, string b, string date_a, string date_b){
    if(date_a<date_b) return true;
    else if(date_a>date_b) return false;
    if(a.size()<b.size()) return true;
    else if(a.size()>b.size()) return false;
    for(int i=0; i<a.size(); i++){
        if(a[i]>b[i]) return false;
    }
    return true;
}
void sort(vector<string>& record_input, vector<string>& record_date){
    for(int i=0; i<record_input.size(); i++){
        for(int j=i+1; j<record_input.size(); j++){
            if(compare(record_input[i], record_input[j], record_date[i], record_date[j])==false)
                swap(record_input[i], record_input[j], record_date[i], record_date[j]);
        }
    }
    return;
}
int main(void){
    cout<<"------------------"<<endl;
    int len=5;
    //cin>>len;
    vector<string> record_input={"my/2019-01-01T09:00:01",
                                "my/2019-01-01T09:00:01",
                                "abc/2018-12-24T08:00:00/test/you",
                                "1/2018-12-24T08:00:00/test/Test1",
                                "123/2018-12-24T08:00:09/test/me"};
    //去重，时间戳、长度提取，排序（时间戳、长度、ascii）、打印
    vector<string> record_date(len); 
    extract_date(record_input, record_date);
    for(int i=0; i<record_date.size(); i++)
        cout<<record_date[i]<<endl;
    vector<bool> record_output(len, true);
    sort(record_input, record_date);
    //output
    for(int i=0; i<record_input.size(); i++){
        if(i==0) cout<<record_input[i]<<endl;
        else if(record_input[i]!=record_input[i-1])
            cout<<record_input[i]<<endl;
    }
    return 0;
}