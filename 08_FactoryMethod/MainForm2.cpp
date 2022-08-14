class MainForm : public Form {
 public:
  MainForm(SplitterFactory* facotry) { this->factory = factory; }

  void Buttom1Click() {
    ISplitter* splitter = factory->CreateSplitter();  //多态new
    splitter->split();
  }

 private:
  SplitterFactory* factory;  //工厂
};