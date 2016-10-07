// Interpert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;

// ������ģʽ������һ�����ԣ����������ķ���һ�ֱ�ʾ��������һ��������
// �ý�����ʹ�øñ�ʾ�����������еľ���

// �����ڳ������Ի��߽ű�

// �����龰��һ���ű�����ϵͳ
// wasd�������ҷ�����������Ϊ�ƶ�����
// ��һ�°ɣ����ԺͿ���֧��wasd��ĸ���ƶ�����Ϊ1-9��������


class Fire
{
public:


};

class Action
{
public:
	virtual void Interpret(string &strCmd)
	{
		if (strCmd.length() == 0)
		{
			return;
		}
		else
		{
			string strNum = strCmd.substr(1, 2);
			m_nNum = atoi(strNum.c_str());
			strCmd = strCmd.substr(2);
			Excute();
		}
	}
	virtual void Excute() = 0;
protected:
	int		m_nNum;

};


// W
class Forward : public Action
{
public:
	void Excute()
	{
		for (int i = 0; i < m_nNum; i++)
		{
			printf("ǰ��  ");
		}
	}
};

// A
class Left : public Action
{
public:
	void Excute()
	{
		for (int i = 0; i < m_nNum; i++)
		{
			printf("����  ");
		}
	}
};

class Right : public Action
{
public:
	void Excute()
	{
		for (int i = 0; i < m_nNum; i++)
		{
			printf("����  ");
		}
	}
};

// S
class Back : public Action
{
public:
	void Excute()
	{
		for (int i = 0; i < m_nNum; i++)
		{
			printf("����  ");
		}
	}
};

void Interper(string &str)
{
	string tmpStr = str.substr(0, 1);
	Action	*pAction = NULL;

	char t;
	memcpy(&t, tmpStr.c_str(), 1);
	switch (t)
	{
	case 'W':
		pAction = new Forward();
		break;
	case 'A':
		pAction = new Left();
		break;
	case 'D':
		pAction = new Right();
		break;
	case 'S':
		pAction = new Back();
		break;
	default:
		break;
	}
	if (pAction)
	{
		pAction->Interpret(str);
		delete pAction;
		pAction = NULL;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string str = "A7S4D4W1A5D5";
	while (str.length() != 0)
	{
		Interper(str);
	}
	printf("\n");

	return 0;
}
