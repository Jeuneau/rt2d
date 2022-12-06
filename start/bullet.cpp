#include <list>

class Bullet {

	list<string> Bullets;
	Bullets.push_back("Bullet1");
	Bullets.push_front("Bullet2");

	list<string>::iterator itr;
	itr = Bullets.begin();

	while(*itr != "Bullet1") {
		itr++;
	}
	delete itr;
	Bullets.erase(itr);
	

	for (itr= Bullets.begin(); itr != Bullets.end(); itr++) {
		cout << *itr << endl;
	}

	return 0;


	




};