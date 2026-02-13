#include<string.h>

void hardware_init_hook() {
  extern const char __data_load__;
  extern char __data_start__;
  extern char __data_end__;

  memcpy(&__data_start__,&__data_load__,(&__data_end__ - &__data_start__));
}

struct boot_struct {
  void* initial_SP;
  void (*initial_PC)();
};

extern char __stack;
extern void _start();

const struct boot_struct __boot_sector
__attribute__(( section("boot") ))  =
  { .initial_SP=&__stack, .initial_PC=_start };

void _exit(int status) {
  while(1);
}
