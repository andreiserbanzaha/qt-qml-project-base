#ifndef DEMO_Q_OBJ
#define DEMO_Q_OBJ

#include <QObject>

class DemoQObject : public QObject
{
public:
    Q_OBJECT

    Q_PROPERTY(int data READ data NOTIFY dataChanged)

    int data() const;

signals:
    void dataChanged();

private:
    int m_data;
};

#endif
