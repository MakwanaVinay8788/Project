#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "==============================\n";
}

void addTask(vector<Task> &tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        cout << "===== Task List =====\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            cout << (tasks[i].completed ? "[X] " : "[ ] ");
            cout << tasks[i].description << endl;
        }
        cout << "======================\n";
    }
}

void deleteTask(vector<Task> &tasks) {
    viewTasks(tasks);
    if (tasks.empty()) {
        cout << "No tasks to delete.\n";
    } else {
        int index;
        cout << "Enter the task number to delete: ";
        cin >> index;
        if (index >= 1 && index <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task deleted successfully!\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
}

int main() {
    vector<Task> tasks;

    int choice;

    do {
        displayMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}

