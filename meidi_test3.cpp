/*判断字符串的合法性*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;
bool isCorrect(string input){
    if(input.size()==0) return true;
    //利用堆栈来进行判断
    stack<int> record;
    unordered_map<char, int> flag;
    flag['('] = 1;
    flag[')'] = 1;
    flag['['] = 2;
    flag[']'] = 2;
    flag['{'] = 3;
    flag['}'] = 3;
    //represent '(' '[' '{'
    for(int i=0; i<input.size(); i++){
        //if(record.empty() && (input[i]==')' || input[i]==']' || input[i]=='}')) 
        //   {  record.push(1);break; }
        if(record.empty() || i==0 ) {record.push(flag[input[i]]); continue;}
        //judge whether
        char cur = input[i];
        if(flag[cur]==record.top()) record.pop();
        else record.push(flag[cur]);
        
    }
    bool result;
    if(record.empty()) result = true;
    else result = false;
    return result;
}
using namespace std;
int main(void){
    string input;
    getline(cin, input);
    bool result = isCorrect(input);
    if(result)
        cout<< "true" <<endl;
    else
        cout<< "false" <<endl;
    return 0;
}