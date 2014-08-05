#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui = new ofxUICanvas();
    gui->setWidth(500);
    gui->addLabel("Scratch2Rapiro", OFX_UI_FONT_LARGE);
    gui->addSpacer();
   
    ofSerial serial;
    vector<string> ports;
    vector<ofSerialDeviceInfo> dInfo = serial.getDeviceList();
    for (auto it = dInfo.begin(); it != dInfo.end(); it++) {
        ports.push_back(it->getDevicePath());
    }
    
    gui->setWidgetFontSize(OFX_UI_FONT_MEDIUM);
    ddl = gui->addDropDownList("Select Rapiro Port", ports);
    ddl->setAllowMultiple(false);
    ddl->setAutoClose(true);
    ddl->setName("port");
    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    
    scratch.setup("", 12333); // localhost
    ofAddListener(ofxScratch2::BlockEvent::events, this, &ofApp::blockEvent);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::blockEvent(ofxScratch2::BlockEvent &e){
    
    // default pose
    if(e.paramaters->at(0) == "reset_all") {
        rapiro.setAction(RAPIRO_CMD_STOP);
    } else if(e.paramaters->at(0) == "stop") {
        rapiro.setAction(RAPIRO_CMD_STOP);
    } else if (e.paramaters->at(0) == "move") {
        if (e.paramaters->at(1) == "%u524D" ) {
            rapiro.setAction(RAPIRO_CMD_FORWARD);
        } else if (e.paramaters->at(1) == "%u5F8C%u308D") {
            rapiro.setAction(RAPIRO_CMD_BACKWARD);
        }
    } else if (e.paramaters->at(0) == "turn") {
        cout << e.paramaters->at(1);

        if (e.paramaters->at(1) == "%u5DE6") {
            rapiro.setAction(RAPIRO_CMD_TURN_LEFT);
        } else if (e.paramaters->at(1) == "%u53F3") {
            rapiro.setAction(RAPIRO_CMD_TURN_RIGHT);
        }
    } else if (e.paramaters->at(0) == "wave") {
        if (e.paramaters->at(1) == "%u5DE6") {
            rapiro.setAction(RAPIRO_CMD_WAVE_HAND_LEFT);
        } else if (e.paramaters->at(1) == "%u53F3") {
            rapiro.setAction(RAPIRO_CMD_WAVE_HAND_RIGHT);
        } else if (e.paramaters->at(1) == "%u4E21") {
            rapiro.setAction(RAPIRO_CMD_WAVE_HAND_BOTH);
        }
    } else if (e.paramaters->at(0) == "grab") {
        rapiro.setAction(RAPIRO_CMD_GRAB_HAND_BOTH);
    } else if (e.paramaters->at(0) == "stretch") {
        rapiro.setAction(RAPIRO_CMD_STRETCH_OUT_HAND_RIGHT);
    }
    
    // custom pose
    if (e.paramaters->at(0) == "setServoAtPose") {
        int partId;
        for (partId = 0; partId < 12; partId++) {
            if (convertTablePartId[partId] == e.paramaters->at(2)) {
                break;
            }
        }
        rapiro.setPartValueAtPose(ofToInt(e.paramaters->at(1)),
                                  partId,
                                  ofToInt(e.paramaters->at(3)));
        scratch.updateValue("getServoAtPose/"+e.paramaters->at(1)+"/"+
                            decodeEscapedUnicode(e.paramaters->at(2)), e.paramaters->at(3));
    } else if (e.paramaters->at(0) == "setLedAtPose") {
        int partId;
        for (partId = 12; partId < 15; partId++) {
            if (convertTablePartId[partId] == e.paramaters->at(2)) {
                break;
            }
        }
        rapiro.setPartValueAtPose(ofToInt(e.paramaters->at(1)),
                                  partId,
                                  ofToInt(e.paramaters->at(3)));
        scratch.updateValue("getLedAtPose/"+e.paramaters->at(1)+"/"+
                            decodeEscapedUnicode(e.paramaters->at(2)), e.paramaters->at(3));
    } else if (e.paramaters->at(0) == "resetPose") {
        rapiro.resetPose(ofToInt(e.paramaters->at(1)));
    } else if (e.paramaters->at(0) == "sendPose") {
        rapiro.sendPose(ofToInt(e.paramaters->at(2)), ofToFloat(e.paramaters->at(1)));
    }
}

//--------------------------------------------------------------
string ofApp::decodeEscapedUnicode(string escapedStr) {
    ofStringReplace(escapedStr, "%u", "0x");
    std::stringstream ss(escapedStr);
    unsigned long val;
    ss >> hex >> val;
    return ofTextConverter::toUTF8(val);
}

//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e) {
    if (e.getName() == "port") {
        ofxUIDropDownList *ddlist = (ofxUIDropDownList *) e.widget;
        vector<ofxUIWidget *> &selected = ddlist->getSelected();
        for(int i = 0; i < selected.size(); i++) {
            selectedPort = selected[i]->getName();
            rapiro.setup(selectedPort);
        }
        if(selectedPort != "") {
            ddlist->setLabelText(selectedPort);
        }
    }
}