import QtQuick 2.0
import QtQuick.Controls 2.3

Rectangle {
    width: 400
    height: 300
    color: "#051f58"
    radius: 8

    Button {
        text: "登录页面-登录按钮"
        anchors.centerIn: parent
        onClicked: {
            loginPage.visible = false
            mainPage.visible = true
        }
    }
}