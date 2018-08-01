import QtQuick 2.7
import QtQuick.Controls 1.4


import "."

ApplicationWindow {
    visible: true
    id:root
    width: 800
    height: 480
    title: qsTr("App Name")

    Item {
        id: contentItem
        anchors.fill:parent
        Column
        {
            spacing: 5
            anchors.centerIn: parent
            Text {
                id: languageNote
                text: contentItem.getsText(qsTr("Current language "))+ GlobalConfig.curLanguage
            }
            Text {
                id: note
                text:  GlobalConfig.curLanguage==1?  qsTr("English"):qsTr("Chinese")
            }
            LImage{
             sourceName: "Language.png"
            }
            Button{
                id:switchBtn
             text:  contentItem.getsText(qsTr("switchLanguage"))
             onClicked: {
                 optionsMenu.popup()
             }
            }
        }

        Menu {
            id: optionsMenu

            MenuItem {
                text :contentItem.getsText(qsTr("Chinese"))
                onTriggered: {
                    languageManager.setCurLanguage(0);
//                    qmlLanguage.setLanguage(1);
                }
            }
            MenuItem {
                text:contentItem.getsText(qsTr("English"))
                onTriggered: {
                    languageManager.setCurLanguage(1);
//                    qmlLanguage.setLanguage(0);
                }

            }
        }

        function getsText(text)
        {
            return GlobalConfig.curLanguage==1? text:text
        }

        Connections{
         target: languageManager
         onLanguageChanged:{
              console.debug("onLanguageChanged languageManager")
              GlobalConfig.curLanguage = languageManager.getCurLanguage();
          }
        }
    }
}
