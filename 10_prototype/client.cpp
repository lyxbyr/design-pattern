class MainForm : public Form {
 public:
  MainForm(ISplitter* prototype) { this->prototype = prototype; }

  void Buttom1Click() {
    ISplitter* splitter = prototype->clone();  //克戎原型
    splitter->split();
  }

 private:
  ISplitter* prototype;//原型对象
};