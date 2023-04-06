void ins_init_basic_op(void)
{
	ins_add("add X1,X2,X3","1 0 0 0 1 0 1 1 0 0 0 R3 0 0 0 0 0 0 R2 R1",0,0);
	ins_add("add X1,X2,X3","1 0 0 0 1 0 1 1 0 0 1 R3 0 1 1 0 0 0 RS2 RS1",0,0);
	ins_add("sub X1,X2,X3","1 1 0 0 1 0 1 1 0 0 0 R3 0 0 0 0 0 0 R2 R1",0,0);
	ins_add("sub X1,X2,X3","1 1 0 0 1 0 1 1 0 0 1 R3 0 1 1 0 0 0 RS2 RS1",0,0);
	ins_add("subs X1,X2,X3","1 1 1 0 1 0 1 1 0 0 0 R3 0 0 0 0 0 0 R2 R1",0,0);
	ins_add("and X1,X2,X3","1 0 0 0 1 0 1 0 0 0 0 R3 0 0 0 0 0 0 R2 R1",0,0);
	ins_add("ands X1,X2,X3","1 1 1 0 1 0 1 0 0 0 0 R3 0 0 0 0 0 0 R2 R1",0,0);
	ins_add("orr X1,X2,X3","1 0 1 0 1 0 1 0 0 0 0 R3 0 0 0 0 0 0 R2 R1",0,0);
	ins_add("eor X1,X2,X3","1 1 0 0 1 0 1 0 0 0 0 R3 0 0 0 0 0 0 R2 R1",0,0);
	ins_add("lsl X1,X2,X3","1 0 0 1 1 0 1 0 1 1 0 R3 0 0 1 0 0 0 R2 R1",0,0);
	ins_add("lsr X1,X2,X3","1 0 0 1 1 0 1 0 1 1 0 R3 0 0 1 0 0 1 R2 R1",0,0);
	ins_add("asr X1,X2,X3","1 0 0 1 1 0 1 0 1 1 0 R3 0 0 1 0 1 0 R2 R1",0,0);
	ins_add("mul X1,X2,X3","1 0 0 1 1 0 1 1 0 0 0 R3 0 1 1 1 1 1 R2 R1",0,0);
	ins_add("udiv X1,X2,X3","1 0 0 1 1 0 1 0 1 1 0 R3 0 0 0 0 1 0 R2 R1",0,0);
	ins_add("sdiv X1,X2,X3","1 0 0 1 1 0 1 0 1 1 0 R3 0 0 0 0 1 1 R2 R1",0,0);

	ins_add("add X1,X2,#I","1 0 0 1 0 0 0 1 0 0 I12 RS2 RS1",0,0);
	ins_add("sub X1,X2,#I","1 1 0 1 0 0 0 1 0 0 I12 RS2 RS1",0,0);
}
