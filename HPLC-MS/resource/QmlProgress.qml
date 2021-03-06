/*!
 *@file QmlProgress.qml
 *@brief Qml进度条
 *@version 1.0
 *@section LICENSE Copyright (C) 2003-2103 CamelSoft Corporation
 *@author zhengtianzuo
*/
import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.2

ProgressBar {
    property color proColor: "#148014"
    property color proBackgroundColor: "#AAAAAA"
    property int proWidth: 2
    property real progress: 0
    property real proRadius: 3
 //   property alias interval: timer.interval

//    function isRunning(){
//        return(timer.running)
//    }

//    function onStart(){
//        cProgress.progress = 0;
//        timer.running = true;
//    }

//    function onStop(){
//        timer.running = false;
//    }

    id: cProgress
    // anchors.centerIn: parent
    value: 0
    padding: 2


    background: Rectangle {
        implicitWidth: 200
        implicitHeight: 16
        color: cProgress.proBackgroundColor
        radius: cProgress.proRadius
    }

    contentItem: Item {
        implicitWidth: 200
        implicitHeight: 10

        Rectangle {
            width: cProgress.visualPosition * parent.width
            height: parent.height
            radius: 2
            color: cProgress.proColor

        }
    }

    //    Item {
    //        id: valueFormat
    Text{

        color: "blue";
        text: (value * 100).toFixed(2) + "%";
        z: 2;
        anchors.centerIn: parent;

        //        }
    }

//    Timer{
//        id: timer
//        running: false
//        repeat: true
//        interval: 50
//        onTriggered:{
//            cProgress.progress++;
//            console.log(cProgress.progress)
//            if (cProgress.progress > 100){
//                cProgress.onStop();
//                return;
//            }
//        }
//    }
    function setProgress(value){
        //console.log(value.property("qml"));
       // console.log("dsfs")
       // console.log(value)
        cProgress.value = value;
        if(value<=0.1)
            cProgress.proColor = "#FF3300"
        else if(value<=0.3)
            cProgress.proColor = "#FFCC33"
        else {
            cProgress.proColor = "#148014"}

    }
}
