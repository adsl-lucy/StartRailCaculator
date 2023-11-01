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

#ifndef PROTOCOL_STARRAILCACULATOR
#define PROTOCOL_STARRAILCACULATOR

//基本定义以及全局常量所在
//之所以叫protocol，是因为相比base_define这更像一个模块之间的通信协议

#include <QDate>
#include <QDateTime>
#include <QVector>
#include <QMap>

#include "DoubleMatrix.h"


	//游戏运维常量
	const QDateTime Const_StarRailOpenDay	= QDateTime(QDate(2023, 4, 26), QTime(10, 0));		//开服日期为2023/4/26 10:00
	const QDateTime Const_StarRailLatestDay = QDateTime(QDate(2024, 4, 26), QTime(10, 0));		//允许计算的最晚日期为2024/4/26 10:00（不然误差太大了）
	
	//42天一个大版本
	//一个大版本刷新会刷新大月卡，并且运维会送维护300氵+修BUG300氵（直播奖励不算）
	const int		Const_BigMonthCardPeriod = 42;
	
	//最高等级模拟宇宙每周打完送225氵
	const int		Const_MonitorSpaceCrystal = 225;

	//深渊1层60水
	const int		Const_AbyssCrystalPerLevel = 60;

	//卡池常量
	const double	Const_GoldCharacterProbability		= 0.006;	//五星角色出率
	const double    Const_GoldUpCharacterProbability	= 0.5;		//五星角色是UP角色的概率
	const double	Const_GoldWeaponProbability		= 0.008;	//五星武器出率
	const double	Const_GoldUpWeaponProbability		= 0.75;		//五星武器是UP武器的概率
	const int	Const_LargestGetGoldCharTNum		= 90;		//五星角色保底数量
	const int	Const_LargetGetGoldWeaponTNum		= 80;		//五星武器保底数量

//星铁计算器错误码
enum class EN_StarRailErrorNum : int	
{
	//资源计算器输入错误码

	ResouceEst_InputNoError,			//没有输入错误

	ResouceEst_StartDateTooEarly,			//开始日期早于开服日期
	ResouceEst_StartDateTooLate,			//终止日期晚于开服两年后（其实是懒得搞长图表）
	ResouceEst_StartEndSameDay,			//开始日期和终止日期相同
	ResouceEst_StartDayLateThanEndDay,		//终止日期早于起始日期
	ResouceEst_StopDayTooLate,			//终止日期太晚

	ResouceEst_CurrentTicketNumInvaild,		//当前票数无效
	ResouceEst_CurrentCrystalInvaild,		//当前星琼无效
	ResouceEst_SmallMonthCardRemainDayInvaild,	//小月卡剩余天数无效
	ResouceEst_CurrentPaidCrystalInvaild,		//当前古老梦华无效
	ResouceEst_AbyssAverageNumInvaild,		//深渊平均通关数无效

	//圣遗物估算
	RelicEst_InputNoError,

	RelicEst_NoPlayTime,				//打本次数为0
	RelicEst_ValidPrimePropertyZero,		//没选有效主属性
	RelicEst_ValidSubPropertyLessThan4,		//有效副属性小于4个
};



//资源计算参数
struct St_ResourceEstimateParameter
{
	QDate	startDate;				//开始日期
	QDate	stopDate;				//结束日期
	int	currentTicket		= 0;		//当前专票
	int	currentCrystal		= 0;		//当前星琼
	int	currentPaidCrystal	= 0;		//当前古老梦华
	bool	buySmallMonthCard	= true;		//买不买小月卡
	bool	buyBigMonthCard		= false;	//买不买大月卡
	int	smallMonthCardLastday	= 0;		//当前小月卡剩余天数
	int	abyssAverageNum		= 0;		//平均深渊剩余天数
};

//资源计算返回结果中某一天的状态
struct St_ResourceEstimateDateResult
{
	QDate	currentDate;						//当天日期
	int	TodayCrystalIncome	= 0;			//当天星琼收益

	int	currentTicket		= 0;			//当前专票
	int	currentCrystal		= 0;			//当前星琼
	int	currentPaidCrystal	= 0;			//当前古老梦华

	bool	buySmallMonthCard	= false;		//当天购买了小月卡
	bool	buyBigMonthCard		= false;		//当天购买了大月卡

	bool	playAbyss		= false;		//当天打了新深渊
	bool	playMonitorSpace	= false;		//当天打了模拟宇宙

