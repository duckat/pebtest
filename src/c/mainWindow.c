#include <pebble.h>
#include "mainWindow.h"

Window *mainWindow;

void main_window_load(Window *window){
  
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