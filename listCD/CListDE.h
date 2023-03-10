#include "Cnode.h"
#include <iostream>

using namespace std;

template<typename trem> class ClistDE{
private:
	Cnode<trem>* Head;
	Cnode<trem>* IT;
	int N;
public:
	ClistDE();
	~ClistDE();
	bool Insert(trem x);
	trem Erase();
	void ITMM();
	void ITmm();
	void ITbegin();
	int size();
	trem ReturnIT();
	bool Empty();
	void Clear();
	bool Search(trem X);
	
};

template<typename trem> ClistDE<trem>::ClistDE(){
	Head=0;
	IT=0;
	N=0;
}

template<typename trem> int ClistDE<trem>::size(){
	return N;
}

template<typename trem> bool ClistDE<trem>::Insert(trem x){
	Cnode<trem>*P=Cnode<trem>::MontaNode(x);
	if(!P){
		return false;
	}
	if(!Head){
		Head=IT=P->Next=P->Back=P;
	}
	else{
		P->Back=Head->Back;
		P->Next=Head;
		(Head->Back)->Next=P;
		Head->Back=P;
		Head=P;
	}
	N++;
	return true;
}

template<typename trem> trem ClistDE<trem>::Erase(){
	trem x=-1;
	if(!Head){
		return x;
	}
	Cnode<trem>* aux=IT;
	if(IT->Next!=IT){
		(IT->Next)->Back=IT->Back;
		(IT->Back)->Next=IT->Next;
	}
	else{
		Head=0;
	}
	if(Head==IT){
		Head=IT=IT->Next;
	}
	else{
		IT=IT->Next;
	}
	N--;
	x=Cnode<trem>::DesmontaNode(aux);
	return x;
}

template<typename trem> void ClistDE<trem>:: ITMM(){
	IT=IT->Next;
}

template<typename trem> void ClistDE<trem>:: ITmm(){
	IT=IT->Back;
}

template<typename trem> void ClistDE<trem>:: ITbegin(){
	IT=Head;
}

template<typename trem> trem ClistDE<trem>:: ReturnIT(){
	trem x;
	if(!IT){
		return x;
	}
	x=IT->D;
	return x;
}

template<typename trem> bool ClistDE<trem>:: Empty(){
	return !Head;
}

template<typename trem> bool ClistDE<trem>:: Search(trem x){
	if(!Head){
		return false;
	}
	Cnode<trem>* P=Head->Next;
	while(P!=Head && (P->D)!=x){
		P=P->Next;
	}
	if((P->D)==x){
		IT=P;
		return true;
	}
	return false;
}
template<typename trem> void ClistDE<trem>:: Clear(){
	if(Head){
		Cnode<trem>* P=Head->Next;
		Cnode<trem>* aux;
		while(P!=Head){
			aux=P;
			P=P->Next;
			Cnode<trem>::DesmontaNode(aux);
		}
		Cnode<trem>::DesmontaNode(Head);
		Head=0;
		IT=0;
		N=0;
	}
}
template<typename trem> ClistDE<trem>::~ClistDE(){
	if(!Head){
		Cnode<trem>* P=Head->Next;
		Cnode<trem>* aux;
		while(P!=Head){
			aux=P;
			P=P->Next;
			Cnode<trem>::DesmontaNode(aux);
		}
		Cnode<trem>::DesmontaNode(P);
	}
}
