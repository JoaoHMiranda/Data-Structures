#include "node.h"


template<typename trem>class queue{
private:
	int N;
	node<trem>* Head;
	node<trem>* Tail;
public:
	queue();
	~queue();
	bool push(trem x);
	trem pop();
	int size();
	bool empty();
	trem front();	
	void clear();
};
