#include <iostream>
using namespace std;

class GameObject {
public:
    virtual void collide(GameObject& otherObject) = 0;
    //...
};

class SpaceShip : public GameObject {
public:
    virtual void collide(GameObject& otherObject);
    //...
};

void SpaceShip::collide(GameObject& otherObject) {
    const type_info& objectType = typeid(otherObject);
    if (objectType == typeid(SpaceShip)) {
        SpaceShip& ss = static_cast<SpaceShip&>(otherObject);
        //process a SpaceShip-SpaceShip collision;
    }
    else if (objectType == typeid(SpaceStation)) {
        SpaceStation& ss = static_cast<SpaceStation&>(otherObject);
        //process a SpaceShip-SpaceShip collision;
    }
    else if (objectType == typeid(Asteroid)) {
        Asteroid& ss = static_cast<Asteroid&>(otherObject);
        //process a SpaceShip-SpaceShip collision;
    }
    else {
        throw CollisionWithUnknownObject(otherObject);
    }
}

class SpaceStation : public GameObject {
    virtual void collide(GameObject& otherObject);
    //...
};

class Asteroid : public GameObject {
    virtual void collide(GameObject& otherObject);
    //...
};

void checkForCollision(GameObject& object1, GameObject& object2) {
    if (theyJustCollided(object1, object2))
        processCollision(object1, object2);
    else {
        //...
    }
}

int main(int argv, char* argc[]) {
    return 0;
}