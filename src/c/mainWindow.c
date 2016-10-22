#include <pebble.h>
#include "mainWindow.h"

Window *mainWindow;
TextLayer *mainTitleText;

void main_window_load(Window *window){
  Layer *window_layer = window_get_root_layer(window);
  
  mainTitleText = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_text(mainTitleText, "Main window!");
  text_layer_set_text_alignment(mainTitleText, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(mainTitleText));
}
void main_window_unload(Window *window){

}
void main_window_create(){
  mainWindow = window_create();
  window_set_window_handlers(mainWindow, (WindowHandlers){
    .load = main_window_load,
    .unload = main_window_unload
  });
}

void main_window_destroy(){
  window_destroy(mainWindow);
}

Window *main_window_get_window(){
  return mainWindow;
}