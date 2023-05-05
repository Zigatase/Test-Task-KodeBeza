#include "Include.h"


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
                std::cout << LogicalDisks << std::endl;

            if (LogicalDisks[i] == 0)
            {
                std::cout << LogicalDisks + i + 1 << std::endl;
            }

            i += 1;
        } while (i < LogicalDisksLen - 2);
    }

};


//
void EnumeratingLocalDisks();
void EnumerationsOfAllFiles();
void CollectingInformation();


// --- Main ---
int main()
{
    EnumerationsOfAllFiles();

    system("pause");

    return 0;
}


// --- Part #1 ---
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

            // Getting the volume size in bytes
            BOOL Get = GetDiskFreeSpaceExA(
                LogicalDisks,
                NULL,
                (PULARGE_INTEGER)&lpTotalNumberOfBytes,
                (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes
            );

            std::cout << LogicalDisks << LogicalDisksName << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << std::endl;
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

            std::cout << LogicalDisks + i + 1 << LogicalDisksName << "\t" << SystemNet << "\t" << lpTotalNumberOfBytes << std::endl;
        }

        i += 1;
    } while (i < LogicalDisksLen - 2);
}


// --- Part #2 ---
void EnumerationsOfAllFiles()
{
    WIN32_FIND_DATAW wfd;

    HANDLE const hFind = FindFirstFileW(L"C:\\*", &wfd);

    setlocale(LC_ALL, "rus");

    if (INVALID_HANDLE_VALUE != hFind)
    {
        do
        {
            if (wfd.cFileName[0] != '.' && wfd.cFileName[0] != '..')
            {
                SYSTEMTIME time;

                FileTimeToSystemTime(&wfd.ftCreationTime, &time);

                //
                std::wcout << &wfd.cFileName[0] << "\t" << time.wYear << "\\" << time.wMonth << "\\" << time.wDay << "\t" << time.wHour + 3 << ":" << time.wMinute << std::endl;
            }
        } while (0 != FindNextFileW(hFind, &wfd));

        FindClose(hFind);
    }

}


// --- Part #3 ---
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

    std::cout << username << "\t" << pcName << std::endl;
}