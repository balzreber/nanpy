#include <Arduino.h>
#include <Servo.h>
#include "ServoClass.h"
#include "MethodDescriptor.h"
#include <stdlib.h>

ServoClass::ServoClass():v(0) {

};

void ServoClass::elaborate( MethodDescriptor* m ) {
    if (strcmp(m->getClass(), "Servo") == 0) {

        if (strcmp(m->getName(),"new") == 0) {       
            v.insert(new Servo());
            v[v.getLastIndex()]->attach(m->getInt(0));
            Serial.println(v.getLastIndex());
        }

        if (strcmp(m->getName(), "write") == 0) {
            v[m->getObjectId()]->write(m->getInt(0));
            Serial.println("0");
        }

        if (strcmp(m->getName(), "read") == 0) {
            Serial.println(v[m->getObjectId()]->read());
        }

        if (strcmp(m->getName(), "writeMicroseconds") == 0) {
            v[m->getObjectId()]->writeMicroseconds(m->getInt(0));
            Serial.println("0");
        }

        if (strcmp(m->getName(), "readMicroseconds") == 0) {
            Serial.println(v[m->getObjectId()]->readMicroseconds());
        }

        if (strcmp(m->getName(), "detach") == 0) {
            v[m->getObjectId()]->detach();
            Serial.println("0");
        }

        if (strcmp(m->getName(), "attached") == 0) {
            Serial.println(v[m->getObjectId()]->attached());
        }

        if (strcmp(m->getName(), "remove") == 0) {
            delete(v[m->getObjectId()]);
            v.remove(m->getObjectId());
            Serial.println("0");
        }

    }
};