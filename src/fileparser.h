/*
 * fileparser.h
 *
 *  Created on: Sep 26, 2022
 *      Author: DHACHAUH
 */

#ifndef SRC_FILEPARSER_H_
#define SRC_FILEPARSER_H_

#include "device.h"

using namespace std;
using namespace filer;

namespace filer{
	class fileparser{
	public:
		fileparser();
		string removeSpaces(string str);
		void lineparser(string line, device &dp);
		vector<device> filepparser(string filename1);
	};
}


#endif /* SRC_FILEPARSER_H_ */
