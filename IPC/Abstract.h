#pragma once
#include <Windows.h>

namespace ipc
{

	class Client
	{
	public:

		virtual bool Connect(PVOID id_p) = 0;

		virtual bool Send(PVOID data, int len) = 0;

		virtual bool Disconnect() = 0;
	};

	class Server
	{
	public:
		virtual bool Listen() = 0;

		virtual bool Read(PVOID data) = 0;

		virtual bool Close() = 0;
	};

}