	int	currentdayExpense		= 0;		//当天开销
	int	totalSmallCardExpence		= 0;		//累计小月卡投入	
	int	totalBigMonthCardExpence	= 0;		//累计大月卡投入
	int	totalExpense			= 0;		//累计总投入
};

//卡池类型
enum class EN_CardPoolType : int
{
	character,	//角色池
	weapon,		//武器池
};

//单次抽卡结果
enum class En_DrawCardResult : int
{
	normal,			//普通卡（辣鸡）
	character_wrongGold,	//角色池歪了
	character_UpGold,	//角色池出货
	weapon_wrongGold,	//武器池歪了
	weapon_UpGold		//武器池出货
};

//卡池停止实验计算参数
struct St_CardPoolEstimatePara
{
	EN_CardPoolType	poolType = EN_CardPoolType::character;	//计算的卡池类型
	bool		wrongGold = false;			//上一个五星歪了
	int		areadyInTicket = 0;			//已经垫了多少抽
};

//N步之内出货概率结果
struct St_CardPoolEstimateResult
{
	EN_CardPoolType	poolType		= EN_CardPoolType::character;//卡池类型
	int		distanceToBigGuarantee	= 0;		//最大抽数
	bool		smallGuaranteeInCase	= true;		//这个抽卡过程是否存在小保底（比如上一个金歪了，那就只有大保底）
	double		smallGraranteeGetUpProb	= 0;		//小保底位置出货概率
	double		bigGuaranteeGetTupProb	= 0;		//大保底才出货概率
	double		getUpPosExpectation	= 0;		//期望出货位置
	double		crystalExpenExpectation	= 0;		//期望投入星琼
	QMap<int, double> mapPorbDistribution;			//累计出货概率分布模拟结论
};

//抽卡对象
enum class En_DrawCardType : int
{
	characterOnly,	//只抽角色
	waeponOnly,	//只抽武器
	getAll,		//我全都要
};

//卡池切换方式
enum class En_PoolTransfromType :int
{
	NCharacterMWeapon,	//角色出货N次再武器出货M次
	NWeaponMCharacter,	//武器出货N次再角色出货M次
	NTCharacterMTWeapon,	//角色池投入N抽，武器池投入M抽
	NTWeaponMTCharacter,	//武器池投入N抽，角色池投入M抽
};

//资源投入与出货分析计算参数
struct St_InvestmentEstimatePara
{
	int inputCrystal	= 0;//投入星琼
	int inputTicket		= 0;//投入专票

	En_DrawCardType		drawCardType		= En_DrawCardType::characterOnly;		//抽卡对象
	En_PoolTransfromType	poolTransformType	= En_PoolTransfromType::NCharacterMWeapon;	//轮换方式

	bool lastGoldCharacterWrong		= false;	//上一个五星角色是否歪了
	int  areadyInCharacterPoolTicket	= 0;		//角色池已经投入的抽数（距离上一个五星角色）
	bool lastGoldWeaponWrong		= false;	//上一个五星武器是否歪了
	int  areadyInWeaponPoolTicket		= 0;		//武器池已经投入的抽数（距离上一个五星武器）

	//轮换参数，N为第一个输入框，M为第二个输入框
	int N = 0;
	int M = 0;

};

//资源投入与出货分析计算结果
struct St_InvectmentEstimateResult
{
	int inputCrystal	= 0;	//投入星琼（没算专票）
	int inputTicket		= 0;	//投入专票（没算星琼）

	En_DrawCardType		drawCardType		= En_DrawCardType::characterOnly;		//抽卡方式
	En_PoolTransfromType	poolTransformType	= En_PoolTransfromType::NCharacterMWeapon;	//轮换方式
	//轮换参数，N为第一个输入框，M为第二个输入框
	int N = 0;
	int M = 0;


	double NoUpCharacterPorb		= 0;	//UP角色沉船概率
	double UpCharacterGetTimeExpectation	= 0;	//UP角色获取期望

	double NoUpWeaponProb			= 0;	//UP武器沉船概率
	double UpWeaponGetExpectation		= 0;	//UP武器获取期望

	DoubleMatrix ProbDensityMatrix;		//概率分布矩阵，行是获取UP角色数量，列是获取UP武器数量，值是概率

};

