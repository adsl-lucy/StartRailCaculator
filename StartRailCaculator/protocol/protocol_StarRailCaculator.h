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

//���������Լ�ȫ�ֳ�������
//֮���Խ�protocol������Ϊ���base_define�����һ��ģ��֮���ͨ��Э��

#include <QDate>
#include <QDateTime>
#include <QVector>
#include <QMap>

#include "DoubleMatrix.h"


	//��Ϸ��ά����
	const QDateTime Const_StarRailOpenDay	= QDateTime(QDate(2023, 4, 26), QTime(10, 0));		//��������Ϊ2023/4/26 10:00
	const QDateTime Const_StarRailLatestDay = QDateTime(QDate(2024, 4, 26), QTime(10, 0));		//����������������Ϊ2024/4/26 10:00����Ȼ���̫���ˣ�
	
	//42��һ����汾
	//һ����汾ˢ�»�ˢ�´��¿���������ά����ά��300��+��BUG300�ߣ�ֱ���������㣩
	const int		Const_BigMonthCardPeriod = 42;
	
	//��ߵȼ�ģ������ÿ�ܴ�����225��
	const int		Const_MonitorSpaceCrystal = 225;

	//��Ԩ1��60ˮ
	const int		Const_AbyssCrystalPerLevel = 60;

	//���س���
	const double	Const_GoldCharacterProbability				=	0.006;		//���ǽ�ɫ����
	const double    Const_GoldUpCharacterProbability			=	0.5;		//���ǽ�ɫ��UP��ɫ�ĸ���
	const double	Const_GoldWeaponProbability					=   0.008;		//������������
	const double	Const_GoldUpWeaponProbability				=	0.75;		//����������UP�����ĸ���
	const int		Const_LargestGetGoldCharTNum				=	90;			//���ǽ�ɫ��������
	const int		Const_LargetGetGoldWeaponTNum				=	80;			//����������������

//����������������
enum class EN_StarRailErrorNum : int	
{
	//��Դ���������������

	ResouceEst_InputNoError,						//û���������

	ResouceEst_StartDateTooEarly,					//��ʼ�������ڿ�������
	ResouceEst_StartDateTooLate,					//��ֹ�������ڿ����������ʵ�����ø㳤ͼ��
	ResouceEst_StartEndSameDay,						//��ʼ���ں���ֹ������ͬ
	ResouceEst_StartDayLateThanEndDay,				//��ֹ����������ʼ����
	ResouceEst_StopDayTooLate,						//��ֹ����̫��

	ResouceEst_CurrentTicketNumInvaild,				//��ǰƱ����Ч
	ResouceEst_CurrentCrystalInvaild,				//��ǰ������Ч
	ResouceEst_SmallMonthCardRemainDayInvaild,		//С�¿�ʣ��������Ч
	ResouceEst_CurrentPaidCrystalInvaild,			//��ǰ�����λ���Ч
	ResouceEst_AbyssAverageNumInvaild,				//��Ԩƽ��ͨ������Ч

	//ʥ�������
	RelicEst_InputNoError,

	RelicEst_NoPlayTime,					//�򱾴���Ϊ0
	RelicEst_ValidPrimePropertyZero,		//ûѡ��Ч������
	RelicEst_ValidSubPropertyLessThan4,		//��Ч������С��4��
};



//��Դ�������
struct St_ResourceEstimateParameter
{
	QDate	startDate;								//��ʼ����
	QDate	stopDate;								//��������
	int		currentTicket			= 0;			//��ǰרƱ
	int		currentCrystal			= 0;			//��ǰ����
	int		currentPaidCrystal		= 0;			//��ǰ�����λ�
	bool	buySmallMonthCard		= true;			//����С�¿�
	bool	buyBigMonthCard			= false;		//������¿�
	int		smallMonthCardLastday	= 0;			//��ǰС�¿�ʣ������
	int		abyssAverageNum			= 0;			//ƽ����Ԩʣ������
};

