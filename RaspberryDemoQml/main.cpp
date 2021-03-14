/*#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

int main(int argc, char *argv[])
{
    qDebug()<<"hello from qt";

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>

#include "server.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    //QSettings serverSettings(QString("/home/pi/config.ini"), QSettings::IniFormat);
    Settings settings;
    Server server(settings);

    //settings.setDImg("file:C:/Users/Admin/Downloads/pics/door.png");
    //settings.setDNum(2);
    //settings.setDTypeOne(1);
    //settings.setDTypeTwo(0);
    //settings.setNum(30);
    //settings.setInterval(5);

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
