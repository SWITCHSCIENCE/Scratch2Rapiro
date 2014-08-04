//
//  Rapiro.h
//  example2
//
//  Created by Kenta Hara on 5/29/14.
//
//

#ifndef __example2__Rapiro__
#define __example2__Rapiro__

#include "ofMain.h"
#include "Part.h"

enum RapiroCommand {
    RAPIRO_CMD_STOP,
    RAPIRO_CMD_FORWARD,
    RAPIRO_CMD_BACKWARD,
    RAPIRO_CMD_TURN_RIGHT,
    RAPIRO_CMD_TURN_LEFT,
    RAPIRO_CMD_WAVE_HAND_BOTH,
    RAPIRO_CMD_WAVE_HAND_RIGHT,
    RAPIRO_CMD_GRAB_HAND_BOTH,
    RAPIRO_CMD_WAVE_HAND_LEFT,
    RAPIRO_CMD_STRETCH_OUT_HAND_RIGHT
};

class Rapiro {
public:
    Rapiro();
    ~Rapiro(){};
    
    bool setup(string portName, int baud = 57600);
    
    bool setAction(RapiroCommand cmd);
    void setPartValueAtPose(int poseId, int partId, int value);
    void resetPose(int poseId);
    bool sendPose(int poseId, float sec);
    
private:
    bool sendCommand(string command);

    string createCommand();
    ofSerial serial;
    vector<Pose> poses;
};

#endif /* defined(__example2__Rapiro__) */
