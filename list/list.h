#include "node.h"


template<typename trem>class list{
private:
	int N;
	node<trem>* Head;
public:
	list();
	~list();
	bool insert(trem x);
	trem pop();
	int size();
	bool empty();
	trem front();	
	void clear();
	trem erase(trem x);
	bool search(trem x,trem*P);
};
