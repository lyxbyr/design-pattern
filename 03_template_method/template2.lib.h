
class Library {
 public:
  void run() {
    step1();
    if (step2()) {
      step3();
    }
    for (int i = 0; i < 4; i++) {
      step4();
    }
    step5();
  }

  virtual ~Library() {}

 protected:
  void step1() {}
  void step3() {}
  void step5() {}

  virtual bool step2() = 0;
  virtual bool step4() = 0;
};