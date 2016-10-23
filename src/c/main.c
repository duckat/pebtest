#include <pebble.h>
#include "splashWindow.h"
#include "mainWindow.h"
#include "balanceWindow.h"
#include "atmWindow.h"

int logged_in = true;
// void launch_main_window(void *data){

// }


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


void start_splash_window() {
    splash_window_create();
    window_stack_push(splash_window_get_window(), true);
}

void start_main_window() {
    main_window_create();
    window_set_click_config_provider(main_window_get_window(), click_config_provider);
    window_stack_push(main_window_get_window(), true);
}

void init(){
  //Register AppMessage events
  app_message_register_inbox_received(in_received_handler);           
  app_message_open(512, 512);    //Large input and output buffer sizes
}

static void in_received_handler(DictionaryIterator *iter, void *context) 
{
    Tuple *t = dict_read_first(iter);
    if(t)
    {
        start_main_window();
    }
}

int main(){
  //app_timer_register(1500, launch_main_window, NULL);
  init();
  start_splash_window();

  app_event_loop();
  splash_window_destroy();
  main_window_destroy();
}