//圣遗物
	const double	Const_3RelicProb = 0.1;		//65级均衡本出3金仪器概率（剩余概率就是2金）

	//衣服主属性概率
	const double	Const_PriPro_ratio_clothes_HPPercentage		= 0.22;
	const double	Const_PriPro_ratio_clothes_attackPercentage	= 0.22;
	const double	Const_PriPro_ratio_clothes_defencePercentage	= 0.22;
	const double	Const_PriPro_ratio_clothes_CRITProb		= 0.10;
	const double	Const_PriPro_ratio_clothes_CRITDamage		= 0.10;
	const double	Const_PriPro_ratio_clothes_HealAddition		= 0.10;
	const double	Const_PriPro_ratio_clothes_DebuffAccuracy	= 0.04;

	//鞋子主属性概率
	const double	Const_PriPro_ratio_shoes_HPPercentage		= 0.3;
	const double	Const_PriPro_ratio_shoes_attackPercentage	= 0.3;
	const double	Const_PriPro_ratio_shoes_defencePercentage	= 0.3;
	const double	Const_PriPro_ratio_shoes_speed			= 0.1;

	//绳子主属性概率(加起来是99.9%)
	const double	Const_PriPro_ratio_cord_HPPercentage		= 0.283;
	const double	Const_PriPro_ratio_cord_attackPercentage	= 0.283;
	const double	Const_PriPro_ratio_cord_defencePercentage	= 0.283;
	const double	Const_PriPro_ratio_cord_breakDamage		= 0.1;
	const double	Const_PriPro_ratio_cord_chargeEfficiency	= 0.05;

	//球主属性概率(加起来是100.1%)
	const double	Const_PriPro_ratio_ball_HPPercentage		= 0.147;
	const double	Const_PriPro_ratio_ball_attackPercentage	= 0.147;
	const double	Const_PriPro_ratio_ball_defencePercentage	= 0.147;

	const double	Const_PriPro_ratio_ball_fire			= 0.08;
	const double	Const_PriPro_ratio_ball_thunder			= 0.08;
	const double	Const_PriPro_ratio_ball_wind			= 0.08;
	const double	Const_PriPro_ratio_ball_ice			= 0.08;
	const double	Const_PriPro_ratio_ball_null			= 0.08;
	const double	Const_PriPro_ratio_ball_quantum			= 0.08;
	const double	Const_PriPro_ratio_ball_physical		= 0.08;

	//出货副词条数量概率
	const double	Const_ratio_SubPro_2Affix = 0.33;//出货2词条
	const double	Const_ratio_SubPro_3Affix = 0.33;//出货3词条
	const double	Const_ratio_SubPro_4Affix = 0.33;//出货4词条

	//副词缀权重
	const int	Const_SubPro_weight_HPValue		= 11;	//固定生命值
	const int	Const_SubPro_weight_HPPercentage	= 11;	//百分比生命值
	const int	Const_SubPro_weight_attackValue		= 11;	//固定攻击力
	const int	Const_SubPro_weight_attackPercentage	= 11;	//百分比攻击
	const int	Const_SubPro_weight_defenceValue	= 11;	//固定防御力
	const int	Const_SubPro_weight_defencePercentage	= 11;	//百分比防御
	const int	Const_SubPro_weight_CRITProb		= 7;	//暴击率
	const int	Const_SubPro_weight_CRITDamage		= 7;	//暴击伤害
	const int	Const_SubPro_weight_DebuffDefence	= 5;	//效果抵抗
	const int	Const_SubPro_weight_DebuffAccuracy	= 5;	//效果命中
	const int	Const_SubPro_weight_breakDamage		= 5;	//击破特攻
	const int	Const_SubPro_weight_speed		= 5;	//速度

	//副词缀强化值
	//固定生命值
	const double	Const_SubPro_value_caseA_HPValue = 33.8;	
	const double	Const_SubPro_value_caseB_HPValue = 38;	
	const double	Const_SubPro_value_caseC_HPValue = 42;	

	//百分比生命值
	const double	Const_SubPro_value_caseA_HPPercentage = 0.0346;	
	const double	Const_SubPro_value_caseB_HPPercentage = 0.0389;	
	const double	Const_SubPro_value_caseC_HPPercentage = 0.0432;	

	//固定攻击力
	const double	Const_SubPro_value_caseA_attackValue = 16.9;	
	const double	Const_SubPro_value_caseB_attackValue = 19;	
	const double	Const_SubPro_value_caseC_attackValue = 21;	

	//百分比攻击
	const double	Const_SubPro_value_caseA_aattackPercentage = 0.0346;	
	const double	Const_SubPro_value_caseB_aattackPercentage = 0.0389;	
	const double	Const_SubPro_value_caseC_aattackPercentage = 0.0432;

	//固定防御力
	const double	Const_SubPro_value_caseA_defenceValue = 16.9;	
	const double	Const_SubPro_value_caseB_defenceValue = 19;	
	const double	Const_SubPro_value_caseC_defenceValue = 21;	

	//百分比防御
	const double	Const_SubPro_value_caseA_defencePercentage = 0.0432;	
	const double	Const_SubPro_value_caseB_defencePercentage = 0.0486;	
	const double	Const_SubPro_value_caseC_defencePercentage = 0.054;	

	//暴击率
	const double	Const_SubPro_value_caseA_CRITProb = 0.0259;	
	const double	Const_SubPro_value_caseB_CRITProb = 0.0292;	
	const double	Const_SubPro_value_caseC_CRITProb = 0.0324;	

	//暴击伤害
	const double	Const_SubPro_value_caseA_CRITDamage = 0.0518;	
	const double	Const_SubPro_value_caseB_CRITDamage = 0.0583;	
	const double	Const_SubPro_value_caseC_CRITDamage = 0.0648;	

	//效果抵抗
	const double	Const_SubPro_value_caseA_DebuffDefence = 0.0346;	
	const double	Const_SubPro_value_caseB_DebuffDefence = 0.0389;
	const double	Const_SubPro_value_caseC_DebuffDefence = 0.0432;

	//效果命中
	const double	Const_SubPro_value_caseA_DebuffAccuracy = 0.0346;
	const double	Const_SubPro_value_caseB_DebuffAccuracy = 0.0389;
	const double	Const_SubPro_value_caseC_DebuffAccuracy = 0.0432;

	//击破特攻
	const double	Const_SubPro_value_caseA_breakDamage = 0.0518;
	const double	Const_SubPro_value_caseB_breakDamage = 0.0583;
	const double	Const_SubPro_value_caseC_breakDamage = 0.0648;

	//速度
	const double	Const_SubPro_value_caseA_speed = 2;
	const double	Const_SubPro_value_caseB_speed = 2.25;
	const double	Const_SubPro_value_caseC_speed = 2.5;


