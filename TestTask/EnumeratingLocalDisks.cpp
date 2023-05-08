#include "EnumeratingLocalDisks.h"


// --- Task #1 ---
std::vector<std::string> EnumeratingLocalDisks()
{
    setlocale(LC_ALL, "rus");

    std::vector<std::string> Disk;
    std::vector<std::string> SysNet;
    std::vector<unsigned long long> Total;

    //
    char LogicalDisks[512];
    char LogicalDisksName[512];
    char SystemNet[512];

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
                NULL,
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

            // DBG std::cout << LogicalDisks << LogicalDisksName << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes  << " Bytes" << std::endl;
            std::cout << LogicalDisks << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes  << " Bytes" << std::endl;


            Disk.push_back(LogicalDisks);
            SysNet.push_back(SystemNet);
            Total.push_back(lpTotalNumberOfBytes);
        }

        if (LogicalDisks[i] == 0)
        {
            // Getting Name Toms and File System Tom
            BOOL GetVoluInfoDisk = GetVolumeInformationA(
                LogicalDisks + i + 1,
                LogicalDisksName,
                sizeof(LogicalDisksName),
                NULL,
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

            // DBG std::cout << LogicalDisks + i + 1 << LogicalDisksName << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << " Bytes" << std::endl;
            std::cout << LogicalDisks + i + 1 << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << " Bytes" << std::endl;


            Disk.push_back(LogicalDisks + i + 1);
            SysNet.push_back(SystemNet);
            Total.push_back(lpTotalNumberOfBytes);
        }

        i += 1;
    } while (i < LogicalDisksLen - 2);

    return Disk;
}
