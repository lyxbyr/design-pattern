#include "template2.lib.h"

class Application : public Library {
 protected:
  virtual bool step2() {}
  virtual bool step4() {}
};

int main() {
  Library* pLib = new Application();
  pLib->run();
  delete pLib;
  return 0;
}