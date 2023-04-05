
#include "bbtree.h"

int main()
{
    bbtree<char> a;
    string str;
    cout<<"digite uma Expressao Prefixada (sem espaco)"<<endl<<endl;;
	cin>>str;
	for(int i=0;i<(int)str.size();i++){
		a.insert(str[i]);
	}
	cout<<endl<<"Expressao Infixada "<<endl<<endl;;
	a.Inorder();
}
