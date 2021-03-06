#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

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
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void star(float x, float y, float radius1, float radius2, int npoints);
    void mandala(int index, int radius1, int radius2, int resolution, float rotAngle, float angleStep);

    int noOfStars;
    vector<int> radius1;
    vector<int> radius2;
    vector<int> resolution;
    vector<float> rotAngle;
    vector<float> angleStep;


};
