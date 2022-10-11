import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // 主页面一开始设置"隐藏"，登录成功后才显示
    MainPage {
        id: mainPage
        width: 500
        height: 350
        visible: false // 设置"隐藏"
        anchors.centerIn: parent
    }

    LoginPage {
        id: loginPage
        width: 300
        height: 200
        anchors.centerIn: parent
    }
}