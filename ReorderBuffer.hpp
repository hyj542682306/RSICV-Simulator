#ifndef ReorderBuffer_hpp
#define ReorderBuffer_hpp

#include<bits/stdc++.h>

struct ROB_node{
	unsigned int Inst,func3,func7,shamt;
	unsigned int Dest;
	unsigned int Value,Jump;
	bool Ready,End;
	unsigned int pc,id;
	ROB_node(){
		Ready=End=false;
		Inst=func3=func7=shamt=Value=0;
		pc=Jump=id=Dest=-1;
	}
	void clear(){
		Ready=End=false;
		Inst=func3=func7=shamt=Value=0;
		pc=Jump=id=Dest=-1;
	}
};

class ReorderBuffer{
private:
	unsigned int head,tail,_empty;
	ROB_node q[SIZE];
public:
	ReorderBuffer(){
		head=tail=0;_empty=1;
	}
	void clear(){
		head=tail=0;_empty=1;
	}
	bool empty(){
		return _empty;
	}
	bool full(){
		return head==tail&&!_empty;
	}
	ROB_node front(){
		return q[head];
	}
	unsigned int nxtpos(){
		return tail;
	}
	void push(ROB_node x){
		x.id=tail;
		q[tail]=x;
		tail=(tail+1)%SIZE;
		_empty=0;
	}
	void update(unsigned int p,ROB_node x){
		q[p]=x;
	}
	ROB_node take(unsigned int p){
		return q[p];
	}
	void pop(){
		if(_empty)return ;
		q[head].clear();
		head=(head+1)%SIZE;
		if(head==tail)_empty=1;
	}
};

#endif