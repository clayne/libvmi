/*
 * The LibVMI Library is an introspection library that simplifies access to 
 * memory in a target virtual machine or in a file containing a dump of 
 * a system's physical memory.  LibVMI is based on the XenAccess Library.
 *
 * Copyright (C) 2010 Sandia National Laboratories
 * Author: Bryan D. Payne (bpayne@sandia.gov)
 */

#include "libvmi.h"
#include "private.h"

os_t vmi_get_ostype (vmi_instance_t vmi)
{
    return vmi->os_type;
}

unsigned long vmi_get_offset (vmi_instance_t vmi, char *offset_name)
{
    size_t max_length = 100;

    if (strncmp(offset_name, "win_tasks", max_length) == 0){
        return vmi->os.windows_instance.tasks_offset;
    }
    else if (strncmp(offset_name, "win_pdbase", max_length) == 0){
        return vmi->os.windows_instance.pdbase_offset;
    }
    else if (strncmp(offset_name, "win_pid", max_length) == 0){
        return vmi->os.windows_instance.pid_offset;
    }
    else if (strncmp(offset_name, "win_peb", max_length) == 0){
        return vmi->os.windows_instance.peb_offset;
    }
    else if (strncmp(offset_name, "win_iba", max_length) == 0){
        return vmi->os.windows_instance.iba_offset;
    }
    else if (strncmp(offset_name, "win_ph", max_length) == 0){
        return vmi->os.windows_instance.ph_offset;
    }
    else if (strncmp(offset_name, "linux_tasks", max_length) == 0){
        return vmi->os.linux_instance.tasks_offset;
    }
    else if (strncmp(offset_name, "linux_mm", max_length) == 0){
        return vmi->os.linux_instance.mm_offset;
    }
    else if (strncmp(offset_name, "linux_pid", max_length) == 0){
        return vmi->os.linux_instance.pid_offset;
    }
    else if (strncmp(offset_name, "linux_pgd", max_length) == 0){
        return vmi->os.linux_instance.pgd_offset;
    }
    else if (strncmp(offset_name, "linux_addr", max_length) == 0){
        return vmi->os.linux_instance.addr_offset;
    }
    else{
        warnprint("Invalid offset name in vmi_get_offset (%s).\n", offset_name);
        return 0;
    }
}