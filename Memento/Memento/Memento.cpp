// Memento.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// ����¼ģʽ(Memento): �ٲ��ܻ���װ�Ե�ǰ����
// ����һ��������ڲ�״̬�� ���ڶ���֮�Ᵽ�����״̬
// �����Ժ�Ϳɽ��ö���ָ���ԭ�ȱ����״̬


// �龰���裬�洢�ڻָ���Ϸ�������״̬

// ģ�������״̬�Ľṹ��
struct SRoleState
{
	int nlevle;
	int nHp;
	int nMp;
};

// ����״̬�Ĵ浵
class Memento
{
public:
	void GetInfo(SRoleState &sState) const
	{
		sState = m_sRolestate;
	}
	void SetInfo(const SRoleState& sState)
	{
		m_sRolestate = sState;
	}
private:
	SRoleState	m_sRolestate;
};

// �����ɫ
class Role
{
public:
	void SaveState(Memento &memo)
	{
		memo.SetInfo(m_sRoleState);

	}
	void LoadState(const Memento &memo)
	{
		memo.GetInfo(m_sRoleState);
	}

	void SetRoleState_fortest(int lvl, int hp, int mp)
	{
		m_sRoleState.nlevle = lvl;
		m_sRoleState.nHp = hp;
		m_sRoleState.nMp = mp;
	}

	void ShowInfor()
	{
		printf("The lvl of hero is %d\nHp:%d\nMp:%d\n",
			m_sRoleState.nlevle,
			m_sRoleState.nHp,
			m_sRoleState.nMp);
	}
protected:
	SRoleState m_sRoleState;
};

class MementoMgr
{
public:
	void SetMemnto(const Memento& mem)
	{
		m_memento = mem;
	}
	Memento GetMemnto()
	{
		return m_memento;
	}
protected:
	Memento		m_memento;
private:
};

int _tmain(int argc, _TCHAR* argv[])
{
	MementoMgr mgr;
	Role hero;


	// Ӣ�۵ĳ�ʼ����
	hero.SetRoleState_fortest(0, 100, 100);
	hero.ShowInfor();
	Memento memStart;
	hero.SaveState(memStart);
	mgr.SetMemnto(memStart);

	// ����Ӣ�۵�����
	hero.SetRoleState_fortest(10, 500, 300);
	hero.ShowInfor();

	// �ص�
	hero.LoadState(mgr.GetMemnto());
	hero.ShowInfor();
	return 0;
}

// ��������
//The lvl of hero is 0
//Hp:100
//Mp:100
//The lvl of hero is 10
//Hp:500
//Mp:300
//The lvl of hero is 0
//Hp:100
//Mp:100

