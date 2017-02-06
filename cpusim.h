//============================================================================
// Name        : cpusim.h
// Author      : Michael Ocean
// Version     : 1.17
// Copyright   : GPLv3
// Description : Fetch and Execute Simulator Skeleton for csc380.
//============================================================================
//
//  DO NOT CHANGE ANYTHING IN THIS FILE OR YOU WILL LOSE POINTS
//    IF you feel you MUST change something, EMAIL ME FIRST.
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

using namespace std;

#define MEMLENGTH 16
#define OPCODE 0xF000	// the opcode is the first 4 bits
#define OPERAND 0x0FFF	// the operand is the last 12 bits

typedef uint16_t WORD; // word is an (unsigned) int, 16 bits

void HexPrint(WORD val, int width);

// CPU registers and memory
// Essentially, these make up our virtual machine
struct cpu_t{
	int PC;				// this is the CPU's program counter
	WORD ACC;			// this is the CPU's accumulator
	WORD IR;			// this is the CPU's instruction register

	// a few helpful methods.  NOTHING in this struct should change.  
	WORD getOpcode(){
		return (IR & OPCODE) >> 12;
	}

	WORD getOperand(){
		return IR & OPERAND;
	}

	void init(){
		PC=0;
		ACC=0;
		IR=0x0000;
	}

	void debugCPUState(){
		// print 
		cout << "PC: " << PC <<endl;
		
		cout << "IR: ";
		HexPrint(IR, 4);
		cout << endl;
		
		cout << "\t (Opcode:";
		HexPrint(getOpcode(), 1);
		cout << ")" << endl;

		cout << "\t (Operand:";
		HexPrint(getOperand(), 3);
		cout << ")" << endl;
		
		
		cout << "ACC: ";
		HexPrint(ACC,4);
		cout << endl;
	}
};

/**
 ** initMachine() initializes the state of the virtual machine state.
 ** (1) zeros out the CPU registers
 ** (2) sets the program counter to the start of memory
 ** (3) fills memory with zeros 
 **/ 
void initMachine(cpu_t &cpu, WORD memory[])
{
	cpu.init();
	for(int i=0;i<MEMLENGTH;i++){
		memory[i] = 0x0000;
	}
}

/** this function will print a hex version of the value you give
 ** it, front padded with as many zeros as needed to fit a width 
 ** of 'width' --- for example HexPrint(23,2) prints 17 
 ** and HexPrint(32,3) prints 020
 ** it does NOT print a newline
 **/
void HexPrint(WORD val, int width)
{
	 // switch to hex
	cout.flags(ios::hex);
	
	// set zero paddnig
	cout.fill('0');    
	cout.width(width);
	
	// print the val
	cout << val ;
	
	// switch back to decimal
	cout.flags(ios::dec);
}	

/** 
 ** a helper function that prints out the 
 ** state of the virtual machine
 **/
void debugMachineState(int loop, cpu_t cpu, WORD memory[])
{	
	cout << "-----------------" << endl;
	cout << "Pass # " << loop << endl;
	cpu.debugCPUState();

	cout << "memory contents:" << endl;
	for(int i=0;i<MEMLENGTH;i++){
		cout << "mem[";
		HexPrint(i,3);
		cout << "] == ";
		HexPrint(memory[i],4);
		cout << endl;
	}

	cout << "-----------------" << endl;
}
	
/**
 ** expects the first input to be the number of lines, then the rest of the
 ** lines should be hex input.  Don't change this.
 **/
void readMemoryFromStdInput(WORD memory[])
{
	int len;
	WORD tmp;
	cout << "How many lines of input? ";
	cin >> len;
	cout << "Now enter "<< len << " lines of HEX" << endl;
	for(int i=0;i<min(len,MEMLENGTH);i++)
	{
		cout << "[" << i << "]:";
		cin >> hex >> tmp;
		memory[i] = tmp;
	}
	for(int i=len;i<MEMLENGTH;i++)
	{
		memory[i] = 0x0000;
	}

}
