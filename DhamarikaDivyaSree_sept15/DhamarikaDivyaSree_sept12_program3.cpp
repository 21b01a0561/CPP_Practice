#include <iostream>
#include <string>
using namespace std;


class Command {
public:
    string name;
    int duration;

    Command(const string& n, int d) : name(n), duration(d) {}
};


class CommandNode {
public:
    Command* cmd;
    CommandNode* next;

    CommandNode(Command* c) : cmd(c), next(nullptr) {}
};


class CommandExecutor {
public:
    void run(Command& c) {
        
        cout << "Executing: " << c.name << " (" << c.duration << "ms)" << endl;
    }
};


class CommandQueue {
public:
    CommandNode* head;

    CommandQueue() : head(nullptr) {}

    void enqueue(Command* c) {
        CommandNode* node = new CommandNode(c);
        if (!head) head = node;
        else {
            CommandNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = node;
        }
    }

  
    void executeAll() {
        CommandNode* current = head;
        while (current) {
            CommandNode* nextNode = current->next;
            CommandExecutor exec;
            exec.run(*current->cmd);

            delete current->cmd;
            delete current;

            current = nextNode;
        }
        head = nullptr; 
    }

    void printQueue() {
        
        if (!head) {
            cout << "Queue is empty." << endl;
        } else {
            CommandNode* temp = head;
            while (temp) {
                cout << temp->cmd->name << " (" << temp->cmd->duration << "ms)" << endl;
                temp = temp->next;
            }
        }
    }

    ~CommandQueue() {
        
        CommandNode* temp = head;
        while (temp) {
            CommandNode* nextNode = temp->next;
            delete temp->cmd;
            delete temp;
            temp = nextNode;
        }
    }
};


int main() {
    CommandQueue queue;


    queue.enqueue(new Command("Start Motor", 100));
    queue.enqueue(new Command("Open Valve", 50));
    queue.enqueue(new Command("Move Arm", 120));
    queue.enqueue(new Command("Stop Motor", 80));
    queue.enqueue(new Command("Close Valve", 60));
    
    cout << "--- Command Queue ---" << endl;
    queue.printQueue();

    cout << "\nExecuting all commands:\n";
    queue.executeAll();

    
    cout << "\nQueue after execution:\n";
    queue.printQueue();

    return 0;
}