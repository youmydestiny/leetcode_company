#include <iostream>
#include <string>
#include <vector>
using namespace std;
string reverse_string(string aim){
    string result;
    while(aim.size()>0){
        result = aim[0] + result;
        if(aim.size()>1)
            aim = aim.substr(1,aim.size()-1);
        else 
            aim = "";
    }
    return result;
}
int main(void){
    int len=2;
    
    string input="0abcdefgh1abcdefgh";

    vector<string> record_input(len);
    int index = 0;
    // input data split
    while(input.size()>0){
        record_input[index] = input.substr(0,9);
        cout<<"index : "<<index<<" "<<record_input[index]<<endl;
        if(input.size()>9)
            input = input.substr(9, input.size()-9);
        else input = "";
        index ++;
    }
    // process
    vector<string> result(len);
    for(int i=0; i<len; i++){
        if(record_input[i][0]=='1'){
            cout<<"result "<< i<< " : "<<record_input[i]<<endl;
            result[i] = record_input[i].substr(1, 8);
            cout<<"1 : "<<i<<" "<<result[i]<<endl;
        }
        else{
            string code = record_input[i].substr(1,8);
            cout<<"code: "<<code<<endl;
            result[i] = reverse_string(code);
            cout<<"0 : "<<i<<" "<<result[i]<<endl;
        }
        
    }
    //output
    for(int i=0; i<len; i++){
        if(i<len-1)
            cout<<result[i]<<" ";
        else 
            cout<<result[i]<<endl;
    }
    return 0;
}