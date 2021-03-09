#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "settings.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    Settings settings;

    settings.setDImg("file:C:/Users/Admin/Downloads/pics/door.png");
    settings.setDNum(2);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("settings", &settings);
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    /*QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);*/

    engine.load(url);

    return app.exec();
}
