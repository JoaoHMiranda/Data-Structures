//~ #include <iostream>
#include "AVLTree.h"

//~ using namespace std;

int main(){
	AVLTree<int> A;
	A.Insert(10);
	A.Insert(20);
	A.Insert(30);
	A.Insert(40);
	A.Insert(50);
	A.Insert(25);
	int x=-1;
	cout<<"Pre"<<endl;
	A.Preorder();
	cout<<endl;
	cout<<endl;
	cout<<"In"<<endl;
	A.Inorder();
	cout<<endl;
	cout<<endl;
	cout<<"Pos"<<endl;
	A.Posorder();
	cout<<endl;
	cout<<endl;
	cout<<endl;
	if(A.Erase(30,&x)){
		cout<<"apagou o "<<x<<endl;
	}
	else{
		cout<<"Nao apagou o "<<x<<endl;
	}
	cout<<endl;
	if(A.Search(x)){
		cout<<"Achou o "<<x<<endl;
	}
	else{
		cout<<"Nao achou o "<< x<<endl;
	}
	cout<<endl;
	cout<<"Arvore com altura "<<A.High()<<endl;
	
}
