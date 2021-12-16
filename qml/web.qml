import QtQuick 2.4
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtWebEngine 1.1
 
Rectangle {
    id: root
 
    width: 800
    height: 600
 
    Rectangle {
        id: edit_area
        width: parent.width
        height: 70
        anchors {
            left: parent.left
            right: parent.right
        }
        color: "#E4EEF9"
 
        Button {
            id: goBack_click
            anchors {
                left: parent.left
                leftMargin: 5
                verticalCenter: edit_area.verticalCenter
            }
            width: 30
            height: url_edit.height
            property color bgColor: webView.canGoBack?"blue":"gray"
            style: ButtonStyle {
                background: Rectangle {
                    anchors.fill: parent
                    color: goBack_click.bgColor
                    radius: width/2
                }
                label: Label {
                    text: "<-"
                    font.pixelSize: 20
                }
            }
            onClicked: {
                webView.goBack()
            }
        }
        Button {
            id: goForward_click
            anchors {
                left: goBack_click.right
                leftMargin: 2
                verticalCenter: edit_area.verticalCenter
            }
            width: 30
            height: url_edit.height
            property color bgColor: webView.canGoForward?"blue":"gray"
            style: ButtonStyle {
                background: Rectangle {
                    anchors.fill: parent
                    color: goForward_click.bgColor
                    radius: width/2
                }
                label: Label {
                    text: "->"
                    font.pixelSize: 20
                }
            }
            onClicked: {
                webView.goForward()
            }
        }
 
        TextField {
            id: url_edit
            width: parent.width-150
            height: 27
            anchors {
                left: goForward_click.right
                leftMargin: 5
                rightMargin: 80
                verticalCenter: parent.verticalCenter
            }
            placeholderText: qsTr("请输入网址")
            focus: true
            font.pixelSize: 16
        }
 
        Button {
            id: enter_click
            anchors {
                left: url_edit.right
                leftMargin: 5
                verticalCenter: edit_area.verticalCenter
            }
            width: 60
            height: url_edit.height
            style: ButtonStyle {
                background: Rectangle {
                    anchors.fill: parent
                    color: "blue"
                    radius: 5
                }
                label: Label {
                    text: "go>>>"
                    font.pixelSize: 20
                }
            }
            onClicked: {
                webView.url = "https://" + url_edit.text
                url_edit.text = webView.url
            }
        }
        Keys.onReturnPressed: {
            webView.url = "https://" + url_edit.text
            url_edit.text = webView.url
        }
    }
 
    WebEngineView {
        id: webView
        anchors {
            top: edit_area.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            margins: 1
        }
        //url: "https://www.baidu.com"
        smooth: true
        visible: true
        onNewViewRequested: request.openIn(webView)
 
        onUrlChanged: {
            url_edit.text = webView.url
        }
    }
}