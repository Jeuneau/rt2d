#include "Health.h"

Health::Health() {
	health = 10;

	// draw the text
	setPlainText("Health: ") + Health::number(health); // Health: 3
	setDefaultTextColor(red);
	setFont("times", 16);
}

void Health::decrease() {
	health--;
	setPlainText("Health: ") + number(health); // Health: 2
}

int Health::getHealth() {
	return health;
}
