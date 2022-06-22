#ifndef OBSERVER_H
#define OBSERVER_H


/**
 * @brief The Observer struct represents the obervers of the design pattern Observer/Observable.
 */
struct Observer{

    /**
     * @brief update updates their states.
     */
    virtual void update(){}
};

#endif // OBSERVER_H
