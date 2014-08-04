//
//  Part.h
//  example2
//
//  Created by Kenta Hara on 6/12/14.
//
//

#ifndef __example2__Part__
#define __example2__Part__

#include "ofMain.h"
#include "Rapiro.h"
#include <iostream>
#include <string>

const int PARTS_MAX = 15;
const string partNames[PARTS_MAX] = {"head", "weist",
    "right_arm_roll", "right_arm_pitch", "right_hand",
    "left_arm_roll", "left_arm_pitch", "left_hand",
    "right_foot_yaw", "right_foot_pitch",
    "left_foot_yaw", "left_foot_pitch",
    "led_red", "led_green", "led_blue"};

class Part {
public:
    Part(std::string deviceName, const unsigned int _valueMin, const unsigned int _valueMax) {
        name = deviceName;
        valueMin = _valueMin;
        valueMax = _valueMax;
        edited = false;
        value = 90;
    };
    
    ~Part(){};
    
    void setValue(const unsigned int t) {
        edited = true;
        value = (int)ofClamp(t, valueMin, valueMax);
        ofLogNotice(name + ":") << value;
    };
    unsigned int getValue() { return value; };
    unsigned int getValueMin() { return valueMin; };
    unsigned int getValueMax() { return valueMax; };
    bool isEdited(){ return edited; };
    std::string getName() { return name; };
    void reset() { edited = false; value = 90; };
    
private:
    unsigned int value;
    unsigned int valueMin;
    unsigned int valueMax;
    bool edited;
    std::string name;
};


class Pose {
public:
    // angles from http://make-muda.weblike.jp/2014/02/1062/. Thanks!
    int valuesMin[PARTS_MAX] = {0, 0, 0, 40, 50, 0, 50, 70, 45, 40, 45, 55, 0, 0, 0};
    int valuesMax[PARTS_MAX] = {180, 180, 180, 130, 110, 180, 140, 130, 135, 125, 135, 140, 255, 255, 255};
    
    Pose() {
        for (int i = 0; i < PARTS_MAX; i++) {
            parts.push_back(Part(partNames[i], valuesMin[i], valuesMax[i]));
        }
    };
    Pose(string fileName){};
    ~Pose(){};
    
    void setPose(string fileName){};
    void setValueAt(unsigned int partId, unsigned int value) {
        parts[partId].setValue(value);
    };
    void reset() {
        for (auto it = parts.begin(); it != parts.end(); it++) {
            it->reset();
        }
    }
    
    std::string getPoseCommand() {
        string command = "#P";
        for (auto it = parts.begin(); it != parts.end(); it++) {
            if (!(it->isEdited()))
                continue;
            if (it->getName() == "led_red" ) {
                command += "R" + ofToString(it->getValue(), 3, '0');
            } else if (it->getName() == "led_green") {
                command += "G" + ofToString(it->getValue(), 3, '0');
            } else if (it->getName() == "led_blue") {
                command += "B" + ofToString(it->getValue(), 3, '0');
            }else {
                command += "S" + ofToString(it - parts.begin(),  2, '0') + "A" + ofToString(it->getValue(), 3, '0');
            }
        }
        return command;
    }
    
private:
    vector<Part> parts;
};


#endif /* defined(__example2__Part__) */
