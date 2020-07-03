#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(180);

	this->draw_butter_fly(glm::vec2(-180, -180), 280);

	this->draw_butter_fly(glm::vec2(90, -270), 90);
	this->draw_butter_fly(glm::vec2(270, -270), 120);
	this->draw_butter_fly(glm::vec2(90, -90), 130);
	this->draw_butter_fly(glm::vec2(270, -90), 100);

	this->draw_butter_fly(glm::vec2(-90, 270), 90);
	this->draw_butter_fly(glm::vec2(-270, 270), 120);
	this->draw_butter_fly(glm::vec2(-90, 90), 130);
	this->draw_butter_fly(glm::vec2(-270, 90), 100);

	this->draw_butter_fly(glm::vec2(180, 180), 280);
}


//--------------------------------------------------------------
void ofApp::draw_butter_fly(glm::vec2 location, float size) {

	ofPushMatrix();
	ofTranslate(location);

	int param = ofRandom(1000);
	for (int k = 0; k < 2; k++) {

		ofRotateY(180);

		/// --- ///

		ofPushMatrix();
		k == 0 ? ofRotateY(sin(param + ofGetFrameNum() * 0.6) * 15) : ofRotateY(cos(param + ofGetFrameNum() * 0.6) * 15);

		ofBeginShape();

		ofVertex(glm::vec2());
		ofBezierVertex(glm::vec2(0, size * -0.25), glm::vec2(size * 0.25, size * -0.5), glm::vec2(size * 0.5, size * -0.5));

		ofVertex(glm::vec2(glm::vec2(size * 0.5, size * -0.5)));
		ofBezierVertex(glm::vec2(size * 0.55, size * -0.25), glm::vec2(size * 0.55, size * -0.25), glm::vec2(glm::vec2(size * 0.5, size * -0.05)));

		ofVertex(glm::vec2(size * 0.5, size * -0.05));
		ofBezierVertex(glm::vec2(size * 0.25, size * 0.05), glm::vec2(size * 0.25, size * 0.01), glm::vec2(0, 0));

		ofEndShape();

		ofPopMatrix();

		/// --- ///

		ofPushMatrix();
		k == 0 ? ofRotateY(sin(param + ofGetFrameNum() * 0.6) * 10) : ofRotateY(cos(param + ofGetFrameNum() * 0.6) * 10);

		ofBeginShape();

		ofVertex(glm::vec2(0, 0));
		ofBezierVertex(glm::vec2(size * 0.25, size * -0.01), glm::vec2(size * 0.25, size * 0.08), glm::vec2(size * 0.35, size * 0.15));

		ofVertex(glm::vec2(glm::vec2(size * 0.35, size * 0.15)));
		ofBezierVertex(glm::vec2(size * 0.35, size * 0.2), glm::vec2(size * 0.38, size * 0.25), glm::vec2(glm::vec2(size * 0.35, size * 0.35)));

		ofVertex(glm::vec2(size * 0.35, size * 0.35));
		ofBezierVertex(glm::vec2(size * 0.1, size * 0.35), glm::vec2(0, size * 0.15), glm::vec2(0, 0));

		ofEndShape();

		ofPopMatrix();
	}

	ofPopMatrix();
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}