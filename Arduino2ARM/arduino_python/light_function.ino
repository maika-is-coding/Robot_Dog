// 燈光控制區塊
void light_close() {
  for (int j = 0; j < LED_COUNT; j++) {
    strip.setPixelColor(j, 0, 0, 0);
  }
  strip.show();
}

void white_light_open() {
  for (int l = 0; l < LED_COUNT; l++) {
    strip.setPixelColor(l, 255, 255, 255);
  }
  strip.show();
}
