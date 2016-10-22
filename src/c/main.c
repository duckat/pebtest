#include <pebble.h>
#include "splashWindow.h"
#include "mainWindow.h"

int logged_in = false;

void launch_main_window(void *data){
  main_window_create();
  window_stack_push(main_window_get_window(), true);
}

void check_login(){
  //query android for login status
  if (logged_in) 
  {
    launch_main_window(NULL);
  }
}

int main(){
  splash_window_create();
  window_stack_push(splash_window_get_window(), true);

  //app_timer_register(1500, launch_main_window, NULL);
  check_login();

  app_event_loop();
  splash_window_destroy();
  main_window_destroy();
}