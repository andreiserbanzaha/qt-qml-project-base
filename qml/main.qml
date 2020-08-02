import QtQuick 2.6
import test.test 1.0

Rectangle
{
    anchors.centerIn: parent
    width: 1280
    height: 720
    color: "lightblue"

    DemoObj
    {
        id: demoObj
    }

    Text
    {
        anchors.centerIn: parent
        text: demoObj.data
    }
}
