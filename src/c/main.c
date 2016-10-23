#include <pebble.h>
#include "splashWindow.h"
#include "mainWindow.h"
#include "balanceWindow.h"
#include "atmWindow.h"

int logged_in = true;
// void launch_main_window(void *data){

// }
static void init(){
  static PebbleAppHandlers s_handlers = {
    .messaging_info = {
      .buffer_sizes = {
        .inbound = 64,
        .outbound = 16
      }
      .default_callbacks.callbacks{
        .out_sent = my_out_sent_handler,
        
      }
    }
  }
}
void launch_balance_window(void *data){
  balance_window_create();
  window_stack_push(balance_window_get_window(), true);
}

void launch_atm_window(void *data){
  atm_window_create();
  window_stack_push(atm_window_get_window(), true);
}
//Click handlers for three buttons
void up_click_handler(ClickRecognizerRef recognizer, void *context)
{
  
}
void down_click_handler(ClickRecognizerRef recognizer, void *context)
{
  launch_atm_window(NULL);
}

void select_click_handler(ClickRecognizerRef recognizer, void *context)
{
    launch_balance_window(NULL);
}
//subscribes each button to a handler
void click_config_provider(void *context)
{
    window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
    window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
    window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}



void check_login(){
  //query android for login status
  if (logged_in) 
  {
    main_window_create();
    window_set_click_config_provider(main_window_get_window(), click_config_provider);
    window_stack_push(main_window_get_window(), true);
  } else {
    splash_window_create();
    window_stack_push(splash_window_get_window(), true);
  }
}

int main(){
  //app_timer_register(1500, launch_main_window, NULL);
  init();
  check_login();

  app_event_loop();
  splash_window_destroy();
  main_window_destroy();
}