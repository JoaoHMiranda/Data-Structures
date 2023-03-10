#include "Tnode.h"
#include <bits/stdc++.h>

using namespace std;

template<class trem>class bbtree{
public:
    Tnode<trem>* root;
    int N;

    bbtree()
	{
		root = 0;
		N = 0;
	}
	
	
    static Tnode<trem>* rmin(Tnode<trem>* R){
		if(R->left) return rmin(R->left);
		return R;
	}
	
	
	trem min(){
		if(!root){
			trem x;
			return x;
		}
		Tnode<trem>* Z=bbtree::rmin(root);
		return Z->D;
	}
	
	
	static Tnode<trem>* rmax(Tnode<trem>* R){
		if(R->rght) return RMax(R->rght);
		return R;
	}
	
	
	trem max(){
		if(!root){
			trem x;
			return x;
		}
		Tnode<trem>* Z=bbtree::rmax(root);
		return Z->D;
	}
	
	
	
    bool insert(Tnode<trem>*aux,Tnode<trem>**P)
	{
		if(!*P)
		{
			*P = aux;
			return true;
		}
		if(((*P)->D) == (aux->D))
		{
			Tnode<trem>::desmontaNode(aux);
			return false;
		}
		if(aux->D < (*P)->D)
		{ //vai para esquerda
			return insert(aux,&(*P)->left);
		}
		return insert(aux,&(*P)->right);
	}
	
	
	
	bool insert(trem x)
	{
		Tnode<trem> *B = Tnode<trem>::montaNode(x);
		if(!B)
		{
			return false;
		}
		if(insert(B,&root))
		{
			N++;
			return true;
		}
		return false;
	}
	
	
	
    Tnode<trem> *erase(Tnode<trem>**R,trem x)
	{
		Tnode<trem> *aux;
		if(!(*R)) return 0;
		if(x < (*R)->D)
		{
			return erase(&(*R)->left,x);
		}
		if(x > (*R)->D)
		{
			return erase(&(*R)->right,x);
		}
		if(!(*R)->left)
		{
			aux = *R;
			*R = (*R)->right;
			return aux;
		}
		if(!(*R)->right)
		{
			aux = *R;
			*R = (*R)->left;
			return aux;
		}
		Tnode<trem> *M = rmin((*R)->right);
		swap(M->D,(*R)->D);
		return erase(&(*R)->right,x);
	}
	
	
	bool erase(trem x)
	{
		if(!root) return false;
		Tnode<trem>* aux=erase(&root,x);
		if(aux!=0){
			N--;
			Tnode<trem>::desmontaNode(aux);
			return true;
		}
		return false;
			
	}
	
	
	void Inorder(){
		Inorder(root);
	}



	void Inorder(Tnode<trem>* R){
		if(R){
			Inorder(R->left);
			cout<<R->D <<" ";
			Inorder(R->right);
		}
	}
	
	
	void Preorder(){
		Preorder(root);
	}
	
	
	
	void Preorder(Tnode<trem>* R){
		if(R){
			cout<<R->D<<" ";
			Preorder(R->left);
			Preorder(R->right);
		}
	}
	


	void  Posorder(){
		Posorder(root);
	}
	
	
	void Posorder(Tnode<trem>* R){
		if(R){
			Posorder(R->left);
			Posorder(R->right);
			cout<<R->D << " ";
		}
	}
	
	
	
	int size()
	{
		return N;
		std::cout << N;
	}
	
	
	
	bool empty(){
		return !root;
	}
	
	
	static void clear(Tnode<trem>* t){
		if(!t)return;
        clear(t->left);
        clear(t->right);
        Tnode<trem>::desmontaNode(t);
	}
	
	
	void clear(){
		clear(root);
		root=0;
		N=0;
	}
};




