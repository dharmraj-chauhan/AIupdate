/*
 * 	File name:	comparison.cpp
 *
 *  Created on: Sep 26, 2022
 *      Author: dhachauh
 */

#include "comparison.h"
#include "device.h"
#include "fileparser.h"
#include "checksum.h"

using namespace std;
using namespace filer;
using namespace chsum;

namespace filer {

void comparison :: getupdater(vector<string> &sourcevector, vector<string> &destvector, string destpath, int lineofupdate, int lensize) {
	ofstream finalfile(destpath);
	int size1 = sourcevector.size();
	int size2 = destvector.size();
	cout << "Size1: " << size1 << "Size2: " << size2 << endl;
	string temp;

	cout << "lensize: " << lensize << " lineofupdate: " << lineofupdate << endl;
	cout << "final ans: " << size1+lensize+lineofupdate << endl;
	cout << "true 1: " << 1+lensize+lineofupdate << endl;
	cout << "true 2: " << lineofupdate << endl;
	int i = 0; int j = 0; int k = 0;
	while(i < size1+lensize){
		if((i < lineofupdate+lensize) && (i >= lineofupdate)){
			cout << "Line No1: " << i << endl;
			temp = destvector[j] + "\n";
			cout << temp << endl;
			finalfile << temp;
			j++;
		} else {
			cout << "Line No2: " << i << endl;
			temp = sourcevector[k] + "\n";
			cout << temp << endl;
			finalfile << temp;
			k++;
		}
		i++;
	}
	cout << "updating successfully" << endl;
}

bool comparison :: getvector(string filePath, vector<string> & fileVec){
    ifstream in(filePath.c_str());
    if(!in){
        cerr << "Cannot open the File : " << filePath << endl;
        return false;
    }
    cout << "FilePath: " << filePath << endl;
    string str;
    while (getline(in, str)){
        fileVec.push_back(str);
    }

   for(auto it = fileVec.begin(); it != fileVec.end(); ++it){
	   cout << *it << endl;
   }

    in.close();
	return true;
}


comparison :: comparison(string destfilepath){
	string devicefilepath = "C:\\Users\\DHACHAUH\\eclipse-workspace\\AIupdate\\inc\\device.txt";
	fileparser fs;
	vector<device> destination = fs.filepparser(destfilepath);
    vector<device> sourcefile = fs.filepparser(devicefilepath);
	int first = sourcefile.size();
	int secs = destination.size();
//	cout << first << " and "<< secs << endl;
	for(int i = 0; i<first; i++) {
		for(int j = 0; j<secs; j++) {
			try {
				if(sourcefile[i].getDeviceId() == destination[j].getDeviceId()){
					if(sourcefile[i].getApplicationName() == destination[j].getApplicationName()){
//						cout << "Heyy I found it the base address is " << sourcefile[i].getBaseAddr() << endl;
						if (sourcefile[i].getVersionNo()== destination[j].getVersionNo()){
							cout << "Your Application is already Updated" << endl;
						} else {
//							cout << "Magic No: " << destination[j].getMagicNo() << endl;
							string temp1 = destination[j].getLinesofupdate();
//							cout << "Temp1: " << temp1 << endl;
							int lineofupdate = stoi(temp1);
							string temp2 = destination[j].getSizeofupdate();
							int lensize = stoi(temp2);
//							cout << "Temp2: " << temp2 << endl;
							string sourcepath = sourcefile[i].getBootInfo();
							string destpath = destination[j].getSourcefileAddr();
							vector<string> sourcevector;
							vector<string> destvector;

							cout << "Updating Process is start\nit will take a few mins...." << endl;
//							cout << lineofupdate << "," << lensize << "," << sourcepath << "," << destpath << endl;

							getvector(sourcepath, sourcevector);
							getvector(destpath, destvector);
							getupdater(sourcevector, destvector, sourcepath, lineofupdate, lensize);
							cout << "Heyy, Successfully updated.." << endl;
						}
					}
				}
			} catch (const std::exception& e) {
				cout << e.what() << endl;
			}
		}
	}

}
} /* namespace cmp */
