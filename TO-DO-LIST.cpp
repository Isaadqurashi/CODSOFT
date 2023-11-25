#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}
};

class TodoList
{
private:
    vector<Task> tasks;

public:
    void addTask(const string &desc)
    {
        tasks.push_back(Task(desc));
        cout << "Task added: " << desc << endl;
    }

    void viewTasks() const
    {
        if (tasks.empty())
        {
            cout << "No tasks in the list." << endl;
        }
        else
        {
            cout << "Tasks in the list:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i)
            {
                cout << i + 1 << ". " << tasks[i].description;
                if (tasks[i].completed)
                {
                    cout << " [Completed]";
                }
                else
                {
                    cout << " [Pending]";
                }
                cout << endl;
            }
        }
    }

    void markTaskAsCompleted(size_t index)
    {
        if (index >= 1 && index <= tasks.size())
        {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        }
        else
        {
            cout << "Invalid task index. Please enter a valid index." << endl;
        }
    }

    void removeTask(size_t index)
    {
        if (index >= 1 && index <= tasks.size())
        {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        }
        else
        {
            cout << "Invalid task index. Please enter a valid index." << endl;
        }
    }
};

int main()
{
    TodoList todoList;

    int choice;
    string taskDescription;
    size_t taskIndex;

    cout << "\n\n\t\t\t***********************************************************\n";
    cout << "\t\t\t*                                                         *\n";
    cout << "\t\t\t*             WELCOME  TO  YOUR  TODO  LIST               *\n";
    cout << "\t\t\t*                                                         *\n";
    cout << "\t\t\t***********************************************************\n";
    do
    {
        cout << "\nTodo List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, taskDescription);
            todoList.addTask(taskDescription);
            break;

        case 2:
            todoList.viewTasks();
            break;

        case 3:
            cout << "Enter the index of the task to mark as completed: ";
            cin >> taskIndex;
            todoList.markTaskAsCompleted(taskIndex);
            break;

        case 4:
            cout << "Enter the index of the task to remove: ";
            cin >> taskIndex;
            todoList.removeTask(taskIndex);
            break;

        case 5:
            cout << "Exiting the Todo List. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 5);
}
