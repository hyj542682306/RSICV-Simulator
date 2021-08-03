#ifndef LoadStoreBuffer_hpp
#define LoadStoreBuffer_hpp

#include<bits/stdc++.h>

struct LSB_node{
	unsigned int Op;
	unsigned int Vj,Vk;
	unsigned int Qj,Qk;
	unsigned int A;
	bool Busy,Commit;
	unsigned int Reorder,func3;
	unsigned int pc;
	LSB_node(){
		Busy=Commit=false;
		Op=Vj=Vk=A=func3=0;
		Qj=Qk=pc=Reorder=-1;
	}
	void clear(){
		Busy=Commit=false;
		Op=Vj=Vk=A=func3=0;
		Qj=Qk=pc=Reorder=-1;
	}
	bool Ready(){
		if(Op==0b0000011)return (int)Qj==-1;//Load
		else if(Op==0b0100011)return Commit;//Store
		return false;
	}
};

class LoadStoreBuffer{
private:
	unsigned int head,tail,_empty;
	LSB_node q[SIZE];
public:
	LoadStoreBuffer(){
		head=tail=0;_empty=1;
	}
	void clear(){
		head=tail=0;_empty=1;
		for(int i=0;i<SIZE;++i)q[i].clear();
	}
	bool empty(){
		return _empty;
	}
	bool full(){
		return head==tail&&!_empty;
	}
	void push(LSB_node x){
		q[tail]=x;
		tail=(tail+1)%SIZE;
		_empty=0;
	}
	unsigned int gethead(){
		return head;
	}
	LSB_node front(){
		return q[head];
	}
	LSB_node back(){
		return q[(tail-1+SIZE)%SIZE];
	}
	LSB_node take(unsigned int p){
		return q[p];
	}
	void update(unsigned int p,LSB_node x){
		q[p]=x;
	}
	void pop(){
		if(_empty)return ;
		q[head].clear();
		head=(head+1)%SIZE;
		if(head==tail)_empty=1;
	}
	void pop_back(){
		if(_empty)return ;
		tail=(tail-1+SIZE)%SIZE;
		q[tail].clear();
		if(head==tail)_empty=1;
	}
};

#endif