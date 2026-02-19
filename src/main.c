#include <stdio.h>
#include <math.h>
#include "sys/cm4.h"
#include "sys/devices.h"
#include "sys/init.h"
#include "sys/clock.h"
#include "sys/timer.h"
#include "sys/notes.h"
#include "sys/musique.h"


int main() {
  init_timer_buzzer();
  while (1)
  {
	  au_clair_de_la_lune();
  }
  
  return 0;
}



