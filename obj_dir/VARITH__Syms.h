// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VARITH__SYMS_H_
#define _VARITH__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VARITH.h"

// SYMS CLASS
class VARITH__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VARITH*                        TOPp;
    
    // CREATORS
    VARITH__Syms(VARITH* topp, const char* namep);
    ~VARITH__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
