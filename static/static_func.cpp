#include "static_func.h"

int counter() {
  static int status = 0;
  return status++;
}

void speak_hidden() {
  hidden();
}

static void hidden() {
  std::cout << "A static function cannot be called from another file.\n";
}
