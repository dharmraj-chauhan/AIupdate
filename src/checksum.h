/*
 * 	File no: 	checksum.h
 *
 *  Created on: Sep 28, 2022
 *      Author: dhachauh
 */

#ifndef SRC_CHECKSUM_H_
#define SRC_CHECKSUM_H_

#include <iomanip>

#include "device.h"
#include "fileparser.h"

using namespace std;
using namespace filer;

namespace chsum {
class checksum {
public:
	int getchecksum(string filepath);
	int getchecksum(string filepath1, string filepath2);
};
}

#endif /* SRC_CHECKSUM_H_ */
