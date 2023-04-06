#ifdef __GNUC__
#ifndef __linux__
#error "This program can only run on Linux"
#endif
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define float double
#else
asm ".align 3"
asm ".entry"
asm "add x1,sp,#8"
asm "ldr x0,[sp]"
asm "str x1,[sp,#-16]!"
asm "str x0,[sp,#-16]!"
asm "bl @main"
asm "mov x8,#94"
asm "svc #0"
#include "syscall.c"
#include "mem.c"
#include "malloc.c"
#endif
#include "xmalloc.c"
#include "string.c"
