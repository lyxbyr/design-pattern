
//具体类
class BinaryISplitter : public ISplitter {
 public:
  virtual ISplitter* clone() { return new BinaryISplitter(*this); }
};

class TxtISplitter : public ISplitter {
 public:
  virtual ISplitter* clone() { return new TxtISplitter(*this); }
};

class PictureSplitter : public ISplitter {
 public:
  virtual ISplitter* clone() { return new PictureSplitter(*this); }
}