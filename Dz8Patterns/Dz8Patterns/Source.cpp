#include <iostream>
#include <clocale>

using namespace std;

class IPrint 
{
public:
    virtual void PrintDevice() abstract;
};

class VideoCard : public IPrint 
{
public:
    void PrintDevice() override 
    {
        cout << "Видеокарта: высокая производительность, 8ГБ видеопамяти." << endl;
    }
};

class Processor : public IPrint 
{
public:
    void PrintDevice() override 
    {
        cout << "Процессор: 8 ядер, 3.6ГГц." << endl;
    }
};

class HardDrive : public IPrint 
{
public:
    void PrintDevice() override 
    {
        cout << "Жесткий диск: 1ТБ, SSD." << endl;
    }
};

class RAM : public IPrint 
{
public:
    void PrintDevice() override 
    {
        cout << "Оперативная память: 16ГБ, 3200МГц." << endl;
    }
};

class DeviceReport 
{
protected:
    IPrint* device;
public:
    DeviceReport(IPrint* device) : device(device) {}

    void PrintReport() const 
    {
        device->PrintDevice();
    }
};


int main() 
{
    setlocale(LC_ALL, "Russian");

    VideoCard videoCard;
    Processor processor;
    HardDrive hardDrive;
    RAM ram;

    DeviceReport videoCardReport(&videoCard);
    DeviceReport processorReport(&processor);
    DeviceReport hardDriveReport(&hardDrive);
    DeviceReport ramReport(&ram);

    cout << "Отчёт об устройствах:" << endl;

    cout << "Видеокарта:" << endl;
    videoCardReport.PrintReport();

    cout << "Процессор:" << endl;
    processorReport.PrintReport();

    cout << "Жесткий диск:" << endl;
    hardDriveReport.PrintReport();

    cout << "Оперативная память:" << endl;
    ramReport.PrintReport();

    return 0;
}