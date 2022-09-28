#include "device.h"

using namespace std;
using namespace filer;

device :: device()
{device_id=""; magic_no=""; device_name=""; checksum=""; boot_info=""; sourcefile_addr=""; base_addr=""; update_size=""; version_no=""; linesofupdate=""; application_name="";}

const string device :: getChecksum() const {
	return checksum;
}

void device :: setChecksum(const string checksum) {
	this->checksum = checksum;
}

const string device :: getDeviceId() const {
	return device_id;
}

void device :: setDeviceId(const string deviceId) {
	device_id = deviceId;
}

const string device :: getDeviceName() const {
	return device_name;
}

void device :: setDeviceName(const string deviceName) {
	device_name = deviceName;
}

const string device :: getMagicNo() const {
	return magic_no;
}

void device :: setMagicNo(const string magicNo) {
	magic_no = magicNo;
}

const string device :: getBootInfo() const {
	return boot_info;
}

void device :: setBootInfo(const string bootInfo) {
	boot_info = bootInfo;
}

const string device :: getBaseAddr() const {
	return base_addr;
}

void device :: setBaseAddr(const string baseAddr) {
	base_addr = baseAddr;
}

const string device :: getSourcefileAddr() const {
	return sourcefile_addr;
}

void device :: setSourcefileAddr(const string sourcefileAddr) {
	sourcefile_addr = sourcefileAddr;
}

const string device :: getLinesofupdate() const {
	return linesofupdate;
}

void device :: setLinesofupdate(const string linesofupdate) {
	this->linesofupdate = linesofupdate;
}

const string device :: getVersionNo() const {
	return version_no;
}

void device :: setVersionNo(const string versionNo) {
	version_no = versionNo;
}

const string device :: getSizeofupdate() const {
	return update_size;
}

void device :: setSizeofupdate(const string updateSize) {
	update_size = updateSize;
}

const string device :: getApplicationName() const {
	return application_name;
}

void device :: setApplicationName(const string applicationname) {
	application_name = applicationname;
}
