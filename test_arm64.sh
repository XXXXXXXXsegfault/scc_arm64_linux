#!/bin/sh -ev
mkdir test || true
bin/host_arm64/scpp scpp/main.c test/scpp.i
bin/host_arm64/scpp scc/main.c test/scc.i
bin/host_arm64/scpp bcode/main.c test/bcode.i
bin/host_arm64/scpp asm/main.c test/asm.i
bin/host_arm64/scc test/scpp.i test/scpp.bcode
bin/host_arm64/scc test/scc.i test/scc.bcode
bin/host_arm64/scc test/bcode.i test/bcode.bcode
bin/host_arm64/scc test/asm.i test/asm.bcode
bin/host_arm64/bcode test/scpp.bcode test/scpp.asm
bin/host_arm64/bcode test/scc.bcode test/scc.asm
bin/host_arm64/bcode test/bcode.bcode test/bcode.asm
bin/host_arm64/bcode test/asm.bcode test/asm.asm
bin/host_arm64/asm test/scpp.asm test/scpp
bin/host_arm64/asm test/scc.asm test/scc
bin/host_arm64/asm test/bcode.asm test/bcode
bin/host_arm64/asm test/asm.asm test/asm
cmp test/scpp bin/host_arm64/scpp
cmp test/scc bin/host_arm64/scc
cmp test/bcode bin/host_arm64/bcode
cmp test/asm bin/host_arm64/asm
