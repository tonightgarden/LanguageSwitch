import QtQuick 2.0
import "."

Image{
    id:image
    property string sourceName
    onSourceNameChanged: {
      setImgSource();
    }
    Connections{
     target: GlobalConfig
     onCurLanguageChanged:{
          setImgSource();
      }
    }
    function setImgSource()
    {
        var lauguage;
        switch(GlobalConfig.curLanguage)
        {
        case GlobalConfig.language_Chinese:
             lauguage = "cn/";
            break;
        case GlobalConfig.language_English:
             lauguage = "en/";
            break;
        }
        image.source = GlobalConfig.qrc+lauguage+sourceName;
    }
}
