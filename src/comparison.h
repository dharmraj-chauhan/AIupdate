/*
 * comparison.h
 *
 *  Created on: Sep 26, 2022
 *      Author: dhachauh
 */

#ifndef SRC_COMPARISON_H_
#define SRC_COMPARISON_H_

#include "device.h"
#include "fileparser.h"

using namespace std;
using namespace filer;

namespace filer {

class comparison: public filer::fileparser, public filer::device {
public:

	bool getvector(string filePath, vector<string> & fileVec);
	void getsdvector(vector<device> source, vector<device> dest);
	void getupdater(vector<string> &sourcevector, vector<string> &destvector, string destpath, int line, int size);
	comparison(string file1);
};

} /* namespace cmp */

#endif /* SRC_COMPARISON_H_ */
