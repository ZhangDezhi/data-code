import QtQuick 2.3
import QtQml 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0
Rectangle{
    id:root
    width:500*statusbar.rate
    height: 300*statusbar.rate
    property alias mouseX: area.mouseX
    property alias mouseY: area.mouseY
    property string imgPath: menuBar.picPath
    signal save(string str)
    property double lineWidth: 1 //线宽
    property color paintColor: menuBar.paintColor //画笔颜色
    property var ctx: canvas.getContext('2d')
    function saveImage(imgName)
    {
        return canvas.save(imgName)
    }
    //新建画布，清除画布
    function newImage()
    {
         ctx.clearRect(0,0,canvas.width,canvas.height)
         canvas.requestPaint()
    }
    function rePaint()
    {
    }
    Image{
        id:imgP
        source:{
            if(imgPath!="")
                "file:///"+imgPath;
            else
                "";
        }
        visible: false
        width:canvas.width
        height: canvas.height
    }
    //
    Timer{
        interval: 100
        running: true
        triggeredOnStart: true
        repeat: true
        onTriggered: canvas.requestPaint()
    }
//    Image{
//        id:picImg
//        anchors.fill: parent
//    }
    //画板
    Canvas {
        id: canvas
        anchors.fill: parent
        antialiasing: true
        property real lastX //画笔的终止位置
        property real lastY
        //opacity: 0
        onImageLoaded: {
            if(canvas.isImageLoaded(imgP.source))
            {
                console.log("imps")
            }
            if(canvas.isImageError(imgP.source))
            {
                console.log("impE")
            }
        }
        onPaint: {
            if(imgP.source!="")
                ctx.drawImage(imgP,0,0)
            ctx.lineWidth = lineWidth
            ctx.strokeStyle = paintColor
            ctx.beginPath()
            ctx.moveTo(lastX, lastY)
            lastX = area.mouseX
            lastY = area.mouseY
            ctx.lineTo(lastX, lastY)
            ctx.stroke()
        }
        MouseArea {
            id: area
            anchors.fill: parent
            acceptedButtons: Qt.AllButtons
            onPressed: {
                canvas.lastX = mouseX
                canvas.lastY = mouseY
            }
            onPositionChanged: {
                canvas.requestPaint()
            }
            onClicked: {
                if(mouse.button==Qt.RightButton)
                    contentMenu.popup();
//                var url=canvas.toDataURL('image/png');
//                picImg.source=url;
            }
            //鼠标形状改变
            cursorShape: (containsMouse? (pressed? Qt.CrossCursor: Qt.ArrowCursor): Qt.ArrowCursor);
            Menu { // 右键菜单
                //title: "Edit"
                id: contentMenu
                MenuItem {
                    text: "新建"
                    shortcut: "Ctrl+N"
                    onTriggered: {}
                }
                MenuItem {
                    text: "保存"
                    shortcut: "Ctrl+S"
                    onTriggered: {}
                }
                MenuItem {
                    text: "粘贴"
                    shortcut: "Ctrl+V"
                    onTriggered: {}
                }
                MenuSeparator { }
                Menu {
                    title: "More Stuff"
                    MenuItem {
                        text: "Do Nothing"
                    }
                }
            }
        }
    }
    //左侧
    Rectangle{
        width: 5
        height: 5
        x:parent.width
        y:parent.height/2
        border.color: "black"
        border.width: 1
        MouseArea{
            id:xRate
            anchors.fill: parent
            cursorShape: (containsMouse? (pressed? Qt.SizeHorCursor: Qt.ArrowCursor): Qt.ArrowCursor);
            drag.target: parent
            onPositionChanged: {
                root.width=parent.x
            }
        }
    }
    //下侧
    Rectangle{
        width: 5
        height: 5
        border.color: "black"
        border.width: 1
        x:parent.width/2
        y:parent.height
        Drag.active: yRate.drag.active
        Drag.hotSpot.x: 10
        Drag.hotSpot.y: 10
        MouseArea{
            id:yRate
            anchors.fill: parent
            cursorShape: (containsMouse? (pressed? Qt.SizeVerCursor: Qt.ArrowCursor): Qt.ArrowCursor);
            drag.target: parent
            onPositionChanged: {
                root.height=parent.y
            }
        }
    }
    //对角
    Rectangle{
        width: 5
        height: 5
        x:parent.width
        y:parent.height
        border.color: "black"
        border.width: 1
        Drag.active: xyRate.drag.active
        Drag.hotSpot.x: 10
        Drag.hotSpot.y: 10
        MouseArea{
            id:xyRate
            anchors.fill: parent
            cursorShape: (containsMouse? (pressed? Qt.SizeFDiagCursor: Qt.ArrowCursor): Qt.ArrowCursor);
            drag.target: parent
            onPositionChanged: {
                root.width=parent.x
                root.height=parent.y
            }
        }
    }
}
