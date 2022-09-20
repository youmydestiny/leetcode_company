/*点赞回复量计算*/
#include<iostream>
#include<vector>
using namespace std;
void calNum(vector<int> recordUser, int&click, int& reply){
    int length = recordUser.size();
    if(length==0) return;
    for(int i=0; i<length; i++){
        int curType = recordUser[i];
        if(curType==2) click++;
        else if(curType==4) continue;
        else if(curType==1) reply++;
        else{
            if(click>reply) click++;
            else if(click<reply) reply++;
            else{ click++; reply++;}
        }
    }
    return;
}
int main(void){
    int num;
    cin>>num;
    vector<int> recordUser(num);
    for(int i=0; i<num; i++){
        cin>>recordUser[i];
    }
    int click=0;
    int reply=0;
    calNum(recordUser, click, reply);
    cout<<reply<<" "<<click<<endl;
    return 0;
}