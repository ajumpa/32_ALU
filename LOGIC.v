module Or(
          input  [31:0] A,
          input  [31:0] B,
          output [31:0] OrOut);
  
  assign OrOut = A | B;

endmodule

module LOGIC( 
           input  [31:0] A,
           input  [31:0] B,
           input  [3:0] ALuOp,
           output [31:0] outputs);
  
  wire [31:0] OrOut;
  wire [31:0] XorAndMuxOut;
  wire [31:0] NorOrMuxOut;
  
  Or o(A, B, OrOut);
  OneBitMux NorOrMux(~OrOut, OrOut, ALuOp[1], NorOrMuxOut);
  OneBitMux XorAndMux(A^B, A&B, ALuOp[1], XorAndMuxOut);
  OneBitMux FinalMux(NorOrMuxOut, XorAndMuxOut, ALuOp[0], outputs);
endmodule
