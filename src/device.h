/*
 * 		filename:	filereader.h
 *
 *  	Created on: Sep 26, 2022
 *      Author: 	DHACHAUH
 */

#ifndef SRC_DEVICE_H_
#define SRC_DEVICE_H_

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <exception>
#include <bits/stdc++.h>

using namespace std;

namespace filer{
	class device{
	private:
		string device_id;
		string magic_no;
		string device_name;
		string checksum;
		string boot_info;
		string sourcefile_addr;
		string base_addr;
		string version_no;
		string linesofupdate;
		string update_size;
		string application_name;

	public:
		device();
		const string getChecksum() const;
		void setChecksum(const string checksum);
		const string getDeviceId() const;
		void setDeviceId(const string deviceId);
		const string getDeviceName() const;
		void setDeviceName(const string deviceName);
		const string getMagicNo() const;
		void setMagicNo(const string magicNo);
		const string getBootInfo() const;
		void setBootInfo(const string bootInfo);
		const string getBaseAddr() const;
		void setBaseAddr(const string baseAddr);
		const string getSourcefileAddr() const;
		void setSourcefileAddr(const string sourcefileAddr);
		const string getLinesofupdate() const;
		void setLinesofupdate(const string linesofupdate);
		const string getVersionNo() const;
		void setVersionNo(const string versionNo);
		const string getSizeofupdate() const;
		void setSizeofupdate(const string updateSize);
		const string getApplicationName() const;
		void setApplicationName(const string application_name);

	};
}

#endif /* SRC_DEVICE_H_ */
