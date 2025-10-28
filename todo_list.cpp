#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void showMenu() {
    cout << "\n===== To-Do List Menu =====" << endl;
    cout << "1. View Tasks" << endl;
    cout << "2. Add Task" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
}

void viewTasks() {
    ifstream file("tasks.txt");
    string task;
    int count = 1;

    cout << "\n📋 Your Tasks:" << endl;
    if (!file) {
        cout << "No tasks found!" << endl;
        return;
    }

    while (getline(file, task)) {
        cout << count++ << ". " << task << endl;
    }
    file.close();
}

void addTask() {
    ofstream file("tasks.txt", ios::app);
    string task;
    cout << "Enter a new task: ";
    cin.ignore();
    getline(cin, task);
    file << task << endl;
    file.close();
    cout << "✅ Task added successfully!" << endl;
}

void deleteTask() {
    vector<string> tasks;
    ifstream file("tasks.txt");
    string task;
    while (getline(file, task)) {
        tasks.push_back(task);
    }
    file.close();

    if (tasks.empty()) {
        cout << "No tasks to delete!" << endl;
        return;
    }

    int choice;
    cout << "\nEnter the task number to delete: ";
    cin >> choice;

    if (choice < 1 || choice > tasks.size()) {
        cout << "Invalid choice!" << endl;
        return;
    }

    tasks.erase(tasks.begin() + choice - 1);
    ofstream outfile("tasks.txt");
    for (auto &t : tasks) outfile << t << endl;
    outfile.close();

    cout << "🗑️ Task deleted successfully!" << endl;
}

int main() {
    int option;
    do {
        showMenu();
        cin >> option;
        switch (option) {
            case 1: viewTasks(); break;
            case 2: addTask(); break;
            case 3: deleteTask(); break;
            case 4: cout << "Exiting... 👋" << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (option != 4);

    return 0;
}
