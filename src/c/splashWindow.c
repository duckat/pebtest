#include <pebble.h>
#include "splashWindow.h"

Window *splashWindow;
TextLayer *splashImageTitle, *splashMessage;

void splash_window_load(Window *window){
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  splashImageTitle = text_layer_create((GRect) { .origin = { 0, 72 }, .size = { bounds.size.w, 20 } });
  splashMessage = text_layer_create((GRect) { .origin = { 0, 108 }, .size = { bounds.size.w, 40 } });
  text_layer_set_text(splashImageTitle, "Not logged in");
  text_layer_set_overflow_mode(splashMessage, GTextOverflowModeWordWrap);
  text_layer_set_text(splashMessage, "Log in on Android and restart app");
  text_layer_set_text_alignment(splashImageTitle, GTextAlignmentCenter);
  text_layer_set_text_alignment(splashMessage, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(splashImageTitle));
  layer_add_child(window_layer, text_layer_get_layer(splashMessage));
}
void splash_window_unload(Window *window){
  text_layer_destroy(splashImageTitle);
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  //might not even use this
}
 
static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

void splash_window_create(){
  splashWindow = window_create();
  window_set_click_config_provider(splashWindow, click_config_provider);
  window_set_window_handlers(splashWindow, (WindowHandlers){
    .load = splash_window_load,
    .unload = splash_window_unload
  });
}

void splash_window_destroy(){
  window_destroy(splashWindow);
}

Window *splash_window_get_window(){
  return splashWindow;
}