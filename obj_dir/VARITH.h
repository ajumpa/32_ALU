// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VARITH_H_
#define _VARITH_H_  // guard

#include "verilated.h"

//==========

class VARITH__Syms;

//----------

VL_MODULE(VARITH) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(ALuOp,3,0);
    VL_IN(A,31,0);
    VL_IN(B,31,0);
    VL_OUT(outputs,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    IData/*31:0*/ ARITH__DOT__AdderOut;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VARITH__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VARITH);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VARITH(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VARITH();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VARITH__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VARITH__Syms* symsp, bool first);
  private:
    static QData _change_request(VARITH__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VARITH__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VARITH__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VARITH__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VARITH__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
