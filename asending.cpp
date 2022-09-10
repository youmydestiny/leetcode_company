a = [1,2,15,17,5]
b = [2,3,12,23,24]
#include<vector>
using namespace std;
std::vector<int>  mergeArray(std::vector<int> a, std::vector<int> b){
	if(a.size()==0) return b;
	if(b.size()==0) return a;
	int first_index = 0;
	int second_index = 0;
	std::vector<int> result;
	while(first_index<a.size() && second_index<b.size()){
		if(a[first_index]<=b[second_index]){
			result.push_back(a[first_index]);
			first_index++;
		}
		else{
			result.push_back(b[second_index]);
			second_index++;
		}
	}
	if(first_index<a.size()){
		for(int i=first_index; i<a.size(); i++){
			result.push_back(a[i]);
		}
	}
	if(second_index<b.size()){
		for(int i=second_index; i<b.size(); i++){
			result.push_back(b[i]);
		}
	}
	return result;
}