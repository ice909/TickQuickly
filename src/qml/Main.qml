import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: root
    width: 800
    height: 600
    visible: true
    title: "TickQuickly"

    RowLayout {
        anchors.fill: parent
        spacing: 0

        // 任务列表
        Rectangle {
            width: 300
            Layout.fillHeight: true
            Column {
                anchors.fill: parent
                anchors.margins: 16
                spacing: 8

                TextField {
                    id: inputTask
                    placeholderText: "添加任务"
                    width: parent.width
                    color: "#000"
                    onAccepted: {
                        if (inputTask.text.length > 0) {
                            taskModel.addTask(inputTask.text)
                            inputTask.text = ""
                        }
                    }
                    background: Rectangle {
                        anchors.fill: parent
                        color: inputTask.activeFocus ? "#fff" : "#1919194D"
                        radius: 6
                        border.color: inputTask.activeFocus ? "#4772FA" : null
                        border.width: inputTask.activeFocus ? 1 : 0
                    }
                }

                ListView {
                    model: taskModel
                    width: parent.width
                    height: parent.height - 80
                    delegate: Rectangle {
                        width: parent.width
                        height: 40
                        radius: 6
                        color: mouseArea.containsMouse ? "#1919190a" : "transparent"
                        RowLayout {
                            anchors.fill: parent
                            anchors.leftMargin: 16
                            anchors.rightMargin: 16     
                            spacing: 8
                            Text {
                                Layout.alignment: Qt.AlignVCenter
                                text: model.title
                                font.pointSize: 16
                                color: "#191919"
                            }
                        }

                        MouseArea {
                            id: mouseArea
                            anchors.fill: parent
                            hoverEnabled: true
                        }
                    }
                }
            }
        }
        // 任务详情
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "lightgreen"
            Text {
                anchors.centerIn: parent
                text: "Right Pane"
                font.pointSize: 24
            }
        }
    }
}
