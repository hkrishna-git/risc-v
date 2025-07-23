## [x86_64] Compilation with GCC and its performance

---

/opt/riscv/bin/riscv64-unknown-linux-gnu-c++ -O3 -v -march=rv64gcv -mabi=lp64d -DOPTIMIZE matrix_mul.cpp
Using built-in specs.
COLLECT_GCC=/opt/riscv/bin/riscv64-unknown-linux-gnu-c++
COLLECT_LTO_WRAPPER=/opt/riscv/libexec/gcc/riscv64-unknown-linux-gnu/15.1.0/lto-wrapper
Target: riscv64-unknown-linux-gnu
Configured with: /home/hkrishna/riscv-toolchain/riscv-gnu-toolchain/gcc/configure --target=riscv64-unknown-linux-gnu --prefix=/opt/riscv --with-sysroot=/opt/riscv/sysroot --with-pkgversion=g1b306039ac4 --with-system-zlib --enable-shared --enable-tls --enable-languages=c,c++,fortran --disable-libmudflap --disable-libssp --disable-libquadmath --disable-libsanitizer --disable-nls --disable-bootstrap --src=.././gcc --disable-default-pie --enable-multilib --with-abi=lp64d --with-arch=rv64gc --with-isa-spec=20191213 'CFLAGS_FOR_TARGET=-O2    -mcmodel=medlow' 'CXXFLAGS_FOR_TARGET=-O2    -mcmodel=medlow'
Thread model: posix
Supported LTO compression algorithms: zlib
gcc version 15.1.0 (g1b306039ac4)
COLLECT_GCC_OPTIONS='-O3' '-v' '-march=rv64gcv' '-mabi=lp64d' '-D' 'OPTIMIZE' '-shared-libgcc' '-misa-spec=20191213' '-mtls-dialect=trad' '-march=rv64imafdcv_zicsr_zifencei_zmmul_zaamo_zalrsc_zca_zcd_zve32f_zve32x_zve64d_zve64f_zve64x_zvl128b_zvl32b_zvl64b' '-dumpdir' 'a-'
 /opt/riscv/libexec/gcc/riscv64-unknown-linux-gnu/15.1.0/cc1plus -quiet -v -imultilib lib64/lp64d -D_GNU_SOURCE -D OPTIMIZE matrix_mul.cpp -quiet -dumpdir a- -dumpbase matrix_mul.cpp -dumpbase-ext .cpp -march=rv64gcv -mabi=lp64d -misa-spec=20191213 -mtls-dialect=trad -march=rv64imafdcv_zicsr_zifencei_zmmul_zaamo_zalrsc_zca_zcd_zve32f_zve32x_zve64d_zve64f_zve64x_zvl128b_zvl32b_zvl64b -O3 -version -o /tmp/ccfqkDMl.s
GNU C++17 (g1b306039ac4) version 15.1.0 (riscv64-unknown-linux-gnu)
        compiled by GNU C version 13.3.0, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version none
GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
ignoring nonexistent directory "/opt/riscv/sysroot/usr/local/include"
#include "..." search starts here:
#include <...> search starts here:
 /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/../../../../riscv64-unknown-linux-gnu/include/c++/15.1.0
 /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/../../../../riscv64-unknown-linux-gnu/include/c++/15.1.0/riscv64-unknown-linux-gnu/lib64/lp64d
 /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/../../../../riscv64-unknown-linux-gnu/include/c++/15.1.0/backward
 /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/include
 /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/include-fixed
 /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/../../../../riscv64-unknown-linux-gnu/include
 /opt/riscv/sysroot/usr/include
End of search list.
Compiler executable checksum: 1a1f8246df46fb25b105b74ab547e136
COLLECT_GCC_OPTIONS='-O3' '-v' '-march=rv64gcv' '-mabi=lp64d' '-D' 'OPTIMIZE' '-shared-libgcc' '-misa-spec=20191213' '-mtls-dialect=trad' '-march=rv64imafdcv_zicsr_zifencei_zmmul_zaamo_zalrsc_zca_zcd_zve32f_zve32x_zve64d_zve64f_zve64x_zvl128b_zvl32b_zvl64b' '-dumpdir' 'a-'
 /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/../../../../riscv64-unknown-linux-gnu/bin/as -v --traditional-format -march=rv64gcv -march=rv64imafdcv_zicsr_zifencei_zmmul_zaamo_zalrsc_zca_zcd_zve32f_zve32x_zve64d_zve64f_zve64x_zvl128b_zvl32b_zvl64b -mabi=lp64d -misa-spec=20191213 -o /tmp/cct7UXfE.o /tmp/ccfqkDMl.s
