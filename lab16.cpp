#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bus {
public:
    string driver;
    int busNumber;
    int routeNumber;
    string brand;
    int startYear;
    int mileage;

    Bus(string d, int bN, int rN, string br, int sY, int m)
        : driver(d), busNumber(bN), routeNumber(rN), brand(br), startYear(sY), mileage(m) {}
};

void listBusesByRouteNumber(const vector<Bus>& buses, int routeNumber) {
    cout << "������ �������� ��� �������� " << routeNumber << ":" << endl;
    for (const auto& bus : buses) {
        if (bus.routeNumber == routeNumber) {
            cout << "����: " << bus.driver << ", ����� ��������: " << bus.busNumber
                << ", �����: " << bus.brand << ", г� ������� ������������: "
                << bus.startYear << ", �����: " << bus.mileage << " ��" << endl;
        }
    }
}

void listBusesOverTenYears(const vector<Bus>& buses, int currentYear) {
    cout << "������ ��������, �� �������������� ����� 10 ����:" << endl;
    for (const auto& bus : buses) {
        if (currentYear - bus.startYear > 10) {
            cout << "����: " << bus.driver << ", ����� ��������: " << bus.busNumber
                << ", �����: " << bus.brand << ", г� ������� ������������: "
                << bus.startYear << ", �����: " << bus.mileage << " ��" << endl;
        }
    }
}

void listBusesByMileage(const vector<Bus>& buses, int mileageThreshold) {
    cout << "������ ��������, ����� � ���� ����� " << mileageThreshold << " ��:" << endl;
    for (const auto& bus : buses) {
        if (bus.mileage > mileageThreshold) {
            cout << "����: " << bus.driver << ", ����� ��������: " << bus.busNumber
                << ", �����: " << bus.brand << ", г� ������� ������������: "
                << bus.startYear << ", �����: " << bus.mileage << " ��" << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    vector<Bus> buses = {
        Bus("������ �.�.", 101, 5, "Mercedes", 2012, 15000),
        Bus("������ �.�.", 102, 5, "MAN", 2008, 25000),
        Bus("������� �.�.", 103, 7, "Volvo", 2015, 12000),
        Bus("�������� �.�.", 104, 7, "Scania", 2010, 9000),
        Bus("������ �.�.", 105, 8, "Iveco", 2005, 30000)
    };

    int routeNumber = 5;
    int currentYear = 2024;
    int mileageThreshold = 10000;

    listBusesByRouteNumber(buses, routeNumber);
    cout << endl;
    listBusesOverTenYears(buses, currentYear);
    cout << endl;
    listBusesByMileage(buses, mileageThreshold);

    return 0;
}