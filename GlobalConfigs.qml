pragma Singleton
import QtQuick 2.0
QtObject {
//    objectName: "GlobalConfigObject"
    property int language_Chinese : 0;
    property int language_English : 1;

    property int curLanguage : 0;
    property string qrc : "qrc:/source/image/";
//    signal curLanguages;
//    function emitLanguageSignal()
//    {
//         curLanguages();
//    }
 }
