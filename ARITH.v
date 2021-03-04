module ThirtyTwoBitAdder(
                        input  [31:0] A,
                        input  [31:0] B,
                        input   co,
                        output [31:0] AdderOut);
  assign AdderOut =  A + B + {31'h0, co};
endmodule

module ARITH( 
           input  [31:0] A,
           input  [31:0] B,
           input  [3:0] ALuOp,
           output [31:0] outputs);
  
  wire [31:0] B_select;
  wire [31:0] AdderOut;
  OneBitMux B_selector(~B,B,ALuOp[1], B_select);
  ThirtyTwoBitAdder adder(A,B_select,ALuOp[1], AdderOut);
  OneBitMux SltSelector({32{AdderOut[31]}}, AdderOut, ALuOp[3], outputs);
endmodule
