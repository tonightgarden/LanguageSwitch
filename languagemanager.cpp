#include "languagemanager.h"
#include <QDebug>


LanguageManager::LanguageManager(QGuiApplication &app)
{
//    qDebug()<<"LanguageManager";
     m_app = &app;
}

void LanguageManager::setCurLanguage(int value)
{
    curLanguage = value;
    changeLanguage();
//  信号在此发送 qml界面中语言不会被切换  ？个人不太理解
//    emit languageChanged();
}

int LanguageManager::getCurLanguage()
{
     return curLanguage;
}




void LanguageManager::changeLanguage()
{
    QTranslator translator;
    if (curLanguage == 1)
    {
        if( translator.load(":/en_US.qm"))
        {
            qDebug()<<"load  en_us ok ";
        }else
        {
            qDebug()<<"load  en_us failed ";
        }

    }else if (curLanguage == 0) {
        if(translator.load(":/zh_CN.qm"))
        {
            qDebug()<<"load  zh_CN ok ";
        }else
        {
            qDebug()<<"load  zh_CN failed ";
        }
    }
    if( m_app->installTranslator(&translator))
    {
        qDebug()<<"installTranslator ok ";
        //  信号在此发送 qml界面中语言 会被切换
        emit languageChanged();
    }else
    {
        qDebug()<<"installTranslator failed ";
    }
}
