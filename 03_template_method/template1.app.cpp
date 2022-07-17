#include "template1.lib.h"

class Application {
 public:
  bool step2() {}
  bool step4() {}
};

int main() {
  Library lib;
  Application app;
  lib.step1();
  if (app.step2()) {
    lib.step3();
  }
  for (int i = 0; i < 4; i++) {
    app.step4();
  }
  lib.step5();
}