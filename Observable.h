#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <Observer.h>
#include <vector>

using namespace std;

/**
 * @brief The Observable struct represents the observable of the deisgn pattern Obeserver/Observable.
 */
struct Observable{
    vector<Observer*> obs;

    /**
     * @brief addObs adds the class to the list of observers.
     * @param o the class to add.
     */
    void addObs(Observer& o){
        obs.push_back(&o);
    }


    /**
     * @brief notify notifies the observers.
     */
    void notify(){
        for(Observer* o:obs){
            o->update();
        }
    }
};

#endif // OBSERVABLE_H
