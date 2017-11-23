#include <stdio.h>
#include <malloc.h>

#include <gsKit.h>
#include <dmaKit.h>
#include <gsToolkit.h>

int main(int argc, char *argv[]) {
  GSGLOBAL *gsGlobal = gsKit_init_global();

  // Initialise DMAKit
  dmaKit_init(
    D_CTRL_RELE_OFF,
    D_CTRL_MFD_OFF,
    D_CTRL_STS_UNSPEC,
    D_CTRL_STD_OFF,
    D_CTRL_RCYC_8,
    1 << DMA_CHANNEL_GIF
  );

  // Initialise the DMAKit's channel
  dmaKit_chan_init(DMA_CHANNEL_GIF);

  // gsGlobal->BGColor->Red = 0x87;
  // gsGlobal->BGColor->Green = 0x47;
  // gsGlobal->BGColor->Blue = 0xbd;

  gsKit_init_screen(gsGlobal);

  gsKit_mode_switch(gsGlobal, GS_PERSISTENT);

  u64 myColor = GS_SETREG_RGBAQ(0x87,0x47,0xbd,0x00,0x00);

  gsKit_clear(gsGlobal, myColor);

  gsKit_mode_switch(gsGlobal, GS_ONESHOT);
  
  gsKit_queue_exec(gsGlobal);

  gsKit_sync_flip(gsGlobal);

  gsKit_deinit_global(gsGlobal);

  return 0;
}
