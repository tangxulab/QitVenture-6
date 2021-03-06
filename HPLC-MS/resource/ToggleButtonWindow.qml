import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: qsTr("Qml选择开关")

    Label{
        id: label
        anchors.bottom: qmlToggleButton.top
        anchors.horizontalCenter: parent.horizontalCenter
        height: 24
        width: contentWidth
    }

    QmlToggleButton{
        id: qmlToggleButton
        anchors.centerIn: parent
        height: 26
        width: 80
        leftString: qsTr("打开")
        rightString: qsTr("关闭")
        onToggleLeft: label.text = qmlToggleButton.leftString
        onToggleRight: label.text = qmlToggleButton.rightString
    }
}
