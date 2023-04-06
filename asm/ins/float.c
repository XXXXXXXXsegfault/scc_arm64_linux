void ins_init_float(void)
{
	ins_add("fmov F1,X2","1 0 0 1 1 1 1 0 0 1 1 0 0 1 1 1 0 0 0 0 0 0 R2 R1",0,0);
	ins_add("fmov X1,F2","1 0 0 1 1 1 1 0 0 1 1 0 0 1 1 0 0 0 0 0 0 0 R2 R1",0,0);

	ins_add("fadd F1,F2,F3","0 0 0 1 1 1 1 0 0 1 1 R3 0 0 1 0 1 0 R2 R1",0,0);
	ins_add("fsub F1,F2,F3","0 0 0 1 1 1 1 0 0 1 1 R3 0 0 1 1 1 0 R2 R1",0,0);
	ins_add("fmul F1,F2,F3","0 0 0 1 1 1 1 0 0 1 1 R3 0 0 0 0 1 0 R2 R1",0,0);
	ins_add("fdiv F1,F2,F3","0 0 0 1 1 1 1 0 0 1 1 R3 0 0 0 1 1 0 R2 R1",0,0);
	ins_add("fneg F1,F2","0 0 0 1 1 1 1 0 0 1 1 0 0 0 0 1 0 1 0 0 0 0 R2 R1",0,0);

	ins_add("scvtf F1,X2","1 0 0 1 1 1 1 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 R2 R1",0,0);
	ins_add("fcvtns X1,F2","1 0 0 1 1 1 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 R2 R1",0,0);

	ins_add("fcmp F1,F2","0 0 0 1 1 1 1 0 0 1 1 R2 0 0 1 0 0 0 R1 0 0 0 0 0",0,0);
}
