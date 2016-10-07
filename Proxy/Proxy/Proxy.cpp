#include "stdafx.h"  
#include <windows.h>  
#include <iostream>  
using namespace std;

//�����ģʽ�е�����  
//A���ô�����B����CС��������  

class IGiveGift
{
public:
	IGiveGift(){ ; }
	virtual ~IGiveGift(){ ; }

	virtual void GiveGift() = 0;
};

class PersonA : public IGiveGift
{
public:
	PersonA(const std::string & strGirlName)
	{
		m_strGirlName = strGirlName;
	}
	void GiveGift()
	{
		std::cout << m_strGirlName.c_str() << "," << "��������" << endl;
	}
private:
	std::string m_strGirlName;

};

class ProxyB : public IGiveGift
{
public:
	void SetClientPerson(PersonA *pA)
	{
		m_pPersonA = pA;
	}
	void GiveGift()
	{
		m_pPersonA->GiveGift();
	}
private:
	PersonA *m_pPersonA;
};

int _tmain(int argc, _TCHAR* argv[])
{
	//A�������ˣ����Ŷ������˵�˼��  
	PersonA *pA = new PersonA("CС��");
	//A��������˼����������ҵ��˴���B��  
	ProxyB *pB = new ProxyB();
	pB->SetClientPerson(pA);
	//B����������  
	pB->GiveGift();

	//��Ļ  
	if (pA)
	{
		delete pA;
		pA = NULL;
	}
	if (pB)
	{
		delete pB;
		pB = NULL;
	}
	return 0;
}
