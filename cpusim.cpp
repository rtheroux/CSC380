//============================================================================
// Name        : cpusim.cpp
// Author      : Michael Ocean
// Version     : 1.17
// Copyright   : GPLv3
// Description : Fetch and Execute Simulator Skeleton for csc380.
//   based on the Pencil and Paper computer ISA, though extended
//============================================================================
#include "cpusim.h"   
// look at the cpusim.h to see what methods are defined there
// and the definition for cpu_t

/**
 ** this function MUST BE CHANGED to do what fetch does.  modify the
 ** cpu as if a fetch happened
 **/
void fetch(cpu_t &cpu, WORD memory[])
{	
	
	// do what fetch should do
	cpu.IR = memory[cpu.PC];
	cpu.IR = cpu.getOpcode();
	//cpu.ACC = cpu.getOperand();
	cout << " " << cpu.IR << " ";
}

/**
 ** this function MUST BE CHANGED to do what execute does.
 ** Right now, It should look at the IR and figure out what
 ** to do.  Right now it only understands the STOP opcode.
 **
 ** this function should (and currently) returns false if 
 ** the opcode is stop and return true in all other 
 ** circumstances.
 **
 **/
bool execute(cpu_t &cpu, WORD memory[])
{	
	// do what execute should do
	if(cpu.getOpcode()==0x0) // this is the opcode for stop
	{
		// so, do nothing...
		// and return false, which means the program is not running now
		return false;
	}
	else if(cpu.getOpcode()==0x1) // ADD
	{
		
		// return true, because the program is still running
		return true;
	}
	else if(cpu.getOpcode()==0x2) // SUBTRACT
	{
				
		// and return true, because the program is still running
		return true;
	}
	else if(cpu.getOpcode()==0x3) // LOAD
	{
		cpu.ACC = memory[cpu.getOperand()];			
		// and return true, because the program is still running
		return true;
	}
	else if(cpu.getOpcode()==0x4) // STORE
	{
				
		// and return true, because the program is still running
		return true;
	}
	else if(cpu.getOpcode()==0x5) // READ
	{
				
		// and return true, because the program is still running
		return true;
	}
	else if(cpu.getOpcode()==0x6) // DISPLAY
	{
				
		// and return true, because the program is still running
		return true;
	}
	else if(cpu.getOpcode()==0x7) // JUMPIF
	{
				
		// and return true, because the program is still running
		return true;
	}
	else if(cpu.getOpcode()==0xf) // NOP
	{
				
		// and return true, because the program is still running
		return true;
	}
	else if(cpu.getOpcode()==0x9) // READ
	{
				
		// and return true, because the program is still running
		return true;
	}
	
}

/**
 ** this function MUST BE CHANGED 
 **/
void increment(cpu_t &cpu)
{
	if (((cpu.IR != 7) && (cpu.IR != 8)) && (cpu.IR !=9)){ //makes sure opcode isn't
		cpu.PC++;				       //jumpif, stop or jump
	}
}
	
/** 
 ** the main function -- this is where the magic happens
 ** you should NOT need to change this, but DO look at 
 ** what it does!!
 **/
int main (int argc, char *argv[]) 
{
	// keep track of what cycle this is
	int loops=0;
	bool running = true; 

	// CPU registers and memory
	// Essentially, these make up our virtual machine
	cpu_t cpu;
	WORD memory[MEMLENGTH];	// this is the system memory

	initMachine(cpu, memory); // clear out the virtual system

	readMemoryFromStdInput(memory);	// read memory from input/file
	
	debugMachineState(loops, cpu, memory); // print the state (for confirmation sake)
	
	while(running) // is the machine still running?
	{
		fetch(cpu, memory);
		
		increment(cpu);
		
		// (execute returns FALSE if it just ran a STOP instruction)
		running = execute(cpu, memory);
		
		// print the state of the machine after this pass
		// (and incriment the loops counter)
		debugMachineState(++loops, cpu, memory);
	}

	return 0; // tell the OS there was no error
}
