import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
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
            color: "lightblue"
            Text {
                anchors.centerIn: parent
                text: "Left Pane"
                font.pointSize: 24
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
