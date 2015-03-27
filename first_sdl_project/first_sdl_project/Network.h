#ifndef _NETWORK_H_
#define _NETWORK_H_

//#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include<process.h>
#include <Windows.h>
#include<iostream>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

using namespace std;
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27017"

class GameManager;

class Network {
public:
	struct sharedMem
	{
		SOCKET ListenSocket;// = INVALID_SOCKET;
		SOCKET ClientSocket[3];// = { INVALID_SOCKET, INVALID_SOCKET, INVALID_SOCKET };
		int numConnect;// = 0;
	} mem;

	int Init();
	void Send(char* msg);
	void RecvLoop();
	void ConnectLoop();

	bool HandleMessage(char* msg);

	void Close();
	
	SOCKET ConnectSocket;// = INVALID_SOCKET;

	void ConnectionType();
	bool isServer;

private:

	GameManager* manager;
	
	void static Static_RecvLoop(void* param);
	void static Static_ConnectLoop(void* param);
	
	char inBuffer[512];// = { 0 };
};

#endif