#include "node.h"


template<typename trem>class stack{
private:
	int N;
	node<trem>* Top;
public:
	stack();
	~stack();
	bool push(trem x);
	trem pop();
	int size();
	bool empty();
	trem top();	
	void clear();
};
