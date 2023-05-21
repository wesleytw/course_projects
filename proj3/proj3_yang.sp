* proj3
.prot
.lib "Tech_File/cic018.l" TT
.temp 15
.unprot
.option post

M1 L L VDD VDD p_18 w=20u l=500n m=2
M2 Vout L VDD VDD p_18 w=20u l=500n m=2

M3 L Vin DW GND n_18 w=10u l=1u m=4
M4 Vout Vin DW GND n_18 w=10u l=1u m=4

M0 DW Vin GND GND n_18 w=10u l=500n m=4

V1 VDD 0 1.8
V2 GND 0 0
V3 Vin 0 0

.dc V3 0 1.8 0.01
.probe V(Vout)

.end