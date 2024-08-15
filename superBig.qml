//import QtQuick 2.0

//Rectangle {
//    width:800
//    height:600

//    GridView{
//        id:gridView
//        width: parent.width
//        height:parent.height
//        cellWidth: 400
//        cellHeight: 250

//        model:ListModel{
//            ListElement{imageSource: "qrc:/sources/pic1.png";icoSrc: "qrc:/sources/temp10.png";title:"云上实验室";resolution:"1920*1080";description:"暂无描述"}
//            ListElement{imageSource: "qrc:/sources/pic2.png";icoSrc: "qrc:/sources/temp10.png";title:"云上实验室";resolution:"1920*1080";description:"暂无描述"}
//            ListElement{imageSource: "qrc:/sources/pic3.png";icoSrc: "qrc:/sources/temp10.png";title:"云上实验室";resolution:"1920*1080";description:"暂无描述"}
//            ListElement{imageSource: "qrc:/sources/pic4.png";icoSrc: "qrc:/sources/temp10.png";title:"云上实验室";resolution:"1920*1080";description:"暂无描述"}
//            ListElement{imageSource: "qrc:/sources/pic5.png";icoSrc: "qrc:/sources/temp10.png";title:"云上实验室";resolution:"1920*1080";description:"暂无描述"}
//        }

//        delegate:Rectangle{
//            width: gridView.cellWidth-15
//            height: gridView.cellHeight

//            color: "transparent"
//            border.color: "#f0f0f0"
//            border.width: 2
//            radius: 5

//            Column{
//                width: parent.width
//                spacing: 5

//            Image {
//                id:image
//                source: model.imageSource
//                width: parent.width
//                height: gridView.height
//                fillMode: Image.PreserveAspectFit
//            }

//            Row{
//                width: parent.width
//                spacing: 10 //根据需要调整元素之间的间距
//                anchors.baselineOffset: parent.height - Image.height

//                Image {
//                    id:ico
//                    source: model.icoSrc
//                    width: 50
//                    height: 50
//                }
//                Column{
//                    width: gridView.width - ico.width - 10
//                    spacing: 20

//                    Row{
//                        width: parent.width
//                        spacing: 140
//                        Text {
//                            text:model.title
//                            horizontalAlignment: Text.AlignHCenter
//                            font.bold: true
//                        }

//                        Text {
//                            text:model.resolution
//                            horizontalAlignment: Text.AlignHCenter
//                            color: "gray"
//                        }
//                    }

//                    Text{
//                        text: model.description
//                        horizontalAlignment: Text.AlignHCenter
//                         color: "gray"
//                        }
//                    }
//                }
//           }
//        }

//    }
//}

import QtQuick 2.0

Rectangle {
    width: 800
    height: 600

    GridView {
        id: gridView
        width: parent.width
        height: parent.height
        cellWidth: 400
        cellHeight: 300

        model: ListModel {
            ListElement { imageSource: "qrc:/sources/pic1.png"; icoSrc: "qrc:/sources/temp10.png"; title: "云上实验室"; resolution: "1920*1080"; description: "暂无描述" }
            ListElement { imageSource: "qrc:/sources/pic2.png"; icoSrc: "qrc:/sources/temp10.png"; title: "云上实验室"; resolution: "1920*1080"; description: "暂无描述" }
            ListElement { imageSource: "qrc:/sources/pic3.png"; icoSrc: "qrc:/sources/temp10.png"; title: "云上实验室"; resolution: "1920*1080"; description: "暂无描述" }
            ListElement { imageSource: "qrc:/sources/pic4.png"; icoSrc: "qrc:/sources/temp10.png"; title: "云上实验室"; resolution: "1920*1080"; description: "暂无描述" }
            ListElement { imageSource: "qrc:/sources/pic5.png"; icoSrc: "qrc:/sources/temp10.png"; title: "云上实验室"; resolution: "1920*1080"; description: "暂无描述" }
        }

        delegate: Rectangle {
            width: gridView.cellWidth - 15
            height: gridView.cellHeight
            color: "transparent"
            border.color: "#f0f0f0"
            border.width: 2
            radius: 5

            Column {
                width: parent.width
                height: parent.height
                spacing: 10

                // Image at the top
                Image {
                    id: image
                    source: model.imageSource
                    width: parent.width
                    height: parent.height * 0.75
                    fillMode: Image.PreserveAspectFit
                }

                // Content section below Image
                Row {
                    width: parent.width
                    height: parent.height - image.height
                    spacing: 10

                    // Left side
                    Rectangle {
                        width: 50
                        height: 50
                       anchors.left: parent.left
                       anchors.leftMargin: 10  // Set the margin here
                       Image {
                           id: ico
                           source: model.icoSrc
                           anchors.fill: parent
                       }
                   }

                    Rectangle {
                       width: parent.width - 70 // Adjusting for ico width (40) and margin (10)
                       height: parent.height - image.height
                       anchors.right: parent.right
                       Column {
                           width: parent.width
                           spacing: 30

                           // Title and resolution
                           Row {
                               width: parent.width
                               spacing: 180
                               Text {
                                   text: model.title
                                   font.bold: true
                                   horizontalAlignment: Text.AlignHCenter
//                                   width: (parent.width - 10) / 2
                               }
                               Text {
                                   text: model.resolution
                                   color: "gray"
                                   horizontalAlignment: Text.AlignHCenter
//                                   width: (parent.width - 10) / 2
                               }
                           }

                           // Description
                           Text {
                               text: model.description
                               color: "gray"
                               width: parent.width
                               wrapMode: Text.Wrap
                               horizontalAlignment: Text.AlignLeft
                           }
                       }
                   }
                }
            }
        }
    }
}
