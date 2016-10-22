#include <pebble.h>
#include "splashWindow.h"

Window *splashWindow;
TextLayer *splashImageTitle;

void splash_window_load(Window *window){
  Layer *window_layer = window_get_root_layer(window);
  
  splashImageTitle = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_text(splashImageTitle, "Splash text!");
  text_layer_set_text_alignment(splashImageTitle, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(splashImageTitle));
  
}
void splash_window_unload(Window *window){
  text_layer_destroy(splashImageTitle);
}
void splash_window_create(){
  splashWindow = window_create();
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