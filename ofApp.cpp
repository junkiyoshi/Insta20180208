#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofEnableLighting();
	ofNoFill();
	this->light.setPosition(ofVec3f(0, 0, 1024));
	this->light.enable();
}

//--------------------------------------------------------------
void ofApp::update() {

	if (ofGetFrameNum() % 180 == 0) {

		ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
		this->r_rect = RecuRect(5, ofVec2f(0, 0), 720, true);
	}

	this->r_rect.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotate(ofGetFrameNum() * 0.25);

	ofNoFill();
	ofDrawRectangle(ofVec2f(-ofGetWidth() / 2, -ofGetHeight() / 2), ofGetWidth(), ofGetHeight());
	this->r_rect.draw();

	this->cam.end();
}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}