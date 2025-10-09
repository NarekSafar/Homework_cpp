#include <iostream>
#include <vector>
#include <forward_list>

class TaskManager {
private:
    std::vector<std::forward_list<std::string>> tasks; 
public:
    TaskManager(int levels = 3) { 
        tasks.resize(levels);
    }

    void addTask(int priority, const std::string& task) {
        if (priority >= 0 && priority < tasks.size()) {
            auto prev = tasks[priority].before_begin();
            for(auto curr = tasks[priority].begin(); curr != tasks[priority].end(); ++curr) {
                prev = curr;    
            }
            tasks[priority].insert_after(prev, task);
        }
    }

    std::string getNextTask() {
        for (int i = 0; i < tasks.size(); ++i) {
            if (!tasks[i].empty()) {
                std::string next = tasks[i].front();
                tasks[i].pop_front();
                return next;
            }
        }
        return "No tasks available!";
    }

    void removeTask(int priority, const std::string& task) {
        if (priority < 0 || priority >= tasks.size()) {
            return;
        }

        std::forward_list<std::string> fl = tasks[priority];
        auto prev = fl.before_begin();
        for (auto it = fl.begin(); it != fl.end(); ++it) {
            if (*it == task) {            
                fl.erase_after(prev);
                return;
            }
            prev = it;
        }
    }

    void printAllTasks() const {
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << "Priority " << i << ":\n";
            if (tasks[i].empty()) {
                std::cout << "  (no tasks)\n";
                continue;
            }
            for (auto it = tasks[i].begin(); it != tasks[i].end(); ++it) {
                std::cout << "  - " << *it << "\n";
            }
        }
    }
};

int main() {
    TaskManager tm(3); 
    tm.addTask(0, "Fix critical bug");
    tm.addTask(2, "Update documentation");
    tm.addTask(0, "Deploy to production");
    tm.addTask(1, "Review pull request");
    std::string task = tm.getNextTask(); 
    std::cout << "Next task" << task << std::endl;
    tm.printAllTasks();
    return 0;
}
