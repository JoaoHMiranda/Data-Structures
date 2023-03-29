#include "node.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<class trem>class bbtree{
public:
    Tnode<trem>* root;
    int N;
    vector<int>adj[1000];

    bbtree(){
		root = 0;
		N = 0;
	}
	
	
	Tnode<trem>* find(Tnode<trem>* t,trem x){
		if(!t)return 0;
		if(t->D==x)return t;
		Tnode<trem>* aux1=find(t->left,x);
		Tnode<trem>* aux2=find(t->right,x);
		return (aux1>aux2 ? aux1:aux2);
	}
	
	Tnode<trem>* find(trem x){
		return find(root,x);
	}
	void burn(Tnode<trem>* r){
		if(!r) cout<<"nao encontrado"<<endl;
		else{
			cout<<r->D<<" ";
			queue<Tnode<trem>*>q;
			q.push(r);
			r->vis=true;
			
			while(!q.empty()){
				auto u=q.front();
				q.pop();
				if( u->left&&!(u->left->vis)){
					q.push(u->left);
					cout<<u->left->D<<" ";
					u->left->vis=true;
				}
				if( u->right&&!(u->right->vis)){
					q.push(u->right);
					cout<<u->right->D<<" ";
					u->right->vis=true;
				}
				if( u->papai&&!(u->papai->vis)){
					q.push(u->papai);
					cout<<u->papai->D<<" ";
					u->papai->vis=true;
				}
			}
			cout<<endl;
		}
	}
		
	void insert(vector<trem>&vec){
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
			aux->papai=A;
			q.push(aux);
			if(i+1<int(vec.size())){
				aux=Tnode<trem>::montaNode(vec[i+1]);
				aux->papai=A;
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
