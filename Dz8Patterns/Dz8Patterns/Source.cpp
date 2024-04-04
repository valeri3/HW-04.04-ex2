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
        cout << "����������: ������� ������������������, 8�� �����������." << endl;
    }
};

class Processor : public IPrint 
{
public:
    void PrintDevice() override 
    {
        cout << "���������: 8 ����, 3.6���." << endl;
    }
};

class HardDrive : public IPrint 
{
public:
    void PrintDevice() override 
    {
        cout << "������� ����: 1��, SSD." << endl;
    }
};

class RAM : public IPrint 
{
public:
    void PrintDevice() override 
    {
        cout << "����������� ������: 16��, 3200���." << endl;
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

    cout << "����� �� �����������:" << endl;

    cout << "����������:" << endl;
    videoCardReport.PrintReport();

    cout << "���������:" << endl;
    processorReport.PrintReport();

    cout << "������� ����:" << endl;
    hardDriveReport.PrintReport();

    cout << "����������� ������:" << endl;
    ramReport.PrintReport();

    return 0;
}