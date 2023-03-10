#include <iostream>
#include "stack.h"

using namespace std;	


template <typename trem> node<trem>* node<trem> :: MontaNode(trem d){
	node* P=new node;
	if(P){
		P->D=d;
		P->Next=0;
	}
	return P;
	
}
template <typename trem> trem node<trem>:: DesmontaNode(node<trem>* P){
	trem x;
	if(P){
		x=P->D;
		delete P;
	}
	return x;
}

template <typename trem> stack<trem>::stack(){
	Top=0;
	N=0;
	
}

template <typename trem> stack<trem>::~stack(){
	node<trem>* P;
	while(Top){
		P=Top;
		Top=Top->Next;
		node<trem>::DesmontaNode(P);
	}	
}

template <typename trem> bool stack<trem>::push(trem x){
	node<trem>* P=node<trem>::MontaNode(x);
	if(!P){
		return false;
	}
	P->Next=Top;
	Top=P;
	N++;
	return true;
}

template <typename trem>  trem stack<trem>::pop(){
	trem x;
	if(Top){
		node<trem>* P=Top;
		Top=P->Next;
		x=node<trem>::DesmontaNode(P);
		N--;
	}
	return x;
}

template <typename trem> int stack<trem>::size(){
	return N;
}

template <typename trem>  bool stack<trem>::empty(){
	return !Top;
}

template <typename trem> trem stack<trem>::top(){
	trem x;
	if(Top){
		x=Top->D;
	}
	return x;
}
template <typename trem> void stack<trem>::clear(){
	node<trem>* P;
	while(Top){
		P=Top;
		Top=Top->Next;
		node<trem>::DesmontaNode(P);
	}
	N=0;
}

int main(){
	stack<string> ab;
	string a="aasd",b="bgdggg";
	ab.push(a);
	ab.push(b);
	
	cout<<ab.top()<<endl;
	cout<<ab.size()<<endl;
	cout<<ab.pop()<<endl;
	cout<<ab.size()<<endl;
	(ab.empty()==true) ?(cout<<0<<endl) : (cout<<1<<endl);

	cout<<endl;
	cout<<ab.top()<<endl;
	cout<<ab.size()<<endl;
	cout<<ab.pop()<<endl;
	cout<<ab.size()<<endl;
	(ab.empty()==true) ?(cout<<0<<endl) : (cout<<1<<endl);

	
}
