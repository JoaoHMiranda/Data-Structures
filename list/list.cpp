#include <iostream>
#include "list.h"

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

template <typename trem> list<trem>::list(){
	Head=0;
	N=0;
	
}

template <typename trem> list<trem>::~list(){
	node<trem>* P;
	while(Head){
		P=Head->Next;
		node<trem>::DesmontaNode(Head);
		Head=P;
	}	
}

template <typename trem> bool list<trem>::insert(trem x){
	node<trem>* P=node<trem>::MontaNode(x);
	if(!P){
		return false;
	}
	P->Next=Head;
	Head=P;
	N++;
	return true;
}

template <typename trem>  trem list<trem>::pop(){
	trem x;
	if(Head){
		node<trem>* P=Head;
		Head=P->Next;
		x=node<trem>::DesmontaNode(P);
		N--;
	}
	return x;
}

template <typename trem> int list<trem>::size(){
	return N;
}

template <typename trem>  bool list<trem>::empty(){
	return !Head;
}

template <typename trem> trem list<trem>::front(){
	trem x;
	if(Head){
		x=Head->D;
	}
	return x;
}

template <typename trem> void list<trem>::clear(){
	node<trem>* P;
	while(Head){
		P=Head;
		Head=Head->Next;
		node<trem>::DesmontaNode(P);
	}
	N=0;
}

template <typename trem> trem list<trem>::erase(trem x){
	node<trem>** P=&Head;
	trem r;
	node<trem>* aux;
	while((*P) && (*P)->D!=x){
		P=&((*P)->Next);
	}
	if(*P){
		aux=*P;
		*P=(aux->Next);
		r=node<trem>::DesmontaNode(aux);
		N--;
	}
	return r;
}

template <typename trem> bool list<trem>::search(trem x,trem *PX){
	node<trem>* P=Head;
	while(P && (P->D)!=x){
		P=P->Next;
	}
	if(P){
		*PX=P->D;
		return true;
	}
	return false;
}


int main(){
	list<string> ab;
	string a="aasd",b="bgdggg";
	ab.insert(a);
	ab.insert(b);
	
	cout<<ab.front()<<endl;
	cout<<ab.size()<<endl;
	cout<<ab.erase("aasd")<<endl;
	cout<<ab.size()<<endl;
	(ab.empty()==true) ?(cout<<0<<endl) : (cout<<1<<endl);
	
	cout<<endl;
	string x="a";
	cout<<x<<endl;
	ab.search("bgdggg",&x);
	cout<<x<<endl;

	cout<<endl;
	cout<<ab.front()<<endl;
	cout<<ab.size()<<endl;
	cout<<ab.erase("bgdggg")<<endl;
	cout<<ab.size()<<endl;
	(ab.empty()==true) ?(cout<<0<<endl) : (cout<<1<<endl);

	
}
