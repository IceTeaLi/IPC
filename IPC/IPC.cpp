#include "IPC.h"

using namespace std;

static const UINT IPC_MESSAGE_CONNECT = ::RegisterWindowMessage(TEXT("IPC_MESSAGE_CONNECT"));

ipc::MessageClient::MessageClient()
{
	
}

ipc::MessageClient::~MessageClient()
{

}

bool ipc::MessageClient::Connect(PVOID id_p)
{
	try
	{
		server_wnd = reinterpret_cast<HWND>(id_p);
		current_process_id=GetCurrentProcessId();
		if (current_process_id==-1)
		{
			cerr << TEXT("Error: GetCurrentProcessId() failed!!!") << endl;
			return false;
		}
		//ͬ��ͨ�ţ��˴����serverδ�ظ�����ɳ���������Ӧ���ø��õķ������棬������
		SendMessage(server_wnd, IPC_MESSAGE_CONNECT, reinterpret_cast<WPARAM>(&current_process_id), NULL);
	}
	catch (bad_cast &e)
	{
		cerr << e.what() << endl;
		return false;
	}
	
	return true;
}

ipc::MessageServer::MessageServer()
{
}

ipc::MessageServer::~MessageServer()
{
}
