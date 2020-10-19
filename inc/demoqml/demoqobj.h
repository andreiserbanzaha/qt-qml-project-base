#ifndef _DEMO_Q_OBJ_H_
#define _DEMO_Q_OBJ_H_

#include <QObject>

class DemoQObject : public QObject {
public:
  Q_OBJECT

  Q_PROPERTY(int data READ data NOTIFY dataChanged)

  int data() const;

signals:
  void dataChanged();

private:
  int m_data;
};

#endif // _DEMO_Q_OBJ_H_
