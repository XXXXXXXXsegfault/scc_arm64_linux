int openat(int dirfd,char *name,int flags,int mode);
asm "@openat"
asm "stp x4,x5,[sp,#-16]!"
asm "stp x6,x7,[sp,#-16]!"
asm "str x8,[sp,#-16]!"
asm "ldr w0,[sp,#48]"
asm "ldr x1,[sp,#64]"
asm "ldr w2,[sp,#80]"
asm "ldr w3,[sp,#96]"
asm "mov x8,#56"
asm "svc #0"
asm "ldr x8,[sp],#16"
asm "ldp x6,x7,[sp],#16"
asm "ldp x4,x5,[sp],#16"
asm "ret"
int open(char *name,int flags,int mode)
{
	return openat(-100,name,flags,mode);
}
int close(int fd);
asm "@close"
asm "stp x4,x5,[sp,#-16]!"
asm "stp x6,x7,[sp,#-16]!"
asm "str x8,[sp,#-16]!"
asm "ldr w0,[sp,#48]"
asm "mov x8,#57"
asm "svc #0"
asm "ldr x8,[sp],#16"
asm "ldp x6,x7,[sp],#16"
asm "ldp x4,x5,[sp],#16"
asm "ret"
int read(int fd,void *buf,int size);
asm "@read"
asm "stp x4,x5,[sp,#-16]!"
asm "stp x6,x7,[sp,#-16]!"
asm "str x8,[sp,#-16]!"
asm "ldr w0,[sp,#48]"
asm "ldr x1,[sp,#64]"
asm "ldr w2,[sp,#80]"
asm "mov x8,#63"
asm "svc #0"
asm "ldr x8,[sp],#16"
asm "ldp x6,x7,[sp],#16"
asm "ldp x4,x5,[sp],#16"
asm "ret"
int write(int fd,void *buf,int size);
asm "@write"
asm "stp x4,x5,[sp,#-16]!"
asm "stp x6,x7,[sp,#-16]!"
asm "str x8,[sp,#-16]!"
asm "ldr w0,[sp,#48]"
asm "ldr x1,[sp,#64]"
asm "ldr w2,[sp,#80]"
asm "mov x8,#64"
asm "svc #0"
asm "ldr x8,[sp],#16"
asm "ldp x6,x7,[sp],#16"
asm "ldp x4,x5,[sp],#16"
asm "ret"
void *brk(void *ptr);
asm "@brk"
asm "stp x4,x5,[sp,#-16]!"
asm "stp x6,x7,[sp,#-16]!"
asm "str x8,[sp,#-16]!"
asm "ldr x0,[sp,#48]"
asm "mov x8,#214"
asm "svc #0"
asm "ldr x8,[sp],#16"
asm "ldp x6,x7,[sp],#16"
asm "ldp x4,x5,[sp],#16"
asm "ret"
void exit(int code);
asm "@exit"
asm "ldr w0,[sp]"
asm "mov x8,#94"
asm "svc #0"
