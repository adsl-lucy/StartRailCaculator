/*****************************************************************************************
**	Copyright(C) <2023-2024> <adsl_lucy>
**
**	Permission is hereby granted, free of charge, to any person obtaining a copy
**	of this software and associated documentation files(the "Software"), to deal
**	in the Software without restriction, including without limitation the rights
**	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
**	copies of the Software, and to permit persons to whom the Software is furnished
**	to do so, subject to the following conditions :
**
**	The above copyright notice and this permission notice shall be included in all
**	copies or substantial portions of the Software.THE SOFTWARE IS PROVIDED "AS IS",
**	WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
**	THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
**	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
**	OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
**	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
*****************************************************************************************/

#ifndef RELIC_RESULT
#define RELIC_RESULT

//һ�������ʥ����
//��Ϊд�ɽṹ��+�������߼�̫������ֱ�ӷ�װ����

#include "./protocol_StarRailCaculator.h"
#include <random>

class RelicResult
{
	//���ո������͹���һ��ʥ��������
	//�����ʱ��ֱ�ӵ���getBirth����
	//���������Ժ���������������/ʹ��λ����ȫ���
public:

	//һ��ģ��ֻ��һ�Σ�Ϊ������
	RelicResult();
	~RelicResult();

protected:
	//��ʼ������������̶ȳ�
	void initPriproMap();
	//��ʼ�������������̶�
	void initSubProNumPos();

public:
	//���������һ�α���õĽ�����������2����3����
	static int   getRelicNum(std::default_random_engine& engine);

	//ͨ��������λ�жϴ�ʲô��
	static const En_raidType getRaidType(const En_RelicType relicTYpe);

	//�Ƿ񵽴���ߵȼ�
	const bool	isHighestLevel()	const { return m_CurrentLevel >= 15;};

	//�������Ƿ���Ч
	bool						isPrimePropertyValid(const St_RelicValidEstimatePara & EstPara);

	//��ȡ����������������׺��ʾ�м����������ǵ��˶��ٴ�������ȥ��
	const int					getSubPropertyNum();

public:
	//����,һ·��������������ȫ������������������true�����򷵻�false����С�Ĺ�����ۣ�
	//1.ѡ��װ
	//2.ѡ������
	//3.ѡ�����������
	//4.ѡ�������������
	//һ���м���ֲ��������������Σ����̻ظ�false��ֱ����������˲���������true
	//���������Ժ���������������/ʹ��λ����ȫ���
	bool					getBirth(const En_raidType& raidType,const St_RelicValidEstimatePara & EstPara, std::default_random_engine& engine);
	//���ò���
	void					resetPara();

//�������������������µ���ֵ��ͬʱ���ó�Ա����
//ģ������ƿ������
protected:
	//���������װ�Ƿ���ȷ,
	bool					creatSetState(std::default_random_engine& engine);
	//����������ɵĲ�λ
	En_RelicType			creatType(const En_raidType raidType, std::default_random_engine& engine);
	//�������������
	En_RelicPrimeProperty	createPrimeProperty(std::default_random_engine& engine);
	//������������м���������
	int						createSubPropertyNum(std::default_random_engine& engine);
	//���ø����������
	void					resetSubPropertyVec();
	//�������һ���µĸ�����
	En_RelicSubProperty		creatNewSubProperty(std::default_random_engine& engine);
	//��ǿһ�Σ�1-4/4-8/8-12/12-15�������/ǿ��һ������׺
	//���������մ�׺���޿մ�׺����ȿ���ǿ��һ������׺��ǿ����ֵ��3�ֿ���
	//����Ѿ�������ô�޷���ǿ
	bool					upgradeOnce(const St_RelicValidEstimatePara & EstPara,std::default_random_engine& engine);
	//��ȡһ���´�������ֵ
	double					createNewSubPropertyValue(En_RelicSubProperty SubProType, std::default_random_engine& engine);
	//ǿ��ĳһ������
	void					upgradeOneSubProperty(En_RelicSubProperty SubProType,double value);
	//����ǿ��������λ�ã�1/2/3/4��
	int						getUpgradeSubProPos(std::default_random_engine& engine);

	//����������Ƿ���Ч
	bool					checkPrimePropertyValid(const St_RelicValidEstimatePara& EstPara);
	//��鸱���Դ����Ƿ���Ч
	bool					checkSubProTypeVaildity(En_RelicSubProperty SubProType, const St_RelicValidEstimatePara & EstPara);
	//���ĳһ����������ֵ�Ƿ���Ч
	bool					checkSubProValueVaildity(En_RelicSubProperty SubProType, double SubProValue, const St_RelicValidEstimatePara & EstPara);

//����������������
private:

	bool							m_bSetCorrect		= false;							//��װ�Ƿ���ȷ
	En_RelicType					m_relicType			= En_RelicType::None;				//ʥ���ﲿλ
	En_RelicPrimeProperty			m_primeProperty		= En_RelicPrimeProperty::None;		//ʥ����������


	int							m_CurrentLevel = 0;				//��ǰʥ����ȼ�,0��ʾû����������

	//4����λ����Ĵ�����û�о���none
	En_RelicSubProperty			m_firstSubProType		= En_RelicSubProperty::None;
	En_RelicSubProperty			m_secondSubProType		= En_RelicSubProperty::None;
	En_RelicSubProperty			m_thirdSubProType		= En_RelicSubProperty::None;
	En_RelicSubProperty			m_fourthSubProType		= En_RelicSubProperty::None;


	//����׺������ֵ
	double	m_dHPValue			= 0;			//�̶�����ֵ
	double	m_dHPPercentage		= 0;			//�ٷֱ�����ֵ
	double	m_dAttackValue		= 0;			//�̶�������
	double	m_dAttackPercent	= 0;			//�ٷֱȹ�����
	double	m_dDefenceValue		= 0;			//�̶�������
	double	m_dDefencePercentage= 0;			//�ٷֱȷ�����

	double	m_dCriticalProb		= 0;			//������
	double	m_dCriticalDamage	= 0;			//�����˺�
	double	m_dSpeed			= 0;			//�ٶ�

	double	m_dDeBuffDefence	= 0;			//Ч���ֿ�
	double	m_dBreakDamage		= 0;			//�����ع�
	double	m_dDeBuffAccuracy	= 0;			//Ч������


	//�·�����������ÿ̶�
	QMap<int, En_RelicPrimeProperty> m_mapClothesPripro;

	//Ь������������ÿ̶�
	QMap<int, En_RelicPrimeProperty> m_mapShoesPripro;

	//��������������ÿ̶�
	QMap<int, En_RelicPrimeProperty> m_mapCordPripro;

	//������������ÿ̶�
	QMap<int, En_RelicPrimeProperty> m_mapBallPripro;

	//�����������̶�
	int m_Affix2Pos = 0;
	int m_Affix3Pos = 0;
	int m_Affix4Pos = 0;

	//�����������
	QVector<En_RelicSubProperty> m_vecSubProperty;

};

#endif