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

//一个具体的圣遗物
//因为写成结构体+函数的逻辑太繁复，直接封装成类

#include "./protocol_StarRailCaculator.h"
#include <random>

class RelicResult
{
	//依照副本类型构造一个圣遗物胚子
	//构造的时候直接调用getBirth函数
	//构造的随机性和随机数引擎的种子/使用位置完全相关
public:

	//一次模拟只调一次，为了性能
	RelicResult();
	~RelicResult();

protected:
	//初始化主属性随机刻度池
	void initPriproMap();
	//初始化副属性数量刻度
	void initSubProNumPos();

public:
	//随机产生打一次本获得的金仪器个数（2个或3个）
	static int   getRelicNum(std::default_random_engine& engine);

	//通过遗器部位判断打什么本
	static const En_raidType getRaidType(const En_RelicType relicTYpe);

	//是否到达最高等级
	const bool	isHighestLevel()	const { return m_CurrentLevel >= 15;};

	//主属性是否有效
	bool						isPrimePropertyValid(const St_RelicValidEstimatePara & EstPara);

	//获取副词条数量（副词缀显示有几个，而不是叠了多少次属性上去）
	const int					getSubPropertyNum();

public:
	//出生,一路升到满级，符合全部属性条件条件返回true，否则返回false（最小的构造代价）
	//1.选套装
	//2.选主属性
	//3.选择出生词条数
	//4.选择出生词条类型
	//一旦中间出现不符合条件的情形，立刻回复false，直到最后满足了参数条件才true
	//构造的随机性和随机数引擎的种子/使用位置完全相关
	bool					getBirth(const En_raidType& raidType,const St_RelicValidEstimatePara & EstPara, std::default_random_engine& engine);
	//重置参数
	void					resetPara();

//具体的随机函数，返回新的数值的同时设置成员变量
//模拟性能瓶颈所在
protected:
	//随机决定套装是否正确,
	bool					creatSetState(std::default_random_engine& engine);
	//随机决定生成的部位
	En_RelicType			creatType(const En_raidType raidType, std::default_random_engine& engine);
	//随机决定主属性
	En_RelicPrimeProperty	createPrimeProperty(std::default_random_engine& engine);
	//随机决定胚子有几个副属性
	int						createSubPropertyNum(std::default_random_engine& engine);
	//重置副属性随机池
	void					resetSubPropertyVec();
	//随机构造一个新的副属性
	En_RelicSubProperty		creatNewSubProperty(std::default_random_engine& engine);
	//加强一次（1-4/4-8/8-12/12-15），获得/强化一个副词缀
	//优先填满空词缀，无空词缀，则等可能强化一个副词缀，强化数值有3种可能
	//如果已经满级那么无法加强
	bool					upgradeOnce(const St_RelicValidEstimatePara & EstPara,std::default_random_engine& engine);
	//获取一个新词条的数值
	double					createNewSubPropertyValue(En_RelicSubProperty SubProType, std::default_random_engine& engine);
	//强化某一个词条
	void					upgradeOneSubProperty(En_RelicSubProperty SubProType,double value);
	//决定强化词条的位置（1/2/3/4）
	int						getUpgradeSubProPos(std::default_random_engine& engine);

	//检查主属性是否有效
	bool					checkPrimePropertyValid(const St_RelicValidEstimatePara& EstPara);
	//检查副属性词条是否有效
	bool					checkSubProTypeVaildity(En_RelicSubProperty SubProType, const St_RelicValidEstimatePara & EstPara);
	//检测某一个副属性数值是否有效
	bool					checkSubProValueVaildity(En_RelicSubProperty SubProType, double SubProValue, const St_RelicValidEstimatePara & EstPara);

//具体参数，方便调试
private:

	bool							m_bSetCorrect		= false;							//套装是否正确
	En_RelicType					m_relicType			= En_RelicType::None;				//圣遗物部位
	En_RelicPrimeProperty			m_primeProperty		= En_RelicPrimeProperty::None;		//圣遗物主属性


	int							m_CurrentLevel = 0;				//当前圣遗物等级,0表示没生成主属性

	//4个部位具体的词条，没有就是none
	En_RelicSubProperty			m_firstSubProType		= En_RelicSubProperty::None;
	En_RelicSubProperty			m_secondSubProType		= En_RelicSubProperty::None;
	En_RelicSubProperty			m_thirdSubProType		= En_RelicSubProperty::None;
	En_RelicSubProperty			m_fourthSubProType		= En_RelicSubProperty::None;


	//副词缀具体数值
	double	m_dHPValue			= 0;			//固定生命值
	double	m_dHPPercentage		= 0;			//百分比生命值
	double	m_dAttackValue		= 0;			//固定攻击力
	double	m_dAttackPercent	= 0;			//百分比攻击力
	double	m_dDefenceValue		= 0;			//固定防御力
	double	m_dDefencePercentage= 0;			//百分比防御力

	double	m_dCriticalProb		= 0;			//暴击率
	double	m_dCriticalDamage	= 0;			//暴击伤害
	double	m_dSpeed			= 0;			//速度

	double	m_dDeBuffDefence	= 0;			//效果抵抗
	double	m_dBreakDamage		= 0;			//击破特攻
	double	m_dDeBuffAccuracy	= 0;			//效果命中


	//衣服主属性随机用刻度
	QMap<int, En_RelicPrimeProperty> m_mapClothesPripro;

	//鞋子主属性随机用刻度
	QMap<int, En_RelicPrimeProperty> m_mapShoesPripro;

	//绳子主属性随机用刻度
	QMap<int, En_RelicPrimeProperty> m_mapCordPripro;

	//球主属性随机用刻度
	QMap<int, En_RelicPrimeProperty> m_mapBallPripro;

	//副属性数量刻度
	int m_Affix2Pos = 0;
	int m_Affix3Pos = 0;
	int m_Affix4Pos = 0;

	//副属性随机池
	QVector<En_RelicSubProperty> m_vecSubProperty;

};

#endif