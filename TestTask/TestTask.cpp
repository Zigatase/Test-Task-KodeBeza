#include "Include.h"

using namespace std;

//
class GetLocalDrive
{
private:
    char LogicalDisks[512];
    char LogicalDisksName[512];

public:
    void test()
    {
        //
        DWORD LogicalDisksLen{ GetLogicalDriveStringsA(sizeof(LogicalDisks), LogicalDisks) };

        //
        BOOL test = GetVolumeInformationA(
            "P:\\",
            LogicalDisksName,
            sizeof(LogicalDisksName),
            NULL,
            NULL,
            NULL,
            NULL,
            0
        );


        DWORD i{ 0 };
        do
        {
            if (i == 0)
                cout << LogicalDisks << endl;

            if (LogicalDisks[i] == 0)
            {
                cout << LogicalDisks + i + 1 << endl;
            }

            i += 1;
        } while (i < LogicalDisksLen - 2);
    }

};

//
void EnumeratingLocalDisks();
void EnumerationsOfAllFiles();
void CollectingInformation();

//
int main()
{
    CollectingInformation();

    return 0;
}


// Part #1
void EnumeratingLocalDisks()
{
    //
    char LogicalDisks[512];
    char LogicalDisksName[512];
    char SystemNet[512];

    //
    DWORD Num;

    //
    unsigned long long lpTotalNumberOfBytes;
    unsigned long long lpTotalNumberOfFreeBytes;


    //
    DWORD LogicalDisksLen{ GetLogicalDriveStringsA(sizeof(LogicalDisks), LogicalDisks) };


    DWORD i{ 0 };
    do
    {
        if (i == 0)
        {
            // Get Name Toms and File System Tom
            BOOL GetVoluInfoDisk = GetVolumeInformationA(
                LogicalDisks,
                LogicalDisksName,
                sizeof(LogicalDisksName),
                &Num,
                NULL,
                NULL,
                SystemNet,
                sizeof(SystemNet)
            );

            cout << LogicalDisks << LogicalDisksName << endl;
        }

        if (LogicalDisks[i] == 0)
        {
            // Getting Name Toms and File System Tom
            BOOL GetVoluInfoDisk = GetVolumeInformationA(
                LogicalDisks + i + 1,
                LogicalDisksName,
                sizeof(LogicalDisksName),
                &Num,
                NULL,
                NULL,
                SystemNet,
                sizeof(SystemNet)
            );

            // Getting the volume size in bytes
            BOOL Get = GetDiskFreeSpaceExA(
                LogicalDisks,
                NULL,
                (PULARGE_INTEGER)&lpTotalNumberOfBytes,
                (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes
            );

            cout << LogicalDisks + i + 1 << LogicalDisksName << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << endl;
        }

        i += 1;
    } while (i < LogicalDisksLen - 2);
}


// Part #2
void EnumerationsOfAllFiles()
{

}


// Part #3
void CollectingInformation()
{
    //
    char username[256];
    char pcName[256];

    DWORD sizeUsername = 256;
    DWORD sizePcName = 256;

    //
    GetUserNameA(username, &sizeUsername);
    GetComputerNameA(pcName, &sizePcName);

    cout << username << pcName << endl;
}