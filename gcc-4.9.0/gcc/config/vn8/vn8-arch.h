/* Definitions of types that are used to store VN8 architecture and
   device information.
   Copyright (C) 2012-2014 Free Software Foundation, Inc.
   Contributed by Georg-Johann Lay (vn8@gjlay.de)

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


/* This enum supplies indices into the vn8_arch_types[] table below. */

enum vn8_arch
{
  ARCH_UNKNOWN,
  ARCH_VN81,
  ARCH_VN82,
  ARCH_VN825,
  ARCH_VN83,
  ARCH_VN831,
  ARCH_VN835,
  ARCH_VN84,
  ARCH_VN85,
  ARCH_VN851,
  ARCH_VN86,
  ARCH_VN8XMEGA2,
  ARCH_VN8XMEGA4,
  ARCH_VN8XMEGA5,
  ARCH_VN8XMEGA6,
  ARCH_VN8XMEGA7,
  ARCH_VN8
};


/* Architecture-specific properties.  */

typedef struct
{
  /* Assembler only.  */
  int asm_only;

  /* Core have 'MUL*' instructions.  */
  int have_mul;

  /* Core have 'CALL' and 'JMP' instructions.  */
  int have_jmp_call;

  /* Core have 'MOVW' and 'LPM Rx,Z' instructions.  */
  int have_movw_lpmx;

  /* Core have 'ELPM' instructions.  */
  int have_elpm;

  /* Core have 'ELPM Rx,Z' instructions.  */
  int have_elpmx;

  /* Core have 'EICALL' and 'EIJMP' instructions.  */
  int have_eijmp_eicall;

  /* This is an XMEGA core.  */
  int xmega_p;

  /* This core has the RAMPD special function register
     and thus also the RAMPX, RAMPY and RAMPZ registers.  */
  int have_rampd;

  /* Default start of data section address for architecture.  */
  int default_data_section_start;

  /* Offset between SFR address and RAM address:
     SFR-address = RAM-address - sfr_offset  */
  int sfr_offset;

  /* Architecture id to built-in define __VN8_ARCH__ (NULL -> no macro) */
  const char *const macro;

  /* Architecture name.  */
  const char *const arch_name;
} vn8_arch_t;


/* Device-specific properties.  */

typedef struct
{
  /* Device name.  */
  const char *const name;

  /* Index in vn8_arch_types[].  */
  enum vn8_arch arch;

  /* device specific feature */
  int dev_attribute;

  /* Must lie outside user's namespace.  NULL == no macro.  */
  const char *const macro;

  /* Start of data section.  */
  int data_section_start;

  /* Number of 64k segments in the flash.  */
  int n_flash;

  /* Name of device library.  */
  const char *const library_name;
} vn8_mcu_t;

/* VN8 device specific features.

VN8_ISA_RMW
  Only few vn8 devices have Read-Modify-Write (RMW) instructions
  (XCH, LAC, LAS and LAT)

VN8_SHORT_SP
  Stack Pointer has only 8 bit width.
  The device / multilib has an 8-bit stack pointer (no SPH).

VN8_ERRATA_SKIP
  Some VN8 devices have a core erratum when skipping a 2-word instruction.
  Skip instructions are:  SBRC, SBRS, SBIC, SBIS, CPSE.
  Problems will occur with return address is IRQ executes during the
  skip sequence.

  A support ticket from Atmel returned the following information:

     Subject: (ATTicket:644469) On VN8 skip-bug core Erratum
     From: vn8@atmel.com                    Date: 2011-07-27
     (Please keep the subject when replying to this mail)

     This errata exists only in AT90S8515 and ATmega103 devices.

     For information please refer the following respective errata links
       http://www.atmel.com/dyn/resources/prod_documents/doc2494.pdf
       http://www.atmel.com/dyn/resources/prod_documents/doc1436.pdf  */

enum vn8_device_specific_features
{
  VN8_ISA_NONE,
  VN8_ISA_RMW     = 0x1, /* device has RMW instructions. */
  VN8_SHORT_SP    = 0x2, /* Stack Pointer has 8 bits width. */
  VN8_ERRATA_SKIP = 0x4  /* device has a core erratum. */
};

/* Map architecture to its texinfo string.  */

typedef struct
{
  /* Architecture ID.  */
  enum vn8_arch arch;

  /* textinfo source to describe the archtiecture.  */
  const char *texinfo;
} vn8_arch_info_t;

/* Preprocessor macros to define depending on MCU type.  */

extern const vn8_arch_t vn8_arch_types[];
extern const vn8_arch_t *vn8_current_arch;

extern const vn8_mcu_t vn8_mcu_types[];
extern const vn8_mcu_t *vn8_current_device;
