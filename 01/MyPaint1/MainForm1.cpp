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

  vector<Line> lineVector;
  vector<Rect> rectVector;
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
    Line line(p1, p2);
    lineVector.push_back(line);
  } else if (rdoRect.Checked) {
    int width = abs(p2.x - p1.x);
    int height = abs(p2.y - p2.y);
    Rect rect(p1.width, height);
    rectVector.push_back(rect);
  }

  this->Refresh();

  Form::OnMouseUp(e);
}

void MainForm::OnPaint(const PaintEventArgs& e) {
  for (int i = 0; i < lineVector.size(); i++) {
    e.Graphics.DrawLine(Pens.Red, lineVector[i].start.x, lineVector[i].start.y,
                        lineVector[i].start.end.x, lineVector[i].start.end.y);
  }

  for (int i = 0; i < rectVector.size(); i++) {
    e.Graphics.DrawLine(Pens.Red, rectVector[i].start.x, rectVector[i].start.y,
                        rectVector[i].start.end.x, rectVector[i].start.end.y);
  }

  Form::OnPaint(e);
}