template<typename trem> struct node{
	trem D;
	node* Next;
	static node* MontaNode(trem d);
	static trem DesmontaNode(node<trem>* P);
};
