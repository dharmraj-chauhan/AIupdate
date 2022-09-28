/*
 * 	Filename:	fileparser.cpp
 *
 *  Created on: Sep 26, 2022
 *  Author: 	DHACHAUH
 */


#include "fileparser.h"
#include "device.h"

using namespace std;
using namespace filer;

/**
 * @fn: removeSpaces(string str)
 * @brief: 	To remove empty spaces from the lines given by the
 *          @fn: lineparser and returning back to the lineparser
 * @param: 	String
 * @return: string
 */
string fileparser:: removeSpaces(string str){
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

/**
 * @fn: lineparser(string line, @class:device &object)
 * @brief: 	To extract the information from the config file and store the info
 *          in the vector of the class device.
 *
 * @param: 	String , &object
 * @return: void
 */

void fileparser :: lineparser(string line, device &tempDev){
	string key = "";
	string value = "";

	try{
		int find1 = line.find("=");
		if (find1 == -1 ){
			throw invalid_argument("Key Value Pair is empty\n");
		} else {
			key = removeSpaces(line.substr(0, find1));
			value = removeSpaces(line.substr(find1+1));
			transform(key.begin(), key.end(), key.begin(), ::tolower);
			if(key == "checksum"){
				tempDev.setChecksum(value);
			} else if(key == "device_id"){
				tempDev.setDeviceId(value);
			} else if(key == "device_name") {
				tempDev.setDeviceName(value);
			} else if(key == "magic_no"){
				tempDev.setMagicNo(value);
			} else if(key == "base_address") {
				tempDev.setBaseAddr(value);
			} else if(key == "program_name") {
				tempDev.setApplicationName(value);
			} else if(key == "boot"){
				tempDev.setBootInfo(value);
				string src = "";
				string ver = "";
				string size = "";
				string ulines = "";

				try{
					string str1 = "_";
					int found1 = value.find(str1);
					int found2 = value.find(str1, found1+1);
					int found3 = value.find(str1, found2+1);
//					cout << found1 << found2 << found3 << endl;
					if((found1 == -1) || (found2 == -1) || (found3 == -1)){
						throw invalid_argument("LineofUpdate/Version/Size is not Present\n");
					} else {
						ulines = value.substr(found1-1, found1);
						size = value.substr(found1+1, (found2-found1-1));
						ver = value.substr(found2+1, (found3-found2-1));
						src = value.substr(found3+1);

						if(src == ""){
							src = "C:\\Users\\DHACHAUH\\Downloads\\" + tempDev.getApplicationName() + ".txt";
						}

						tempDev.setSourcefileAddr(src);
						tempDev.setLinesofupdate(ulines);
						tempDev.setVersionNo(ver);
						tempDev.setSizeofupdate(size);
					}
				} catch(const invalid_argument& ia) {
			        cerr << ia.what() << endl;
			    }
			}
		}
	} catch (const invalid_argument& ia){
		cout<< "pass" << endl;
	}
}

/**
 * @fn: filepparser(string filename1)
 * @brief: 	To open the config files and pass each line to the lineparser function
 *           and creating object for every entry.
 * @param: 	String
 * @return: fileinfo
 */

vector<device> fileparser :: filepparser(string filename1){
	vector<device> fileinfo;

	ifstream file1;
	string lines; // temp variable to store the file line data
	file1.open(filename1);

	while (file1) { // keep reading until end-of-file
		device tempDevcie;
		getline(file1, lines);
		while(lines.length() != 0 && file1) {
			lineparser(lines, tempDevcie);
			getline(file1, lines);
		}

//		cout << "Device name at input time: " << tempobj->getDeviceName() << endl;
		fileinfo.push_back(tempDevcie);
	}

//	int total_length = fileinfo.size();
//		cout << "Total length:- " << total_length << endl;
//	for (int i=0; i<total_length; i++)
//	{
//		cout << "---------------------Fileinfo No "  << i << "info---------------------"<<endl;
//		cout << "Device name: " << fileinfo[i].getDeviceName() << endl;
//		cout << "Application name: " << fileinfo[i].getApplicationName() << endl;
//		cout << "Checksum: " << fileinfo[i].getChecksum() << endl;
//		cout << "Device ID: " << fileinfo[i].getDeviceId() << endl;
//		cout << "Device Name: " << fileinfo[i].getDeviceName() << endl;
//		cout << "Magic No: " << fileinfo[i].getMagicNo() << endl;
//		cout << "Boot info: " << fileinfo[i].getBootInfo() << endl;
//		cout << "Base Address: " << fileinfo[i].getBaseAddr() << endl;
//		cout << "Source Address: " << fileinfo[i].getSourcefileAddr() << endl;
//		cout << "Device name: " << fileinfo[i].getDeviceName() << endl;
//		cout << "Lines of Update: " << fileinfo[i].getLinesofupdate() << endl;
//		cout << "Version Name: " << fileinfo[i].getVersionNo() << endl;
//		cout << "Size of update: " << fileinfo[i].getSizeofupdate() << endl;
//	}
	file1.close();

	return fileinfo;
}

fileparser :: fileparser(){
}
