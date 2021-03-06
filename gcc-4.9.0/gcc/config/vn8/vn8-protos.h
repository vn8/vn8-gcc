/* Prototypes for exported functions defined in vn8.c

   Copyright (C) 2000-2014 Free Software Foundation, Inc.
   Contributed by Denis Chertykov (chertykov@gmail.com)

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */


extern int vn8_function_arg_regno_p (int r);
extern void vn8_cpu_cpp_builtins (struct cpp_reader * pfile);
extern enum reg_class vn8_regno_reg_class (int r);
extern void asm_globalize_label (FILE *file, const char *name);
extern void vn8_adjust_reg_alloc_order (void);
extern int vn8_initial_elimination_offset (int from, int to);
extern int vn8_simple_epilogue (void);
extern int vn8_hard_regno_rename_ok (unsigned int, unsigned int);
extern rtx vn8_return_addr_rtx (int count, rtx tem);
extern void vn8_register_target_pragmas (void);
extern void vn8_init_expanders (void);

#ifdef TREE_CODE
extern void vn8_asm_output_aligned_decl_common (FILE*, const_tree, const char*, unsigned HOST_WIDE_INT, unsigned int, bool);
extern void asm_output_external (FILE *file, tree decl, char *name);
extern int vn8_progmem_p (tree decl, tree attributes);

#ifdef RTX_CODE /* inside TREE_CODE */
extern void vn8_init_cumulative_args (CUMULATIVE_ARGS*, tree, rtx, tree);
#endif /* RTX_CODE inside TREE_CODE */

#endif /* TREE_CODE */

#ifdef RTX_CODE
extern int vn8_hard_regno_call_part_clobbered (unsigned, enum machine_mode);
extern const char *output_movqi (rtx insn, rtx operands[], int *l);
extern const char *output_movhi (rtx insn, rtx operands[], int *l);
extern const char *output_movsisf (rtx insn, rtx operands[], int *l);
extern const char *vn8_out_tstsi (rtx, rtx*, int*);
extern const char *vn8_out_tsthi (rtx, rtx*, int*);
extern const char *vn8_out_tstpsi (rtx, rtx*, int*);
extern const char *vn8_out_compare (rtx, rtx*, int*);
extern const char *vn8_out_compare64 (rtx, rtx*, int*);
extern const char *ret_cond_branch (rtx x, int len, int reverse);
extern const char *vn8_out_movpsi (rtx, rtx*, int*);

extern const char *ashlqi3_out (rtx insn, rtx operands[], int *len);
extern const char *ashlhi3_out (rtx insn, rtx operands[], int *len);
extern const char *ashlsi3_out (rtx insn, rtx operands[], int *len);

extern const char *ashrqi3_out (rtx insn, rtx operands[], int *len);
extern const char *ashrhi3_out (rtx insn, rtx operands[], int *len);
extern const char *ashrsi3_out (rtx insn, rtx operands[], int *len);

extern const char *lshrqi3_out (rtx insn, rtx operands[], int *len);
extern const char *lshrhi3_out (rtx insn, rtx operands[], int *len);
extern const char *lshrsi3_out (rtx insn, rtx operands[], int *len);

extern const char *vn8_out_ashlpsi3 (rtx, rtx*, int*);
extern const char *vn8_out_ashrpsi3 (rtx, rtx*, int*);
extern const char *vn8_out_lshrpsi3 (rtx, rtx*, int*);

extern bool vn8_rotate_bytes (rtx operands[]);

extern const char* vn8_out_fract (rtx, rtx[], bool, int*);
extern rtx vn8_to_int_mode (rtx);

extern void vn8_expand_prologue (void);
extern void vn8_expand_epilogue (bool);
extern bool vn8_emit_movmemhi (rtx*);
extern int vn8_epilogue_uses (int regno);
extern int vn8_starting_frame_offset (void);

