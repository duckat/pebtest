#include <pebble.h>
#include "atmWindow.h"

Window *atmWindow;
TextLayer *atmTitleText;
BitmapLayer *bitmap_layer;
GBitmap *bitmap;
// GRect bounds = GRect(0, 0, 144, 168);
void atm_window_load(Window *window){
  Layer *window_layer = window_get_root_layer(window);
  


  bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_SAMPLEMAP);
  bitmap_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(bitmap_layer, bitmap);
  bitmap_layer_set_compositing_mode(bitmap_layer, GCompOpSet);
  bitmap_layer_set_alignment(bitmap_layer, GAlignCenter);
  layer_add_child(window_layer, bitmap_layer_get_layer(bitmap_layer));
  
  atmTitleText = text_layer_create(GRect(0, 0, 144, 20));
  text_layer_set_text(atmTitleText, "Nearest ATM");
//   text_layer_set_font(atmTitleText, fonts_load_custom_font
//      (resource_get_handle(RESOURCE_ID_FONT_EXPRESSWAY16)));
  text_layer_set_text_alignment(atmTitleText, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(atmTitleText));
}
void atm_window_unload(Window *window){
  text_layer_destroy(atmTitleText);
  gbitmap_destroy(bitmap);
  bitmap_layer_destroy(bitmap_layer);
}
void atm_window_create(){
  atmWindow = window_create();
  window_set_window_handlers(atmWindow, (WindowHandlers){
    .load = atm_window_load,
    .unload = atm_window_unload
  });
}

void atm_window_destroy(){
  atm_window_unload(atmWindow);
  window_destroy(atmWindow);
}

Window *atm_window_get_window(){
  return atmWindow;
}