module OneBitMux(
                        input  [31:0] A,
                        input  [31:0] B,
                        input   select,
                        output [31:0] ArithOut);
  
  assign ArithOut = (select == 1'b1)? A : B;
endmodule

module ALU( 
           input  [31:0] A,
           input  [31:0] B,
           input  [3:0] ALuOp,
           output [31:0] outputs);
  
  wire [31:0] LogOut;
  wire [31:0] ArithOut;

  ARITH arith(A, B, ALuOp, ArithOut);
  LOGIC log(A, B, ALuOp, LogOut);

  OneBitMux mux(LogOut, ArithOut, ALuOp[2], outputs);
endmodule