//��Դ���㷵�ؽ����ĳһ���״̬
struct St_ResourceEstimateDateResult
{
	QDate	currentDate;							//��������
	int		TodayCrystalIncome		= 0;			//������������

	int		currentTicket			= 0;			//��ǰרƱ
	int		currentCrystal			= 0;			//��ǰ����
	int		currentPaidCrystal		= 0;			//��ǰ�����λ�

	bool	buySmallMonthCard		= false;		//���칺����С�¿�
	bool	buyBigMonthCard			= false;		//���칺���˴��¿�

	bool	playAbyss				= false;		//�����������Ԩ
	bool	playMonitorSpace		= false;		//�������ģ������

	int		currentdayExpense			= 0;		//���쿪��
	int		totalSmallCardExpence		= 0;		//�ۼ�С�¿�Ͷ��	
	int		totalBigMonthCardExpence	= 0;		//�ۼƴ��¿�Ͷ��
	int		totalExpense				= 0;		//�ۼ���Ͷ��
};

//��������
enum class EN_CardPoolType : int
{
	character,		//��ɫ��
	weapon,			//������
};

//���γ鿨���
enum class En_DrawCardResult : int
{
	normal,					//��ͨ����������
	character_wrongGold,	//��ɫ������
	character_UpGold,		//��ɫ�س���
	weapon_wrongGold,		//����������
	weapon_UpGold			//�����س���
};

//����ֹͣʵ��������
struct St_CardPoolEstimatePara
{
	EN_CardPoolType	poolType = EN_CardPoolType::character;		//����Ŀ�������
	bool			wrongGold = false;							//��һ����������
	int				areadyInTicket = 0;							//�Ѿ����˶��ٳ�
};

//N��֮�ڳ������ʽ��
struct St_CardPoolEstimateResult
{
	EN_CardPoolType	poolType					= EN_CardPoolType::character;//��������
	int				distanceToBigGuarantee		= 0;		//������
	bool			smallGuaranteeInCase		= true;		//����鿨�����Ƿ����С���ף�������һ�������ˣ��Ǿ�ֻ�д󱣵ף�
	double			smallGraranteeGetUpProb		= 0;		//С����λ�ó�������
	double			bigGuaranteeGetTupProb		= 0;		//�󱣵ײų�������
	double			getUpPosExpectation			= 0;		//��������λ��
	double			crystalExpenExpectation		= 0;		//����Ͷ������
	QMap<int, double> mapPorbDistribution;					//�ۼƳ������ʷֲ�ģ�����
};

//�鿨����
enum class En_DrawCardType : int
{
	characterOnly,	//ֻ���ɫ
	waeponOnly,		//ֻ������
	getAll,			//��ȫ��Ҫ
};

//�����л���ʽ
enum class En_PoolTransfromType :int
{
	NCharacterMWeapon,		//��ɫ����N������������M��
	NWeaponMCharacter,		//��������N���ٽ�ɫ����M��
	NTCharacterMTWeapon,	//��ɫ��Ͷ��N�飬������Ͷ��M��
	NTWeaponMTCharacter,	//������Ͷ��N�飬��ɫ��Ͷ��M��
};

//��ԴͶ������������������
struct St_InvestmentEstimatePara
{
	int inputCrystal	= 0;//Ͷ������
	int inputTicket		= 0;//Ͷ��רƱ

	En_DrawCardType			drawCardType		= En_DrawCardType::characterOnly;			//�鿨����
	En_PoolTransfromType	poolTransformType	= En_PoolTransfromType::NCharacterMWeapon;	//�ֻ���ʽ

	bool lastGoldCharacterWrong			= false;	//��һ�����ǽ�ɫ�Ƿ�����
	int  areadyInCharacterPoolTicket	= 0;		//��ɫ���Ѿ�Ͷ��ĳ�����������һ�����ǽ�ɫ��
	bool lastGoldWeaponWrong			= false;	//��һ�����������Ƿ�����
	int  areadyInWeaponPoolTicket		= 0;		//�������Ѿ�Ͷ��ĳ�����������һ������������

