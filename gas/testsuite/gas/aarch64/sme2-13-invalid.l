[^ :]+: Assembler messages:
[^ :]+:[0-9]+: Error: expected a ZA array vector at operand 1 -- `smlall 0,z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a register or register list at operand 2 -- `smlall za\.s\[w8,0:3\],0,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected an SVE vector register at operand 3 -- `smlall za\.s\[w8,0:3\],z0\.b,0'
[^ :]+:[0-9]+: Error: expected 'za' rather than a ZA tile at operand 1 -- `smlall za0\.s\[w8,0:3\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected 'za' rather than a ZA tile at operand 1 -- `smlall za0h\.s\[w8,0:3\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a selection register in the range w8-w11 at operand 1 -- `smlall za\.s\[w7,0:3\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a selection register in the range w8-w11 at operand 1 -- `smlall za\.s\[w12,0:3\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a range of four offsets at operand 1 -- `smlall za\.s\[w8,0\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a range of four offsets at operand 1 -- `smlall za\.s\[w8,0:1\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a range of four offsets at operand 1 -- `smlall za\.s\[w8,0:2\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a range of four offsets at operand 1 -- `smlall za\.s\[w8,0,vgx4\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: unexpected vector group size at operand 1 -- `smlall za\.s\[w8,0:3,vgx2\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: unexpected vector group size at operand 1 -- `smlall za\.s\[w8,0:3,vgx4\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: starting offset is not a multiple of 4 at operand 1 -- `smlall za\.s\[w8,1:4\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: starting offset is not a multiple of 4 at operand 1 -- `smlall za\.s\[w8,2:5\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: starting offset is not a multiple of 4 at operand 1 -- `smlall za\.s\[w8,3:6\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: immediate offset out of range 0 to 12 at operand 1 -- `smlall za\.s\[w8,16:19\],z0\.b,z0\.b\[0\]'
[^ :]+:[0-9]+: Error: z0 ?- ?z15 expected at operand 3 -- `smlall za\.s\[w8,0:3\],z0\.b,z16\.b\[0\]'
[^ :]+:[0-9]+: Error: register element index out of range 0 to 15 at operand 3 -- `smlall za\.s\[w8,0:3\],z0\.b,z0\.b\[-1\]'
[^ :]+:[0-9]+: Error: register element index out of range 0 to 15 at operand 3 -- `smlall za\.s\[w8,0:3\],z0\.b,z0\.b\[16\]'
[^ :]+:[0-9]+: Error: operand mismatch -- `smlall za\.s\[w8,0:3\],z0\.h,z0\.h\[0\]'
[^ :]+:[0-9]+: Info:    did you mean this\?
[^ :]+:[0-9]+: Info:    	smlall za\.d\[w8, 0:3\], z0\.h, z0\.h\[0\]
[^ :]+:[0-9]+: Error: operand mismatch -- `smlall za\.s\[w8,0:3\],z0\.s,z0\.s\[0\]'
[^ :]+:[0-9]+: Info:    did you mean this\?
[^ :]+:[0-9]+: Info:    	smlall za\.s\[w8, 0:3\], z0\.b, z0\.b\[0\]
[^ :]+:[0-9]+: Error: expected a selection register in the range w8-w11 at operand 1 -- `smlall za\.s\[w7,0:3\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a selection register in the range w8-w11 at operand 1 -- `smlall za\.s\[w12,0:3\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a range of four offsets at operand 1 -- `smlall za\.s\[w8,0\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a range of four offsets at operand 1 -- `smlall za\.s\[w8,0:1\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a range of four offsets at operand 1 -- `smlall za\.s\[w8,0:2\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a list of 4 registers at operand 2 -- `smlall za\.s\[w8,0:3,vgx4\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: starting offset is not a multiple of 4 at operand 1 -- `smlall za\.s\[w8,1:4\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: starting offset is not a multiple of 4 at operand 1 -- `smlall za\.s\[w8,2:5\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: starting offset is not a multiple of 4 at operand 1 -- `smlall za\.s\[w8,3:6\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: immediate offset out of range 0 to 4 at operand 1 -- `smlall za\.s\[w8,8:11\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: start register out of range at operand 2 -- `smlall za\.s\[w8,0:3\],{ ?z1\.b ?- ?z2\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: z0 ?- ?z15 expected at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z1\.b ?},z16\.b\[0\]'
[^ :]+:[0-9]+: Error: register element index out of range 0 to 15 at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[-1\]'
[^ :]+:[0-9]+: Error: register element index out of range 0 to 15 at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z1\.b ?},z0\.b\[16\]'
[^ :]+:[0-9]+: Error: expected a selection register in the range w8-w11 at operand 1 -- `smlall za\.s\[w7,0:3\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a selection register in the range w8-w11 at operand 1 -- `smlall za\.s\[w12,0:3\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a range of four offsets at operand 1 -- `smlall za\.s\[w8,0\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a range of four offsets at operand 1 -- `smlall za\.s\[w8,0:1\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a range of four offsets at operand 1 -- `smlall za\.s\[w8,0:2\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: expected a list of 2 registers at operand 2 -- `smlall za\.s\[w8,0:3,vgx2\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: starting offset is not a multiple of 4 at operand 1 -- `smlall za\.s\[w8,1:4\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: starting offset is not a multiple of 4 at operand 1 -- `smlall za\.s\[w8,2:5\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: starting offset is not a multiple of 4 at operand 1 -- `smlall za\.s\[w8,3:6\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: immediate offset out of range 0 to 4 at operand 1 -- `smlall za\.s\[w8,8:11\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: start register out of range at operand 2 -- `smlall za\.s\[w8,0:3\],{ ?z1\.b ?- ?z4\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: start register out of range at operand 2 -- `smlall za\.s\[w8,0:3\],{ ?z2\.b ?- ?z5\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: start register out of range at operand 2 -- `smlall za\.s\[w8,0:3\],{ ?z3\.b ?- ?z6\.b ?},z0\.b\[0\]'
[^ :]+:[0-9]+: Error: z0 ?- ?z15 expected at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z3\.b ?},z16\.b\[0\]'
[^ :]+:[0-9]+: Error: register element index out of range 0 to 15 at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[-1\]'
[^ :]+:[0-9]+: Error: register element index out of range 0 to 15 at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z3\.b ?},z0\.b\[16\]'
[^ :]+:[0-9]+: Error: unexpected vector group size at operand 1 -- `smlall za\.s\[w8,0:3,vgx2\],z0\.b,z0\.b'
[^ :]+:[0-9]+: Error: unexpected vector group size at operand 1 -- `smlall za\.s\[w8,0:3,vgx4\],z0\.b,z0\.b'
[^ :]+:[0-9]+: Error: immediate offset out of range 0 to 12 at operand 1 -- `smlall za\.s\[w8,16:19\],z0\.b,z0\.b'
[^ :]+:[0-9]+: Error: z0 ?- ?z15 expected at operand 3 -- `smlall za\.s\[w8,0:3\],z0\.b,z16\.b'
[^ :]+:[0-9]+: Error: expected a list of 4 registers at operand 2 -- `smlall za\.s\[w8,0:3,vgx4\],{ ?z0\.b ?- ?z1\.b ?},z0\.b'
[^ :]+:[0-9]+: Error: immediate offset out of range 0 to 4 at operand 1 -- `smlall za\.s\[w8,8:11\],{ ?z0\.b ?- ?z1\.b ?},z0\.b'
[^ :]+:[0-9]+: Error: expected a list of 2 or 4 registers at operand 2 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z2\.b ?},z0\.b'
[^ :]+:[0-9]+: Error: z0 ?- ?z15 expected at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z1\.b ?},z16\.b'
[^ :]+:[0-9]+: Error: expected a list of 2 registers at operand 2 -- `smlall za\.s\[w8,0:3,vgx2\],{ ?z0\.b ?- ?z3\.b ?},z0\.b'
[^ :]+:[0-9]+: Error: immediate offset out of range 0 to 4 at operand 1 -- `smlall za\.s\[w8,8:11\],{ ?z0\.b ?- ?z3\.b ?},z0\.b'
[^ :]+:[0-9]+: Error: z0 ?- ?z15 expected at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z3\.b ?},z16\.b'
[^ :]+:[0-9]+: Error: expected a list of 4 registers at operand 2 -- `smlall za\.s\[w8,0:3,vgx4\],{ ?z0\.b ?- ?z1\.b ?},{ ?z0\.b ?- ?z1\.b ?}'
[^ :]+:[0-9]+: Error: immediate offset out of range 0 to 4 at operand 1 -- `smlall za\.s\[w8,8:11\],{ ?z0\.b ?- ?z1\.b ?},{ ?z0\.b ?- ?z1\.b ?}'
[^ :]+:[0-9]+: Error: start register out of range at operand 2 -- `smlall za\.s\[w8,0:3\],{ ?z1\.b ?- ?z2\.b ?},{ ?z0\.b ?- ?z1\.b ?}'
[^ :]+:[0-9]+: Error: start register out of range at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z1\.b ?},{ ?z1\.b ?- ?z2\.b ?}'
[^ :]+:[0-9]+: Error: expected a list of 2 registers at operand 2 -- `smlall za\.s\[w8,0:3,vgx2\],{ ?z0\.b ?- ?z3\.b ?},{ ?z0\.b ?- ?z3\.b ?}'
[^ :]+:[0-9]+: Error: immediate offset out of range 0 to 4 at operand 1 -- `smlall za\.s\[w8,8:11\],{ ?z0\.b ?- ?z3\.b ?},{ ?z0\.b ?- ?z3\.b ?}'
[^ :]+:[0-9]+: Error: start register out of range at operand 2 -- `smlall za\.s\[w8,0:3\],{ ?z1\.b ?- ?z4\.b ?},{ ?z0\.b ?- ?z3\.b ?}'
[^ :]+:[0-9]+: Error: start register out of range at operand 2 -- `smlall za\.s\[w8,0:3\],{ ?z2\.b ?- ?z5\.b ?},{ ?z0\.b ?- ?z3\.b ?}'
[^ :]+:[0-9]+: Error: start register out of range at operand 2 -- `smlall za\.s\[w8,0:3\],{ ?z3\.b ?- ?z6\.b ?},{ ?z0\.b ?- ?z3\.b ?}'
[^ :]+:[0-9]+: Error: start register out of range at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z3\.b ?},{ ?z1\.b ?- ?z4\.b ?}'
[^ :]+:[0-9]+: Error: start register out of range at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z3\.b ?},{ ?z2\.b ?- ?z5\.b ?}'
[^ :]+:[0-9]+: Error: start register out of range at operand 3 -- `smlall za\.s\[w8,0:3\],{ ?z0\.b ?- ?z3\.b ?},{ ?z3\.b ?- ?z6\.b ?}'
