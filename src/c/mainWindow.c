#include <pebble.h>
#include "mainWindow.h"

Window *mainWindow;
// TextLayer *mainTitleText;
BitmapLayer *bitmap_layer;
GBitmap *bitmap;

void main_window_load(Window *window){
  Layer *window_layer = window_get_root_layer(window);
  
  bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_MAINBG);
  bitmap_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(bitmap_layer, bitmap);
  bitmap_layer_set_compositing_mode(bitmap_layer, GCompOpSet);
  bitmap_layer_set_alignment(bitmap_layer, GAlignCenter);
  layer_add_child(window_layer, bitmap_layer_get_layer(bitmap_layer));
  
//   mainTitleText = text_layer_create(GRect(0, 0, 144, 168));
//   text_layer_set_text(mainTitleText, "Menu\n\n\n\n\nCheck Balance\n\n\n\nNearest ATM");
//   text_layer_set_text_alignment(mainTitleText, GTextAlignmentCenter);
//   layer_add_child(window_layer, text_layer_get_layer(mainTitleText));
}
void main_window_unload(Window *window){
//   text_layer_destroy(mainTitleText);
  gbitmap_destroy(bitmap);
  bitmap_layer_destroy(bitmap_layer);
}
void main_window_create(){
  mainWindow = window_create();
  window_set_window_handlers(mainWindow, (WindowHandlers){
    .load = main_window_load,
    .unload = main_window_unload
  });
}

void main_window_destroy(){
  main_window_unload(mainWindow);
  window_destroy(mainWindow);
}

Window *main_window_get_window(){
  return mainWindow;
}