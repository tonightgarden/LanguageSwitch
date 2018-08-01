#include "qmllanguage.h"

#include <QDebug>

QmlLanguage::QmlLanguage(QGuiApplication &app, QQmlApplicationEngine& engine)
{
    m_app = &app;
    m_engine = &engine;
}

void QmlLanguage::setLanguage(int nLanguage)
{
    QTranslator translator;
    if (nLanguage == 0)
    {
        translator.load(":/en_US.qm");
    }else{
        translator.load(":/zh_CN.qm");
    }
    qDebug()<<nLanguage;
    m_app->installTranslator(&translator);
    emit languageChanged();
//    m_engine->retranslate();
}
