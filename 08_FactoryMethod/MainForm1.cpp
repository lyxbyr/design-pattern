class MainForm : public Form {
  TextBox* txtFilePath;
  TextBox* txtFileNumber;
  ProgressBar* progresBar;

 public:
  void Buttom1Click() {
    ISplitter* splitter = new BinarySplitter();  //依赖具体类
    splitter->split();
  }
};