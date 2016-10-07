// Command.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

// ����ģʽ��Command������һ�������װΪһ�����󣬴Ӷ�ʹ������ò�ͬ������Կͻ�
// ���в��������������Ŷӻ��¼������־���Լ�֧�ֿɳ����Ĳ�����

// ���ǽ�����Ĳ����������ִ�з��룬������������һ���������

class Receiver
{
public:
	Receiver(const std::string &strName)
	{
		m_strName = strName;
	}
	std::string m_strName;
};
class Cmd
{
public:
	Cmd(Receiver *pRcv)
		: m_pReceiver(pRcv)
	{
		;
	}
	virtual ~Cmd(){ ; }

	virtual void Execute() = 0;
protected:
	Receiver	*m_pReceiver;
};

class MoveCmd : public Cmd
{
public:
	MoveCmd(Receiver *pRcv)
		: Cmd(pRcv)
	{

	}
	void Execute()
	{
		printf("Move %s\n", m_pReceiver->m_strName.c_str());
	}
};

class RotateCmd : public Cmd
{
public:
	RotateCmd(Receiver *pRcv)
		: Cmd(pRcv)
	{

	}

	void Execute()
	{
		printf("Rotate %s\n", m_pReceiver->m_strName.c_str());
	}
};

class CmdMgr
{
public:
	void SetCommand(Cmd *pCmd)
	{
		m_VecCmd.push_back(pCmd);
	}
	void ExecuteCommand()
	{
		std::vector<Cmd*>::iterator iter = m_VecCmd.begin();
		for (; iter != m_VecCmd.end();)
		{
			Cmd* pCmd = (*iter);
			pCmd->Execute();
			if (pCmd)
			{
				delete pCmd;
				pCmd = NULL;
			}
			iter = m_VecCmd.erase(iter);
		}
	}
private:
	std::vector<Cmd*>  m_VecCmd;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Receiver	recvr("Cube");
	CmdMgr		mgr;

	Cmd* pMoveCmd = new MoveCmd(&recvr);
	Cmd* pRotateCmd = new RotateCmd(&recvr);

	mgr.SetCommand(pMoveCmd);
	mgr.SetCommand(pRotateCmd);

	mgr.ExecuteCommand();


	return 0;
}
