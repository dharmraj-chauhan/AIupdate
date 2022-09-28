/*
 * 	file name:	main.cpp
 *
 *  Created on: Sep 26, 2022
 *  Author: 	dhachauh
 *
 */

#include "fileparser.h"
#include "comparison.h"
#include "checksum.h"
#include "device.h"

#define MI_SIZE 3

using namespace std;
using namespace filer;
using namespace chsum;

int main(int argc, char** argv){
	if (argc < 3){
		cout << "Please, Enter more then 2 command line arguments." << endl;
	} else {
		comparison fp1(argv[1]);
	}
//	comparison fp1("C:\\Users\\DHACHAUH\\eclipse-workspace\\AIupdate\\src\\updateconfig.txt");

	return 0;
}
