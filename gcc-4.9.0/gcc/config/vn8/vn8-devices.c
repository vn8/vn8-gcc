/* Copyright (C) 2009-2014 Free Software Foundation, Inc.
   Contributed by Anatoly Sokolov (aesok@post.ru)

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

#ifndef IN_GEN_VN8_MMCU_TEXI
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#endif /* IN_GEN_VN8_MMCU_TEXI */

/* List of all known VN8 MCU architectures.
   Order as of enum vn8_arch from vn8.h.  */

const vn8_arch_t
vn8_arch_types[] =
{
  /* unknown device specified */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x0060, 32, NULL,              "vn82"  },
  /*
    A  M  J  LM E  E  E  X  R   d S   S O   A
    S  U  M  PO L  L  I  M  A   a t   F ff  r
    M  L  P  MV P  P  J  E  M   t a   R s   c
             XW M  M  M  G  P   a r     e   h
                   X  P  A  D     t     t   ID   */
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0x0060, 32, "1",   "vn81"  },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x0060, 32, "2",   "vn82"  },
  { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0x0060, 32, "25",  "vn825" },
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0x0060, 32, "3",   "vn83"  },
  { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0x0060, 32, "31",  "vn831" },
  { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0x0060, 32, "35",  "vn835" },
  { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0x0060, 32, "4",   "vn84"  },
  { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0x0060, 32, "5",   "vn85"  },
  { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0x0060, 32, "51",  "vn851" },
  { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0x0060, 32, "6",   "vn86"  },

  { 0, 1, 1, 1, 0, 0, 0, 1, 0, 0x2000,  0, "102", "vn8xmega2" },
  { 0, 1, 1, 1, 1, 1, 0, 1, 0, 0x2000,  0, "104", "vn8xmega4" },
  { 0, 1, 1, 1, 1, 1, 0, 1, 1, 0x2000,  0, "105", "vn8xmega5" },
  { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0x2000,  0, "106", "vn8xmega6" },
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0x2000,  0, "107", "vn8xmega7" },
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0x0060,  0, "2", "vn8" }
};

const vn8_arch_info_t
vn8_texinfo[] =
{
  { ARCH_VN81,
    "This ISA is implemented by the minimal VN8 core and supported "
    "for assembler only." },
  { ARCH_VN82,
    "``Classic'' devices with up to 8@tie{}KiB of program memory." },
  { ARCH_VN825,
    "``Classic'' devices with up to 8@tie{}KiB of program memory and with "
    "the @code{MOVW} instruction." },
  { ARCH_VN83,
    "``Classic'' devices with 16@tie{}KiB up to 64@tie{}KiB of "
    " program memory." },
  { ARCH_VN831,
    "``Classic'' devices with 128@tie{}KiB of program memory." },
  { ARCH_VN835,
    "``Classic'' devices with 16@tie{}KiB up to 64@tie{}KiB of "
    "program memory and with the @code{MOVW} instruction." },
  { ARCH_VN84,
    "``Enhanced'' devices with up to 8@tie{}KiB of program memory." },
  { ARCH_VN85,
    "``Enhanced'' devices with 16@tie{}KiB up to 64@tie{}KiB of "
    "program memory." },
  { ARCH_VN851,
    "``Enhanced'' devices with 128@tie{}KiB of program memory." },
  { ARCH_VN86,
    "``Enhanced'' devices with 3-byte PC, i.e.@: with more than 128@tie{}KiB "
    "of program memory." },
  { ARCH_VN8XMEGA2,
    "``XMEGA'' devices with more than 8@tie{}KiB and up to 64@tie{}KiB "
    "of program memory." },
  { ARCH_VN8XMEGA4,
    "``XMEGA'' devices with more than 64@tie{}KiB and up to 128@tie{}KiB "
    "of program memory." },
  { ARCH_VN8XMEGA5,
    "``XMEGA'' devices with more than 64@tie{}KiB and up to 128@tie{}KiB "
    "of program memory and more than 64@tie{}KiB of RAM." },
  { ARCH_VN8XMEGA6,
    "``XMEGA'' devices with more than 128@tie{}KiB of program memory." },
  { ARCH_VN8XMEGA7,
    "``XMEGA'' devices with more than 128@tie{}KiB of program memory "
    "and more than 64@tie{}KiB of RAM." },
  { ARCH_VN8,
    "``VN8'' devices with 256@tie{}KiB of program memory and more than 8@tie{}KiB of RAM." }
};

const vn8_mcu_t
vn8_mcu_types[] =
{
#define VN8_MCU(NAME, ARCH, DEV_ATTRIBUTE, MACRO, DATA_SEC, N_FLASH, LIBNAME)\
  { NAME, ARCH, DEV_ATTRIBUTE, MACRO, DATA_SEC, N_FLASH, LIBNAME },
#include "vn8-mcus.def"
#undef VN8_MCU
    /* End of list.  */
  { NULL, ARCH_UNKNOWN, VN8_ISA_NONE, NULL, 0, 0, NULL }
};

