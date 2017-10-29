#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    rotAngle = 0;
    angleStep = 0.1;

}

//--------------------------------------------------------------
void ofApp::update(){
    // create bounds for the angle rotation
    if(rotAngle <= -15 || rotAngle >= 15)
    {
        angleStep = -1 * angleStep;
    }
    // update the angle each frame
    rotAngle += angleStep;
}

//--------------------------------------------------------------
void ofApp::draw(){
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
    int resolution = ofMap(mouseX,0,ofGetWidth(),2,20, true);
    float noOfStars = 20;

    // !! didnt realize i is clearly meant to indicate index
    ofPushMatrix();
        // translate buffer(?) to center of window
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
        for(float i = 0; i <= noOfStars; i++)
        {
                // rotate individual
                ofRotate(i*5+ rotAngle);
                // scale along the x+y-axis according to star index
                ofScale(1-1/noOfStars,1-1/noOfStars, 1);
                // color: linearly map the the index to 8-bit value with active clamping
                ofSetColor(ofMap(i,0,noOfStars,0,255, true));
                // linearly map the mouse y-position in the window to custom range with active clamping
                int radius2 = ofMap(mouseY,0,ofGetHeight(),50,400,true);
                int radius1 = 200;
                star(0, 0, radius1, radius2, resolution);
    }
    ofPopMatrix();

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
