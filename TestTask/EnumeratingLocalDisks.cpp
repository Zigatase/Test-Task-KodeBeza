#include "EnumeratingLocalDisks.h"


// --- Task #1 ---
void EnumeratingLocalDisks()
{
    setlocale(LC_ALL, "rus");

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
            BOOL GetInfoDisk = GetVolumeInformationA(
                LogicalDisks,
                LogicalDisksName,
                sizeof(LogicalDisksName),
                &Num,
                NULL,
                NULL,
                SystemNet,
                sizeof(SystemNet)
            );

            // Getting the volume size in bytes
            BOOL GetDiskFreeSpace = GetDiskFreeSpaceExA(
                LogicalDisks,
                NULL,
                (PULARGE_INTEGER)&lpTotalNumberOfBytes,
                (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes
            );

            std::cout << LogicalDisks << LogicalDisksName << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << " Bytes" << std::endl;
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
                LogicalDisks + i + 1,
                NULL,
                (PULARGE_INTEGER)&lpTotalNumberOfBytes,
                (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes
            );

            std::cout << LogicalDisks + i + 1 << LogicalDisksName << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << " Bytes" << std::endl;
        }

        i += 1;
    } while (i < LogicalDisksLen - 2);
}
