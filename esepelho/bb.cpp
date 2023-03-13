#include "bbtree.h"

int main(){
	int n;
	cin>>n;
	vector<int>num(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	
	bbtree<int> A;
	A.insert(num);
    if(A.check()) cout<<"E uma arvore espelhada"<<endl;
    else cout<<"Nao e uma arvore espelhada"<<endl;
}
