// Copyright (c) 2019 Ivan Šincek

#ifndef INVOKER
#define INVOKER

#include <windows.h>
#include <string>

std::string intToStr(int num);

std::string strToLower(std::string str);

std::string strToUpper(std::string str);

std::string trim(std::string str);

void print(std::string msg);

std::string input(std::string msg);

bool isPositiveNumber(std::string str);

void cmdExec(std::string command = "");

void psExec(std::string encoded);

bool createFile(std::string file, std::string data = "");

std::string readFile(std::string file);

bool writeFile(std::string file, std::string data);

bool copyFile(std::string original, std::string copy);

bool downloadFile(std::string url, std::string out);

bool editRegKey(PHKEY hKey, std::string subkey, std::string name, std::string data);

bool scheduleTask(std::string name, std::string user, std::string file, std::string args = "");

bool reverseTcp(std::string ip, int port);

int getProcessId();

bool terminateProcess(int pid);

bool runProcess(std::string file, std::string args = "", PHANDLE hToken = NULL);

bool dumpProcessMemory(int pid);

std::string getWebContent(std::string url, int port, std::string method = "GET");

std::string extractPayload(std::string data, std::string element, std::string placeholder);

bool injectBytecode(int pid, std::string bytecode);

bool injectDll(int pid, std::string file);

void listProcessDlls(int pid);

struct hook {
	std::string file;
	HANDLE hThread;
	bool active;
};

void hookJob(struct hook* info);

HANDLE createHookThread(struct hook* info);

void enableAccessTokenPrivs();

HANDLE duplicateAccessToken(int pid);

std::string getUnquotedServiceName();

bool manageService(std::string name, int mode);

bool replaceStickyKeys();

#endif

