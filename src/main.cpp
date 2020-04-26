#include <QGuiApplication>
#include <QQuickView>
#include <QUrl>
#include <QDir>

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setSource(QUrl::fromLocalFile(QDir::toNativeSeparators("out/bin/qml/main.qml")));
    view.show();

    return app.exec();
}
