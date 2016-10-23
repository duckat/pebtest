#include <pebble.h>
#include "splashWindow.h"
#include "mainWindow.h"
#include "balanceWindow.h"
#include "atmWindow.h"

int PEBBLE_CODE_LOGGED_IN = 0;
int PEBBLE_CODE_SELECTION = 1;
int PEBBLE_CODE_IMAGE_URL = 2;

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
  // Declare the dictionary's iterator
  DictionaryIterator *out_iter;

  // Prepare the outbox buffer for this message
  AppMessageResult result = app_message_outbox_begin(&out_iter);

  if(result == APP_MSG_OK) {
    // Add an item to ask for weather data
    int value = 1;
    dict_write_int(out_iter, PEBBLE_CODE_SELECTION, &value, sizeof(int), true);

    // Send this message
    result = app_message_outbox_send();

    // Check the result
    if(result != APP_MSG_OK) {
      APP_LOG(APP_LOG_LEVEL_ERROR, "Error sending the outbox: %d", (int)result);
    }

  } else {
    // The outbox cannot be used right now
    APP_LOG(APP_LOG_LEVEL_ERROR, "Error preparing the outbox: %d", (int)result);
  }

  launch_atm_window(NULL);
}

void select_click_handler(ClickRecognizerRef recognizer, void *context)
{
  // Declare the dictionary's iterator
  DictionaryIterator *out_iter;

  // Prepare the outbox buffer for this message
  AppMessageResult result = app_message_outbox_begin(&out_iter);

  if(result == APP_MSG_OK) {
    // Add an item to ask for weather data
    int value = 0;
    dict_write_int(out_iter, PEBBLE_CODE_SELECTION, &value, sizeof(int), true);

    // Send this message
    result = app_message_outbox_send();

    // Check the result
    if(result != APP_MSG_OK) {
      APP_LOG(APP_LOG_LEVEL_ERROR, "Error sending the outbox: %d", (int)result);
    }

  } else {
    // The outbox cannot be used right now
    APP_LOG(APP_LOG_LEVEL_ERROR, "Error preparing the outbox: %d", (int)result);
  }
  
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

static void inbox_received_callback(DictionaryIterator *iter, void *context) 
{
    Tuple *t = dict_read_first(iter);
    if (t) {
      //
    }
}

static void inbox_dropped_callback(AppMessageResult reason, void *context) {
  // A message was received, but had to be dropped
  APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped. Reason: %d", (int)reason);
}

static void outbox_sent_callback(DictionaryIterator *iter, void *context) {
  // The message just sent has been successfully delivered

}

static void outbox_failed_callback(DictionaryIterator *iter,
                                      AppMessageResult reason, void *context) {
  // The message just sent failed to be delivered
  APP_LOG(APP_LOG_LEVEL_ERROR, "Message send failed. Reason: %d", (int)reason);
}

void init(){
  //Register AppMessage events
  app_message_register_inbox_received(inbox_received_callback);
  app_message_register_inbox_dropped(inbox_dropped_callback);
  app_message_register_outbox_sent(outbox_sent_callback);
  app_message_register_outbox_failed(outbox_failed_callback);
       
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());    //Large input and output buffer sizes
}


int main(){
  //app_timer_register(1500, launch_main_window, NULL);
  init();
  start_splash_window();

  app_event_loop();
  splash_window_destroy();
  main_window_destroy();
}