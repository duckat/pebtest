#include <pebble.h>
#include "balanceWindow.h"

Window *balanceWindow;
TextLayer *balanceTitleText;

void balance_window_load(Window *window){
  Layer *window_layer = window_get_root_layer(window);
  
  balanceTitleText = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_text(balanceTitleText, "Balance\n\n\n\n\n$0.00");
  text_layer_set_text_alignment(balanceTitleText, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(balanceTitleText));
}
void balance_window_unload(Window *window){

}
void balance_window_create(){
  balanceWindow = window_create();
  window_set_window_handlers(balanceWindow, (WindowHandlers){
    .load = balance_window_load,
    .unload = balance_window_unload
  });
}

void balance_window_destroy(){
  window_destroy(balanceWindow);
}

Window *balance_window_get_window(){
  return balanceWindow;
}