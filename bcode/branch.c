void gen_branch(struct ins *ins,char *op_1,char *op_2)
{
	struct operand op1,op2;
	int class1,class2;
	int sign,c;
	c=0;
	if(ins->count_args<4)
	{
		error(ins->line,"too few arguments.");
	}
	get_operand(ins,1,&op1);
	get_operand(ins,2,&op2);
	class1=0;
	class2=0;
	sign=1;
	if(op_is_reg(&op1))
	{
		if(!if_class_signed(op1.tab->class))
		{
			sign=0;
		}
		class1=1;
	}
	else if(op_is_const(&op1))
	{
		class1=2;
	}
	else if(op_is_addr(&op1))
	{
		class1=3;
		c=8;
	}
	else if(!if_class_signed(op1.tab->class))
	{
		sign=0;
	}
	if(op_is_reg(&op2))
	{
		if(!if_class_signed(op2.tab->class))
		{
			sign=0;
		}
		class2=1;
	}
	else if(op_is_const(&op2))
	{
		class2=2;
	}
	else if(op_is_addr(&op2))
	{
		class2=3;
		c=8;
	}
	else if(!if_class_signed(op2.tab->class))
	{
		sign=0;
	}
	if(class1==0||class1==1)
	{
		if(class2==0||class2==1)
		{
			if(op1.tab->class>op2.tab->class)
			{
				c=op1.tab->class;
			}
			else
			{
				c=op2.tab->class;
			}
		}
		else
		{
			c=op1.tab->class;
		}
	}
	else
	{
		if(class2==0||class2==1)
		{
			c=op2.tab->class;
		}
		else
		{
			c=8;
		}
	}
	if(c==9)
	{
		sign=0;
	}
	if(class1==1)
	{
		reg_ext(op1.tab->reg+4,op1.tab->class,c);
	}
	if(class2==1)
	{
		reg_ext(op2.tab->reg+4,op2.tab->class,c);
	}
	if(class1==1)
	{
		outs("mov x1,");
		out_reg64(op1.tab->reg+4);
		outs("\n");
	}
	else if(class1==0)
	{
		op_mem_ldst("ldr",&op1,1);
	}
	else if(class1==2)
	{
		outs("mov64 x1,");
		op_out_const(c,&op1);
		outs("\n");
	}
	else if(class1==3)
	{
		op_calculate_addr(&op1,1);
	}
	if(class2==1)
	{
		outs("mov x2,");
		out_reg64(op2.tab->reg+4);
		outs("\n");
	}
	else if(class2==0)
	{
		op_mem_ldst("ldr",&op2,2);
	}
	else if(class2==2)
	{
		outs("mov64 x2,");
		op_out_const(c,&op2);
		outs("\n");
	}
	else if(class2==3)
	{
		op_calculate_addr(&op2,2);
	}
	if(c==9)
	{
		if(class1==2||class1==3||op1.tab->class==9)
		{
			outs("fmov d1,x1\n");
		}
		else
		{
			outs("scvtf d1,x1\n");
		}
		if(class2==2||class2==3||op2.tab->class==9)
		{
			outs("fmov d2,x2\n");
		}
		else
		{
			outs("scvtf d2,x2\n");
		}
		outs("fcmp d1,d2\n");
	}
	else
	{
		outs("subs xzr,x1,x2\n");
	}
	if(sign)
	{
		outs(op_1);
	}
	else
	{
		outs(op_2);
	}
	outs(" @_$LB");
	outs(ins->args[3]);
	outs("\n");
	last_store_valid=0;
}
