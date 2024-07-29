#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Employee {
public:
    int id;
    std::string name;
    std::vector<std::string> attendance;

    Employee(int id, std::string name) : id(id), name(name) {}

    void markAttendance() {
        time_t now = time(0);
        std::string dt = ctime(&now);
        attendance.push_back(dt);
    }

    void displayAttendance() {
        std::cout << "\033[1;34mAttendance records for " << name << ":\n\033[0m";
        for (const auto& date : attendance) {
            std::cout << date;
        }
    }
};

class AttendanceSystem {
private:
    std::vector<Employee> employees;

    Employee* findEmployeeById(int id) {
        for (auto& employee : employees) {
            if (employee.id == id) {
                return &employee;
            }
        }
        return nullptr;
    }

public:
    void addEmployee(int id, const std::string& name) {
        employees.emplace_back(id, name);
    }

    void markAttendance(int id) {
        Employee* employee = findEmployeeById(id);
        if (employee) {
            employee->markAttendance();
            std::cout << "\033[1;32mAttendance marked for " << employee->name << "\n\033[0m";
        } else {
            std::cout << "\033[1;31mEmployee not found!\n\033[0m";
        }
    }

    void displayAttendance(int id) {
        Employee* employee = findEmployeeById(id);
        if (employee) {
            employee->displayAttendance();
        } else {
            std::cout << "\033[1;31mEmployee not found!\n\033[0m";
        }
    }

    void displayAllEmployees() {
        std::cout << "\033[1;33mEmployees:\n\033[0m";
        for (const auto& employee : employees) {
            std::cout << "\033[1;36mID: " << employee.id << ", Name: " << employee.name << "\n\033[0m";
        }
    }
};

int main() {
    std::cout << "\033[1;35mWelcome to BOON COMPANY LIMITED Attendance System\n\033[0m";
    
    AttendanceSystem system;

    // Adding 10 employees
    system.addEmployee(1, "Ram");
    system.addEmployee(2, "Sita");
    system.addEmployee(3, "Hari");
    system.addEmployee(4, "Gita");
    system.addEmployee(5, "Kedar");
    system.addEmployee(6, "Chandrakala");
    system.addEmployee(7, "Dhurba");
    system.addEmployee(8, "Rukmati");
    system.addEmployee(9, "Badri");
    system.addEmployee(10, "Kumari");

    int choice, id;
    std::string name;

    while (true) {
        std::cout << "\n\033[1;35mAttendance System Menu\n\033[0m";
        std::cout << "1. Add Employee\n";
        std::cout << "2. Mark Attendance\n";
        std::cout << "3. Display Attendance\n";
        std::cout << "4. Display All Employees\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Employee ID: ";
                std::cin >> id;
                std::cout << "Enter Employee Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                system.addEmployee(id, name);
                break;
            case 2:
                std::cout << "Enter Employee ID: ";
                std::cin >> id;
                system.markAttendance(id);
                break;
            case 3:
                std::cout << "Enter Employee ID: ";
                std::cin >> id;
                system.displayAttendance(id);
                break;
            case 4:
                system.displayAllEmployees();
                break;
            case 5:
                return 0;
            default:
                std::cout << "\033[1;31mInvalid choice! Please try again.\n\033[0m";
        }
    }
}
