#include <iostream>
#include <string>
using namespace std;

//abstract Base
class Employee {
protected: // put as protected otherwise wasn't able to reach tasks..
	string name;
	int id;
	string email;
	string tasks[3];
	int salary;

public:
	Employee(string n, int i, string e, string t[], int s) :
		name(n), id(i), email(e), salary(s) {
		for (int i = 0; i < 3; i++) {
			this->tasks[i] = t[i];
		}
	}
	virtual ~Employee() {}

	virtual void displayTasks() const = 0; //pure virtual method

	//getters
	string getName() const { return name; }
	int getId() const { return id; }
	string getEmail() const { return email; }
	int getSalary() const { return salary; }
};


class Supervisor : public Employee {
public:
	Supervisor(string name, int id, string email, string tasks[], int salary) :
		Employee(name, id, email, tasks, salary) {}

	//overrided 
	void displayTasks() const override {
		cout << "As a supervisor i do: ";
		for (int i = 0; i < 3; i++) {
			cout << tasks[i] << (i < 2 ? " " : ""); //add space between tasks using ternary))) Ternary is so cool btw didn't know about it before the course
		}
		cout << endl; // backspace to avoid next employee text on the same line
	}
};


class Regular : public Employee {
public:
	Regular(string name, int id, string email, string tasks[], int salary) :
		Employee(name, id, email, tasks, salary) {}

	//overrided
	void displayTasks() const override {
		cout << "As a regular I do: ";
		for (int i = 0; i < 3; i++) {
			cout << tasks[i] << (i < 2 ? " " : "");
		}
		cout << endl;
	}
};


class WorkEnvironment {
private:
	Employee** employees;
	int numEmployees;

public:
	WorkEnvironment() : employees(0), numEmployees(0) {}

	~WorkEnvironment() { //freeing ram, deleting each employee to avoud leakage
		for (int i = 0; i < numEmployees; i++) {
			delete employees[i];
		}
		delete[] employees;
	}

	//adding through pointing to base class
	void addEmployee(Employee* employee) {
		//new array to copy employees
		Employee** newEmployees = new Employee * [numEmployees + 1];
		for (int i = 0; i < numEmployees; i++) {
			newEmployees[i] = employees[i]; //copying to new array
		}
		//add them
		newEmployees[numEmployees] = employee;
		delete[] employees; //freeing old array
		employees = newEmployees; //pointing to new
		numEmployees++;
	}

	void displayEmployeeTasks() const {
		cout << "\n Employee tasks: \n";
		for (int i = 0; i < numEmployees; i++) {
			employees[i]->displayTasks();
		}
	}
};

int main() {
	WorkEnvironment workEnvironment;
	Employee* employee = nullptr;

	int numEmployees = 0;
	string name, email;
	int id, salary = 0;
	string tasks[3];
	int choose = 0;


	cout << "How many employees: ?";
	cin >> numEmployees;
	cin.ignore(); //buffers

	//asking for details
	for (int i = 0; i < numEmployees; i++) {
		cout << "Enter details for Employe #" << i + 1 << " :";
		cout << "Name:";
		getline(cin, name);
		cout << "ID: ";
		cin >> id;
		cout << "Email:";
		cin >> email;
		cout << "salary:";
		cin >> salary;
		cin.ignore(); //clearing buffers before tasks

		cout << "Enter tasks (3): ";
		for (int i = 0; i < 3; i++) {
			cin >> tasks[i];
		}

		cout << "Is this a Supervisor (1) or Regular (2)? ";
		cin >> choose;
		cin.ignore();

		switch (choose) {
		case 1: employee = new Supervisor(name, id, email, tasks, salary);
			break;
		case 2:employee = new Regular(name, id, email, tasks, salary);
			break;
		default: cout << "Invalid option!";
		}

		workEnvironment.addEmployee(employee);
	}
	workEnvironment.displayEmployeeTasks();

	return 0;
}
