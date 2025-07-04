#source: start1.s
#source: tls128.s
#source: tls-ie-10.s
#source: tls-hx.s
#as: --no-underscore --emulation=criself --pic -I$srcdir/$subdir
#ld: -m crislinux
#objdump: -d -s -t -r -p

# Check that we have proper NPTL/TLS markings and GOT for an
# executable with a single R_CRIS_32_GOT_TPREL.

.*:     file format elf32-cris

Program Header:
#...
     TLS off    0x0+a0 vaddr 0x0+820a0 paddr 0x0+820a0 align 2\*\*2
         filesz 0x0+84 memsz 0x0+84 flags r--
private flags = 0:
#...
SYMBOL TABLE:
#...
0+80 l       \.tdata	0+4 x
#...
Contents of section \.text:
#...
Contents of section \.tdata:
#...
Contents of section \.got:
 82124 00000000 00000000 00000000 fcffffff  .*

Disassembly of section \.text:

00080094 <_start>:
   80094:	41b2                	moveq 1,\$r11
#...
00080098 <tlsdsofn10>:
   80098:	6fae 0c00 0000      	move\.d c <tls128\+0xc>,\$r10
#...
