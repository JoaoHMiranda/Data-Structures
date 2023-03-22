#include "dist.h"

int main(){
	int n;
	cin>>n;
	vector<int>num(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	bbtree<int> A;
	A.insert(num);
	cout<<"Max dist "<<A.maxdist()<<endl;;
}
