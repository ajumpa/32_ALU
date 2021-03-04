#include "VALU.h"
#include "verilated.h"
#include <iostream>

/**
 *  CPP driver code for verilog 32-bit ALU implementation
 *
 */

using namespace std;

int eval_output(int A, 
                  int B, 
                  int outputs, 
                  int op)
{ 
  int correct;
  char op_c;
  switch (op) {
    case 0:
      correct = A + B;
      break;
    case 2:
      correct = A-B;
      break;
    case 4:
      correct = A&B;
      break;
    case 5:
      correct = A|B;
      break;
    case 6:
      correct = A^B;
      break;
    case 7:
      correct = ~(A|B);
      break;
    case 10:
      correct = A < B;
      outputs *= -1;
      break;
    default:
      printf("OP %d not valid.\n", op);
      exit(1);
      break;
  }
  return (correct == outputs);
}


int main(int argc, char **argv)
{
  Verilated::commandArgs(argc, argv);
  VALU* alu = new VALU;
  int n_tests = 10;  
  int rand_max = 10;
  if (argc > 3)
  {
    printf("Usage: ./VARITH [Numb Tests] [Rand Max]");
    exit(1);
  } 
  else {
    if (argv[1])
      n_tests = atoi(argv[1]);
    if (argv[2])
      rand_max = atoi(argv[2]);
  }
    
  while (!Verilated::gotFinish()) 
  { 
    printf("Running %d tests with values between 0 and %d\n", n_tests, rand_max);
    int success = 0;

    // Operands are 32 bits, operators are 4 bits
    int ops[7] = {0,2,4,5,6,7,10};
    int o_ix = 0;
    for(int i =0; i < n_tests; i++)
    {
      alu->A = rand()%(rand_max+1);
      alu->B = rand()%(rand_max+1);
      alu->ALuOp = ops[(o_ix++)%7];
      alu->eval();
      success += eval_output(alu->A, alu->B, alu->outputs, alu->ALuOp);
    }
    printf("%.2f success rate, press ctrl-c to stop simulation...\n\n", (float) success/n_tests*100);
    sleep(5);
  }
  
  delete alu;
  exit(0);
}
