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
    cout << "Список автобусів для маршруту " << routeNumber << ":" << endl;
    for (const auto& bus : buses) {
        if (bus.routeNumber == routeNumber) {
            cout << "Водій: " << bus.driver << ", Номер автобуса: " << bus.busNumber
                << ", Марка: " << bus.brand << ", Рік початку експлуатації: "
                << bus.startYear << ", Пробіг: " << bus.mileage << " км" << endl;
        }
    }
}

void listBusesOverTenYears(const vector<Bus>& buses, int currentYear) {
    cout << "Список автобусів, які експлуатуються більше 10 років:" << endl;
    for (const auto& bus : buses) {
        if (currentYear - bus.startYear > 10) {
            cout << "Водій: " << bus.driver << ", Номер автобуса: " << bus.busNumber
                << ", Марка: " << bus.brand << ", Рік початку експлуатації: "
                << bus.startYear << ", Пробіг: " << bus.mileage << " км" << endl;
        }
    }
}

void listBusesByMileage(const vector<Bus>& buses, int mileageThreshold) {
    cout << "Список автобусів, пробіг у яких більше " << mileageThreshold << " км:" << endl;
    for (const auto& bus : buses) {
        if (bus.mileage > mileageThreshold) {
            cout << "Водій: " << bus.driver << ", Номер автобуса: " << bus.busNumber
                << ", Марка: " << bus.brand << ", Рік початку експлуатації: "
                << bus.startYear << ", Пробіг: " << bus.mileage << " км" << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    vector<Bus> buses = {
        Bus("Іванов І.І.", 101, 5, "Mercedes", 2012, 15000),
        Bus("Петров П.П.", 102, 5, "MAN", 2008, 25000),
        Bus("Сидоров С.С.", 103, 7, "Volvo", 2015, 12000),
        Bus("Кузнецов К.К.", 104, 7, "Scania", 2010, 9000),
        Bus("Лебедєв Л.Л.", 105, 8, "Iveco", 2005, 30000)
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