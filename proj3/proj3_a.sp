* proj3
* proj3
.prot
.lib "Tech_File/cic018.l" TT
.unprot
.option post

M1 L L VDD VDD p_18 w=2u l=500n m=1
M2 Vout L VDD VDD p_18 w=2u l=500n m=1

M3 L Vinn DW GND n_18 w=1u l=500n m=6
M4 Vout Vinp DW GND n_18 w=1u l=500n m=6

M0 DW Vb GND GND n_18 w=1u l=500n m=20

V1 VDD 0 1.8
V2 GND 0 0
V3 Vinp 0 sin 0.9 0.005 10meg
V4 Vinn 0 sin 0.9 -0.005 10meg
V5 Vb 0 0.5
.ac dec 10 10 100meg
.tr 1n 1u
.measure ac ac_gain param=('Vdb(Vout)-Vdb(Vinp-Vinn)')
.probe 

.end
