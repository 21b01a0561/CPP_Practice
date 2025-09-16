#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <chrono>
#include <iomanip>

class Sensor {
public:
    int id;
    float value;
    float threshold;
    std::string status;

    Sensor(int id_, float value_, float threshold_)
        : id(id_), value(value_), threshold(threshold_), status("OK") {}

    virtual ~Sensor() = default;
    virtual void simulateFault() = 0;

    bool isFaulty() const {
        return value > threshold;
    }

    virtual std::string typeName() const = 0;
};


class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(int id_, float value_, float threshold_)
        : Sensor(id_, value_, threshold_) {}

    void simulateFault() override {
        static std::default_random_engine rng(
            static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
        std::normal_distribution<float> noise(0.0f, 1.0f);
        std::bernoulli_distribution spikeChance(0.15);

        if (spikeChance(rng)) {
            std::uniform_real_distribution<float> spike(5.0f, 20.0f);
            value += spike(rng);
            status = "SPIKE";
        } else {
            value += noise(rng);
            status = isFaulty() ? "HIGH" : "OK";
        }
        if (value > threshold + 10.0f) status = "CRITICAL";
    }

    std::string typeName() const override { return "TemperatureSensor"; }
};


class PressureSensor : public Sensor {
public:
    PressureSensor(int id_, float value_, float threshold_)
        : Sensor(id_, value_, threshold_) {}

    void simulateFault() override {
        static std::default_random_engine rng(
            static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count() + 123));
        std::normal_distribution<float> drift(0.0f, 0.5f);
        std::bernoulli_distribution leakChance(0.10);

        if (leakChance(rng)) {
            std::uniform_real_distribution<float> leak(-15.0f, -5.0f);
            value += leak(rng);
            status = "LEAK";
        } else {
            value += drift(rng);
            status = isFaulty() ? "HIGH" : "OK";
        }
    }

    std::string typeName() const override { return "PressureSensor"; }
};


class Actuator {
public:
    int id;
    std::string state;
    int responseTime;

    Actuator(int id_, const std::string& state_, int responseTime_)
        : id(id_), state(state_), responseTime(responseTime_) {}

    void triggerAction() {
        if (state == "Idle") state = "Active";
        else if (state == "Active") state = "Idle";
    }
};


class FaultLogger {
    std::string filename;
public:
    explicit FaultLogger(const std::string& fname = "faults.log")
        : filename(fname) {
        std::ofstream ofs(filename, std::ios::trunc);
        ofs << "---- Fault Log Start ----\n";
    }

    void log(const Sensor& s) {
        std::ofstream ofs(filename, std::ios::app);
        auto t = std::chrono::system_clock::now();
        auto t_c = std::chrono::system_clock::to_time_t(t);
        ofs << std::put_time(std::localtime(&t_c), "%F %T") << " | "
            << s.typeName() << " id=" << s.id
            << " value=" << s.value
            << " threshold=" << s.threshold
            << " status=" << s.status << "\n";
    }
};


void logFault(Sensor* s) {
    if (!s) return;
    std::ofstream ofs("faults.log", std::ios::app);
    auto t = std::chrono::system_clock::now();
    auto t_c = std::chrono::system_clock::to_time_t(t);
    ofs << std::put_time(std::localtime(&t_c), "%F %T") << " | "
        << s->typeName() << " id=" << s->id
        << " value=" << s->value
        << " threshold=" << s->threshold
        << " status=" << s->status << " (global log)\n";
}


class FaultInjector {
public:
    std::vector<Sensor*> sensors;
    std::vector<Actuator*> actuators;

    void injectSensorFault(Sensor* s) {
        if (!s) return;
        s->simulateFault();
        if (s->isFaulty()) s->status = "FAULTY";
    }

    void injectActuatorDelay(Actuator& a) {
        a.responseTime += 100;
        a.state = "Delayed";
    }

