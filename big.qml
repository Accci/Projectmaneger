
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Rectangle {
    width: 800
    height: 600

    GridView {
        id: gridView
        width: parent.width
        height: parent.height
        cellWidth: 267
        cellHeight: 200
        model: ListModel {
            ListElement { imageSource: "qrc:/sources/temp.png"; title: "HL_test"; date: "2023/03/24" }
            ListElement { imageSource: "qrc:/sources/temp2.png"; title: "HL_test"; date: "2023/03/24" }
            ListElement { imageSource: "qrc:/sources/temp3.png"; title: "HL_test"; date: "2023/03/24" }
            ListElement { imageSource: "qrc:/sources/temp4.png"; title: "HL_test"; date: "2023/03/24" }
            ListElement { imageSource: "qrc:/sources/temp5.png"; title: "HL_test"; date: "2023/03/24" }
            ListElement { imageSource: "qrc:/sources/temp6.png"; title: "HL_test"; date: "2023/03/24" }
            ListElement { imageSource: "qrc:/sources/temp7.png"; title: "HL_test"; date: "2023/03/24" }
            ListElement { imageSource: "qrc:/sources/temp8.png"; title: "HL_test"; date: "2023/03/24" }
        }

        delegate: Rectangle  {
            width: gridView.cellWidth-20
            height: gridView.cellHeight

            color: "transparent"

            border.color: "#f0f0f0" // 设置边框颜色
            border.width: 2 // 设置边框宽度
            radius: 5 // 可选：设置圆角半径


            Column {
                width: parent.width
                spacing: 0

                Image {
                    source: model.imageSource
                    width: parent.width
                    height: gridView.cellHeight-15
                    fillMode: Image.PreserveAspectFit
                }

                Row {
                        width: parent.width
                        spacing: 140 // 根据需要调整元素之间的间距

                        Text {
                            text: model.title
                            horizontalAlignment: Text.AlignHCenter
                            font.bold: true
                        }

                        Text {
                            text: model.date
                            horizontalAlignment: Text.AlignHCenter
                            color: "gray"
                        }
                  }
            }
        }
    }
}

