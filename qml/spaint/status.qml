import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
Rectangle {
    color: "#F0F0F0";
    implicitHeight: 30;
    width: parent.width;
    property string position: "" //位置坐标
    property int pWidth: 0  //图像宽度
    property int pHeight: 0 //图像高度
    property alias sliderValue:pslider.value //放大缩小值
    //放大倍数
    property double  rate: {
        if(pslider.value==0)1;
        else
            (1+pslider.value).toFixed(2)
    }
    Row{
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        Image{
            width: 20
            height: 20
            source: "./res/pic.png"
            anchors.verticalCenter: parent.verticalCenter
        }
        Text{
            id:pos
            anchors.verticalCenter: parent.verticalCenter
            text:" "+position
        }
    }
    Row{
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        Image{
            width: 20
            height: 20
            source: "./res/pic.png"
            anchors.verticalCenter: parent.verticalCenter
        }
        Text{
            id:pix
            text:" "+pWidth+" x "+pHeight+"像素"
            anchors.verticalCenter: parent.verticalCenter
        }
    }
    Row{
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        spacing: 5
        Text{
            id:pre //百分比
            color: "black"
            anchors.verticalCenter: parent.verticalCenter
            text:{
                if(pslider.value==0)
                    "100%"
                else
                    (1+pslider.value).toFixed(2)*100+"%"
            }
        }
        Image{
            width: 20
            height: 20
            source: "./res/decrease.png"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if( pslider.value-0.25<-1)
                        pslider.value=-1;
                    else
                        pslider.value=pslider.value-0.25
                }
            }
        }
        Slider {
            id:pslider
            minimumValue: -1
            maximumValue: 1
            value:0
            style: SliderStyle {
                groove: Rectangle {
                    implicitWidth: 150
                    implicitHeight: 5
                    color: "#F0F0F0"
                    border.color: "lightgray"
                    border.width: 1
                }
                handle: Rectangle {
                    anchors.centerIn: parent
                    color: control.pressed ? "blue" : "lightgray"
                    implicitWidth: 12
                    implicitHeight: 20
                }
            }
            onValueChanged: {
                var img=canvas.ctx.getImageData(0, 0, canvas.width, canvas.height)
                  canvas.ctx.putImageData(img, 0, 0)
            }
        }
        Image{
            width: 20
            height: 20
            source: "./res/increase.png"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if( pslider.value+0.25>1)
                        pslider.value=1;
                    else
                       pslider.value= pslider.value+0.25
                }
            }
        }
    }
}
