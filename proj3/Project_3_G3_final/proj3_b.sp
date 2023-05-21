* proj3
* proj3
.prot
.lib "Tech_File/cic018.l" TT
.unprot
.inc "/home/course/csr530606/Tech_File/pierre_o.pex.sp"
.option post
.global vdd vss
vdd vdd gnd 1.8

*.subckt diffamp vinn vinp vout vb
*M1 L L VDD VDD p_18 w=1u l=500n m=2
*M2 Vout L VDD VDD p_18 w=1u l=500n m=2

*M3 L Vinn DW GND n_18 w=3u l=0.5u m=2
*M4 Vout Vinp DW GND n_18 w=3u l=0.5u m=2

*M0 DW Vb GND GND n_18 w=4u l=0.5u m=4



*.ends
x1 vdd vout gnd vinn vinp vb diffamp

Vinp Vinp 0 sin 0.9 0.005 10meg
Vinn Vinn 0 sin 0.9 -0.005 10meg
Vb Vb 0 0.5
.ac dec 10 10 100meg
.tr 1n 1u

.end
