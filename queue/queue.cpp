#include <iostream>
#include "queue.h"

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

template <typename trem> queue<trem>::queue(){
	Head=Tail=0;
	N=0;
	
}

template <typename trem> queue<trem>::~queue(){
	node<trem>* P;
	while(Head){
		P=Head;
		Head=P->Next;
		node<trem>::DesmontaNode(P);
	}	
}

template <typename trem> bool queue<trem>::push(trem x){
	node<trem>* P=node<trem>::MontaNode(x);
	if(!P){
		return false;
	}
	if(Head){
		Tail->Next=P;
	}
	else{
		Head=P;
	}
	Tail=P;
	Tail->Next=0;
	N++;
	return true;
}

template <typename trem>  trem queue<trem>::pop(){
	trem x;
	if(Head){
		node<trem>* P=Head;
		Head=Head->Next;
		x=node<trem>::DesmontaNode(P);
		if(!Head){
			Tail=0;
		}
		N--;
	}
	return x;
}

template <typename trem> int queue<trem>::size(){
	return N;
}

template <typename trem>  bool queue<trem>::empty(){
	return !Head;
}

template <typename trem> trem queue<trem>::front(){
	trem x;
	if(Head){
		x=Head->D;
	}
	return x;
}
template <typename trem> void queue<trem>::clear(){
	node<trem>* P;
	while(Head){
		P=Head;
		Head=P->Next;
		node<trem>::DesmontaNode(P);
	}
	N=0;
}

int main(){
	queue<int> ab;
	int a=10,b=20;
	ab.push(a);
	ab.push(b);
	
	cout<<ab.front()<<endl;
	cout<<ab.size()<<endl;
	cout<<ab.pop()<<endl;
	cout<<ab.size()<<endl;
	(ab.empty()==true) ?(cout<<0<<endl) : (cout<<1<<endl);

	cout<<endl;
	cout<<ab.front()<<endl;
	cout<<ab.size()<<endl;
	cout<<ab.pop()<<endl;
	cout<<ab.size()<<endl;
	(ab.empty()==true) ?(cout<<0<<endl) : (cout<<1<<endl);

	
}
