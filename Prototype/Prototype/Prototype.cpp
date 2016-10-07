#include "stdafx.h"
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <iostream>




// ԭ��ģʽ��ʵ���Ǵ�һ�������ٴ�������һ���ɶ��ƵĶ��󣬶��Ҳ���Ҫ֪���κδ�����ϸ��


// ��1����deepCopy��ʲô��������"="����дһ��DeepCopy�����Ϳ������
// ��2��ò��û������޶ȵĽ�ʡ�ڴ棬Ҫ��ʡ�ڴ��ǲ���Ҫ����Ԫģʽ��
// ��3��C++�����û��ʲôMemberwiseClone()



// �����龰��ĳ��Ϸ�����û��½���ɫʱ�������һ��������ɫ��
// Ȼ���û����ڴ˻����϶Ըû�����ɫ�����޸�
// ����ʵӦ���Ǹ�����ҵ��Ա�����ѡ�񣬴��´���һ�������Ľ�ɫ���Σ�Ȼ�������װ�磬�����򻯣�

// char *�������������

#define DELETE_OBJECT(p)	{ if (p) delete p;	p = NULL; }

enum ESex
{
	male,
	famale
};

class IRole
{
public:
	virtual void Setproperty(ESex eSex, int nAge) = 0;
	virtual void SetDescription(char * pDescpt, int nLength) = 0;
	virtual void Show() = 0;
	virtual IRole* Clone() = 0;
	virtual void SetName(const std::string &strName) = 0;

protected:
	std::string m_strName;
	ESex		m_eSex;
	int			m_nAge;
	char*		m_pDescription;
	int			m_nDscriptLength;

};

class BaseRole : public IRole
{
public:
	BaseRole()
		//: m_eSex(male)
		//, m_nAge(25)
		//, m_pDescription(NULL)
	{
		m_eSex = male;
		m_nAge = 25;
		m_pDescription = NULL;
	}
	virtual ~BaseRole()
	{
		DELETE_OBJECT(m_pDescription);
	}

	void SetName(const std::string &strName)
	{
		m_strName = strName;
	}
	void Setproperty(ESex eSex, int nAge)
	{
		m_eSex = eSex;
		m_nAge = nAge;
	}
	void SetDescription(char * pDescpt, int nLength)
	{
		m_nDscriptLength = nLength;
		m_pDescription = new char[nLength + 1];
		memset(m_pDescription, 0, nLength + 1);
		memcpy(m_pDescription, pDescpt, nLength);
	}
	void Show()
	{
		printf("\n\nNow Show A Role Information:\n");
		printf("Name:%s\n", m_strName.c_str());
		if (male == m_eSex)
		{
			printf("Sex: Male\n");
		}
		else
		{
			printf("Sex: FeMale\n");
		}
		printf("Age :%d\n", m_nAge);
		printf(m_pDescription);
		printf("\n");
	}
	IRole* Clone()
	{
		BaseRole * pRole = new BaseRole;
		pRole->m_eSex = m_eSex;
		pRole->m_nAge = m_nAge;
		pRole->m_strName = m_strName;
		pRole->m_nDscriptLength = m_nDscriptLength;
		pRole->m_pDescription = new char[m_nDscriptLength + 1];
		memset(pRole->m_pDescription, 0, m_nDscriptLength + 1);
		memcpy(pRole->m_pDescription, m_pDescription, m_nDscriptLength);
		return pRole;
	}

protected:
private:
};


int _tmain(int argc, _TCHAR* argv[])
{

	//�����������
	char *pChar = "So clever!";
	int nLength = strlen(pChar);

	char *pChar_1 = "A Nice People!";
	int nLength_1 = strlen(pChar_1);

	//����BaseRole
	BaseRole *pBase = new BaseRole;
	pBase->Setproperty(male, 15);
	pBase->SetDescription(pChar, nLength);
	pBase->SetName("BaseRole");

	//����BaseRole��������
	BaseRole *pTom = (BaseRole*)pBase->Clone();
	pTom->SetDescription(pChar_1, nLength_1);
	pTom->SetName("Tom");

	BaseRole *pLucy = dynamic_cast<BaseRole*>(pBase->Clone());
	pLucy->Setproperty(famale, 18);
	pLucy->SetName("Lucy");

	pBase->Show();
	pTom->Show();
	pLucy->Show();

	DELETE_OBJECT(pBase);
	DELETE_OBJECT(pTom);
	DELETE_OBJECT(pLucy);

	return 0;
}

/*���
Now Show A Role Information:
Name:BaseRole
Sex: Male
Age :15
So clever!


Now Show A Role Information:
Name:Tom
Sex: Male
Age :15
A Nice People!


Now Show A Role Information:
Name:Lucy
Sex: FeMale
Age :18
So clever!
�밴���������. . .
*/