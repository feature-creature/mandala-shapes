#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // declare local variables

    // ofMap:
    // Linerally map a value between two ranges.
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
    int resolution = ofMap(mouseX,0,ofGetWidth(),3,20, true);


    ofSetColor(0);
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    star(0, 0, 100, 150, resolution);

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
