#include "AVLNode.h"
#include <iostream>
#include <algorithm> 

using namespace std;

template<typename trem> class AVLTree{
public:

	int N;
	AVLNode<trem>* Root;
	
	AVLTree<trem>() {
		N=0;
		Root=0;
	}
	static AVLNode<trem>* RMin(AVLNode<trem>* R){
		if(R->Left) return RMin(R->Left);
		return R;
	}
	
	
	trem Min(){
		if(!Root){
			trem x;
			return x;
		}
		AVLNode<trem>* Z=AVLTree::RMin(Root);
		return Z->D;
	}
	
	
	static AVLNode<trem>* RMax(AVLNode<trem>* R){
		if(R->Rght) return RMax(R->Rght);
		return R;
	}
	
	
	trem Max(){
		if(!Root){
			trem x;
			return x;
		}
		AVLNode<trem>* Z=AVLTree::RMax(Root);
		return Z->D;
	}
	
	
	static int H(AVLNode<trem>* R){
		if(!R) return 0;
		int L=H(R->Left);
		int Ri=H(R->Right);
		return 1+std::max(L,Ri);
	}
	
	
	int High(){
		return AVLTree<trem>::H(Root);
	}
	
	
	static AVLNode<trem>* find(AVLNode<trem>* R,trem x){
		if(!R || (R->D)==x) return R;
		if(x<(R->D))return find(R->Left,x);
		return find(R->Right,x);
	}
	
	
	bool Search(trem x){
		if(!Root) return false;
		AVLNode<trem>* R=AVLTree<trem>::find(Root,x);
		if(!R) return false;
		return true;
	}
	
	
	static void RSD(AVLNode<trem>**R){
		AVLNode<trem>* a=*R;
		AVLNode<trem>* b=a->Left;
		a->Left=b->Right;
		b->Right=a;
		*R=b;
		if(b->fb==-1){
			a->fb=b->fb=0;
		}
		else{
			a->fb=-1;
			b->fb=1;
		}
	}
	
	
	static void RSE(AVLNode<trem>**R){
		AVLNode<trem>* a=*R;
		AVLNode<trem>* b=a->Right;
		a->Right=b->Left;
		b->Left=a;
		*R=b;
		if(b->fb==1){
			a->fb=b->fb=0;
		}
		else{
			a->fb=1;
			b->fb=-1;
		}
	}
	
	
	static void RDD(AVLNode<trem>**R){
		AVLNode<trem>* a=*R;
		AVLNode<trem>* b=a->Left;
		AVLNode<trem>* c=b->Right;
		b->Right=c->Left;
		a->Left=c->Right;
		c->Right=a;
		c->Left=b;
		*R=c;
		if(c->fb==0){
			a->fb=b->fb=0;
		}
		else{
			if(c->fb==-1){
				b->fb=c->fb=0;
				a->fb=1;
			}
			else{
				a->fb=c->fb=0;
				b->fb=-1;
			}
		}
	}
	
	
	static void RDE(AVLNode<trem>**R){
		AVLNode<trem>* a=*R;
		AVLNode<trem>* b=a->Right;
		AVLNode<trem>* c=b->Left;
		b->Left=c->Right;
		a->Right=c->Left;
		c->Left=a;
		c->Right=b;
		*R=c;
		if(c->fb==0){
			a->fb=b->fb=0;
		}
		else{
			if(c->fb==1){
				b->fb=c->fb=0;
				a->fb=-1;
			}
			else{
				a->fb=c->fb=0;
				b->fb=1;
			}
		}
	}
	
	
	static bool Insert(AVLNode<trem>** R,AVLNode<trem>* aux,bool* inserir){
		if(!(*R)){
			*R=aux;
			aux->fb=0;
			*inserir=true;
			return true;
		}
		if((*R)->D==(aux->D)){
			AVLNode<trem>::DesmontaNode(aux);
			*inserir=false;
			return false;
		}
		if((aux->D)<((*R)->D)){
			//esquerda
			if(AVLTree::Insert(&((*R)->Left),aux,inserir)){
				if((*R)->fb==0){
					(*R)->fb=-1;
					return true;
				}
				if((*R)->fb==1){
					(*R)->fb=0;
					return false;
				}
				if(((*R)->Left)->fb==-1){
					//simple
					AVLTree::RSD(R);
					return false;
				}
				//dupla
				AVLTree::RDD(R);
				return false;
			}
			return false;
		}
		//direita
		if(AVLTree::Insert(&((*R)->Right),aux,inserir)){
			if((*R)->fb==0){
				(*R)->fb=1;
				return true;
			}
			if((*R)->fb==-1){
				(*R)->fb=0;
				return false;
			}
			if(((*R)->Right)->fb==1){
				//simple
				AVLTree::RSE(R);
				return false;
			}
			//dupla
			AVLTree::RDE(R);
			return false;
		}
		return false;
	}
	
	
	
	bool Insert(trem x){
		AVLNode<trem>* R=AVLNode<trem>::MontaNode(x);
		bool inserir=false;
		if(!R)return inserir;
		N=N+1;
		if(!Root){
			Root=R;
			inserir=true;
			return inserir;
		}
		Insert(&Root,R,&(inserir));
		return inserir;
	}
	
	
	static bool Erase(AVLNode<trem>**R,trem x,AVLNode<trem>**aux){
		if(!(*R)) return false;
		if(x<(*R)->D){
			//esquerda
			if(AVLTree<trem>::Erase(&((*R)->Left),x,aux)){
				if((*R)->fb==-1){
					(*R)->fb=0;
					return true;
				}
				if((*R)->fb==0){
					(*R)->fb=1;
					return false;
				}
				if((*R)->Right->fb>=0){
					//simples
					AVLTree<trem>::RSE(R);
					return true;
				}
				//dupla
				AVLTree<trem>::RDE(R);
				return true;
			}
			return false;
		}
		if(x>(*R)->D){
			//direirta
			if(AVLTree<trem>::Erase(&((*R)->Right),x,aux)){
				if((*R)->fb==1){
					(*R)->fb=0;
					return true;
				}
				if((*R)->fb==0){
					(*R)->fb=-1;
					return false;
				}
				if((*R)->Right->fb<=0){
					//simples
					AVLTree<trem>::RSD(R);
					return true;
				}
				//dupla
				AVLTree<trem>::RDD(R);
				return true;
			}
			return false;
		}
		if(!(*R)->Left){
			*aux=*R;
			*R=(*R)->Right;
			return true;
		}
		if(!(*R)->Right){
			*aux=*R;
			*R=(*R)->Left;
			return true;
		}
		//dois filhos 
		AVLNode<trem>* M=AVLTree<trem>:: RMin((*R)->Right);
		std::swap(M->D,(*R)->D);
		if(AVLTree<trem>::Erase(&((*R)->Right),x,aux)){
			if((*R)->fb==1){
				(*R)->fb=0;
				return true;
			}
			if((*R)->fb==0){
				(*R)->fb=-1;
				return false;
			}
			if((*R)->Right->fb<=0){
				//simples
				AVLTree<trem>::RSD(R);
				return true;
			}
			//dupla
			AVLTree<trem>::RDD(R);
			return true;
		}
		return false;
	}
		
	bool Erase(trem x,trem* z){
		*z=-1;
		if(!Root) return false;
		AVLNode<trem>* aux=0;
		AVLTree<trem>::Erase(&(Root),x,&aux);
		if(aux!=0){
			*z=AVLNode<trem>::DesmontaNode(aux);
			return true;
		}
		return false;
			
	}
	
	
	bool Erase(trem x){
		if(!Root) return false;
		AVLNode<trem>* aux=0;
		AVLTree<trem>::Erase(&(Root),x,&aux);
		if(aux!=0){
			N--;
			AVLNode<trem>::DesmontaNode(aux);
			return true;
		}
		return false;
			
	}
	
	
	static void Clear(AVLNode<trem>* t){
		if(!t)return;
        Clear(t->Left);
        Clear(t->Right);
        AVLNode<trem>::DesmontaNode(t);
	}
	
	
	void Clear(){
		AVLTree<trem>::Clear(Root);
		Root=0;
		N=0;
	}


	static void Inorder(AVLNode<trem>* R){
		if(R){
			Inorder(R->Left);
			cout<<R->D <<" ";
			Inorder(R->Right);
		}
	}
	
	
	void Inorder(){
		AVLTree<trem>::Inorder(Root);
	}
	
	
	static void Preorder(AVLNode<trem>* R){
		if(R){
			cout<<R->D<<" ";
			Preorder(R->Left);
			Preorder(R->Right);
		}
	}
	
	
	void Preorder(){
		AVLTree<trem>::Preorder(Root);
	}
	
	
	static void Posorder(AVLNode<trem>* R){
		if(R){
			Posorder(R->Left);
			Posorder(R->Right);
			cout<<R->D << " ";
		}
	}
	
	
	void Posorder(){
		AVLTree<trem>::Posorder(Root);
	}
	
	
	~AVLTree<trem>(){
		AVLTree<trem>::Clear(Root);
	}
	
};
