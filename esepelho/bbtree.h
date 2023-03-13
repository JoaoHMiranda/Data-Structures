#include "Tnode.h"
#include <bits/stdc++.h>

using namespace std;

template<class trem>class bbtree{
public:
    Tnode<trem>* root;
    string checar;
    int N;

    bbtree()
	{
		checar="";
		root = 0;
		N = 0;
	}
	
	bool check(){
		Inorder(root);
		string aux=checar;
		reverse(checar.begin(), checar.end());
		if(aux==checar)return true;
		return false;
	}
		
	void insert(vector<int>&vec){
		queue<Tnode<trem>*>q;
		N=vec.size();
		if(!vec.empty()){
			Tnode<trem>* R=Tnode<trem>::montaNode(vec[0]);
			root=R;
			q.push(R);
		}
		for(int i=1;i<int(vec.size());i=i+2){
			Tnode<trem>* A=q.front();
			q.pop();
			Tnode<trem>* aux=Tnode<trem>::montaNode(vec[i]);
			A->left=aux;
			q.push(aux);
			if(i+1<int(vec.size())){
				aux=Tnode<trem>::montaNode(vec[i+1]);
				A->right=aux;
				q.push(aux);
			}
		}	
	}
	
	void Inorder(){
		Inorder(root);
	}



	void Inorder(Tnode<trem>* R){
		if(R){
			Inorder(R->left);
			checar+=to_string((R->D));
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




