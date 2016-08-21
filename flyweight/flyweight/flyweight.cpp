// Flyweight.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>
#include <vector>
#include <string>
#include <map>
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
  virtual std::string GetName() { return m_strName; }
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
  TreeModel(const string & name)
  {
    m_pMesh = new Mesh(name);
  }

  ~TreeModel()
  {
    if (m_pMesh)
    {
      delete m_pMesh;
      m_pMesh = nullptr;
    }
  }

  void Draw(POSInfo *pInfo)
  {
    printf("\n.........\n");
    m_pMesh->PrintInfo();

    if (pInfo)
    {
      printf(" : \nWe will draw it at :\n(x:%lf, y:%lf, z:%lf)", pInfo->m_x, pInfo->m_y, pInfo->m_z);
    }

    printf("\n.........\n");
  }

protected:
  Mesh* m_pMesh;
};

class TreeModelFactory
{
public:
  TreeModelFactory()
  {
    std::vector<std::string> name_array = { "����", "С��", "СС��" };
    for (std::vector<std::string>::iterator iter = name_array.begin(); iter != name_array.end(); iter++)
    {
      m_TreeModelInstances[*iter] = new TreeModel(*iter);
    }
  }

  TreeModel* GetTreeInstance(std::string name)
  {
    std::map<std::string, TreeModel*>::iterator finder;
    finder = m_TreeModelInstances.find(name);
    if(finder != m_TreeModelInstances.end())
    {
      return finder->second;
    }
    else
    {
      m_TreeModelInstances[name] = new TreeModel(name);
    }
 }
  ~TreeModelFactory()
  {
    // .......
    // delete tree
    // delete mesh
    // delete ro
    // releas map
  }
private:
  std::map<std::string, TreeModel*> m_TreeModelInstances;
};


int _tmain(int argc, _TCHAR* argv[])
{
  TreeModelFactory *pTreeFactory = new TreeModelFactory();

  TreeModel* pT1 = pTreeFactory->GetTreeInstance("����");
  pT1->Draw(new POSInfo(1, 2, 3, 0, 0, 0, 1, 2, 3));

  TreeModel *pT2 = pTreeFactory->GetTreeInstance("С��");
  pT2->Draw(new POSInfo(6, 2, 3, 7, 0, 0, 1, 2, 3));

  pT2->Draw(new POSInfo(10, 12, 30, 7, 0, 0, 1, 2, 3));
  pT1->Draw(new POSInfo(10, 12, 30, 7, 0, 0, 1, 2, 3));



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
