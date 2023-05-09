#include "EnumeratingLocalDisks.h"


std::vector<std::string> EnumeratingLocalDisks(BOOL Cout)
{
    try
    {
        std::vector<std::string> Disk;
        std::vector<std::string> SysNet;
        std::vector<unsigned long long> Total;

        std::vector<std::string> err{ "ERROR" };

        char LogicalDisks[512];
        char LogicalDisksName[512];
        char SystemNet[512];

        unsigned long long lpTotalNumberOfBytes;
        unsigned long long lpTotalNumberOfFreeBytes;

        // Getting Disks
        DWORD LogicalDisksLen{ GetLogicalDriveStringsA(sizeof(LogicalDisks), LogicalDisks) };


        DWORD i{ 0 };
        do
        {
            if (i == 0)
            {
                // Getting Name Toms and File System Tom
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

                if (GetInfoDisk == FALSE)
                {
                    std::cerr << "ERROR -> Failed to Get Disk information" << std::endl;
                    return err;
                }

                // Getting the volume size in bytes
                BOOL GetDiskFreeSpace = GetDiskFreeSpaceExA(
                    LogicalDisks,
                    NULL,
                    (PULARGE_INTEGER)&lpTotalNumberOfBytes,
                    (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes
                );

                if (GetDiskFreeSpace == FALSE)
                {
                    std::cerr << "ERROR -> Failed to Get Disk Free space" << std::endl;
                    return err;
                }


                if (Cout)
                    std::cout << "\t" << LogicalDisks << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << " Bytes" << std::endl;


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

                if (GetVoluInfoDisk == FALSE)
                {
                    std::cerr << "ERROR -> Failed to Get Disk information" << std::endl;
                    return err;
                }

                // Getting the volume size in bytes
                BOOL GetDiskFree = GetDiskFreeSpaceExA(
                    LogicalDisks + i + 1,
                    NULL,
                    (PULARGE_INTEGER)&lpTotalNumberOfBytes,
                    (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes
                );

                if (GetDiskFree == FALSE)
                {
                    std::cerr << "ERROR -> Failed to Get Disk Free space" << std::endl;
                    return err;
                }


                if (Cout)
                    std::cout << "\t" << LogicalDisks + i + 1 << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << " Bytes" << std::endl;

                Disk.push_back(LogicalDisks + i + 1);
                SysNet.push_back(SystemNet);
                Total.push_back(lpTotalNumberOfBytes);
            }

            i += 1;

        } while (i < LogicalDisksLen - 2);

        return Disk;
    }
    catch (const std::exception& ex)
    {
        std::cout << "--- Exception Command 1 ---" << std::endl;
        std::cout << &ex << std::endl;
    }
}