	//�ֻ�������NΪ��һ�������MΪ�ڶ��������
	int N = 0;
	int M = 0;

};

//��ԴͶ�����������������
struct St_InvectmentEstimateResult
{
	int inputCrystal	= 0;		//Ͷ������û��רƱ��
	int inputTicket		= 0;		//Ͷ��רƱ��û������

	En_DrawCardType			drawCardType		= En_DrawCardType::characterOnly;			//�鿨��ʽ
	En_PoolTransfromType	poolTransformType	= En_PoolTransfromType::NCharacterMWeapon;	//�ֻ���ʽ
	//�ֻ�������NΪ��һ�������MΪ�ڶ��������
	int N = 0;
	int M = 0;


	double NoUpCharacterPorb				= 0;	//UP��ɫ��������
	double UpCharacterGetTimeExpectation	= 0;	//UP��ɫ��ȡ����

	double NoUpWeaponProb					= 0;	//UP������������
	double UpWeaponGetExpectation			= 0;	//UP������ȡ����

	DoubleMatrix ProbDensityMatrix;					//���ʷֲ��������ǻ�ȡUP��ɫ���������ǻ�ȡUP����������ֵ�Ǹ���

};

//ʥ����
	const double	Const_3RelicProb = 0.1;		//65�����Ȿ��3���������ʣ�ʣ����ʾ���2��

	//�·������Ը���
	const double	Const_PriPro_ratio_clothes_HPPercentage			= 0.22;
	const double	Const_PriPro_ratio_clothes_attackPercentage		= 0.22;
	const double	Const_PriPro_ratio_clothes_defencePercentage	= 0.22;
	const double	Const_PriPro_ratio_clothes_CRITProb				= 0.10;
	const double	Const_PriPro_ratio_clothes_CRITDamage			= 0.10;
	const double	Const_PriPro_ratio_clothes_HealAddition			= 0.10;
	const double	Const_PriPro_ratio_clothes_DebuffAccuracy		= 0.04;

	//Ь�������Ը���
	const double	Const_PriPro_ratio_shoes_HPPercentage		= 0.3;
	const double	Const_PriPro_ratio_shoes_attackPercentage	= 0.3;
	const double	Const_PriPro_ratio_shoes_defencePercentage	= 0.3;
	const double	Const_PriPro_ratio_shoes_speed				= 0.1;

	//���������Ը���(��������99.9%)
	const double	Const_PriPro_ratio_cord_HPPercentage		= 0.283;
	const double	Const_PriPro_ratio_cord_attackPercentage	= 0.283;
	const double	Const_PriPro_ratio_cord_defencePercentage	= 0.283;
	const double	Const_PriPro_ratio_cord_breakDamage			= 0.1;
	const double	Const_PriPro_ratio_cord_chargeEfficiency	= 0.05;

	//�������Ը���(��������100.1%)
	const double	Const_PriPro_ratio_ball_HPPercentage		= 0.147;
	const double	Const_PriPro_ratio_ball_attackPercentage	= 0.147;
	const double	Const_PriPro_ratio_ball_defencePercentage	= 0.147;

	const double	Const_PriPro_ratio_ball_fire				= 0.08;
	const double	Const_PriPro_ratio_ball_thunder				= 0.08;
	const double	Const_PriPro_ratio_ball_wind				= 0.08;
	const double	Const_PriPro_ratio_ball_ice					= 0.08;
	const double	Const_PriPro_ratio_ball_null				= 0.08;
	const double	Const_PriPro_ratio_ball_quantum				= 0.08;
	const double	Const_PriPro_ratio_ball_physical			= 0.08;

	//������������������
	const double	Const_ratio_SubPro_2Affix = 0.33;//����2����
	const double	Const_ratio_SubPro_3Affix = 0.33;//����3����
	const double	Const_ratio_SubPro_4Affix = 0.33;//����4����

	//����׺Ȩ��
	const int	Const_SubPro_weight_HPValue				= 11;	//�̶�����ֵ
	const int	Const_SubPro_weight_HPPercentage		= 11;	//�ٷֱ�����ֵ
	const int	Const_SubPro_weight_attackValue			= 11;	//�̶�������
	const int	Const_SubPro_weight_attackPercentage	= 11;	//�ٷֱȹ���
	const int	Const_SubPro_weight_defenceValue		= 11;	//�̶�������
	const int	Const_SubPro_weight_defencePercentage	= 11;	//�ٷֱȷ���
	const int	Const_SubPro_weight_CRITProb			= 7;	//������
	const int	Const_SubPro_weight_CRITDamage			= 7;	//�����˺�
	const int	Const_SubPro_weight_DebuffDefence		= 5;	//Ч���ֿ�
	const int	Const_SubPro_weight_DebuffAccuracy		= 5;	//Ч������
	const int	Const_SubPro_weight_breakDamage			= 5;	//�����ع�
	const int	Const_SubPro_weight_speed				= 5;	//�ٶ�

	//����׺ǿ��ֵ
	//�̶�����ֵ
	const double	Const_SubPro_value_caseA_HPValue = 33.8;	
	const double	Const_SubPro_value_caseB_HPValue = 38;	
	const double	Const_SubPro_value_caseC_HPValue = 42;	

	//�ٷֱ�����ֵ
	const double	Const_SubPro_value_caseA_HPPercentage = 0.0346;	
	const double	Const_SubPro_value_caseB_HPPercentage = 0.0389;	
	const double	Const_SubPro_value_caseC_HPPercentage = 0.0432;	

	//�̶�������
	const double	Const_SubPro_value_caseA_attackValue = 16.9;	
	const double	Const_SubPro_value_caseB_attackValue = 19;	
	const double	Const_SubPro_value_caseC_attackValue = 21;	

	//�ٷֱȹ���
	const double	Const_SubPro_value_caseA_aattackPercentage = 0.0346;	
	const double	Const_SubPro_value_caseB_aattackPercentage = 0.0389;	
	const double	Const_SubPro_value_caseC_aattackPercentage = 0.0432;

	//�̶�������
	const double	Const_SubPro_value_caseA_defenceValue = 16.9;	
	const double	Const_SubPro_value_caseB_defenceValue = 19;	
	const double	Const_SubPro_value_caseC_defenceValue = 21;	

	//�ٷֱȷ���
	const double	Const_SubPro_value_caseA_defencePercentage = 0.0432;	
	const double	Const_SubPro_value_caseB_defencePercentage = 0.0486;	
	const double	Const_SubPro_value_caseC_defencePercentage = 0.054;	

	//������
	const double	Const_SubPro_value_caseA_CRITProb = 0.0259;	
	const double	Const_SubPro_value_caseB_CRITProb = 0.0292;	
	const double	Const_SubPro_value_caseC_CRITProb = 0.0324;	

	//�����˺�
	const double	Const_SubPro_value_caseA_CRITDamage = 0.0518;	
	const double	Const_SubPro_value_caseB_CRITDamage = 0.0583;	
	const double	Const_SubPro_value_caseC_CRITDamage = 0.0648;	

	//Ч���ֿ�
	const double	Const_SubPro_value_caseA_DebuffDefence = 0.0346;	
	const double	Const_SubPro_value_caseB_DebuffDefence = 0.0389;
	const double	Const_SubPro_value_caseC_DebuffDefence = 0.0432;

	//Ч������
	const double	Const_SubPro_value_caseA_DebuffAccuracy = 0.0346;
	const double	Const_SubPro_value_caseB_DebuffAccuracy = 0.0389;
	const double	Const_SubPro_value_caseC_DebuffAccuracy = 0.0432;

	//�����ع�
	const double	Const_SubPro_value_caseA_breakDamage = 0.0518;
	const double	Const_SubPro_value_caseB_breakDamage = 0.0583;
	const double	Const_SubPro_value_caseC_breakDamage = 0.0648;

	//�ٶ�
	const double	Const_SubPro_value_caseA_speed = 2;
	const double	Const_SubPro_value_caseB_speed = 2.25;
	const double	Const_SubPro_value_caseC_speed = 2.5;


