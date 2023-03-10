template<typename trem> class AVLNode{
public:
	trem D;
	int fb;
	AVLNode<trem>* Right;
	AVLNode<trem>* Left;
	
	
	static AVLNode* MontaNode(trem d){
		AVLNode<trem>* P=new AVLNode<trem>;
		if(P){
			P->D=d;
			P->Right=P->Left=0;
			P->fb=0;
		}
		return P;
	}
	
	static trem DesmontaNode(AVLNode<trem>* P){
		trem x;
		if(P){
			x=P->D;
			delete P;
		}
		return x;
	}
};
