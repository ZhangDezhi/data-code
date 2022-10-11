ToolBar{
        id:toolBar
        anchors.top: menuBar.bottom
        Row{
            anchors.verticalCenter: parent.verticalCenter
            spacing: 5
            ToolButton{
                width:25
                height: 25
                tooltip: "保存"
                iconSource: "./res/save.png"
            }
            ToolButton{
                width:25
                height: 25
                tooltip: "撤销"
                iconSource: "./res/revoke.png"
            }
            ToolButton{
                width:25
                height: 25
                tooltip: "恢复"
                iconSource: "./res/undo.png"
            }
            Rectangle{
                width:25
                height: 25
                color: menuBar.paintColor
                border.color: "gray"
                border.width: 1
            }
        }
    }    
