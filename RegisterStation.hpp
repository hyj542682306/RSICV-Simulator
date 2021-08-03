#ifndef RegisterStation_hpp
#define RegisterStation_hpp

#include<bits/stdc++.h>

struct RS_node{
	unsigned int Op;
	unsigned int Qj,Qk;
	unsigned int Vj,Vk;
	unsigned int A;
	bool Busy;
	unsigned int Reorder,func3,func7,shamt;
	unsigned int pc;
	RS_node(){
		Busy=false;
		Op=Vj=Vk=A=Reorder=func3=func7=shamt=0;
		Qj=Qk=pc=-1;
	}
	void clear(){
		Busy=false;
		Op=Vj=Vk=A=Reorder=func3=func7=shamt=0;
		Qj=Qk=pc=-1;
	}
	bool Ready(){
		//LUI or AUIPC or JAL
		if(Op==0b0110111||Op==0b0010111||Op==0b1101111)return true;
		//JALR
		if(Op==0b1100111)return (int)Qj==-1;
		//Branch
		if(Op==0b1100011)return (int)Qj==-1&&(int)Qk==-1;
		//Load
		if(Op==0b0000011)return (int)Qj==-1;
		//Store
		if(Op==0b0100011)return (int)Qj==-1&&(int)Qk==-1;
		//ADDI ~ SRAI
		if(Op==0b0010011)return (int)Qj==-1;
		//ADD ~ AND
		if(Op==0b0110011)return (int)Qj==-1&&(int)Qk==-1;
		
		return false;
	}
};

class RegisterStation{
private:
	RS_node v[SIZE];
public:
	RegisterStation(){}
	void clear(){
		for(int i=0;i<SIZE;++i)v[i].clear();
	}
	bool full(){
		for(int i=0;i<SIZE;++i)
			if(!v[i].Busy)return false;
		return true;
	}
	unsigned int getpos(){
		for(int i=0;i<SIZE;++i)
			if(!v[i].Busy)return i;
		return -1;
	}
	void update(int p,RS_node x){
		v[p]=x;
	}
	RS_node take(int p){
		return v[p];
	}
	void erase(int p){
		v[p].clear();
	}
};

#endif