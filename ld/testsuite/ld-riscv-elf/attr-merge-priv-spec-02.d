#source: attr-merge-priv-spec-a.s
#source: attr-merge-priv-spec-d.s
#as: -march-attr
#ld: -r
#readelf: -A

Attribute Section: riscv
File Attributes
  Tag_RISCV_arch: [a-zA-Z0-9_\"].*
  Tag_RISCV_priv_spec: 1
  Tag_RISCV_priv_spec_minor: 10