//副本类型
enum class En_raidType:int
{
	Relic,//遗器本
	SimulateUniverse,//模拟宇宙
};

//圣遗物部位
enum class En_RelicType :int
{
	None,		//未生成（Debug用）
	Head,		//头
	Hand,		//手
	Clothes,	//衣服
	Shoes,		//鞋子
	Cord,		//绳子
	Ball		//球
};

//圣遗物主属性
enum class En_RelicPrimeProperty :int
{
	None,				//没有主属性（Debug用）
	HPValue,			//固定生命值
	HPPercentage,			//百分比生命值
	AttackValue,			//固定攻击力
	AttackPercentage,		//百分比攻击力
	DefencePercentage,		//百分比防御
	CriticalProb,			//暴击率
	CriticalDamage,			//暴击伤害
	Speed,				//速度
	ChargeEfficiency,		//充能效率
	BreakDamage,			//击破特攻
	DeBuffAccuracy,			//效果命中
	HealAddition,			//治疗加成

	Fire,				//火伤加成
	Thunder,			//雷伤加成
	Wind,				//风伤加成
	Ice,				//冰伤加成
	Null,				//虚无加成
	Quantum,			//量子加成
	Physical			//物理加成
};

//圣遗物副属性
enum class En_RelicSubProperty :int
{
	None,				//没属性，用于添加词缀逻辑

	HPValue,			//固定生命值
	HPPercentage,			//百分比生命值
	AttackValue,			//固定攻击力
	AttackPercentage,		//百分比攻击力
	DefenceValue,			//固定防御力
	DefencePercentage,		//百分比防御力

	CriticalProb,			//暴击率
	CriticalDamage,			//暴击伤害
	Speed,				//速度

	DeBuffDefence,			//效果抵抗
	BreakDamage,			//击破特攻
	DeBuffAccuracy,			//效果命中
};

//有效圣遗物参数
struct St_RelicValidEstimatePara
{
	int	playTime	= 0;//打本次数

	En_RelicType	relicType = En_RelicType::None;				//计算圣遗物部位
	
	//圣遗物有效主属性标志位
	bool		PrimePro_Valid_HPValue			= false;	//固定生命值
	bool		PrimePro_Valid_HPPercentage		= false;	//百分比生命值
	bool		PrimePro_Valid_AttackValue		= false;	//固定攻击力
	bool		PrimePro_Valid_AttackPercentage		= false;	//百分比攻击力
	bool		PrimePro_Valid_DefencePercentage	= false;	//百分比防御
	bool		PrimePro_Valid_CriticalProb		= false;	//暴击率
	bool		PrimePro_Valid_CriticalDamage		= false;	//暴击伤害
	bool		PrimePro_Valid_Speed			= false;	//速度
	bool		PrimePro_Valid_ChargeEfficiency		= false;	//充能效率
	bool		PrimePro_Valid_BreakDamage		= false;	//击破特攻
	bool		PrimePro_Valid_DeBuffAccuracy		= false;	//效果命中
	bool		PrimePro_Valid_HealAddition		= false;	//治疗加成

