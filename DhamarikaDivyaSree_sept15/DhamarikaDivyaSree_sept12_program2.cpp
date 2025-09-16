#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sensor {
public:
    int id;
    float value;
    int priority;
    string status;

    Sensor(int i, float v, int p) : id(i), value(v), priority(p), status("OK") {}

    void updateValue(float v) {
        value = v;
        status = (v > 80.0) ? "CRITICAL" : "NORMAL";
    }
};

class Controller {
public:
    Sensor* sensorList[10];
    Sensor* criticalSensor;

    Controller(Sensor* list[], int size) {
        for (int i = 0; i < size; i++) {
            sensorList[i] = list[i];
        }
        bindCriticalSensor(size);
    }

   void bindCriticalSensor(int size) {
    if (size <= 0) return;
    criticalSensor = sensorList[0];
    for (int i = 1; i < size; i++) {
        if (sensorList[i]->priority < criticalSensor->priority) {
            criticalSensor = sensorList[i];
        }
    }
}
    void updateCriticalSensor(float newValue) {
        if (!criticalSensor) return;
        criticalSensor->updateValue(newValue);
        cout << "Updated critical sensor (id=" << criticalSensor->id
             << ") value=" << criticalSensor->value
             << " status=" << criticalSensor->status << endl;
    }

    void printStatus(int size) {
        if (!criticalSensor) {
            cout << "No critical sensor bound.\n";
        } else {
            cout << "Controller Status: Critical Sensor -> ID=" << criticalSensor->id
                 << " Priority=" << criticalSensor->priority
                 << " Value=" << criticalSensor->value
                 << " Status=" << criticalSensor->status << endl;
        }
        printSensorMap(size);
    }

    void printSensorMap(int size) {
        cout << "--- Sensor Map ---" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Sensor ID=" << sensorList[i]->id
                 << " Value=" << sensorList[i]->value
                 << " Priority=" << sensorList[i]->priority
                 << " Status=" << sensorList[i]->status << endl;
        }
        cout << "------------------" << endl;
    }
};

class SensorDiagnostics {
public:
    string checkHealth(Sensor& s) {
        return (s.status == "CRITICAL") ? "Needs attention!" : "Healthy";
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    const int SIZE = 10;
    Sensor* sensors[SIZE];

   
    for (int i = 0; i < SIZE; i++) {
        int priority = rand() % 5 + 1;
        sensors[i] = new Sensor(i + 1, 70.0 + i * 5, priority);
    }

    Controller controller(sensors, SIZE);
    controller.printStatus(SIZE);


    controller.updateCriticalSensor(108.0);
    controller.printStatus(SIZE);

    SensorDiagnostics diag;
    if (controller.criticalSensor)
        cout << "Health check: " << diag.checkHealth(*controller.criticalSensor) << endl;

   
    for (int i = 0; i < SIZE; i++) {
        delete sensors[i];
    }

    return 0;
}