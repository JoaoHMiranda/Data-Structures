template<class trem> 
class Tnode{
public:
	trem D;
	Tnode<trem>* left;
	Tnode<trem>* right;
	static Tnode* montaNode(trem dat);
	static trem desmontaNode(Tnode* P);
};

template<class trem>
Tnode<trem>* Tnode<trem>::montaNode(trem dat){
	Tnode<trem>* P=new Tnode;
	if(P){
		P->D=dat;
		P->left=0;
		P->right=0;
	}
	return P;
}

template<class trem>
trem Tnode<trem>::desmontaNode(Tnode<trem>* P){
	trem x;
	if(P){
		x=P->D;
		delete P;
	}
	return x;
}