import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2
//菜单选项
Rectangle{
    id:root
    height: 120
    width: appWindow.width
    property color paintColor //绘制颜色
    property string picPath:""//图片路径
    TabView{
        width: appWindow.width
        id:tabView
        Tab{
            title: "文件"
            Rectangle {
                id: see
                width: appWindow.width
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    top: parent.top
                    topMargin: 8
                }
                color: "transparent"
                Row{
                    spacing: 5
                    Column{
                        Row{
                            spacing: 5
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/new.png"
                                rectColor: "transparent"
                                describle: "新建"
                                onClicked: {
                                    messageDialog.text="是否保存？"
                                    messageDialog.standardButtons=StandardButton.Yes | StandardButton.No
                                    messageDialog.icon=StandardIcon.Question
                                    messageDialog.open()
                                }
                            }
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/open.png"
                                rectColor: "transparent"
                                describle: "打开"
                                onClicked: {
                                    fileDialog.open()
                                    fileDialog.selectExisting=true
                                }
                            }
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/save.png"
                                rectColor: "transparent"
                                describle: "保存"
                                onClicked:{
                                    fileDialog.selectExisting=false
                                    fileDialog.open()
                                }
                            }
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/saveOther.png"
                                describle: "另存"
                                onClicked:{
                                    fileDialog.selectExisting=false
                                    fileDialog.open()
                                }
                            }
                        }
                        Rectangle{
                            width: parent.width
                            height: 25
                            color:"#F5F6F7"
                            anchors.horizontalCenter: parent.horizontalCenter
                            Text{
                                text:"文件操作"
                                color:"#929292"
                                anchors.centerIn: parent
                            }
                        }
                    }
                    //分隔符
                    Rectangle{height: 64;width: 1;color:"#E2E3E4";}
                    Column{
                        Row{
                            spacing: 5
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/print.png"
                                rectColor: "transparent"
                                describle: "打印"
                                onClicked: appWindow.showFullScreen()
                            }
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/exit.png"
                                rectColor: "transparent"
                                describle: "退出"
                                onClicked:  Qt.quit()
                            }
                        }
                        Rectangle{
                            width: parent.width
                            height: 25
                            color:"#F5F6F7"
                            anchors.horizontalCenter: parent.horizontalCenter
                            Text{
                                text:"操作"
                                color:"#929292"
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
                FileDialog {
                    id: fileDialog;
                    title: qsTr("Please choose an image file");
                    nameFilters:["PNG(*.png)","JPEG(*.jpg *.jpeg *.jpe)","GIF(*.gif)","位图(*.bmp)"]
                    property int isSave: 1 //判断是打开还是保存操作
                    onAccepted: {
                        if(!fileDialog.selectExisting)
                            if(canvas.saveImage(picPath))
                            {
                                messageDialog.title="提示"
                                messageDialog.text="保存成功！"
                                messageDialog.icon=StandardIcon.Information
                                messageDialog.standardButtons=StandardButton.Ok
                                messageDialog.open()
                            }
                        var filepath = new String(fileUrl);
                        if(Qt.platform.os == "windows")
                            root.picPath= filepath.slice(8);
                        else
                            root.picPath = filepath.slice(7);
                    }
                }
                //弹窗提示
                MessageDialog {
                    id: messageDialog
                    onAccepted: {
                        console.log("do samething")
                    }
                    onYes: {fileDialog.selectExisting=false;fileDialog.open();}
                    onNo: canvas.newImage()
                }
            }
        }
        Tab{
            title: "设置"
            Rectangle {
                id: colorTools
                width: appWindow.width
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    top: parent.top
                    topMargin: 8
                }
                color: "transparent"
                Row{
                    spacing: 5
                    anchors.left: parent.left
                    anchors.leftMargin: 15
                    Column{
                        Row{
                            spacing: 5
                            //设置线宽
                            PicButton{
                                id:selectWeight
                                width:50
                                height: grid.height
                                imagePath: "res/weight.png"
                                describle: "粗细"
                                isImageVisible:true
                                onClicked: {
                                    listWeight.visible=listWeight.visible==true?false:true;
                                    listWeight.z=3
                                }
                            }
                            //分隔符
                            Rectangle{height: grid.height;width: 1;color:"#E2E3E4";}
                            //选中的颜色
                            PicButton{
                                id:selectRect
                                width:50
                                height: grid.height
                                describle: "颜色"
                            }
                            //分隔符
                            Rectangle{height: grid.height;width: 1;color:"#E2E3E4";}
                            //色彩网格
                            Grid{
                                id:grid
                                columns: 7
                                rows:2
                                spacing: 2
                                Repeater {
                                    model: ["#33B5E5", "#99CC00", "#FFBB33", "#FF4444","#DD6644","#AA4444","#FFBB33", "#FF4444","#DD6644","#AA4444","#FFBB33", "#FF4444","#DD6644","#AA4444"]
                                    ColorGrid {
                                        id: red
                                        color: modelData
                                        onClicked:{
                                            selectRect.rectColor=color
                                            root.paintColor = color
                                        }
                                    }
                                }
                            }
                            //分隔符
                            Rectangle{height: grid.height;width: 1;color:"#E2E3E4";}
                            //颜色对话框
                            PicButton{
                                id:editRect
                                width:50
                                height: grid.height
                                isImageVisible: true
                                imagePath: "res/pic.png"
                                rectColor: "transparent"
                                describle: "编辑"
                                onClicked: colorD.open()
                                ColorDialog{
                                    id:colorD
                                    onColorChanged: {selectRect.rectColor=color;root.paintColor=color;}
                                }
                            }
                            //分隔符
                            Rectangle{height: grid.height;width: 1;color:"#E2E3E4";}
                        }
                        Rectangle{
                            width: grid.width
                            height: 30
                            color:"#F5F6F7"
                            anchors.horizontalCenter: parent.horizontalCenter
                            Text{
                                text:"颜色"
                                color:"#929292"
                                anchors.centerIn: parent
                            }
                        }
                    }
                    //形状设置
                    Column{
                        Grid{
                            id:xz
                            width: 200
                            height: 60
                            Repeater{
                                model:[]
                            }
                        }
                        Rectangle{
                            width: xz.width
                            height: 30
                            color:"#F5F6F7"
                            anchors.horizontalCenter: parent.horizontalCenter
                            Text{
                                text:"形状"
                                color:"#929292"
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }
        }
        Tab{
            title: "查看"
            Rectangle {
                id: show
                width: appWindow.width
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    top: parent.top
                    topMargin: 8
                }
                color: "transparent"
                Row{
                    spacing: 5
                    Column{
                        Row{
                            spacing: 5
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/increase.png"
                                rectColor: "transparent"
                                describle: "放大"
                                onClicked: {
                                    if( statusbar.sliderValue+0.25>1)
                                        statusbar.sliderValue=1;
                                    else
                                        statusbar.sliderValue= statusbar.sliderValue+0.25
                                }
                            }
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/decrease.png"
                                rectColor: "transparent"
                                describle: "缩小"
                                onClicked: {
                                    if( statusbar.sliderValue-0.25<-1)
                                        statusbar.sliderValue=-1;
                                    else
                                        statusbar.sliderValue= statusbar.sliderValue-0.25
                                }
                            }
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/big.png"
                                describle: "100%"
                                onClicked: statusbar.sliderValue=0;
                            }
                        }
                        Rectangle{
                            width: parent.width
                            height: 25
                            color:"#F5F6F7"
                            anchors.horizontalCenter: parent.horizontalCenter
                            Text{
                                text:"缩放"
                                color:"#929292"
                                anchors.centerIn: parent
                            }
                        }
                    }
                    //分隔符
                    Rectangle{height: 64;width: 1;color:"#E2E3E4";}
                    Column{
                        Row{
                            spacing: 5
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/fullScreen.png"
                                rectColor: "transparent"
                                describle: "全屏"
                                onClicked: appWindow.showFullScreen()
                            }
                            PicButton{
                                width: 50
                                height: 64
                                isImageVisible: true
                                imagePath: "res/exitFull.png"
                                rectColor: "transparent"
                                describle: "退出"
                                onClicked: appWindow.showNormal()
                            }
                        }
                        Rectangle{
                            width: parent.width
                            height: 25
                            color:"#F5F6F7"
                            anchors.horizontalCenter: parent.horizontalCenter
                            Text{
                                text:"显示"
                                color:"#929292"
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }
        }
        style:TabViewStyle{
            frameOverlap: 1
            tab: Rectangle {
                color: styleData.selected ? "#F5F6F7" :"#FFFFFF"
                implicitWidth: Math.max(text.width + 4, 100)
                implicitHeight: 30
                radius: 1
                Text {
                    id: text
                    anchors.centerIn: parent
                    text: styleData.title
                    color: "black"
                    font.pixelSize: 12
                }
            }
            frame: Rectangle {
                width: appWindow.width
                color: "#F5F6F7"
            }
        }
    }
}
