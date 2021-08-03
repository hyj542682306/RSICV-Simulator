#ifndef InstructionQueue_hpp
#define InstructionQueue_hpp

#include<bits/stdc++.h>

class InstructionQueue{
private:
	unsigned int head,tail,_empty;
	unsigned int q[SIZE];
public:
	InstructionQueue(){
		head=tail=0;_empty=1;
		memset(q,0,sizeof(q));
	}
	void clear(){
		head=tail=0;_empty=1;
		memset(q,0,sizeof(q));
	}
	bool empty(){
		return _empty;
	}
	bool full(){
		return head==tail&&!_empty;
	}
	void push(unsigned int x){
		q[tail]=x;
		tail=(tail+1)%SIZE;
		_empty=0;
	}
	unsigned int front(){
		return q[head];
	}
	void pop(){
		if(_empty)return ;
		head=(head+1)%SIZE;
		if(head==tail)_empty=1;
	}
};

#endif