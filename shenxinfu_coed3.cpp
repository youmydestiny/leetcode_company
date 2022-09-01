#include<iostream>
#include<vector>
using namespace std;
//五进制与十进制互相转换
string dec2five(string cur){
    long long cur_num=0;
    // string to int
    for(int i=0; i<cur.size(); i++){
        cur_num = cur_num*10 + cur[i]-'0'; 
    }
    // dec to five
    string result="";
    vector<string> five={"o","y","e","a","s"};
    while(cur_num!=0){
        result = (five[cur_num%5]) +result; 
        cur_num = cur_num/5;
    }
    return result;
}
int five2dec(string cur){
    if(cur.size()==0) return 0;
    long long result = 0;
    for(int i=0; i<cur.size(); i++){
        switch(cur[i]){
            case 'o':
                result = result*5 + 0;
                break;
            case 'y':
                result = result*5 + 1;
                break;
            case 'e':
                result = result*5 + 2;
                break;
            case 'a':
                result = result*5 + 3;
                break;
            case 's':
                result = result*5 + 4;
                break;
        }
        
    }
    return result;
}
int main(void){
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        string cur;
        cin>>cur;
        if(cur[0]<='9' && cur[0]>='0')
            cout<<dec2five(cur)<<endl;
        else
            cout<<five2dec(cur)<<endl;
    }
    return 0;
}