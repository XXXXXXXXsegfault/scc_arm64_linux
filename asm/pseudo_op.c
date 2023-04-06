void parse_pseudo_op(char *str)
{
	char *word,*p,c;
	unsigned long int val;
	int n;
	if(str_match(&str,"string"))
	{
		word=read_word(&str);
		if(*word!='\"')
		{
			error(l->line,"expected string after \'.string\'.");
		}
		p=word+1;
		while(*p!='\"')
		{
			p=sgetc(p,&c);
			soutc(c);
		}
		free(word);
		soutc(0);
	}
	else if(str_match(&str,"entry"))
	{
		l->needs_recompile=1;
		elf_header.entry=pc;
	}
	else if(str_match(&str,"datasize"))
	{
		word=read_word(&str);
		if(word)
		{
			data_size=const_to_num(word);
			free(word);
		}
	}
	else if(str_match(&str,"byte"))
	{
		n=0;
		do
		{
			if(n==32)
			{
				error(l->line,"too many constants in one line.");
			}
			if(parse_const(&str,&val)==-1)
			{
				error(l->line,"invalid constant expression.");
			}
			swrite(&val,1);
			++n;
		}
		while(str_match(&str,","));
	}
	else if(str_match(&str,"word"))
	{
		n=0;
		do
		{
			if(n==16)
			{
				error(l->line,"too many constants in one line.");
			}
			if(parse_const(&str,&val)==-1)
			{
				error(l->line,"invalid constant expression.");
			}
			swrite(&val,2);
			++n;
		}
		while(str_match(&str,","));
	}
	else if(str_match(&str,"long"))
	{
		n=0;
		do
		{
			if(n==8)
			{
				error(l->line,"too many constants in one line.");
			}
			if(parse_const(&str,&val)==-1)
			{
				error(l->line,"invalid constant expression.");
			}
			swrite(&val,4);
			++n;
		}
		while(str_match(&str,","));
	}
	else if(str_match(&str,"quad"))
	{
		n=0;
		do
		{
			if(n==4)
			{
				error(l->line,"too many constants in one line.");
			}
			if(parse_const(&str,&val)==-1)
			{
				error(l->line,"invalid constant expression.");
			}
			swrite(&val,8);
			++n;
		}
		while(str_match(&str,","));
	}
	else if(str_match(&str,"align"))
	{
		word=read_word(&str);
		if(word)
		{
			val=const_to_num(word);
			if(val<5)
			{
				while((1<<val)-1&spos)
				{
					soutc(0);
				}
				l->needs_recompile=1;
			}
		}
	}
	else
	{
		error(l->line,"unknown pseudo-op.");
	}
}
