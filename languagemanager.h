#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <QTranslator>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#define KEY_LAUGUAGE "language"

class LanguageManager : public QObject
{
    Q_OBJECT
//    Q_ENUMS(Language)
public:

//    enum Language
//    {
//        Chinese,
//        English,
//    };

    LanguageManager(QGuiApplication& app);

    Q_INVOKABLE void setCurLanguage(int value);
    Q_INVOKABLE int getCurLanguage();
    void changeLanguage();

signals:
    void languageChanged();


public slots:
private:
     int curLanguage = 0;
//     QSettings settings;
       QGuiApplication *m_app;
//     QQmlApplicationEngine *m_engine;
};

#endif // LANGUAGEMANAGER_H
