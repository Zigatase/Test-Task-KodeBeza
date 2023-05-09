#include "main.h"


// --- Main ---
int main()
{
    setlocale(LC_ALL, "rus");


    std::string command;

    std::cout << "Using the /help command, you can get the entire list of commands.\n" << std::endl;


    while (true)
    {
        std::cout << "\nCommand -> ";
        std::getline(std::cin, command);

        if (command == "/help")
        {
            std::cout << "\n" << std::endl;

            std::cout << "Command 1 --- Enumerates the local disks (logical volumes) of the workstation on which the application is running." << std::endl;
            std::cout << "\t* Volume name \n\t* Volume size in bytes \n\t* The name of the volume's file system (string designation of the file system type)\n" << std::endl;


            std::cout << "Command 2 --- Lists all files and folders located on each of the logical volumes. With the indication of their parameters:" << std::endl;
            std::cout << "\t* File/Folder name \n\t* The timestamp of the creation of this object in the format YYYY-MM-DD hh-mm \n\t* Object type (folder/file) \n\t* Total number of files \n\t* Total number of folders\n" << std::endl;

            std::cout << "Command 3 --- Collecting information:" << std::endl;
            std::cout << "\t* Full name of the user who launched the application \n\t* List of groups that the user belongs to \n\t* Workstation name\n" << std::endl;

            std::cout << "Command /exit --- Close App.\n" << std::endl;

        }

        else if (command == "1")
        {
            EnumeratingLocalDisks(TRUE);
        }

        else if (command == "2")
        {
            ListingAllFileAndDir();
        }

        else if (command == "3")
        {
            CollectingInformation();
        }

        else if (command == "/exit")
        {
            return true;
        }

        else
        {
            std::cout << "Enter the correct command!" << std::endl;
        }
    }

    system("pause");

    return 0;
}