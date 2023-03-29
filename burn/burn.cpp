#include "burn.h"

int main(){
	int n,b;
	cin>>n;
	vector<int>num(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	bbtree<int> A;
	A.insert(num);
	cin>>b;
	
	Tnode<int>* save=A.find(b);
	A.burn(save);
}
