/*
 * checksum.cpp
 *
 *  Created on: Sep 28, 2022
 *      Author: dhachauh
 */


#include "comparison.h"
#include "device.h"
#include "fileparser.h"
#include "checksum.h"

using namespace std;
using namespace filer;
using namespace chsum;

namespace chsum {

int checksum :: getchecksum(string filepath){

	int a = 0;
	int b = 0;
	int sum = 0;

	const int SUM_ARR_SZ = 100;
	string FileNames1[SUM_ARR_SZ];
	string FileNames2[SUM_ARR_SZ];

	ifstream inFile;
	inFile.open(filepath, ios::binary);

    //save file name
    FileNames1[a] = filepath;
    a++;

    //use seekg and tellg to determine file size
    char Arr[100000];
    inFile.seekg(0, ios_base::end);
    int fileLen = inFile.tellg();
    inFile.seekg(0, ios_base::beg);
    inFile.read(Arr, fileLen);
    inFile.close();
    for (int i = 0; i < 100000; i++)
    {
        sum += Arr[i];
    }

    //store the sum into CheckSum1 array
    b++;
    cout << " File checksum = " << sum << endl;
    inFile.close();
    inFile.clear(std::ios_base::goodbit);


    return sum;
	}
}