//��������
enum class En_raidType:int
{
	Relic,//������
	SimulateUniverse,//ģ������
};

//ʥ���ﲿλ
enum class En_RelicType :int
{
	None,		//δ���ɣ�Debug�ã�
	Head,		//ͷ
	Hand,		//��
	Clothes,	//�·�
	Shoes,		//Ь��
	Cord,		//����
	Ball		//��
};

//ʥ����������
enum class En_RelicPrimeProperty :int
{
	None,					//û�������ԣ�Debug�ã�
	HPValue,				//�̶�����ֵ
	HPPercentage,			//�ٷֱ�����ֵ
	AttackValue,			//�̶�������
	AttackPercentage,		//�ٷֱȹ�����
	DefencePercentage,		//�ٷֱȷ���
	CriticalProb,			//������
	CriticalDamage,			//�����˺�
	Speed,					//�ٶ�
	ChargeEfficiency,		//����Ч��
	BreakDamage,			//�����ع�
	DeBuffAccuracy,			//Ч������
	HealAddition,			//���Ƽӳ�

	Fire,				//���˼ӳ�
	Thunder,			//���˼ӳ�
	Wind,				//���˼ӳ�
	Ice,				//���˼ӳ�
	Null,				//���޼ӳ�
	Quantum,			//���Ӽӳ�
	Physical			//����ӳ�
};

