#include <bits/stdc++.h>

using namespace std;


//Node Arvore Bi
template<class trem> 
class Tnode{
public:
	trem D;
	int Peso;
	Tnode<trem>* left;
	Tnode<trem>* right;
	
	static Tnode<trem>* montaNode(trem dat,int peso){
		Tnode<trem>* P=new Tnode;
		if(P){
			if(dat==' '){
				dat='-';
			}
			P->Peso=peso;
			P->D=dat;
			P->left=0;
			P->right=0;
		}
		return P;
	}

	static trem desmontaNode(Tnode<trem>* P){
		trem x;
		if(P){
			x=P->D;
			delete P;
		}
		return x;
	}
};








//Arvore Bi
template<class trem>class bbtree{
public:
    Tnode<trem>* root;
    int N;

    bbtree(){
		root = 0;
		N = 0;
	}
	

    bbtree(Tnode<trem>* A, Tnode<trem>* B){
		root = 0;
		N = 3;
		int a=A->Peso;
		int b=B->Peso;
		root = Tnode<trem>::montaNode('_',a+b);
		if(a>=b){
			root->right=A;
			root->left=B;
		}
		else {
			root->right=B;
			root->left=A;
		}
	}
	int getpeso(){
		return root->Peso;
	}
	
	Tnode<trem>* getRoot(){
		return root;
	}
	
	
    bool insert(Tnode<trem>*aux,Tnode<trem>**P){
		if(!*P){
			*P = aux;
			return true;
		}
		if(((*P)->Peso) == (aux->Peso)){
			Tnode<trem>::desmontaNode(aux);
			return false;
		}
		if(aux->Peso < (*P)->Peso){ 
			//vai para esquerda
			return insert(aux,&(*P)->left);
		}
		return insert(aux,&(*P)->right);
	}
	
	
	
	bool insert(trem x,int peso){
		Tnode<trem> *B = Tnode<trem>::montaNode(x,peso);
		if(!B){
			return false;
		}
		if(insert(B,&root)){
			N++;
			return true;
		}
		return false;
	}
	
	
	
    Tnode<trem> *erase(Tnode<trem>**R,trem x){
		Tnode<trem> *aux;
		if(!(*R)) return 0;
		if(x < (*R)->Peso){
			return erase(&(*R)->left,x);
		}
		if(x > (*R)->Peso){
			return erase(&(*R)->right,x);
		}
		if(!(*R)->left){
			aux = *R;
			*R = (*R)->right;
			return aux;
		}
		if(!(*R)->right){
			aux = *R;
			*R = (*R)->left;
			return aux;
		}
		Tnode<trem> *M = rmin((*R)->right);
		swap(M->D,(*R)->D);
		swap(M->Peso,(*R)->Peso);
		return erase(&(*R)->right,x);
	}
	
	
	bool erase(trem x){
		if(!root) return false;
		Tnode<trem>* aux=erase(&root,x);
		if(aux!=0){
			N--;
			Tnode<trem>::desmontaNode(aux);
			return true;
		}
		return false;
			
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