GNU assembler version 2.44 (riscv64-unknown-linux-gnu) using BFD version (GNU Binutils) 2.44
COMPILER_PATH=/opt/riscv/libexec/gcc/riscv64-unknown-linux-gnu/15.1.0/:/opt/riscv/libexec/gcc/riscv64-unknown-linux-gnu/15.1.0/:/opt/riscv/libexec/gcc/riscv64-unknown-linux-gnu/:/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/:/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/:/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/../../../../riscv64-unknown-linux-gnu/bin/
LIBRARY_PATH=/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/lib64/lp64d/:/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/../../../../riscv64-unknown-linux-gnu/lib/lib64/lp64d/:/opt/riscv/sysroot/lib/lib64/lp64d/:/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/:/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/../../../../riscv64-unknown-linux-gnu/lib/:/opt/riscv/sysroot/lib64/lp64d/:/opt/riscv/sysroot/usr/lib64/lp64d/:/opt/riscv/sysroot/lib/
COLLECT_GCC_OPTIONS='-O3' '-v' '-march=rv64gcv' '-mabi=lp64d' '-D' 'OPTIMIZE' '-shared-libgcc' '-misa-spec=20191213' '-mtls-dialect=trad' '-march=rv64imafdcv_zicsr_zifencei_zmmul_zaamo_zalrsc_zca_zcd_zve32f_zve32x_zve64d_zve64f_zve64x_zvl128b_zvl32b_zvl64b' '-dumpdir' 'a.'
 /opt/riscv/libexec/gcc/riscv64-unknown-linux-gnu/15.1.0/collect2 -plugin /opt/riscv/libexec/gcc/riscv64-unknown-linux-gnu/15.1.0/liblto_plugin.so -plugin-opt=/opt/riscv/libexec/gcc/riscv64-unknown-linux-gnu/15.1.0/lto-wrapper -plugin-opt=-fresolution=/tmp/cceyG5oN.res -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lgcc --sysroot=/opt/riscv/sysroot --eh-frame-hdr -melf64lriscv -X -dynamic-linker /lib/ld-linux-riscv64-lp64d.so.1 /opt/riscv/sysroot/usr/lib64/lp64d/crt1.o /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/lib64/lp64d/crti.o /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/lib64/lp64d/crtbegin.o -L/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/lib64/lp64d -L/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/../../../../riscv64-unknown-linux-gnu/lib/lib64/lp64d -L/opt/riscv/sysroot/lib/lib64/lp64d -L/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0 -L/opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/../../../../riscv64-unknown-linux-gnu/lib -L/opt/riscv/sysroot/lib64/lp64d -L/opt/riscv/sysroot/usr/lib64/lp64d -L/opt/riscv/sysroot/lib /tmp/cct7UXfE.o -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/lib64/lp64d/crtend.o /opt/riscv/lib/gcc/riscv64-unknown-linux-gnu/15.1.0/lib64/lp64d/crtn.o
COLLECT_GCC_OPTIONS='-O3' '-v' '-march=rv64gcv' '-mabi=lp64d' '-D' 'OPTIMIZE' '-shared-libgcc' '-misa-spec=20191213' '-mtls-dialect=trad' '-march=rv64imafdcv_zicsr_zifencei_zmmul_zaamo_zalrsc_zca_zcd_zve32f_zve32x_zve64d_zve64f_zve64x_zvl128b_zvl32b_zvl64b' '-dumpdir' 'a.'

/opt/riscv/bin/qemu-riscv64 a.out  
Function : main  
Native matrix multiplication time: 13.9353 seconds  
Block matrix multiplication time: 11.7789 seconds  

/opt/riscv/bin/qemu-riscv64 a.out  
Function : main  
Native matrix multiplication time: 15.4485 seconds  
Block matrix multiplication time: 12.9218 seconds  

/opt/riscv/bin/qemu-riscv64 a.out  
Function : main  
Native matrix multiplication time: 14.4312 seconds  
Block matrix multiplication time: 10.1066 seconds  

/opt/riscv/bin/qemu-riscv64 a.out  
Function : main  
Native matrix multiplication time: 14.4327 seconds  
Block matrix multiplication time: 12.5945 seconds  

/opt/riscv/bin/qemu-riscv64 a.out  
Function : main  
Native matrix multiplication time: 10.7621 seconds  
Block matrix multiplication time: 10.2208 seconds  

---