//ʥ���︱����
enum class En_RelicSubProperty :int
{
	None,					//û���ԣ�������Ӵ�׺�߼�

	HPValue,				//�̶�����ֵ
	HPPercentage,			//�ٷֱ�����ֵ
	AttackValue,			//�̶�������
	AttackPercentage,		//�ٷֱȹ�����
	DefenceValue,			//�̶�������
	DefencePercentage,		//�ٷֱȷ�����

	CriticalProb,			//������
	CriticalDamage,			//�����˺�
	Speed,					//�ٶ�

	DeBuffDefence,			//Ч���ֿ�
	BreakDamage,			//�����ع�
	DeBuffAccuracy,			//Ч������
};

//��Чʥ�������
struct St_RelicValidEstimatePara
{
	int	playTime	= 0;//�򱾴���

	En_RelicType	relicType = En_RelicType::None;				//����ʥ���ﲿλ
	
	//ʥ������Ч�����Ա�־λ
	bool		PrimePro_Valid_HPValue				= false;	//�̶�����ֵ
	bool		PrimePro_Valid_HPPercentage			= false;	//�ٷֱ�����ֵ
	bool		PrimePro_Valid_AttackValue			= false;	//�̶�������
	bool		PrimePro_Valid_AttackPercentage		= false;	//�ٷֱȹ�����
	bool		PrimePro_Valid_DefencePercentage	= false;	//�ٷֱȷ���
	bool		PrimePro_Valid_CriticalProb			= false;	//������
	bool		PrimePro_Valid_CriticalDamage		= false;	//�����˺�
	bool		PrimePro_Valid_Speed				= false;	//�ٶ�
	bool		PrimePro_Valid_ChargeEfficiency		= false;	//����Ч��
	bool		PrimePro_Valid_BreakDamage			= false;	//�����ع�
	bool		PrimePro_Valid_DeBuffAccuracy		= false;	//Ч������
	bool		PrimePro_Valid_HealAddition			= false;	//���Ƽӳ�

	bool		PrimePro_Valid_Fire					= false;	//���˼ӳ�
	bool		PrimePro_Valid_Thunder				= false;	//���˼ӳ�
	bool		PrimePro_Valid_Wind					= false;	//���˼ӳ�
	bool		PrimePro_Valid_Ice					= false;	//���˼ӳ�
	bool		PrimePro_Valid_Null					= false;	//���޼ӳ�
	bool		PrimePro_Valid_Quantum				= false;	//���Ӽӳ�
	bool		PrimePro_Valid_Physical				= false;	//����ӳ�

