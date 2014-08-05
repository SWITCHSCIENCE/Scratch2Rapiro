//
//  Rapiro.cpp
//  Scratch2Rapiro
//
//  Created by Kenta Hara on 5/29/14.
//
//

#include "Rapiro.h"

Rapiro::Rapiro() {}

bool Rapiro::setup(string portName, int baud) {
    return serial.setup(portName, baud);
}

bool Rapiro::setAction(RapiroCommand cmd) {
    string buf = "#M" + ofToString((int)cmd);
    ofLogNotice("Rapiro") << buf;
    return serial.writeBytes((unsigned char*)buf.c_str(), buf.length()+1);
}

void Rapiro::setPartValueAtPose(int poseId, int partId, int angle) {
    if (poseId >= poses.size()) {
        poses.resize(poseId+1);
    }
    poses[poseId].setValueAt(partId, angle);
    ofLogNotice("Rapiro::setPartValueAtPose") << poses[poseId].getPoseCommand();
}

void Rapiro::resetPose(int poseId) {
    poses[poseId].reset();
}

bool Rapiro::sendPose(int poseId, float sec) {
    if (poseId >= poses.size()) {
        return false;
    }
    return sendCommand(poses.at(poseId).getPoseCommand()+"T"+ofToString(int(sec*100), 3, '0'));
}

bool Rapiro::sendCommand(string command) {
    ofLogNotice("Rapiro") << command;
    return serial.writeBytes((unsigned char*)command.c_str(), command.length()+1);
}

/*
bool Rapiro::setEyesColor(ofColor c) {
    setEyesColor((int)c.r, (int)c.g, (int)c.b);
}

bool Rapiro::setEyesColor(int r, int g, int b) {
    string buf = "#PR"+ofToString(r)+"G"+ofToString(g)+"B"+ofToString(b)+"T001";
    serial.writeBytes((unsigned char*)buf.c_str(), buf.length()+1);
}
 
bool setEyesColor(int r, int g, int b);
bool setEyesColor(ofColor c);
bool setServoAngle();
*/