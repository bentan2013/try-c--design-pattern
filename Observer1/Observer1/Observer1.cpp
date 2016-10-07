// �۲���ģʽ������һ��һ�Զ���������ö���۲��߶���ͬʱ����ĳһ��
// �������������������״̬�����仯ʱ����֪ͨ���й۲��߶���ʹ
// �����ܹ��Զ������Լ���



// �۲���ģʽ��һ������Ҫ��ģʽ��ʹ��Ƶ���Ƿǳ��߰�

// ��һ������ı���Ҫͬʱ�ı����������ʱ��
// �����岻֪���ж��ٸ������д��ı��ʱ��


// ���õķ�Χ
// �ڡ���ģʽ���У��ڶ�Ĺ۲��߶������ϰ࿪С���NBA������Ʊ��ͬ��
// ��������������ſڵ�ǰ̨�����ϰ�ص���˾��ʱ��ǰ̨��֪ͨ���еġ�ע�ᡱ
// ���ͬ�¸Ͻ��������¡�


// ��ʵ��ά�����Ҳ�����õ�
// ��������Ϊ��Ϊ�۲��߶��������Ϊ��������������ͨ�����۲����ǰ��
// ʱ�������¸������������������������ٵ������������������



// �龰����
// ��һ�ɻ����н��п��ƣ�
// �ȷ���С��10��
// ����תС��20��



#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <vector>

// �Ͼ���Ϊʾ�������ǿ���Ч����Ҫ��
// ���Ծ���using namespace��
using namespace std;

//�������������
class IControl
{
public:
	virtual bool Update(double dtime) = 0;
	virtual bool Begin(double dtime) = 0;
	virtual bool IsFinish() = 0;

protected:
	double	m_dLastTime;
	bool	m_bFinish;
private:
};

//�������������
class FlyControl : public IControl
{
public:
	bool Begin(double dtime)
	{
		m_bFinish = false;
		m_dLastTime = dtime;
		return true;
	}
	bool Update(double dtime)
	{
		double dDetal = dtime - m_dLastTime;
		if (dDetal > 10)
		{
			cout << "Complete fly!" << endl;
			m_bFinish = true;
			return true;
		}
		cout << "We have fly  " << dDetal << "  meters!" << endl;
	}
	bool IsFinish()
	{
		return m_bFinish;
	}
protected:
private:
};

//ת�����������
class RotateControl : public IControl
{
public:
	bool Begin(double dtime)
	{
		m_bFinish = false;
		m_dLastTime = dtime;
		return true;
	}
	bool Update(double dtime)
	{
		double dDetal = dtime - m_dLastTime;
		if (dDetal > 20)
		{
			cout << "Complete Rotate!" << endl;
			m_bFinish = true;
			return true;
		}
		cout << "We have Rotate  " << dDetal << "  degress" << endl;
	}
	bool IsFinish()
	{
		return m_bFinish;
	}
protected:
private:
};


// ����������
class ControlList
{
public:
	int GetCount()
	{
		return m_CtrlVec.size();
	}
	void SetTime(double dTime)
	{
		m_dLastTime = dTime;
	}
	void Attach(IControl *pCtrl)
	{
		for (int i = 0; i < m_CtrlVec.size(); i++)
		{
			if (pCtrl == m_CtrlVec[i])
			{
				return;
			}
		}
		m_CtrlVec.push_back(pCtrl);
	}
	void Detach(IControl *pCtrl)
	{
		for (int i = 0; i < m_CtrlVec.size(); i++)
		{
			if (pCtrl == m_CtrlVec[i])
			{
				m_CtrlVec.erase(m_CtrlVec.begin() + i);
			}
			return;
		}
	}

	bool UpdateAllCtrls(double dtime)
	{
		double dT = dtime - m_dLastTime;
		if (dT == 0.0)
		{
			return false;
		}

		int nSize = m_CtrlVec.size();
		if (m_CtrlVec.size() != 0)
		{
			IControl* pCtrl = m_CtrlVec.front();
			if (NULL != pCtrl)
			{
				pCtrl->Update(dtime);

				if (pCtrl->IsFinish())
				{
					delete pCtrl;
					pCtrl = NULL;
					m_CtrlVec.erase(m_CtrlVec.begin());

					if (m_CtrlVec.size() != 0)
					{
						pCtrl = m_CtrlVec.front();
						if (NULL != pCtrl)
						{
							pCtrl->Begin(dtime);
						}
					}
				}
			}
		}

		m_dLastTime = dtime;

		return true;
	}

protected:
private:
	std::vector<IControl*>	m_CtrlVec;
	double					m_dLastTime;

};


// 
// Plain
// �ɻ���
class Plain : public ControlList
{
public:
protected:
private:
};


int _tmain(int argc, _TCHAR* argv[])
{
	//��ʾ���򣬾Ͳ��ö��߳���

	Plain plain;

	//��������ʱ����0.0
	double curTime = 0.0;
	plain.SetTime(curTime);
	FlyControl *pFlyCtrl = new FlyControl;
	pFlyCtrl->Begin(curTime);
	plain.Attach(pFlyCtrl);
	//��������ʱ����0.1
	curTime = 0.1;
	RotateControl *pRoCtrl = new RotateControl;
	pRoCtrl->Begin(curTime);
	plain.Attach(pRoCtrl);

	while (plain.GetCount())
	{
		Sleep(200);
		// ģ��ʱ�������
		// 7.5�����ٶ�
		curTime += 1.5;
		plain.UpdateAllCtrls(curTime);
	}

	return 0;
}

// ������
//We have fly  1.6  meters!
//We have fly  3.1  meters!
//We have fly  4.6  meters!
//We have fly  6.1  meters!
//We have fly  7.6  meters!
//We have fly  9.1  meters!
//Complete fly!
//We have Rotate  1.5  degress
//We have Rotate  3  degress
//We have Rotate  4.5  degress
//We have Rotate  6  degress
//We have Rotate  7.5  degress
//We have Rotate  9  degress
//We have Rotate  10.5  degress
//We have Rotate  12  degress
//We have Rotate  13.5  degress
//We have Rotate  15  degress
//We have Rotate  16.5  degress
//We have Rotate  18  degress
//We have Rotate  19.5  degress
//Complete Rotate!
//�밴���������. . .