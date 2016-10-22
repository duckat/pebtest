#include <pebble.h>
#include "atmWindow.h"

Window *atmWindow;
TextLayer *atmTitleText;

void atm_window_load(Window *window){
  Layer *window_layer = window_get_root_layer(window);
  
  atmTitleText = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_text(atmTitleText, "Nearest ATM\n\n\n\n\nPicture");
  text_layer_set_text_alignment(atmTitleText, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(atmTitleText));
}
void atm_window_unload(Window *window){

}
void atm_window_create(){
  atmWindow = window_create();
  window_set_window_handlers(atmWindow, (WindowHandlers){
    .load = atm_window_load,
    .unload = atm_window_unload
  });
}

void atm_window_destroy(){
  window_destroy(atmWindow);
}

Window *atm_window_get_window(){
  return atmWindow;
}