	//ʥ������Ч�����Ա�־λ
	bool		SubPro_Valid_HPValue				= true;		//�̶�����ֵ
	bool		SubPro_Valid_HPPercentage			= true;		//�ٷֱ�����ֵ
	bool		SubPro_Valid_AttackValue			= true;		//�̶�������
	bool		SubPro_Valid_AttackPercentage		= true;		//�ٷֱȹ�����
	bool		SubPro_Valid_DefenceValue			= true;		//�̶�������
	bool		SubPro_Valid_DefencePercentage		= true;		//�ٷֱȷ�����

	bool		SubPro_Valid_CriticalProb			= true;		//������
	bool		SubPro_Valid_CriticalDamage			= true;		//�����˺�
	bool		SubPro_Valid_Speed					= true;		//�ٶ�

	bool		SubPro_Valid_DeBuffDefence			= true;		//Ч���ֿ�
	bool		SubPro_Valid_BreakDamage			= true;		//�����ع�
	bool		SubPro_Valid_DeBuffAccuracy			= true;		//Ч������

	//ʥ���︱������Ч��ֵ
	double		SubPro_Value_HP					= 0;		//�̶�����ֵ
	double		SubPro_Value_HPPercentage		= 0;		//�ٷֱ�����ֵ
	double		SubPro_Value_AttackValue		= 0;		//�̶�������
	double		SubPro_Value_AttackPercentage	= 0;		//�ٷֱȹ�����
	double		SubPro_Value_DefenceValue		= 0;		//�̶�������
	double		SubPro_Value_DefencePercentage	= 0;		//�ٷֱȷ�����

	double		SubPro_Value_CriticalProb		= 0;		//������
	double		SubPro_Value_CriticalDamage		= 0;		//�����˺�
	double		SubPro_Value_Speed				= 0;		//�ٶ�

	double		SubPro_Value_DeBuffDefence		= 0;		//Ч���ֿ�
	double		SubPro_Value_BreakDamage		= 0;		//�����ع�
	double		SubPro_Value_DeBuffAccuracy		= 0;		//Ч������

	//����Щ�����Դ�����ֵҪ��
	QVector<En_RelicSubProperty> vecSubPropertyValueRequirement;

};

//��Чʥ������������
struct St_ValidRelicEstimateResult
{
	double	primePropertyValidProportion			= 0;		//��������Ч������ռ��������ı���
	double  primePropertyValidGetProbbability		= 0;		//��ȡ��������Ч������ʣ���ȡ����/�򱾴�����
	double	primePropertyValidGetTimeExpectation	= 0;		//��������Ч������ȡ����(��������Ч�������/��ȡ�����ܸ���)
	double	primePropertyValidPlayTimeExpectation	= 0;		//��ȡһ����������Ч������Ҫ�򱾴���������

	double	allPropertyValidProportion				= 0;		//ȫ������Ч������ռ��������ı���
	double  allPropertyValidGetProbbability			= 0;		//��ȡȫ������Ч������ʣ���ȡ����/�򱾴�����
	double	allPropertyValidGetTimeExpectation		= 0;		//ȫ������Ч������ȡ����(ȫ������Ч�������/��ȡ�����ܸ���)	
	double	allPropertyValidPlayTimeExpectation		= 0;		//��ȡһ��ȫ������Ч������Ҫ�򱾴���������	

	QMap <int, double>	mapPriProValidGetNumProb;		//��������Ч�����ԣ���������Ч����������������ʣ�	
	QMap <int, double>	mapAllProValidGetNumProb;		//ȫ������Ч�����ԣ���������Ч����������������ʣ�����������Ч+��������Ч
	
};


#endif // !PROTOCOL_STARRAILCACULATOR
