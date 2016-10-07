// ί�о���iһ�����÷��������ͣ�һ��Ϊί�з����˷�����ί�н���
// �÷���������ȫ��ͬ����Ϊ��ί�з�����ʹ�ÿ����������κη���һ����
// ���в����ͷ���ֵ��ί�п��Կ����ǶԺ����ĳ����Ǻ����ġ��ࡱ��ί��
// ��ʵ������һ������ĺ���

// ί�ж��������ص����з������������ͬ��ԭ�ͺ���ʶ��
// Ҳ��������ͬ�Ĳ����б�ͷ���ֵ����


// C++ ����ָ������棬������

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <vector>
using namespace std;

// �����࣬Ҳ����ʹ����ģ����ʵ��
// ʵ���ϣ�����void* pArg���Խ��н�һ���ķ�װ
class Object
{
public:
	typedef long (Object::*pFunc)(Object *pObj, void* pArg);
protected:
private:
};


class NameContainer
{
public:
	string strName;
};

// �¼���
class EventHandler
{
public:
	EventHandler(Object *pObject, Object::pFunc pFuncion)
		: m_pObj(pObject)
		, m_pFunc(pFuncion)
	{

	}

	long operator()(Object* pObj, void* pArg)
	{
		return (m_pObj->*m_pFunc)(pObj, pArg);
	}
protected:
	Object			*m_pObj;
	Object::pFunc	m_pFunc;
private:
};

// �¼��������
class EventsContainer
{
public:
	// ĳЩ���ؾͲ�д��
	EventsContainer& operator +=(const EventHandler& rEvent)
	{
		m_EventsVec.push_back(rEvent);
		return *this;
	}
	long operator()(Object* pObj, void *pArg)
	{
		for (int i = 0; i < m_EventsVec.size(); i++)
		{
			// �ݲ��Է���ֵ�����ж�
			m_EventsVec[i](pObj, pArg);
		}
		return 0;
	}
protected:

private:
	vector<EventHandler>  m_EventsVec;
};



class PersonA : public Object
{
public:
	PersonA(const string &strName)
	{
		m_strName = strName;
	}
	long TellName(Object *pObj, void* pArg)
	{

		// ��Ȼ��PersonA��֪����������Ǹ�ʲô�ģ�������ʲô
		// �����֪���Ļ������ö�̬Ҳ���Ժܺý������
		// ���˾��ǳ�����������ִ�����
		string strName = (*((NameContainer*)pArg)).strName;

		cout << "Hello! " << strName.c_str() << ".\nMy name is: " << m_strName.c_str() << endl;
		// ֱ��cout pArg �������ָ��ĵ�ַ��
		return 1;
	}
protected:
private:
	string m_strName;
};

int _tmain(int argc, _TCHAR* argv[])
{
	EventsContainer  tellName;
	PersonA *pA = new PersonA("Joky");
	// Joky����һ��������ˣ�������ÿ�βμӾۻ�ǰ������һ����ʾ��
	// �Ա��ڵ�һʱ�������ҽ��ܣ������Ƕ���Ů
	// ��ʾ����[tellName]ϵͳ
	//ע���¼�
	tellName += EventHandler(
		(Object*)pA,						 // ���� 
		(Object::pFunc)&PersonA::TellName);  // �¼�

	// ��һ�ξۻ���
	// Jokyͨ��[tellName}ϵͳ�����һ��İ���˵�����
	// İ���˽�[Fuuny]
	NameContainer nc;
	nc.strName = "Fuuny";
	tellName(pA, (void*)&nc);

	if (pA)
	{
		delete pA;
		pA = NULL;
	}

	return 0;
}


// ִ�н��
//Hello! Fuuny.
//My name is: Joky
//�밴���������. . .