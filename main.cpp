#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext> //这个必须include
#include "./languagemanager.h"
#include "qmllanguage.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QCoreApplication::setOrganizationName("Join");
    QCoreApplication::setApplicationName("LanguageSwitch");

    QQmlApplicationEngine engine;

    LanguageManager languageManager(app);


    engine.rootContext()->setContextProperty("languageManager", &languageManager);

    //    QmlLanguage qmlLanguage(app, engine);
    //    engine.rootContext()->setContextProperty("qmlLanguage", &qmlLanguage);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));



    return app.exec();
}
