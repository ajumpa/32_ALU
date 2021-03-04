// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VARITH.h for the primary calling header

#include "VARITH.h"
#include "VARITH__Syms.h"

//==========

VL_CTOR_IMP(VARITH) {
    VARITH__Syms* __restrict vlSymsp = __VlSymsp = new VARITH__Syms(this, name());
    VARITH* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VARITH::__Vconfigure(VARITH__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VARITH::~VARITH() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VARITH::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VARITH::eval\n"); );
    VARITH__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VARITH* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ARITH.v", 18, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VARITH::_eval_initial_loop(VARITH__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("ARITH.v", 18, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VARITH::_combo__TOP__1(VARITH__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VARITH::_combo__TOP__1\n"); );
    VARITH* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ARITH__DOT__AdderOut = ((vlTOPp->A + ((2U 
                                                   & (IData)(vlTOPp->ALuOp))
                                                   ? 
                                                  (~ vlTOPp->B)
                                                   : vlTOPp->B)) 
                                    + (1U & ((IData)(vlTOPp->ALuOp) 
                                             >> 1U)));
    vlTOPp->outputs = ((8U & (IData)(vlTOPp->ALuOp))
                        ? VL_NEGATE_I((IData)((1U & 
                                               (vlTOPp->ARITH__DOT__AdderOut 
                                                >> 0x1fU))))
                        : vlTOPp->ARITH__DOT__AdderOut);
}

void VARITH::_eval(VARITH__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VARITH::_eval\n"); );
    VARITH* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VARITH::_eval_initial(VARITH__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VARITH::_eval_initial\n"); );
    VARITH* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VARITH::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VARITH::final\n"); );
    // Variables
    VARITH__Syms* __restrict vlSymsp = this->__VlSymsp;
    VARITH* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VARITH::_eval_settle(VARITH__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VARITH::_eval_settle\n"); );
    VARITH* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VARITH::_change_request(VARITH__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VARITH::_change_request\n"); );
    VARITH* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VARITH::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VARITH::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((ALuOp & 0xf0U))) {
        Verilated::overWidthError("ALuOp");}
}
#endif  // VL_DEBUG

void VARITH::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VARITH::_ctor_var_reset\n"); );
    // Body
    A = VL_RAND_RESET_I(32);
    B = VL_RAND_RESET_I(32);
    ALuOp = VL_RAND_RESET_I(4);
    outputs = VL_RAND_RESET_I(32);
    ARITH__DOT__AdderOut = VL_RAND_RESET_I(32);
}
