#include <stdio.h>
#include <math.h>
#include "sys/cm4.h"
#include "sys/devices.h"
#include "sys/init.h"
#include "sys/clock.h"
#include "sys/timer.h"
#include "sys/notes.h"
#include "sys/musique.h"
#include "sys/potentiometer.h"

int main() {
  init_timer_buzzer();
  init_IRQ_PC13();
  init_led_tricolore();
  configuration_potentiometre();
  while (1)
  {
	  choix_musique();
  }
  return 0;
}
