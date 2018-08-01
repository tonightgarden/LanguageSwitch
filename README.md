# LanguageSwitch
Qt quick  qml 界面语言动态切换（中英文）
疑问？ 哪位解答下
void LanguageManager::setCurLanguage(int value)
{
    curLanguage = value;
    changeLanguage();
//   信号在此发送 qml界面中语言不会被切换 而在changeLanguage()内部installTranslator切换后发送就可以  ？个人不太理解
//    emit languageChanged();
}

![image](https://github.com/tonightgarden/LanguageSwitch/blob/master/1.png)
![image](https://github.com/tonightgarden/LanguageSwitch/blob/master/2.png)