extern void vn8_output_addr_vec_elt (FILE *stream, int value);
extern const char *vn8_out_sbxx_branch (rtx insn, rtx operands[]);
extern const char* vn8_out_bitop (rtx, rtx*, int*);
extern const char* vn8_out_plus (rtx, rtx*, int* =NULL, int* =NULL, bool =true);
extern const char* vn8_out_round (rtx, rtx*, int* =NULL);
extern const char* vn8_out_addto_sp (rtx*, int*);
extern const char* vn8_out_xload (rtx, rtx*, int*);
extern const char* vn8_out_movmem (rtx, rtx*, int*);
extern const char* vn8_out_insert_bits (rtx*, int*);
extern bool vn8_popcount_each_byte (rtx, int, int);
extern bool vn8_has_nibble_0xf (rtx);

extern int extra_constraint_Q (rtx x);
extern int vn8_adjust_insn_length (rtx insn, int len);
extern const char* output_reload_inhi (rtx*, rtx, int*);
extern const char* output_reload_insisf (rtx*, rtx, int*);
extern const char* vn8_out_reload_inpsi (rtx*, rtx, int*);
extern const char* vn8_out_lpm (rtx, rtx*, int*);
extern void vn8_notice_update_cc (rtx body, rtx insn);
extern int reg_unused_after (rtx insn, rtx reg);
extern int _reg_unused_after (rtx insn, rtx reg);
extern int vn8_jump_mode (rtx x, rtx insn);
extern int test_hard_reg_class (enum reg_class rclass, rtx x);
extern int jump_over_one_insn_p (rtx insn, rtx dest);

extern int vn8_hard_regno_mode_ok (int regno, enum machine_mode mode);
extern void vn8_final_prescan_insn (rtx insn, rtx *operand, int num_operands);
extern int vn8_simplify_comparison_p (enum machine_mode mode,
				      RTX_CODE op, rtx x);
extern RTX_CODE vn8_normalize_condition (RTX_CODE condition);
extern void out_shift_with_cnt (const char *templ, rtx insn,
				rtx operands[], int *len, int t_len);
extern enum reg_class vn8_mode_code_base_reg_class (enum machine_mode, addr_space_t, RTX_CODE, RTX_CODE);
extern bool vn8_regno_mode_code_ok_for_base_p (int, enum machine_mode, addr_space_t, RTX_CODE, RTX_CODE);
extern rtx vn8_incoming_return_addr_rtx (void);
extern rtx vn8_legitimize_reload_address (rtx*, enum machine_mode, int, int, int, int, rtx (*)(rtx,int));
extern bool vn8_mem_flash_p (rtx);
extern bool vn8_mem_memx_p (rtx);
extern bool vn8_load_libgcc_p (rtx);
extern bool vn8_xload_libgcc_p (enum machine_mode);

extern rtx lpm_reg_rtx;
extern rtx lpm_addr_reg_rtx;
extern rtx tmp_reg_rtx;
extern rtx zero_reg_rtx;
extern rtx all_regs_rtx[NUM_GPR];
extern rtx rampz_rtx;

#endif /* RTX_CODE */

#ifdef REAL_VALUE_TYPE
extern void asm_output_float (FILE *file, REAL_VALUE_TYPE n);
#endif

extern bool vn8_have_dimode;

/* From vn8-log.c */

#define vn8_edump (vn8_log_set_caller_e (__FUNCTION__))
#define vn8_fdump (vn8_log_set_caller_f (__FUNCTION__))

extern int (*vn8_log_set_caller_e (const char*))(const char*, ...);
extern int (*vn8_log_set_caller_f (const char*))(FILE*, const char*, ...);

extern void vn8_log_set_vn8_log (void);

typedef struct
{
  unsigned address_cost :1;
  unsigned builtin :1;
  unsigned constraints :1;
  unsigned legitimate_address_p :1;
  unsigned legitimize_address :1;
  unsigned legitimize_reload_address :1;
  unsigned progmem :1;
  unsigned rtx_costs :1;
} vn8_log_t;

extern vn8_log_t vn8_log;
