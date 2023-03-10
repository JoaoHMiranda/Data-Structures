#include "CListDE.h"
#include <iostream>

using namespace std;

int main(){
	ClistDE<int>x;
	int a,b,h;
	cin>>a;
	x.Insert(a);
	cin>>b;
	x.Insert(b);
	cout<<"Tamanho "<<x.size()<<endl;
	x.Search(a);
	h=x.Erase();
	cout<<h<<endl;
	cout<<"Tamanho "<<x.size()<<endl;
	x.Search(b);
	h=x.Erase();
	cout<<h<<endl;
	cout<<"Tamanho "<<x.size()<<endl;
	x.Insert(b);
	x.Insert(a);
	cout<<"Tamanho "<<x.size()<<endl;
	x.Clear();
	cout<<"Tamanho "<<x.size()<<endl;
	if(x.Search(b)){
		cout<<"achou"<<endl;
	}
	else{
		cout<<"nao achou"<<endl;
	}
	if(x.Search(a)){
		cout<<"achou"<<endl;
	}
	else{
		cout<<"nao achou"<<endl;
	}
	x.Insert(a);
	if(x.Search(a)){
		cout<<"achou"<<endl;
	}
	else{
		cout<<"nao achou"<<endl;
	}
}
