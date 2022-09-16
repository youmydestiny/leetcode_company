#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
/*顺序循环发糖果，发到A[i]的就离开，问第K个发给哪个同学(1-index)
90% pass*/
long getCurStudent(vector<long> A, long student_num, long K){
    long resStudent = student_num;
    vector<long> cur = A;
    sort(cur.begin(), cur.end());
    long total=0;
    long aim_number = 0;
    for(long i=0; i<student_num; i++){
        //A[i]==0, skip
        if(cur[i]==0) {resStudent--; continue;}
        //repeat, skip
        if(i!=0 && cur[i]==cur[i-1]) {resStudent--; continue;}
        total = resStudent*(i==0? cur[i]:(cur[i]-cur[i-1]));
        if(K<=total){ // at  current loop
            aim_number=cur[i];
            break;
        }
        K -= total;
        resStudent--; //update of student number
    }
    //after get restudent and aim number, just compare
    long aim_count = K%resStudent;
    long count = 0;
    long result_index=-1;
    for(long i=0; i<student_num; i++){
        if(A[i]<aim_number) continue;
        count++;
        if(aim_count==count) result_index = i+1;
    }
    return result_index;
}
int main(void){
    long student_num = 0;
    cin>>student_num;
    long K;
    cin>>K;
    vector<long> A(student_num);
    for(long i=0; i<student_num; i++){
        cin>>A[i];
    }
    long index = getCurStudent(A, student_num, K);
    cout<<index<<endl;
    return 0;
}