	bool		PrimePro_Valid_Fire			= false;	//火伤加成
	bool		PrimePro_Valid_Thunder			= false;	//雷伤加成
	bool		PrimePro_Valid_Wind			= false;	//风伤加成
	bool		PrimePro_Valid_Ice			= false;	//冰伤加成
	bool		PrimePro_Valid_Null			= false;	//虚无加成
	bool		PrimePro_Valid_Quantum			= false;	//量子加成
	bool		PrimePro_Valid_Physical			= false;	//物理加成

	//圣遗物有效副属性标志位
	bool		SubPro_Valid_HPValue			= true;		//固定生命值
	bool		SubPro_Valid_HPPercentage		= true;		//百分比生命值
	bool		SubPro_Valid_AttackValue		= true;		//固定攻击力
	bool		SubPro_Valid_AttackPercentage		= true;		//百分比攻击力
	bool		SubPro_Valid_DefenceValue		= true;		//固定防御力
	bool		SubPro_Valid_DefencePercentage		= true;		//百分比防御力

	bool		SubPro_Valid_CriticalProb		= true;		//暴击率
	bool		SubPro_Valid_CriticalDamage		= true;		//暴击伤害
	bool		SubPro_Valid_Speed			= true;		//速度

	bool		SubPro_Valid_DeBuffDefence		= true;		//效果抵抗
	bool		SubPro_Valid_BreakDamage		= true;		//击破特攻
	bool		SubPro_Valid_DeBuffAccuracy		= true;		//效果命中

	//圣遗物副属性有效数值
	double		SubPro_Value_HP				= 0;		//固定生命值
	double		SubPro_Value_HPPercentage		= 0;		//百分比生命值
	double		SubPro_Value_AttackValue		= 0;		//固定攻击力
	double		SubPro_Value_AttackPercentage		= 0;		//百分比攻击力
	double		SubPro_Value_DefenceValue		= 0;		//固定防御力
	double		SubPro_Value_DefencePercentage		= 0;		//百分比防御力

	double		SubPro_Value_CriticalProb		= 0;		//暴击率
	double		SubPro_Value_CriticalDamage		= 0;		//暴击伤害
	double		SubPro_Value_Speed			= 0;		//速度

	double		SubPro_Value_DeBuffDefence		= 0;		//效果抵抗
	double		SubPro_Value_BreakDamage		= 0;		//击破特攻
	double		SubPro_Value_DeBuffAccuracy		= 0;		//效果命中

	//有哪些副属性存在数值要求
	QVector<En_RelicSubProperty> vecSubPropertyValueRequirement;

};

//有效圣遗物具体计算结果
struct St_ValidRelicEstimateResult
{
	double	primePropertyValidProportion		= 0;		//主属性有效的遗物占所有遗物的比例
	double  primePropertyValidGetProbbability	= 0;		//获取主属性有效遗物概率（获取次数/打本次数）
	double	primePropertyValidGetTimeExpectation	= 0;		//主属性有效遗器获取期望(主属性有效遗物个数/获取遗物总个数)
	double	primePropertyValidPlayTimeExpectation	= 0;		//获取一个主属性有效遗器需要打本次数的期望

	double	allPropertyValidProportion		= 0;		//全属性有效的遗物占所有遗物的比例
	double  allPropertyValidGetProbbability		= 0;		//获取全属性有效遗物概率（获取次数/打本次数）
	double	allPropertyValidGetTimeExpectation	= 0;		//全属性有效遗器获取期望(全属性有效遗物个数/获取遗物总个数)	
	double	allPropertyValidPlayTimeExpectation	= 0;		//获取一个全属性有效遗器需要打本次数的期望	

	QMap <int, double>	mapPriProValidGetNumProb;		//主属性有效遗器对（主属性有效遗物个数，发生概率）	
	QMap <int, double>	mapAllProValidGetNumProb;		//全属性有效遗器对（副属性有效遗物个数，发生概率），副属性有效+主属性有效
	
};


#endif // !PROTOCOL_STARRAILCACULATOR
