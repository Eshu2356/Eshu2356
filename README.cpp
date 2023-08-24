
#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string name;
    std::string dueDate;
    int priority;
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        }
    }

    void listTasks() {
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << "[" << i + 1 << "] ";
            std::cout << "Task: " << tasks[i].name << " | ";
            std::cout << "Due Date: " << tasks[i].dueDate << " | ";
            std::cout << "Priority: " << tasks[i].priority << std::endl;
        }
    }
};

int main() {
    TaskManager taskManager;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. List Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            Task task;
            std::cout << "Enter task name: ";
            std::cin.ignore(); // Clear the newline character from the buffer
            std::getline(std::cin, task.name);
            std::cout << "Enter due date: ";
            std::cin >> task.dueDate;
            std::cout << "Enter priority (1-10): ";
            std::cin >> task.priority;
            taskManager.addTask(task);
        } else if (choice == 2) {
            int index;
            std::cout << "Enter task index to remove: ";
            std::cin >> index;
            taskManager.removeTask(index - 1);
        } else if (choice == 3) {
            taskManager.listTasks();
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
