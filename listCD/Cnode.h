template<typename trem> class Cnode{
public:
	trem D;
	Cnode* Next;
	Cnode* Back;
	static Cnode* MontaNode(trem d);
	static trem DesmontaNode(Cnode<trem>* P);
};

template <typename trem> Cnode<trem>* Cnode<trem> :: MontaNode(trem d){
	Cnode* P=new Cnode;
	if(P){
		P->D=d;
		P->Next=P->Back=0;
	}
	return P;
	
}
template <typename trem> trem Cnode<trem>:: DesmontaNode(Cnode<trem>* P){
	trem x;
	if(P){
		x=P->D;
		delete P;
	}
	return x;
}
