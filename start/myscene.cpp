/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include "myscene.h"
#include <vector>
#include <string>
using namespace std;






MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.

	
	
	// delete when you're done with it.
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/8, SHEIGHT/8); 



	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);

	

		

		//return 0;
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;

	
}


	

void MyScene::update(float deltaTime)
{
	

	
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity->sprite()->color;
		myentity->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}

	
} 

/*struct Bullet
{
	int x = rand() % 100;
	int y = rand() % 100;
};

int main(void)
{
	std::cout << "Bullet Test" << std::endl;

	// an empty container on the stack that contains pointers to actual Bullet instances on the heap
	std::vector<Bullet*> bullets;

	// #############################################################
	// make some new bullets (or add a single Bullet when the fire-key is pressed)
	std::cout << "================== current 10 bullets ==================" << std::endl;
	for (int i = 0; i < 10; i++) {
		Bullet* b = new Bullet(); // create a new Bullet on the heap
		bullets.push_back(b); // keep a pointer to that Bullet in our list
		// addChild(bullets[i]); // if applicable

		std::cout << i << " : (" << b->x << "," << b->y << ")";
		if (b->y > 50) {
			std::cout << " <-- need to delete this bullet (y>50)";
		}
		std::cout << std::endl;
	}

	// #############################################################
	// loop backwards through bullets, to delete them from the heap and from the list.
	std::cout << "================== delete bullets if y>50 ==================" << std::endl;
	for (int i = bullets.size() - 1; i >= 0; i--) { // backwards!!!
		if (bullets[i]->y > 50) {
			std::cout << "-- deleting Bullet " << i << " : (" << bullets[i]->x << "," << bullets[i]->y << ")" << std::endl;
			// removeChild(bullets[i]); // if applicable
			delete bullets[i]; // delete from the heap first
			bullets.erase(bullets.begin() + i); // then, remove from the list
		}
	}

	// #############################################################
	std::cout << "================== our current list of bullets ==================" << std::endl;
	for (int i = 0; i < bullets.size(); i++) {
		std::cout << i << " : (" << bullets[i]->x << "," << bullets[i]->y << ")" << std::endl;
	}

	// #############################################################
	// at the very end (close program / delete scene), delete all bullets still in the list
	std::cout << "================== delete the rest of the bullets ==================" << std::endl;
	for (int i = 0; i < bullets.size(); i++) {
		std::cout << "-- deleting Bullet " << i << " : (" << bullets[i]->x << "," << bullets[i]->y << ")" << std::endl;
		delete bullets[i]; // delete Bullet from the heap (a pointer to it is still in the list)
		bullets[i] = nullptr; // set Bullet pointer to nullptr (don't try to remove it from the list)
	}
	bullets.clear(); // list contains only NULL pointers. Empty the list with 1 command.

	return 0;
} */