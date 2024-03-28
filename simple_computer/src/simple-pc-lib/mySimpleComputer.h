#pragma once
#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H

#define RAM_SIZE 128

#define TRUE 1
#define FALSE 0

#define O 0 // Overflow during the operation
#define D 1 // Division error by 0
#define M 2 // Error overstepping memory limits
#define R 3 // Invalid command received
#define P 4 // Ignoring clock pulses

enum INFO
{
  NOP = 0,
  CPUINFO = 1,
};

enum IO
{
  READ = 10,
  WRITE = 11,
};

enum LD
{
  LOAD = 20,
  STORE,
};

enum MATH
{
  ADD = 30,
  SUB,
  DIVIDE,
  MUL,
};

enum OPERATOR
{
  JUMP = 40,
  JNEG,
  JZ,
  HALT,
};

enum USER
{
  NOT = 51,
  AND,
  OR,
  XOR,
  JNS,
  JC,
  JNC,
  JP,
  JNP,
  CHL,
  SHR,
  RCL,
  RCR,
  NEG,
  ADDC_CELL,
  SUBC_CELL,
  LOGLC,
  LOGRC,
  RCCL,
  RCCR,
  MOVA,
  MOVR,
  MOVCA,
  MOVCR,
  ADDC_RANGE,
  SUBC_RANGE,
};

#define MAX_VALUE_COMMAND 0x7F
#define MIN_VALUE_COMMAND 0x00
#define MAX_VALUE 0x7FFF

#define COMMAND_CODE 0x4000

extern short int flag_register;
extern short int accumulator;
extern short int command_counter;

extern short int memory[RAM_SIZE];

// RAM functions
int sc_memoryInit (void);
int sc_memorySet (short int address, short int value);
int sc_memoryGet (short int address, short int *value);
int sc_memorySave (char *filename);
int sc_memoryLoad (char *filename);

// Registers functions
int sc_regInit (void);
int sc_regSet (short int register, short int value);
int sc_regGet (short int register, short int *value);
int sc_accumulatorInit (void);
int sc_accumulatorSet (short int value);
int sc_accumulatorGet (short int *value);
int sc_icounterInit (void);
int sc_icounterSet (short int value);
int sc_icounterGet (short int *value);

// Command Functions
int sc_commandEncode (short int sign, short int command, short int operand,
                      short int *value);
int sc_commandDecode (short int value, short int *sign, short int *command,
                      short int *operand);
int sc_commandValidate (short int command);

// Input/Output functions
void printCell (int address);
void printFlags (void);
void printDecodedCommand (short int value);
void printBinary (int num);
void printAccumulator (void);
void printCounters (void);
void printTerm (int address, int input);
void printCommand (void);
#endif