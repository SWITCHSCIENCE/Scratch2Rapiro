#pragma once

#include "ofxScratch2.h"
#include "ofMain.h"
#include "Rapiro.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void blockEvent(ofxScratch2::BlockEvent &e);
    
        ofxScratch2::Offline scratch;
        Rapiro rapiro;
        ofColor bg;
        
        string convertTablePartId[15] = {
            "%u982D",
            "%u8170",
            "%u53F3%u8155(%u30ED%u30FC%u30EB)",
            "%u53F3%u8155(%u30D4%u30C3%u30C1)",
            "%u53F3%u624B",
            "%u5DE6%u8155(%u30ED%u30FC%u30EB)",
            "%u5DE6%u8155(%u30D4%u30C3%u30C1)",
            "%u5DE6%u624B",
            "%u53F3%u8DB3(%u30E8%u30FC)",
            "%u53F3%u8DB3(%u30D4%u30C3%u30C1)",
            "%u5DE6%u8DB3(%u30E8%u30FC)",
            "%u5DE6%u8DB3(%u30D4%u30C3%u30C1)",
            "%u8D64",
            "%u7DD1",
            "%u9752"
        };
};
