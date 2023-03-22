#include "node.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<class trem>class bbtree{
public:
    Tnode<trem>* root;
    int N;
    int maior;

    bbtree(){
		root = 0;
		N = 0;
		maior=-1e8;
	}
	int maxdist(){
		maior=-1e6;
		maxdist(root);
		return maior;
		
	}
	
	int maxdist(Tnode<trem>* r){
		if(!r){
			return 0;
		}
		int maiorl=maxdist(r->left);
		int maiorr=maxdist(r->right);
		if(maior<maiorl+maiorr+r->D){
			maior=maiorl+maiorr+r->D;
		}
		return max(maiorl,maiorr)+r->D;

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
	
	int size()
	{
		return N;
		cout << N;
	}
	
	
	bool empty(){
		return !root;
	}
	void inorder(){
		inorder(root);
	}
	void inorder(Tnode<trem>* R){
		if(R){
			inorder(R->left);
			cout<<R->D <<" ";
			inorder(R->right);
		}
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

