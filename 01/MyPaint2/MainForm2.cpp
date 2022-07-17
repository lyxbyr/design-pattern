class Form {
  Form() {}
  virtual void OnMouseDown(const MouseEventArgs& e) = 0;
  virtual void OnMouseUp(const MouseEventArgs& e) = 0;
  virtual void OnPaint(const MouseEventArgs& e) = 0;
};

class MainForm : public Form {
 public:
  MainForm() {}

 protected:
  virtual void OnMouseDown(const MouseEventArgs& e);
  virtual void OnMouseUp(const MouseEventArgs& e);
  virtual void OnPaint(const MouseEventArgs& e);

 private:
  Point p1;
  Point p2;

  vector<Shape*> shapeVector;
};

void MainForm::OnMouseDown(const MouseEventArgs& e) {
  p1.x = e.X;
  p1.y = e.Y;

  //
  Form::OnMouseDown(e);
}

void MainForm::OnMouseUp(const MouseEventArgs& e) {
  p2.x = e.X;
  p2.y = e.Y;

  if (rdoLine.Checked) {
    shapeVector.push_back(new Line(p1, p2));

  } else if (rdoRect.Checked) {
    int width = abs(p2.x - p1.x);
    int height = abs(p2.y - p2.y);
    shapeVector.push_back(new Rect(p1, width, height, ));
  }

  this->Refresh();

  Form::OnMouseUp(e);
}

void MainForm::OnPaint(const PaintEventArgs& e) {
  for (int i = 0; i < shapeVector.size(); i++) {
    shapeVector[i]->Draw(e.Graphics);
  }

  Form::OnPaint(e);
}