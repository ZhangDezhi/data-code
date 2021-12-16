import QtQuick 2.0
import QtQuick.Controls 2.3

Rectangle {
    color: "#498ff8"
    radius: 8

    Button {
        text: "主页面-返回按钮"
        anchors.centerIn: parent
        onClicked: {
            loginPage.visible = true
            mainPage.visible = false
        }
    }
}