
#include <iostream>
#include <string>
#include <iomanip> // for the checksum; calculate the size with timestemp
#include <fstream>
#include <cstring>

using namespace std;

int main1(){

    string filePath;
    char choice;
    int i;
    int a = 0;
    int b = 0;
    int x = 0;
    int y = 0;
    int sum = 0;

    ifstream inFile;

    //arrays
    const int SUM_ARR_SZ = 100;
    string FileNames1[SUM_ARR_SZ];
    unsigned int CheckSum1[SUM_ARR_SZ];
    string FileNames2[SUM_ARR_SZ];
    unsigned int CheckSum2[SUM_ARR_SZ];

    do {
        cout << "Please select: " << endl;
        cout << "   A) Compute checksum of specified file" << endl;
        cout << "   B) Verify integrity of specified file" << endl;
        cout << "   Q) Quit" << endl;
        cin >> choice;

        if (choice == 'a' || choice == 'A')
        {
            //open file in binary mode
            cout << "Specify the file path: " << endl;
            filePath = "C:\\Users\\DHACHAUH\\Downloads\\program15.txt";
            inFile.open(filePath, ios::binary);

            //save file name
            FileNames1[a] = filePath;
            a++;

            //use seekg and tellg to determine file size
            char Arr[100000];
            inFile.seekg(0, ios_base::end);
            int fileLen = inFile.tellg();
            inFile.seekg(0, ios_base::beg);
            inFile.read(Arr, fileLen);
            inFile.close();
            for (i = 0; i < 100000; i++)
            {
                sum += Arr[i];
            }
            //store the sum into CheckSum1 array
            CheckSum1[b] = sum;
            b++;
            cout << " File checksum = " << sum << endl;
            inFile.close();
            inFile.clear(std::ios_base::goodbit);

        }
        if (choice == 'b' || choice == 'B')
        {
            cout << "Specify the file path: " << endl;
            cin >> filePath;
            inFile.open(filePath.c_str(), ios::binary);

            //save file name
            FileNames2[x] = filePath;
            x++;


            //use seekg and tellg to determine file size
            char Arr[100000];
            inFile.seekg(0, ios_base::end);
            int fileLen = inFile.tellg();
            inFile.seekg(0, ios_base::beg);
            inFile.read(Arr, fileLen);
            inFile.close();
            sum=0;
            for (i = 0; i < 100000; i++)
            {
                sum += Arr[i];
            }
            //store the sum into CheckSum1 array
            CheckSum2[y] = sum;
            y++;
            cout << " File checksum = " << sum << endl;
            if(CheckSum1[0]==CheckSum2[0])
            {
                cout << "File is correct" << endl;
            }
            else
            {
                cout << "file is not correct" << endl;
            }
            inFile.close();
            inFile.clear(std::ios_base::goodbit);

        }
    } while (choice != 'q' && choice != 'Q');

    system("pause");
    return 0;
}


