
class BinarySplitter : public ISplitter {};

class TxtSplitter : public ISplitter {};

class PictureSplitter : public ISplitter {};

class BinaryFactory : public SplitterFactory {
 public:
  virtual ISplitter* CreateSplitter() { return new BinaryFactory; }
};

class TxtSplitFactory : public SplitterFactory {
 public:
  virtual ISplitter* CreateSplitter() { return new TxtSplitFactory; }
};

class PictureSplitterFactory : public SplitterFactory {
 public:
  virtual ISplitter* CreateSplitter() { return new PictureSplitterFactory; }
}