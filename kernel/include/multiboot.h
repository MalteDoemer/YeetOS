#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#include "stdint.h"

#define MULTIBOOT_FLAGS_MEMORY (1 << 0)
#define MULTIBOOT_FLAGS_DECICE (1 << 1)
#define MULTIBOOT_FLAGS_CMDLINE (1 << 2)
#define MULTIBOOT_FLAGS_MODULES (1 << 3)
#define MULTIBOOT_FLAGS_AOUT (1 << 4)
#define MULTIBOOT_FLAGS_ELF (1 << 5)
#define MULTIBOOT_FLAGS_MMAP (1 << 6)
#define MULTIBOOT_FLAGS_DRIVES (1 << 7)
#define MULTIBOOT_FLAGS_CONFIG (1 << 8)
#define MULTIBOOT_FLAGS_NAME (1 << 9)

typedef struct mboot_info_t {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
    uint32_t boot_device;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;

    uint32_t elf_num;
    uint32_t elf_size;
    uint32_t elf_addr;
    uint32_t elf_shndx;

    uint32_t mmap_length;
    uint32_t mmap_addr;

    uint32_t drives_length;
    uint32_t drives_addr;

    uint32_t config_table;
    uint32_t boot_loader_name;

    uint32_t apm_table;

    // uint32_t vbe_control_info;
    // uint32_t vbe_mode_info;
    // uint32_t vbe_mode;
    // uint32_t vbe_interface_seg;
    // uint32_t vbe_interface_off;
    // uint32_t vbe_interface_len;

    // uint32_t framebuffer_addr;
    // uint32_t framebuffer_pitch;
    // uint32_t framebuffer_width;
    // uint32_t framebuffer_height;
    // uint32_t framebuffer_bpp;
    // uint32_t framebuffer_type;
    // uint32_t color_info;

} __attribute__((packed)) mboot_info_t;

typedef struct mboot_mmap_t {
    uint32_t size;
    uint32_t addr_low;
    uint32_t addr_high;
    uint32_t length_low;
    uint32_t length_high;
    uint32_t type;
} __attribute__((packed)) mboot_mmap_t;

typedef struct mboot_mod_t {
    uint32_t mod_start;
    uint32_t mod_end;
    uint32_t string;
    uint32_t reserved;
} __attribute__((packed)) mboot_mod_t;


mboot_info_t* get_mboot_info();
void init_multiboot(mboot_info_t* mboot);



#endif // #ifndef MULTIBOOT_H
