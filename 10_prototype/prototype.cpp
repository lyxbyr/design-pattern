class ISplitter {
 public:
  virtual void spilt() = 0;
  virtual ISplitter* clone() = 0;//通过克融自己来创建对象
  virtual ~ISplitter() {}
}