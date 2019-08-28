#pragma once
#include "Abstract.h"

#include <Windows.h>
#include <queue>
#include <iostream>
#include <typeinfo>

namespace ipc
{
	class Cache
	{
	public:
		Cache();
		~Cache();



	private:
		std::queue<PVOID> cache;
	};

	class MessageClient :public Client
	{
	public:
		MessageClient();
		~MessageClient();

		virtual bool Connect(PVOID id_p) override;
		
	private:

		HWND server_wnd = nullptr;

		DWORD current_process_id = -1;

	};

	class MessageServer :public Server
	{
	public:
		MessageServer();
		~MessageServer();
	};


}	//ipc
