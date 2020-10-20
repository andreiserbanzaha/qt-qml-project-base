#include <demoqml/demoqobj.h>

#include <QGuiApplication>
#include <QQuickView>
#include <QString>
#include <QUrl>
#include <QDir>

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    qmlRegisterType<DemoQObject>("test.test", 1, 0, "DemoObj");

    QString currPath = QDir::currentPath();
    view.setSource(QUrl::fromLocalFile(QDir::toNativeSeparators(currPath + "/qml/main.qml")));
    view.setResizeMode(QQuickView::SizeViewToRootObject);
    view.show();

    return app.exec();
}
