#include <iostream>
#include <list>
#include <map>
#include <vector>

class Company {
public:
    std::map<std::string, int> employees;

    void addEmployee(std::string name, int salary) {
        employees[name] = salary;
    }

    std::pair<std::string, int> GetHighPaid() {
        std::pair<std::string, int> HighPaidEmp;
        int maxSalary = 0;

        for (auto employee : employees) {
            if (employee.second > maxSalary) {
                HighPaidEmp = employee;
                maxSalary = employee.second;
            }
        }

        return HighPaidEmp;
    }
};

class Companies {
private:
    std::list<Company> companiesList;

public:
    void addCompany(Company company) {
        companiesList.push_back(company);
    }

    void printAllEmployees() {
        for (auto company : companiesList) {
            std::cout << "Компания:" << std::endl;
            for (auto employee : company.employees) {
                std::cout << "Фамилия: " << employee.first << ", Зарплата: " << employee.second << std::endl;
            }
        }
    }

        std::vector<std::pair<std::string, int>> getHighestPaidEmployees() {
        std::vector<std::pair<std::string, int>> highestPaidEmployees;

        for (auto company : companiesList) {
            auto highestPaid = company.GetHighPaid();
            highestPaidEmployees.push_back(highestPaid);
        }

        return highestPaidEmployees;
    }
};

int main() {
    setlocale(0, "Russian");
    
    Companies companies;

    Company company1;
    company1.addEmployee("Tony", 1'400'000);
    company1.addEmployee("Steve", 80'000);

    Company company2;
    company2.addEmployee("Blade", 10'000);
    company2.addEmployee("Wolverine", 1'180'000);

    companies.addCompany(company1);
    companies.addCompany(company2);

    std::cout << "Все сотрудники всех компаний:" << std::endl;
    companies.printAllEmployees();

    std::cout << "\nСамые высокооплачиваемые сотрудники:" << std::endl;
    auto highestPaidEmployees = companies.getHighestPaidEmployees();
    for (auto employee : highestPaidEmployees) {
        std::cout << "Фамилия: " << employee.first << ", Зарплата: " << employee.second << std::endl;
    }


    return 0;
}