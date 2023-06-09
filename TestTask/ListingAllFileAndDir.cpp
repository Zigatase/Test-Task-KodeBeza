#include "ListingAllFileAndDir.h"


void ListingAllFileAndDir()
{
    try
    {
        std::vector<std::string> PathDir{ EnumeratingLocalDisks(FALSE) };


        for (int i = 0; i < PathDir.size(); i++)
        {
            //
            std::string path = PathDir[i] + "*";

            std::wstring wstrPath = std::wstring(path.begin(), path.end());
            const wchar_t* wcstrPath = wstrPath.c_str();

            WIN32_FIND_DATAW data;

            // Find First File
            HANDLE const hFind = FindFirstFileW((LPCWSTR)wcstrPath, &data);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                std::wcout << std::endl << "--- " << wstrPath << " ---" << std::endl;

                int totalDir{ 0 };
                int totalFile{ 0 };

                do
                {
                    if (data.cFileName[0] != '.' && data.cFileName[0] != '..')
                    {
                        SYSTEMTIME time;

                        FileTimeToSystemTime(&data.ftCreationTime, &time);

                        std::string s = "None";

                        // Checking an object to see if it is a folder if not then it is a file | All numeric values are taken from the MC. documentation.
                        if (data.dwFileAttributes == 16)
                        {
                            s = "DIR";
                            totalDir++;
                        }

                        // ���������� BIN � ��� ����� ����� CD ��� DVD, ������ �������� ������, ������������� � �������-����� ��� DVD.
                        else if (data.dwFileAttributes == 22)
                        {
                            s = "CD and DVD";
                        }

                        else if (data.dwFileAttributes == 8210)
                        {
                            s = "DIR";
                            totalDir++;
                        }

                        else if (data.dwFileAttributes == 18)
                        {
                            s = "DIR";
                            totalDir++;
                        }

                        else if (data.dwFileAttributes == 9238)
                        {
                            s = "DIR";
                            totalDir++;
                        }

                        else if (data.dwFileAttributes == 17)
                        {
                            s = "DIR";
                            totalDir++;
                        }

                        else if (data.dwFileAttributes == 8214)
                        {
                            s = "DIR";
                            totalDir++;
                        }

                        else
                        {
                            s = "FILE";
                            totalFile++;
                        }

                        //
                        std::wcout << "\t" << &data.cFileName[0] << "\t" << time.wYear << "\\" << time.wMonth << "\\" << time.wDay << "\t" << time.wHour + 3 << ":" << time.wMinute << "\t" << std::wstring(s.begin(), s.end()) << std::endl;
                    }
                } while (FindNextFileW(hFind, &data) != 0);

                std::cout << "\nTotal of folders: " << totalDir << "\t" << "Total of files: " << totalFile << std::endl;

                FindClose(hFind);
            }
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << "--- Exception Command 2 ---" << std::endl;
        std::cout << &ex << std::endl;
    }
}
