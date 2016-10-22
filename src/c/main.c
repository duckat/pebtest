#include <pebble.h>
#include "splashWindow.h"
#include "mainWindow.h"

void launch_main_window(void *data){
  window_stack_push(main_window_get_window(), true);
}

int main(){
  splash_window_create();
  window_stack_push(splash_window_get_window(), true);
  app_timer_register(1500, launch_main_window, NULL);
  app_event_loop();
  splash_window_destroy();
}