    void injectAllFaults() {
        for (Sensor* s : sensors) {
            if (s) {
                s->simulateFault();
                if (s->isFaulty()) s->status = "FAULTY";
            }
        }
        for (Actuator* a : actuators) {
            if (a) {
                static std::default_random_engine rng(
                    static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count() + 42));
                std::bernoulli_distribution d(0.3);
                if (d(rng)) injectActuatorDelay(*a);
            }
        }
    }

    void reportStatus() {
        std::cout << "---- Injector Report ----\n";
        std::cout << "Sensors:\n";
        for (Sensor* s : sensors) {
            std::cout << "  [" << s->typeName() << "] id=" << s->id
                      << " value=" << s->value
                      << " thr=" << s->threshold
                      << " status=" << s->status << "\n";
        }
        std::cout << "Actuators:\n";
        for (Actuator* a : actuators) {
            std::cout << "  Actuator id=" << a->id
                      << " state=" << a->state
                      << " responseTime=" << a->responseTime << "ms\n";
        }
        std::cout << "-------------------------\n";
    }
};


void analyzeSystem(FaultInjector* fi) {
    if (!fi) return;
    int faultySensors = 0;
    for (auto s : fi->sensors) { if (s && s->isFaulty()) ++faultySensors; }
    int delayedAct = 0;
    for (auto a : fi->actuators) { if (a && a->state == "Delayed") ++delayedAct; }

    std::ofstream ofs("faults.log", std::ios::app);
    auto t = std::chrono::system_clock::now();
    auto t_c = std::chrono::system_clock::to_time_t(t);
    ofs << std::put_time(std::localtime(&t_c), "%F %T")
        << " | analyzeSystem: faultySensors=" << faultySensors
        << " delayedActuators=" << delayedAct << "\n";
}

class ConfigManager {
public:
    void updateThreshold(Sensor& s, float newThreshold) {
        s.threshold = newThreshold;
    }
};


class SimulationEngine {
    ConfigManager& cfg;
    FaultLogger* logger;
    FaultInjector injector;

public:
    SimulationEngine(ConfigManager& cfg_, FaultLogger* logger_)
        : cfg(cfg_), logger(logger_) {}

    FaultInjector* getInjector() { return &injector; }

    void runCycles(int cycles = 3) {
        for (int c = 0; c < cycles; ++c) {
            std::cout << "\n=== Simulation cycle " << (c+1) << " ===\n";
            injector.injectAllFaults();

            for (Sensor* s : injector.sensors) {
                if (s && s->isFaulty()) {
                    if (logger) logger->log(*s);
                    logFault(s);
                }
            }
            for (Actuator* a : injector.actuators) {
                if (a) a->triggerAction();
            }
            injector.reportStatus();
            analyzeSystem(&injector);
        }
    }

    void changeThreshold(Sensor& s, float newThreshold) {
        cfg.updateThreshold(s, newThreshold);
    }
};


int main() {
    ConfigManager cfg;
    FaultLogger logger("faults.log");
    SimulationEngine engine(cfg, &logger);
    FaultInjector* fi = engine.getInjector();


    TemperatureSensor* t1 = new TemperatureSensor(101, 95.0, 90.0);
    PressureSensor* p1   = new PressureSensor(102, 45.0, 50.0);
    TemperatureSensor* t2 = new TemperatureSensor(103, 88.0, 90.0);

    Actuator* a1 = new Actuator(201, "Idle", 120);
    Actuator* a2 = new Actuator(202, "Idle", 200);

    fi->sensors.push_back(t1);
    fi->sensors.push_back(p1);
    fi->sensors.push_back(t2);
    fi->actuators.push_back(a1);
    fi->actuators.push_back(a2);

    
    engine.changeThreshold(*t1, 85.0);

    
    engine.runCycles(3);

    
    for (Sensor* s : fi->sensors) delete s;
    for (Actuator* a : fi->actuators) delete a;
    fi->sensors.clear();
    fi->actuators.clear();

    std::cout << "\nSimulation finished. Check 'faults.log'.\n";
    return 0;
}
