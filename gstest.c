#include <stdio.h>
#include <malloc.h>

#include <gsKit.h>
#include <dmaKit.h>
#include <gsToolkit.h>

int main(int argc, char *argv[]) {
  GSGLOBAL *gsGlobal = gsKit_init_global();

  gsGlobal->BGColor->Red = 0x87;
  gsGlobal->BGColor->Green = 0x47;
  gsGlobal->BGColor->Blue = 0xbd;

  gsKit_init_screen(gsGlobal);

  gsKit_mode_switch(gsGlobal, GS_PERSISTENT);

  u64 myColor = GS_SETREG_RGBAQ(0x87,0x47,0xbd,0x00,0x00);

  gsKit_clear(gsGlobal, myColor);

  gsKit_deinit_global(gsGlobal);

  return 0;
}
