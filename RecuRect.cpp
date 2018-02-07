#include "RecuRect.h"

RecuRect::RecuRect() {

}

RecuRect::RecuRect(int level, ofVec2f location, float size, bool origin) {

	this->type = ofRandom(100);

	if (origin || (level > 0 && this->type > 20)) {

		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x - size / 4, location.y - size / 4), size / 2));
		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x - size / 4, location.y + size / 4), size / 2));
		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x + size / 4, location.y - size / 4), size / 2));
		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x + size / 4, location.y + size / 4), size / 2));
	}

	this->level = level;
	this->location = location;
	this->size = size;
	this->origin = origin;
	this->height = 0;
	this->height_max = -1 * (140 - 20 * level);
}

RecuRect::~RecuRect() {

}

void RecuRect::update() {

	for (int i = 0; i < this->rects.size(); i++) {

		this->rects[i].update();
	}

	if (this->height > this->height_max) {
		this->height -= 3;
	}
}

void RecuRect::draw() {

	for (int i = 0; i < this->rects.size(); i++) {

		this->rects[i].draw();
	}
	
	if (this->type > 60) {

		ofFill();
		ofDrawBox(this->location.x, this->location.y, -this->height / 2, size, size, this->height);
	}
}
