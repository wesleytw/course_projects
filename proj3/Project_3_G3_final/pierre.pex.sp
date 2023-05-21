* File: pierre.pex.sp
* Created: Fri Apr 28 21:36:35 2023
* Program "Calibre xRC"
* Version "v2016.4_15.11"
* 
.include "pierre.pex.sp.pex"
.subckt diffamp  VDD VOUT VINN VINP GND VB
* 
* VB	VB
* GND	GND
* VINP	VINP
* VINN	VINN
* VOUT	VOUT
* VDD	VDD
M3 N_L_M3_d N_VINN_M3_g N_DW_M3_s N_GND_M3_b N_18 L=5e-07 W=3e-06 AD=4.5e-12
+ AS=4.5e-12 PD=6e-06 PS=6e-06
M4 N_VOUT_M4_d N_VINP_M4_g N_DW_M4_s N_GND_M3_b N_18 L=5e-07 W=3e-06 AD=4.5e-12
+ AS=4.5e-12 PD=6e-06 PS=6e-06
M4@2 N_VOUT_M4@2_d N_VINP_M4@2_g N_DW_M4@2_s N_GND_M3_b N_18 L=5e-07 W=3e-06
+ AD=4.5e-12 AS=4.5e-12 PD=6e-06 PS=6e-06
M3@2 N_L_M3@2_d N_VINN_M3@2_g N_DW_M3@2_s N_GND_M3_b N_18 L=5e-07 W=3e-06
+ AD=4.5e-12 AS=4.5e-12 PD=6e-06 PS=6e-06
M0 N_DW_M0_d N_VB_M0_g N_GND_M0_s N_GND_M3_b N_18 L=5e-07 W=4e-06 AD=6e-12
+ AS=6e-12 PD=7e-06 PS=7e-06
M0@4 N_DW_M0@4_d N_VB_M0@4_g N_GND_M0@4_s N_GND_M3_b N_18 L=5e-07 W=4e-06
+ AD=6e-12 AS=6e-12 PD=7e-06 PS=7e-06
M0@3 N_DW_M0@3_d N_VB_M0@3_g N_GND_M0@3_s N_GND_M3_b N_18 L=5e-07 W=4e-06
+ AD=6e-12 AS=6e-12 PD=7e-06 PS=7e-06
M0@2 N_DW_M0@2_d N_VB_M0@2_g N_GND_M0@2_s N_GND_M3_b N_18 L=5e-07 W=4e-06
+ AD=6e-12 AS=6e-12 PD=7e-06 PS=7e-06
M1 N_L_M1_d N_L_M1_g N_VDD_M1_s N_VDD_M1_b P_18 L=5e-07 W=1e-06 AD=1.135e-12
+ AS=1.145e-12 PD=3.27e-06 PS=3.29e-06
M2 N_VOUT_M2_d N_L_M2_g N_VDD_M2_s N_VDD_M1_b P_18 L=5e-07 W=1e-06 AD=1.135e-12
+ AS=1.145e-12 PD=3.27e-06 PS=3.29e-06
M2@2 N_VOUT_M2@2_d N_L_M2@2_g N_VDD_M2@2_s N_VDD_M1_b P_18 L=5e-07 W=1e-06
+ AD=1.145e-12 AS=1.135e-12 PD=3.29e-06 PS=3.27e-06
M1@2 N_L_M1@2_d N_L_M1@2_g N_VDD_M1@2_s N_VDD_M1_b P_18 L=5e-07 W=1e-06
+ AD=1.145e-12 AS=1.135e-12 PD=3.29e-06 PS=3.27e-06
*
.include "pierre.pex.sp.PIERRE.pxi"
*
.ends
*
*
