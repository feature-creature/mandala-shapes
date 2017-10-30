#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // initialize
    ofSetBackgroundColor(255);
    ofSetBackgroundAuto(false);
    noOfStars = 15;
    for(int i = 0; i <= noOfStars; i++){
        radius1.push_back(ofRandom(50,ofGetScreenWidth()/4));
        radius2.push_back(ofRandom(25,ofGetScreenWidth()/3.5));
        resolution.push_back(i + 2);
        rotAngle.push_back(ofRandom(0,10));
        angleStep.push_back(ofMap(i,0,noOfStars,0.01,0.1));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // create trailing by drawing transparent rect over background
    ofFill();
    ofSetColor(255,10);
    ofDrawRectangle(0,0,ofGetScreenWidth(),ofGetScreenHeight());
//    ofNoFill();
    // declare local variables

    // ofMap:
    // Linerally map a value between two ranges.
    // ofMap(float value, float inputMin, float inputMax, float outputMin, float outputMax, bool clamp=false)
    // return float
    // If an input value is 50% of the way between inputMin and inputMax range,
    // the output value will be 50% of the way between outpuMin and outputMax.
    // ?? non linear mapping options

        // ofMap - NO CLAMPING (DEFAULT):
        // If an input value is outside of the intputMin and inputMax range,
        // negative percentages and percentages greater than 100% will be used.
        // EX: If an input value is 150 and the input range is 0 - 100 and the output range 0 - 1000,
        // since the input value is 150% of the total input range
        // the output value will be 1500 or 150% of the total output range.

        // ofMap - CLAMPING:
        // If an input value is outside of the intputMin and inputMax range,
        // outputMin and outputMax values will be used.
        // EX: If an input value is 150 and the input range is 0 - 100 and the output range 0 - 1000,
        // since the input value is > the total input range
        // the output value will be 1000.

    // ofClamp (standard (mapless) range clamping)
    // If the value is min <= value <= max, returns value.
    // If the value is greater than max, return max;
    // If the value is less than min, return min.
    // Otherwise, return the value unchanged.

    // linearly map the mouse x-position in the window to custom range with active clamping
    // int resolution = ofMap(mouseX,0,ofGetWidth(),2,20, true);

    // !! didnt realize i is clearly meant to indicate index
    ofPushMatrix();
        // translate buffer(?) to center of window
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
        ofScale(ofMap(mouseX,0,ofGetWidth(),0.1,3, true), ofMap(mouseX,0,ofGetWidth(),0.1,3, true));
        for(float i = 0; i <= noOfStars; i++)
        {

            // create bounds for the angle rotation
            if(rotAngle[i] <= -2*i || rotAngle[i] >= 2*i)
            {
                angleStep[i] = -1 * angleStep[i];
            }
            // update the angle each frame
            rotAngle[i] += angleStep[i];

            mandala(i, radius1[i], radius2[i], resolution[i], rotAngle[i], angleStep[i]);
        }
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // save frame as date-frame_number.png
    if(key == 's'){
        ofSaveScreen(ofGetTimestampString() + "-" + ofToString(ofGetFrameNum()) + ".png");
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
void ofApp::star(float x, float y, float radius1, float radius2, int npoints) {
    float angle = 360.0 / npoints;
    float halfAngle = angle/2.0;

    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    for (float a = 0; a < 360.0; a += angle)
    {
        float sx = x + cos(ofDegToRad(a)) * radius2;
        float sy = y + sin(ofDegToRad(a)) * radius2;
        ofVertex(sx, sy);
        sx = x + cos(ofDegToRad(a+halfAngle)) * radius1;
        sy = y + sin(ofDegToRad(a+halfAngle)) * radius1;
        ofVertex(sx, sy);
    }
    ofEndShape();
}

// ?? bad practice to use the same name for parameters and arguments
//--------------------------------------------------------------
void ofApp::mandala(int index, int radius1, int radius2, int resolution, float rotAngle, float angleStep){
//    ?? passing variable reference vs variable value as an argument.
//    ?? updating associated variable
//    // create bounds for the angle rotation
//    if(rotAngle <= -15 || rotAngle >= 15)
//    {
//        angleStep = -1 * angleStep;
//    }
//    // update the angle each frame
//    rotAngle += angleStep;

    // implement rotatation of individual
    ofRotate(index*5 + rotAngle);
    // scale along the x+y-axis according to star index
    // ?? why not z itself
    ofScale(1-1/noOfStars,1-1/noOfStars, 1);
    // color: linearly map the the index to 8-bit value with active clamping
    ofSetColor(ofMap(index,0,noOfStars,150,255, true),30);
    // linearly map the mouse y-position in the window to custom range with active clamping
    star(0, 0, radius1, radius2, resolution);
}
