/* Subroutines for the gcc driver.
   Copyright (C) 2009-2014 Free Software Foundation, Inc.
   Contributed by Anatoly Sokolov <aesok@post.ru>

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

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"

/* Current architecture.  */
const vn8_arch_t *vn8_current_arch = NULL;

/* Current device.  */
const vn8_mcu_t *vn8_current_device = NULL;

/* Initialize vn8_current_arch and vn8_current_device variables.  */

static void
vn8_set_current_device (const char *name)
{
 
 if (NULL != vn8_current_arch)
   return;
 
  for (vn8_current_device = vn8_mcu_types; vn8_current_device->name;
       vn8_current_device++)
    {
      if (strcmp (vn8_current_device->name, name) == 0)
        break;
    }

  vn8_current_arch = &vn8_arch_types[vn8_current_device->arch];
}

/* Returns command line parameters to pass to as.  */

const char*
vn8_device_to_as (int argc, const char **argv)
{
  if (0 == argc)
    return NULL;

  vn8_set_current_device (argv[0]);

  return concat ("-mmcu=", vn8_current_arch->arch_name,
    vn8_current_device->dev_attribute & VN8_ERRATA_SKIP ? "" : " -mno-skip-bug",
    vn8_current_device->dev_attribute & VN8_ISA_RMW ? " -mrmw" : "", NULL);
}

/* Returns command line parameters to pass to ld.  */

const char*
vn8_device_to_ld (int argc, const char **argv)
{
  if (0 == argc)
    return NULL;

  vn8_set_current_device (argv[0]);

  return concat ("-m ", vn8_current_arch->arch_name, NULL);
}

/* Returns command line parameters that describe start of date section.  */

const char *
vn8_device_to_data_start (int argc, const char **argv)
{
  unsigned long data_section_start;
  char data_section_start_str[16];

  if (0 == argc)
    return NULL;

  vn8_set_current_device (argv[0]);
  
  if (vn8_current_device->data_section_start 
      == vn8_current_arch->default_data_section_start)
    return NULL;
    
  data_section_start = 0x800000 + vn8_current_device->data_section_start;
  
  snprintf (data_section_start_str, sizeof(data_section_start_str) - 1,
            "0x%lX", data_section_start);
  
  return concat ("-Tdata ", data_section_start_str, NULL);    
}

/* Returns command line parameters that describe the device startfile.  */

const char *
vn8_device_to_startfiles (int argc, const char **argv)
{
  if (0 == argc)
    return NULL;

  vn8_set_current_device (argv[0]);

  return concat ("crt", vn8_current_device->library_name, ".o%s", NULL);
}

/* Returns command line parameters that describe the device library.  */

const char *
vn8_device_to_devicelib (int argc, const char **argv)
{
  if (0 == argc)
    return NULL;

  vn8_set_current_device (argv[0]);

  return concat ("-l", vn8_current_device->library_name, NULL);
}

const char*
vn8_device_to_sp8 (int argc, const char **argv)
{
  if (0 == argc)
    return NULL;

  vn8_set_current_device (argv[0]);

  /* Leave "vn82" and "vn825" alone.  These two architectures are
     the only ones that mix devices with 8-bit SP and 16-bit SP.
     -msp8 is set by mmultilib machinery.  */

  if (vn8_current_device->macro == NULL
      && (vn8_current_device->arch == ARCH_VN82
          || vn8_current_device->arch == ARCH_VN825))
    return "";

  return (vn8_current_device->dev_attribute & VN8_SHORT_SP)
    ? "-msp8"
    : "%<msp8";
}
