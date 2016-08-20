// Flyweight.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>
#include <vector>
#include <string>
using namespace  std;

// ��Ԫģʽ��Flyweight�������ù�������Ч��֧�ִ���ϸ���ȵĶ���


// ���賡��

// ĳ����ά��Ϸ��������һƬɭ�֣�׼����һ������ͨ���ڷ�λ�ò�ͬ��
// ���ţ��ǶȲ�ͬ���������ڳ�һ��Ƭɭ�֡�

// ʱ���ϵ���Ȳ�д����������

class Obj
{
public:
  Obj(const string &str)
    : m_strName(str)
  {

  }
  virtual void PrintInfo() { ; }
protected:
  string m_strName;
};

// ģ�ͼ�����Ϣ
class Mesh : public Obj
{
public:
  Mesh(const string &str)
    : Obj(str)
  {

  }
  void PrintInfo() override
  {
    string str = "Mesh information of " + m_strName;
    printf(str.c_str());
  }
};


// ģ����̬��Ϣ,��ʵÿ��ģ�Ͷ����Լ�����̬
// ���ڼ���ֻ��ģ��������̬����Ҫ�Լ����õ�
class POSInfo
{
public:
  POSInfo(double centerX, double centerY, double centerZ,
    double yaw, double pitch, double roll,
    double xScale, double yScale, double zScale)
    : m_x(centerX)
    , m_y(centerY)
    , m_z(centerZ)
  {
    //.....
  }
  double  m_x;
  double	m_y;
  double	m_z;
};

// ģ������
class TreeModel
{
public:
  TreeModel(int id, const string & str_mesh_name)
    : m_pInfo(nullptr)
  {
    m_pMesh = new Mesh(str_mesh_name);
  }
  ~TreeModel()
  {
    //only need to  delete pos info
  }
  void CreateNewInstacne(POSInfo *pInfo)
  {
    m_pInfo = pInfo;
  }

  void PrintInfo()
  {
    printf("\n.........\n");
    m_pMesh->PrintInfo();
    printf("Tree mode id is %d", id);

    if (m_pInfo)
    {
      printf(" : \ndetail information :\nx:%lf, y:%lf, z:%lf", m_pInfo->m_x, m_pInfo->m_y, m_pInfo->m_z);
    }
    printf("\n.........\n");

  }
protected:
  Mesh* m_pMesh;
  int	id;
  POSInfo	  *m_pInfo;
};

class TreeModelFactory
{
public:
  TreeModelFactory()
  {
    TreeModel *pTM1 = new TreeModel(0, "����");
    TreeModel *pTM2 = new TreeModel(1, "С��");
    TreeModel *pTM3 = new TreeModel(2, "СС��");
    m_TreeModelVec.push_back(pTM1);
    m_TreeModelVec.push_back(pTM2);
    m_TreeModelVec.push_back(pTM3);
  }

  TreeModel* GetTreeInstance(int num)
  {
    if (num >= 0 && num <= 2)
    {
      return m_TreeModelVec[num];
    }
    return NULL;
  }
  ~TreeModelFactory()
  {
    // .......
    // delete tree
    // delete mesh
    // delete ro
  }
private:
  vector<TreeModel*> m_TreeModelVec;
};


int _tmain(int argc, _TCHAR* argv[])
{
  TreeModelFactory *pTreeFactory = new TreeModelFactory();

  TreeModel* pT1 = pTreeFactory->GetTreeInstance(0);
  pT1->CreateNewInstacne(new POSInfo(1, 2, 3, 0, 0, 0, 1, 2, 3));
  pT1->PrintInfo();

  TreeModel *pT2 = pTreeFactory->GetTreeInstance(2);
  pT2->CreateNewInstacne(new POSInfo(6, 2, 3, 7, 0, 0, 1, 2, 3));
  pT2->PrintInfo();

  TreeModel *pT3 = pTreeFactory->GetTreeInstance(2);
  pT3->CreateNewInstacne(new POSInfo(10, 12, 30, 7, 0, 0, 1, 2, 3));
  pT3->PrintInfo();

  pT2->PrintInfo();



  // ...
  // ...

  // ����ɭ�������е���ֻ�����ּ��������Ⱦ�壬�ȽϽ�ʡ�ڴ�
  // 

  // ��Ȼ�����Ҫ��ÿһ����ͬ����һ����Ż���Ҫ����ÿһ��������Ϣ�����Լ�һ��TreeInstance��
  // TreeIns������ţ�λ��ָ���treeModel��ָ�뼴��

  // �������Ҫ������Щ��Ϣ����ôֻ��Ҫ����PosInfo�б�
  // ��Ҫ��ʱ���ٽ�����ϣ�CreateNewInstacne����Ȼ���ӡ��Ϣ

  return 0;
}
