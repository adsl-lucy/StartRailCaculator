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

#include "StarRailMediator.h"
#pragma execution_character_set("utf-8")

StarRailMediator* StarRailMediator::m_instance = nullptr;

StarRailMediator::StarRailMediator():QObject(nullptr)
{
	initUi();
	initSignalSlots();
}

StarRailMediator::~StarRailMediator()
{

}

StarRailMediator* StarRailMediator::instance()
{
	if (m_instance == nullptr)
	{
		m_instance = new StarRailMediator();
	}
	return m_instance;
}

void StarRailMediator::initUi()
{
	m_mainFrame = new StarRailMainFrame;
}

void StarRailMediator::initSignalSlots()
{
	connect(m_mainFrame,	&StarRailMainFrame::signal_StartEstimateResource,			this,			&StarRailMediator::slot_startResourceEstmate);
	connect(this,			&StarRailMediator::signal_ResouceEstErrorMsg,				m_mainFrame,	&StarRailMainFrame::signal_ResouceEstErrorMsg);
	connect(this,			&StarRailMediator::signal_ResouceEstResult,					m_mainFrame,	&StarRailMainFrame::signal_ResouceEstResult);

	connect(m_mainFrame,	&StarRailMainFrame::signal_StartCardPoolEstimate,			this,			&StarRailMediator::slot_startCardPoolEstimate);
	connect(this,			&StarRailMediator::signal_CardPoolEstResult,				m_mainFrame,	&StarRailMainFrame::signal_CardPoolEstResult);
	connect(this,			&StarRailMediator::signal_UpdateCardPoolEstmateProgress,	m_mainFrame,	&StarRailMainFrame::signal_UpdateCardPoolEstmateProgress);

	connect(m_mainFrame,	&StarRailMainFrame::signal_StartInvestmentIncomeEstimate,	this,			&StarRailMediator::slot_startInvestmentIncomeEstimate);
	connect(this,			&StarRailMediator::signal_UpdateInvestmentEstimateProgress, m_mainFrame,	&StarRailMainFrame::signal_UpdateInvestmentEstimateProgress);
	connect(this,			&StarRailMediator::signal_InvestmentEstimateResult,			m_mainFrame,	&StarRailMainFrame::signal_InvestmentEstimateResult);

	connect(m_mainFrame,	&StarRailMainFrame::signal_StartRelicValidEstimate,			this,			&StarRailMediator::slot_startRelicValidEstimate);
	connect(this,			&StarRailMediator::signal_RelicEstErrorMsg,					m_mainFrame,	&StarRailMainFrame::signal_RelicEstErrorMsg);
	connect(this,			&StarRailMediator::signal_UpdateRelicEstimateProgress,		m_mainFrame,	&StarRailMainFrame::signal_UpdateRelicEstimateProgress);
	connect(this,			&StarRailMediator::signal_RelicEstResult,					m_mainFrame,	&StarRailMainFrame::signal_RelicEstResult);


}

const EN_StarRailErrorNum StarRailMediator::checkResourceEstInputErr(const St_ResourceEstimateParameter& EstPara)
{
	if (EstPara.startDate < Const_StarRailOpenDay.date())//���ܱȿ�������
	{
		return EN_StarRailErrorNum::ResouceEst_StartDateTooEarly;
	}

	if (EstPara.startDate > Const_StarRailLatestDay.date())//��ʼʱ��̫��
	{
		return EN_StarRailErrorNum::ResouceEst_StartDateTooLate;;
	}

	if (EstPara.stopDate < EstPara.startDate)//�����������ڿ�ʼ����
	{
		return EN_StarRailErrorNum::ResouceEst_StartDayLateThanEndDay;
	}

	if (EstPara.startDate == EstPara.stopDate)//�������ںͿ�ʼ������ͬ
	{
		return EN_StarRailErrorNum::ResouceEst_StartEndSameDay;
	}

	if (EstPara.stopDate > Const_StarRailLatestDay.date())//��������̫��
	{
		return EN_StarRailErrorNum::ResouceEst_StopDayTooLate;
	}

	if (EstPara.currentCrystal < 0)//��ǰ������С��0
	{
		return EN_StarRailErrorNum::ResouceEst_CurrentCrystalInvaild;
	}

	if (EstPara.currentTicket < 0)//��ǰƱ������С��0
	{
		return EN_StarRailErrorNum::ResouceEst_CurrentTicketNumInvaild;
	}

	if (EstPara.currentPaidCrystal < 0)//��ǰ�����λ�����С��0
	{
		return EN_StarRailErrorNum::ResouceEst_CurrentPaidCrystalInvaild;
	}

	if (EstPara.abyssAverageNum < 0 || EstPara.abyssAverageNum > 10)//��Ԩ��������
	{
		return EN_StarRailErrorNum::ResouceEst_AbyssAverageNumInvaild;
	}

	if (EstPara.smallMonthCardLastday < 0 || EstPara.smallMonthCardLastday>30)//С�¿�ʣ��������Ч
	{
		return EN_StarRailErrorNum::ResouceEst_SmallMonthCardRemainDayInvaild;
	}

	return EN_StarRailErrorNum::ResouceEst_InputNoError;

}

void StarRailMediator::sendResourceEstErrorMsg(const EN_StarRailErrorNum ErrNum)
{
	QString ErrMsg;
	switch (ErrNum)
	{
		case EN_StarRailErrorNum::ResouceEst_InputNoError						: break;
		case EN_StarRailErrorNum::ResouceEst_StartDateTooEarly					: ErrMsg = QString("��ʼ�������ڿ������ڣ�2023/4/26��");	break;
		case EN_StarRailErrorNum::ResouceEst_StartDateTooLate					: ErrMsg = QString("��ʼʱ��̫������2024/4/26��");		break;
		case EN_StarRailErrorNum::ResouceEst_StartEndSameDay					: ErrMsg = QString("��ʼ���ں���ֹ������ͬ");				break;
		case EN_StarRailErrorNum::ResouceEst_StartDayLateThanEndDay				: ErrMsg = QString("��ֹ����������ʼ����");					break;
		case EN_StarRailErrorNum::ResouceEst_StopDayTooLate						: ErrMsg = QString("��ֹ����̫������2020/4/26��");		break;

		case EN_StarRailErrorNum::ResouceEst_CurrentTicketNumInvaild			: ErrMsg = QString("��ǰƱ����Ч");				break;
		case EN_StarRailErrorNum::ResouceEst_CurrentCrystalInvaild				: ErrMsg = QString("��ǰ������Ч");				break;
		case EN_StarRailErrorNum::ResouceEst_SmallMonthCardRemainDayInvaild		: ErrMsg = QString("С�¿�ʣ��������Ч");		break;
		case EN_StarRailErrorNum::ResouceEst_CurrentPaidCrystalInvaild			: ErrMsg = QString("��ǰ�����λ���Ч");			break;
		case EN_StarRailErrorNum::ResouceEst_AbyssAverageNumInvaild				: ErrMsg = QString("��Ԩƽ��ͨ������Ч");		break;
	}
	emit signal_ResouceEstErrorMsg(ErrNum, ErrMsg);
}

void StarRailMediator::slot_startResourceEstmate(const St_ResourceEstimateParameter& EstPara)
{
	//�鿴�������
	EN_StarRailErrorNum ErrNum = checkResourceEstInputErr(EstPara);

	//��������ɹ���񶼻ᷢ�ʹ����룬��������ɹ��ͻ�����������Ϣ
	sendResourceEstErrorMsg(ErrNum);

	if (ErrNum != EN_StarRailErrorNum::ResouceEst_InputNoError) return;//����������Ͳ�����


	QDate	currentDate				= EstPara.startDate;
	int		currentTicket			= EstPara.currentTicket;
	int		currentCrystal			= EstPara.currentCrystal;
	int		currentPaidCrystal		= EstPara.currentPaidCrystal;
	int		smallMonthCardRemainday = EstPara.smallMonthCardLastday;

	
	int		totalSmallMonthCardExpense	= 0;	//�ۼ�С�¿�Ͷ��
	int		totalBigMonthCardExpense	= 0;	//�ۼƴ��¿�Ͷ��
	int		totalExpense				= 0;	//�ۼ���Ͷ��

	QVector<St_ResourceEstimateDateResult> resultVec;

	//��һ��Ĭ�϶���ȥ���������Ѿ���������������Ľ��
	{
		St_ResourceEstimateDateResult currentDayResult;

		currentDayResult.currentDate			= currentDate;
		currentDayResult.TodayCrystalIncome		= 0;

		currentDayResult.currentCrystal			= currentCrystal;
		currentDayResult.currentTicket			= currentTicket;
		currentDayResult.currentPaidCrystal		= currentPaidCrystal;

		currentDayResult.buySmallMonthCard		= false;
		currentDayResult.buyBigMonthCard		= false;
		currentDayResult.playMonitorSpace		= false;
		currentDayResult.playAbyss				= false;

		currentDayResult.currentdayExpense			= 0;
		currentDayResult.totalSmallCardExpence		= 0;
		currentDayResult.totalBigMonthCardExpence	= 0;
		currentDayResult.totalExpense				= 0;

		resultVec.push_back(currentDayResult);
		currentDate = currentDate.addDays(1);
	}

	//��ʼ���еڶ��쵽���һ��ļ���
	do
	{
		//���쿪��
		int currentdayExpense = 0;
		//��������������룬�Ȼ��û����Ϸ������
		int LastdayCrystal = currentCrystal;

		//������Ϸ�ȴ���С�¿�����
		bool buySmallMonthCard = EstPara.buySmallMonthCard && smallMonthCardRemainday == 0;

		if (buySmallMonthCard)//С�¿������ˣ���ֵ30�����300�����λ�
		{
			currentPaidCrystal			+= 300;
			smallMonthCardRemainday		+= 30;			
			currentdayExpense			+= 30;
			totalSmallMonthCardExpense	+= 30;
			totalExpense				+= 30;
		}

		if (EstPara.buySmallMonthCard)//����С�¿��趨�£�ÿ����90ˮ
		{
			currentCrystal += 90;
			smallMonthCardRemainday -= 1;
		}


		//Ȼ�����ճ����60ˮ
		currentCrystal		+= 60;

		//�����ÿ�ܵ�һ�죬��ô��ģ��������225�ߣ����ͻ�Ƶȼ���
		bool playMonitorSpace = currentDate.dayOfWeek() == 1;

		if (playMonitorSpace)
		{
			currentCrystal += Const_MonitorSpaceCrystal;
		}

		//ÿ���µ�һ��ȥ�̵���5��
		if (currentDate.day() == 1)
		{
			currentTicket += 5;
		}

		int dayFromOpen = Const_StarRailOpenDay.date().daysTo(currentDate);

		//����ǿ�����2�ܵı�������ô��Ԩˢ�£������������
		bool playAbyss = dayFromOpen % 14 == 0;
		if (playAbyss)
		{
			currentCrystal += EstPara.abyssAverageNum * Const_AbyssCrystalPerLevel;
		}

		//�жϽ����ǲ��Ǵ�汾���£�������6��һ�Σ�
		bool bigupdate = dayFromOpen % Const_BigMonthCardPeriod == 0;

		//��汾������300��ά�� + 300����BUG
		if (bigupdate)
		{
			currentCrystal += 600;
		}

		//�жϽ���������¿����ʹ�汾����ͬƵ�ʣ�
		bool buyBigMonthCard = EstPara.buyBigMonthCard && bigupdate;

		if (buyBigMonthCard)
		{		
			currentdayExpense			+= 68;
			totalBigMonthCardExpense	+= 68;
			totalExpense				+= 68;
		}

		//Ĭ��ÿ�ܰѾ��������һ��10����
		if (EstPara.buyBigMonthCard)
		{
			switch (dayFromOpen % Const_BigMonthCardPeriod)
			{
				case 7		:currentTicket	+= 1;	break;
				case 14		:currentTicket	+= 1;	break;
				case 21		:currentTicket	+= 2;	break;
				case 35		:currentCrystal += 680; break;
			}		
		}

		St_ResourceEstimateDateResult currentDayResult;

		currentDayResult.currentDate		= currentDate;
		currentDayResult.TodayCrystalIncome = currentCrystal - LastdayCrystal;

		currentDayResult.currentCrystal		= currentCrystal;
		currentDayResult.currentTicket		= currentTicket;
		currentDayResult.currentPaidCrystal = currentPaidCrystal;

		currentDayResult.buySmallMonthCard	= buySmallMonthCard;
		currentDayResult.buyBigMonthCard	= buyBigMonthCard;
		currentDayResult.playMonitorSpace	= playMonitorSpace;
		currentDayResult.playAbyss			= playAbyss;

		currentDayResult.currentdayExpense			= currentdayExpense;
		currentDayResult.totalSmallCardExpence		= totalSmallMonthCardExpense;
		currentDayResult.totalBigMonthCardExpence	= totalBigMonthCardExpense;
		currentDayResult.totalExpense				= totalExpense;


		resultVec.push_back(currentDayResult);
		currentDate = currentDate.addDays(1);
	} while (currentDate <= EstPara.stopDate);

	emit signal_ResouceEstResult(resultVec);
	
}

void StarRailMediator::slot_startCardPoolEstimate(const St_CardPoolEstimatePara& EstPara)
{
	//����أ�keyΪ�鿨������valueΪ��λ��ֹͣ����
	QMap<int, int> resultMap;

	int	largestDrawTime = 0;//һ��ʵ��������ٴο�

	if (EstPara.poolType == EN_CardPoolType::character)
	{
		if (EstPara.wrongGold == false)
		{
			largestDrawTime = Const_LargestGetGoldCharTNum * 2 - EstPara.areadyInTicket;
		}
		else
		{
			largestDrawTime = Const_LargestGetGoldCharTNum - EstPara.areadyInTicket;
		}
		
	}
	else if (EstPara.poolType == EN_CardPoolType::weapon)
	{
		if (EstPara.wrongGold == false)
		{
			largestDrawTime = Const_LargetGetGoldWeaponTNum * 2 - EstPara.areadyInTicket;
		}
		else
		{
			largestDrawTime = Const_LargetGetGoldWeaponTNum - EstPara.areadyInTicket;
		}
	}

	//��ʼ�������
	for (int i = 0; i <= largestDrawTime; i++)//�����0��ֵ��Ȼ��0
	{
		resultMap.insert(i, 0);
	}

	int startRandomSeed = time(nullptr);
	int ExperimentTime = 100000;//�����ȽϺõ��ظ�����

	for (int currentExpTime = 1; currentExpTime <= ExperimentTime; currentExpTime++)
	{
		//ÿ�ν���ʵ�鶼����һ����������������
		unsigned int seed = startRandomSeed + currentExpTime;
		std::default_random_engine engine(seed);

		int					distanceToLastGold	= EstPara.areadyInTicket + 1;
		bool				wrongGoldBefore		= EstPara.wrongGold;
		En_DrawCardResult	currentResult		= En_DrawCardResult::normal;
		int					currentPos			= 1;


		while (currentPos <= largestDrawTime)
		{
			currentResult = DrawCardAtOnce(EstPara.poolType, wrongGoldBefore, distanceToLastGold, engine);

			if (currentResult == En_DrawCardResult::character_UpGold || currentResult == En_DrawCardResult::weapon_UpGold)
			{
				break;
			}
			else if (currentResult == En_DrawCardResult::character_wrongGold || currentResult == En_DrawCardResult::weapon_wrongGold)
			{
				wrongGoldBefore = true;
				distanceToLastGold = 0;//��Ϊ���ˣ����õ����ľ���
			}

			currentPos++;
			distanceToLastGold++;

		}

		auto mapPos = resultMap.find(currentPos);
		if (mapPos != resultMap.end())
		{
			mapPos.value()++;
		}

		if (currentExpTime % 1000 == 0)//ˢ�½�����
		{
			emit signal_UpdateCardPoolEstmateProgress(currentExpTime/1000);
		}
	}
	
	QMap<int, double>PorbDensityMap;//���ʷֲ��ܶȺ�����������ԣ�

	for (auto resultMapPos = resultMap.begin(); resultMapPos != resultMap.end(); resultMapPos++)
	{
		int TickNum = resultMapPos.key();
		double TickProbDensity = (double)resultMapPos.value() / (double)ExperimentTime;

		PorbDensityMap.insert(TickNum, TickProbDensity);
	}


	St_CardPoolEstimateResult EstResult;

	EstResult.poolType					= EstPara.poolType;
	EstResult.distanceToBigGuarantee	= largestDrawTime;
	EstResult.smallGuaranteeInCase		= !EstPara.wrongGold;

	int smallGuaranteePos	= -1;
	int bigGuaranteePos		= largestDrawTime;

	if (EstResult.smallGuaranteeInCase)
	{
		if (EstPara.poolType == EN_CardPoolType::character)
		{
			smallGuaranteePos = Const_LargestGetGoldCharTNum - EstPara.areadyInTicket;
		}
		else if (EstPara.poolType == EN_CardPoolType::weapon)
		{
			smallGuaranteePos = Const_LargetGetGoldWeaponTNum - EstPara.areadyInTicket;
		}
	}

	EstResult.getUpPosExpectation	= 0;
	double	accumulateProb			= 0;//���ʷֲ����ۼƸ��ʣ�
	int		currentPos				= 1;

	for (auto densityMapPos = PorbDensityMap.begin(); densityMapPos != PorbDensityMap.end(); densityMapPos++)
	{
		int	TickNum				= densityMapPos.key();
		double densityVal		= densityMapPos.value();
		accumulateProb			+= densityVal;

		EstResult.getUpPosExpectation += TickNum * densityVal;
		EstResult.mapPorbDistribution.insert(TickNum, accumulateProb);

		if (smallGuaranteePos != -1 && TickNum == smallGuaranteePos)
		{
			EstResult.smallGraranteeGetUpProb = densityMapPos.value();;
		}

		if (TickNum == EstResult.distanceToBigGuarantee)
		{
			EstResult.bigGuaranteeGetTupProb = densityMapPos.value();
		}
	}

	EstResult.crystalExpenExpectation = EstResult.getUpPosExpectation * 160;

	emit signal_CardPoolEstResult(EstResult);

}

void StarRailMediator::slot_startInvestmentIncomeEstimate(const St_InvestmentEstimatePara & EstPara)
{	
	const int largestDrawTime = EstPara.inputTicket + EstPara.inputCrystal / 160;

	int ExperimentTime = 100000;
	DoubleMatrix resultNumMatrix;

	int startRandomSeed = time(nullptr);

	for (int currentExpTime = 1; currentExpTime <= ExperimentTime; currentExpTime++)
	{
		bool lastGoldCharacterWrong		= EstPara.lastGoldCharacterWrong;
		int areadyInCharacterPoolTicket = EstPara.areadyInCharacterPoolTicket;
		bool lastGoldWeaponWrong		= EstPara.lastGoldWeaponWrong;
		int areadyInWeaponPoolTicket	= EstPara.areadyInWeaponPoolTicket;

		int currentTickCost		= 0;
		int getUpCharacterTime	= 0;
		int getUpWeaponTime		= 0;

		std::default_random_engine engine(startRandomSeed + currentExpTime);

		if (EstPara.drawCardType == En_DrawCardType::characterOnly || EstPara.drawCardType == En_DrawCardType::waeponOnly)
		{
			while (currentTickCost < largestDrawTime)
			{
				if (EstPara.drawCardType == En_DrawCardType::characterOnly)//ֻ���ɫ
				{
					int TicketCost = DrawCardUntilGetUp(EN_CardPoolType::character, lastGoldCharacterWrong, areadyInCharacterPoolTicket, engine);
					currentTickCost += TicketCost;

					if (currentTickCost > largestDrawTime)//������������������ʱ������������Ч
					{
						break;
					}
					else
					{
						lastGoldCharacterWrong = false;
						areadyInCharacterPoolTicket = 0;
						getUpCharacterTime++;
					}
				}
				else if (EstPara.drawCardType == En_DrawCardType::waeponOnly)//ֻ������
				{
					int TicketCost = DrawCardUntilGetUp(EN_CardPoolType::weapon, lastGoldWeaponWrong, areadyInWeaponPoolTicket, engine);
					currentTickCost += TicketCost;

					if (currentTickCost > largestDrawTime)
					{
						break;
					}
					else
					{
						lastGoldWeaponWrong = false;
						areadyInWeaponPoolTicket = 0;
						getUpWeaponTime++;
					}
				}
			}
		}

		if (EstPara.drawCardType == En_DrawCardType::getAll)//����
		{
			if (EstPara.poolTransformType == En_PoolTransfromType::NCharacterMWeapon)
			{
				QPair<int, int> result = DrawCardNPoolAMPoolB(EstPara.poolTransformType, largestDrawTime,engine,
					lastGoldCharacterWrong, areadyInCharacterPoolTicket, lastGoldWeaponWrong, areadyInWeaponPoolTicket, EstPara.N, EstPara.M);
				getUpCharacterTime	= result.first;
				getUpWeaponTime		= result.second;
			}
			else if (EstPara.poolTransformType == En_PoolTransfromType::NWeaponMCharacter)
			{
				QPair<int, int> result = DrawCardNPoolAMPoolB(EstPara.poolTransformType, largestDrawTime, engine,
					lastGoldCharacterWrong, areadyInCharacterPoolTicket, lastGoldWeaponWrong, areadyInWeaponPoolTicket, EstPara.N, EstPara.M);
				getUpWeaponTime = result.first;
				getUpCharacterTime = result.second;
			}
			else if (EstPara.poolTransformType == En_PoolTransfromType::NTCharacterMTWeapon)
			{
				QPair<int, int> result = DrawCardNTPoolAMTPoolB(EstPara.poolTransformType, largestDrawTime, engine,
					lastGoldCharacterWrong, areadyInCharacterPoolTicket, lastGoldWeaponWrong, areadyInWeaponPoolTicket, EstPara.N, EstPara.M);
				getUpCharacterTime = result.first;
				getUpWeaponTime = result.second;
			}
			else if (EstPara.poolTransformType == En_PoolTransfromType::NTWeaponMTCharacter)
			{
				QPair<int, int> result = DrawCardNTPoolAMTPoolB(EstPara.poolTransformType, largestDrawTime, engine,
					lastGoldCharacterWrong, areadyInCharacterPoolTicket, lastGoldWeaponWrong, areadyInWeaponPoolTicket, EstPara.N, EstPara.M);
				getUpWeaponTime = result.first;
				getUpCharacterTime = result.second;
			}
		}

		bool stateExist = resultNumMatrix.checkElementExist(getUpCharacterTime, getUpWeaponTime);

		//������������ζ�������������˻�ȡ��ɫ�Ĵ��������������˻�ȡ�����Ĵ���
		if (stateExist)
		{
			resultNumMatrix.getValueRefAt(getUpCharacterTime, getUpWeaponTime) += 1;
		}
		else
		{
			resultNumMatrix.setValue(getUpCharacterTime, getUpWeaponTime, 1);
		}

		if (currentExpTime % 1000 == 0)
		{
			emit signal_UpdateInvestmentEstimateProgress(currentExpTime / 1000);
		}

	}

	St_InvectmentEstimateResult result;
	result.inputCrystal			= EstPara.inputCrystal;
	result.inputTicket			= EstPara.inputTicket;
	result.drawCardType			= EstPara.drawCardType;
	result.poolTransformType	= EstPara.poolTransformType;

	result.N = EstPara.N;
	result.M = EstPara.M;

	QSize resultSize = resultNumMatrix.getMatrixSize();

	result.ProbDensityMatrix.expandMatrix(resultSize);

	result.NoUpCharacterPorb				= 0;
	result.UpCharacterGetTimeExpectation	= 0;
	result.UpWeaponGetExpectation			= 0;
	result.NoUpWeaponProb					= 0;

	for (int currentRow = 0; currentRow < resultSize.height(); currentRow++)
	{
		for (int currentColumn = 0; currentColumn < resultSize.width(); currentColumn++)
		{
			int characterNum	= currentRow;
			int weaponNum		= currentColumn;

			double resultNum = resultNumMatrix.getValueAt(currentRow, currentColumn);
			double probability = resultNum / ExperimentTime;

			if (characterNum == 0)
			{
				result.NoUpCharacterPorb += probability;
			}

			if (weaponNum == 0)
			{
				result.NoUpWeaponProb += probability;
			}

			result.UpCharacterGetTimeExpectation	+= probability * characterNum;
			result.UpWeaponGetExpectation			+= probability * weaponNum;

			result.ProbDensityMatrix.setValue(currentRow, currentColumn,probability);
		}
	}

	emit signal_InvestmentEstimateResult(result);

}

void StarRailMediator::slot_startRelicValidEstimate(const St_RelicValidEstimatePara & EstPara)
{
	EN_StarRailErrorNum inputError = checkRelicEstInputErr(EstPara);
	sendRelicEstErrorMsg(inputError);

	if (inputError != EN_StarRailErrorNum::RelicEst_InputNoError)
	{
		return;
	}

	int ExperimentTime = 100000;

	int progressGap = ExperimentTime / 100;

	int startRandomSeed = time(nullptr);

	//��������Ч�����ԣ���Ч����������������������
	QMap <int, int> mapPrimePropertyGetNum;
	//�򱾻�ȡ��������Ч�����ԣ��򱾻�ȡ��������Ч����Ĵ������������������
	QMap <int, int> mapPrimePropertyGetTime;
	//ȫ������Ч�����ԣ���Ч����������������������������ȫ������Ч�ǽ�����������+�����Զ���Ч�Ļ���֮�ϵ�
	QMap <int, int> mapAllPropertyGetNum;
	//�򱾻�ȡȫ������Ч�����ԣ��򱾻�ȡȫ������Ч����Ĵ������������������
	QMap <int, int> mapAllPropertyGetTime;

	//��������Ч�����������ͣ����������ʵ�����
	double	totalPrimePropertyValidGetNumProbability = 0;
	//�򱾻�ȡ��������Ч������ĸ��ʣ����������ʵ�����
	double	totalPrimePropertyValidGetTimeProbability = 0;
	//ȫ������Ч�����������ͣ����������ʵ�����
	double	totalAllPropertyValidGetNumProbability = 0;
	//�򱾻�ȡȫ������Ч������ĸ�����ͣ����������ʵ�����
	double	totalAllPropertyValidGetTimeProbability = 0;
	

	const En_raidType raidType = RelicResult::getRaidType(EstPara.relicType);

	for (int currentExpTime = 1; currentExpTime <= ExperimentTime; currentExpTime++)
	{
		std::default_random_engine engine(startRandomSeed + currentExpTime);

		int		totalRelic = 0;
		int		primePropertyValidGetNum	= 0;//��������Ч�������
		int		primePropertyValidGetTime	= 0;//�򱾻�ȡ��������Ч����Ĵ���
		int		allPropertyValidGetNum		= 0;//ȫ������Ч�������
		int		allPropertyValidGetTime		= 0;//�򱾻�ȡȫ������Ч����Ĵ���

		double	primePropertyValidProportion		= 0;//��������Ч�������
		double	getPrimePropertyValidProbability	= 0;//�򱾻�ȡ��������Ч����ĸ���
		double	allPropertyValidProportion			= 0;//ȫ������Ч�������
		double	getAllPropertyValidProbability		= 0;//�򱾻�ȡȫ������Ч����ĸ���

		//����ƿ�����������ܶ�����Ч��case
		RelicResult newRelic;

		for (int playRaidTime = 1; playRaidTime <= EstPara.playTime; playRaidTime++)
		{
			int RelicNum = RelicResult::getRelicNum(engine);

			bool getPrimePrortyValidState	= false;
			bool getAllPrortyValidState		= false;

			for (int currentRelic = 1; currentRelic <= RelicNum; currentRelic++)
			{
				newRelic.resetPara();
				totalRelic++;

				bool allValidState				= newRelic.getBirth(raidType, EstPara, engine);

				bool PrimePropertyValidState	= newRelic.isPrimePropertyValid(EstPara);
				
				if (PrimePropertyValidState)
				{
					primePropertyValidGetNum++;
					getPrimePrortyValidState = true;
				}

				if (allValidState) 
				{
					allPropertyValidGetNum++;
					getAllPrortyValidState = true;
				}
			}

			if (getPrimePrortyValidState)
			{
				primePropertyValidGetTime++;
			}

			if (getAllPrortyValidState)
			{
				allPropertyValidGetTime++;
			}

		}

		primePropertyValidProportion		= (double)primePropertyValidGetNum	/ (double)totalRelic;
		getPrimePropertyValidProbability	= (double)primePropertyValidGetTime / (double)EstPara.playTime;

		allPropertyValidProportion			= (double)allPropertyValidGetNum	/ (double)totalRelic;
		getAllPropertyValidProbability		= (double)allPropertyValidGetTime	/ (double)EstPara.playTime;

		totalPrimePropertyValidGetNumProbability	+= primePropertyValidProportion;
		totalPrimePropertyValidGetTimeProbability	+= getPrimePropertyValidProbability;

		totalAllPropertyValidGetNumProbability		+= allPropertyValidProportion;
		totalAllPropertyValidGetTimeProbability		+= getAllPropertyValidProbability;

		auto priMapGetNumPos = mapPrimePropertyGetNum.find(primePropertyValidGetNum);
		if (priMapGetNumPos == mapPrimePropertyGetNum.end())
		{
			mapPrimePropertyGetNum.insert(primePropertyValidGetNum, 1);
		}
		else
		{
			priMapGetNumPos.value() += 1;
		}

		auto priMapGetTimePos = mapPrimePropertyGetTime.find(primePropertyValidGetTime);
		if (priMapGetTimePos == mapPrimePropertyGetTime.end())
		{
			mapPrimePropertyGetTime.insert(primePropertyValidGetTime, 1);
		}
		else
		{
			priMapGetTimePos.value() += 1;
		}

		auto allMapGetNumPos = mapAllPropertyGetNum.find(allPropertyValidGetNum);
		if (allMapGetNumPos == mapAllPropertyGetNum.end())
		{
			mapAllPropertyGetNum.insert(allPropertyValidGetNum, 1);
		}
		else
		{
			allMapGetNumPos.value() += 1;
		}

		auto allMapGetTimePos = mapAllPropertyGetTime.find(allPropertyValidGetTime);
		if (allMapGetTimePos == mapAllPropertyGetTime.end())
		{
			mapAllPropertyGetTime.insert(allPropertyValidGetTime, 1);
		}
		else
		{
			allMapGetTimePos.value() += 1;
		}

		if (currentExpTime % progressGap == 0)
		{
			emit signal_UpdateRelicEstimateProgress(currentExpTime / progressGap);
		}

	}

	St_ValidRelicEstimateResult EstResult;

	EstResult.primePropertyValidProportion		= totalPrimePropertyValidGetNumProbability	/ ExperimentTime;
	EstResult.primePropertyValidGetProbbability	= totalPrimePropertyValidGetTimeProbability / ExperimentTime;

	EstResult.allPropertyValidProportion		= totalAllPropertyValidGetNumProbability	/ ExperimentTime;
	EstResult.allPropertyValidGetProbbability	= totalAllPropertyValidGetTimeProbability	/ ExperimentTime;

	for (auto PriValidNumMapPos = mapPrimePropertyGetNum.begin(); PriValidNumMapPos != mapPrimePropertyGetNum.end(); PriValidNumMapPos++)
	{
		int		PriValidRelicNum	= PriValidNumMapPos.key();
		int		caseTime			= PriValidNumMapPos.value();
		double	caseProbability		= (double)caseTime / (double)ExperimentTime;
		EstResult.mapPriProValidGetNumProb.insert(PriValidRelicNum, caseProbability);
		EstResult.primePropertyValidGetTimeExpectation += PriValidRelicNum * caseProbability;
	}

	double playRaidGetPriProValidTimeExpectation = 0;

	for (auto PriValidTimeMapPos = mapPrimePropertyGetTime.begin(); PriValidTimeMapPos != mapPrimePropertyGetTime.end(); PriValidTimeMapPos++)
	{
		int		PriValidGetTime = PriValidTimeMapPos.key();
		int		caseTime		= PriValidTimeMapPos.value();
		double	caseProbability = (double)caseTime / (double)ExperimentTime;
		playRaidGetPriProValidTimeExpectation += PriValidGetTime * caseProbability;
	}

	for (auto allValidNumMapPos = mapAllPropertyGetNum.begin(); allValidNumMapPos != mapAllPropertyGetNum.end(); allValidNumMapPos++)
	{
		int		allValidRelicNum		= allValidNumMapPos.key();
		int		caseTime				= allValidNumMapPos.value();
		double	caseProbability			= (double)caseTime / (double)ExperimentTime;
		EstResult.mapAllProValidGetNumProb.insert(allValidRelicNum, caseProbability);
		EstResult.allPropertyValidGetTimeExpectation += allValidRelicNum * caseProbability;
	}

	double playRaidGetAllProValidTimeExpectation = 0;

	for (auto AllValidTimeMapPos = mapAllPropertyGetTime.begin(); AllValidTimeMapPos != mapAllPropertyGetTime.end(); AllValidTimeMapPos++)
	{
		int		AllValidGetTime		= AllValidTimeMapPos.key();
		int		caseTime			= AllValidTimeMapPos.value();
		double	caseProbability = (double)caseTime / (double)ExperimentTime;
		playRaidGetAllProValidTimeExpectation += AllValidGetTime * caseProbability;
	}

	EstResult.primePropertyValidPlayTimeExpectation = 1 / ( playRaidGetPriProValidTimeExpectation / (double)EstPara.playTime);
	EstResult.allPropertyValidPlayTimeExpectation	= 1 / ( playRaidGetAllProValidTimeExpectation / (double)EstPara.playTime);

	emit signal_RelicEstResult(EstResult);

}

En_DrawCardResult StarRailMediator::DrawCardAtOnce(EN_CardPoolType poolType, bool wrongGoldBefore, int distanceToLastGold, std::default_random_engine& engine)
{
	//���ʼ�����ز��������һ��1000���ڵ�������������������ֵ�жϽ��
	int    goldRange	= 0;
	int    UpGoldRange	= 0;

	//���ü��㷶Χ
	if (poolType == EN_CardPoolType::character)//��ɫ��
	{ 
		if (wrongGoldBefore == false)//֮ǰû��
		{
			if (distanceToLastGold < Const_LargestGetGoldCharTNum)//��ͨ���Σ�ǰ90�飩
			{
				goldRange	= Const_GoldCharacterProbability * 1000;
				UpGoldRange = Const_GoldUpCharacterProbability * goldRange;
			}
			else//С����
			{	
				goldRange	= 1000;
				UpGoldRange = Const_GoldUpCharacterProbability * goldRange;
			}
		}
		else//֮ǰ����
		{
			if (distanceToLastGold < Const_LargestGetGoldCharTNum)//�󱣵����Σ���90�飩
			{
				goldRange	= Const_GoldCharacterProbability * 1000;
				UpGoldRange = goldRange;
			}
			else//�󱣵�
			{
				goldRange	= 1000;
				UpGoldRange = goldRange;
			}
		}
	}
	else if (poolType == EN_CardPoolType::weapon)//������
	{
		if (wrongGoldBefore == false)//֮ǰû��
		{
			if (distanceToLastGold < Const_LargetGetGoldWeaponTNum)//��ͨ���Σ�ǰ80�飩
			{
				goldRange	= Const_GoldWeaponProbability * 1000;
				UpGoldRange = Const_GoldUpWeaponProbability * goldRange;
			}
			else//С����
			{
				goldRange	= 1000;
				UpGoldRange = Const_GoldUpWeaponProbability * goldRange;
			}
		}
		else//֮ǰ����
		{
			if (distanceToLastGold < Const_LargetGetGoldWeaponTNum)//�󱣵����Σ���90�飩
			{
				goldRange	= Const_GoldWeaponProbability * 1000;
				UpGoldRange = goldRange;
			}
			else//�󱣵�
			{
				goldRange	= 1000;
				UpGoldRange = goldRange;
			}
		}
	}

	std::uniform_int_distribution<int> di(0, 999);

	int randomNum = di(engine);
	
	if (poolType == EN_CardPoolType::character)
	{
		if (randomNum < UpGoldRange)
		{
			return En_DrawCardResult::character_UpGold;
		}
		else if (randomNum < goldRange)
		{
			return En_DrawCardResult::character_wrongGold;
		}
	}
	else if (poolType == EN_CardPoolType::weapon)
	{
		if (randomNum < UpGoldRange)
		{
			return En_DrawCardResult::weapon_UpGold;
		}
		else if (randomNum < goldRange)
		{
			return En_DrawCardResult::weapon_wrongGold;
		}
	}

	return En_DrawCardResult::normal;

}

int StarRailMediator::DrawCardUntilGetUp(EN_CardPoolType poolType, bool wrongGoldBefore, int areadyInTicket, std::default_random_engine& engine)
{
	int	largestDrawTime = 0;//һ��ʵ��������ٴο�

	if (poolType == EN_CardPoolType::character)
	{
		if (wrongGoldBefore == false)
		{
			largestDrawTime = Const_LargestGetGoldCharTNum * 2 - areadyInTicket;
		}
		else
		{
			largestDrawTime = Const_LargestGetGoldCharTNum - areadyInTicket;
		}

	}
	else if (poolType == EN_CardPoolType::weapon)
	{
		if (wrongGoldBefore == false)
		{
			largestDrawTime = Const_LargetGetGoldWeaponTNum * 2 - areadyInTicket;
		}
		else
		{
			largestDrawTime = Const_LargetGetGoldWeaponTNum - areadyInTicket;
		}
	}


	int					distanceToLastGold = areadyInTicket + 1;
	En_DrawCardResult	currentResult = En_DrawCardResult::normal;
	int					currentPos = 1;


	while (currentPos <= largestDrawTime)
	{
		currentResult = DrawCardAtOnce(poolType, wrongGoldBefore, distanceToLastGold, engine);

		if (currentResult == En_DrawCardResult::character_UpGold || currentResult == En_DrawCardResult::weapon_UpGold)
		{
			return currentPos;
		}
		else if (currentResult == En_DrawCardResult::character_wrongGold || currentResult == En_DrawCardResult::weapon_wrongGold)
		{
			wrongGoldBefore = true;
			distanceToLastGold = 0;//��Ϊ���ˣ����õ����ľ���,�������+1��������Ϊ0
		}

		currentPos++;
		distanceToLastGold++;
	}

	return currentPos;

}

QPair<int, int> StarRailMediator::DrawCardNPoolAMPoolB(En_PoolTransfromType transfromType, int largestTicket, 
	std::default_random_engine & engine, 
	bool wrongGoldCharacterbefore, int areadyInCharacterPoolTicket, bool wrongGoldWeaponBefore, int areadyInWeaponPoolTicket, 
	int N, int M)
{
	if (transfromType == En_PoolTransfromType::NTWeaponMTCharacter || transfromType == En_PoolTransfromType::NTWeaponMTCharacter)
	{
		return QPair<int,int>(-1,-1);
	}

	int currentTicketCost = 0;

	bool	currentWrongGoldChaBefore			= wrongGoldCharacterbefore;
	bool	currentWrongGoldWeaponBefore		= wrongGoldWeaponBefore;
	int		currentAreadyInChaPoolTicket		= areadyInCharacterPoolTicket;
	int		currentAreadyInWeaponPoolTicket		= areadyInWeaponPoolTicket;

	EN_CardPoolType currentPoolType = EN_CardPoolType::character;

	//��ǰ����˶���UP��ɫ/UP����
	int		currentGetUpGlodCharacter	= 0;
	int		currentGetUpGlodWeapon		= 0;


	int RemainN = N;
	int RemainM = M;


	while (currentTicketCost < largestTicket)
	{
		if (transfromType == En_PoolTransfromType::NCharacterMWeapon)
		{
			if (RemainN != 0)
			{
				currentPoolType = EN_CardPoolType::character;
			}
			else if (RemainM != 0)
			{
				currentPoolType = EN_CardPoolType::weapon;
			}			
		}
		else if (transfromType == En_PoolTransfromType::NWeaponMCharacter)
		{
			if (RemainN != 0)
			{
				currentPoolType = EN_CardPoolType::weapon;
			}
			else if (RemainM != 0)
			{
				currentPoolType = EN_CardPoolType::character;
			}
		}

		int ticketCost = 0;

		if (currentPoolType == EN_CardPoolType::character)
		{
			ticketCost = DrawCardUntilGetUp(EN_CardPoolType::character, currentWrongGoldChaBefore, currentAreadyInChaPoolTicket, engine);
			currentWrongGoldChaBefore = false;
			currentAreadyInChaPoolTicket = 0;
		}
		else if (currentPoolType == EN_CardPoolType::weapon)
		{
			ticketCost = DrawCardUntilGetUp(EN_CardPoolType::weapon, currentWrongGoldWeaponBefore, currentAreadyInWeaponPoolTicket, engine);
			currentWrongGoldWeaponBefore = false;
			currentAreadyInWeaponPoolTicket = true;
		}

		currentTicketCost += ticketCost;
		if (currentTicketCost > largestTicket)
		{
			break;
		}

		if (currentPoolType == EN_CardPoolType::character)
		{
			currentGetUpGlodCharacter++;
		}
		else if (currentPoolType == EN_CardPoolType::weapon)
		{
			currentGetUpGlodWeapon++;
		}

		if (RemainN != 0)
		{
			RemainN--;
		}
		else if (RemainM != 0)
		{
			RemainM--;
		}
		
		if(RemainN == 0 && RemainM == 0)
		{
			RemainN = N;
			RemainM = M;
		}
	}

	if (transfromType == En_PoolTransfromType::NCharacterMWeapon)
	{
		return QPair<int, int>(currentGetUpGlodCharacter, currentGetUpGlodWeapon);
	}
	else if (transfromType == En_PoolTransfromType::NWeaponMCharacter)
	{
		return QPair<int, int>(currentGetUpGlodWeapon, currentGetUpGlodCharacter);
	}

	return QPair<int, int>(-1, -1);

}

QPair<int, int> StarRailMediator::DrawCardNTPoolAMTPoolB(En_PoolTransfromType transfromType, int largestTicket, std::default_random_engine & engine, bool wrongGoldCharacterbefore, int areadyInCharacterPoolTicket, bool wrongGoldWeaponBefore, int areadyInWeaponPoolTicket, int N, int M)
{
	if (transfromType == En_PoolTransfromType::NCharacterMWeapon || transfromType == En_PoolTransfromType::NWeaponMCharacter)
	{
		return QPair<int, int>(-1, -1);
	}

	int		currentTicketCost = 0;

	bool	currentWrongGoldChaBefore		= wrongGoldCharacterbefore;
	bool	currentWrongGoldWeaponBefore	= wrongGoldWeaponBefore;
	int		distanceToLastGoldCharacter		= areadyInCharacterPoolTicket + 1;
	int		distanceToLastGoldWeapon		= areadyInWeaponPoolTicket + 1;

	EN_CardPoolType currentPoolType = EN_CardPoolType::character;

	//��ǰ����˶���UP��ɫ/UP����
	int		currentGetUpGlodCharacter = 0;
	int		currentGetUpGlodWeapon = 0;


	int RemainN = N;
	int RemainM = M;


	while (currentTicketCost < largestTicket)
	{
		if (transfromType == En_PoolTransfromType::NTCharacterMTWeapon)
		{
			if (RemainN != 0)
			{
				currentPoolType = EN_CardPoolType::character;
			}
			else if (RemainM != 0)
			{
				currentPoolType = EN_CardPoolType::weapon;
			}
		}
		else if (transfromType == En_PoolTransfromType::NTWeaponMTCharacter)
		{
			if (RemainN != 0)
			{
				currentPoolType = EN_CardPoolType::weapon;
			}
			else if (RemainM != 0)
			{
				currentPoolType = EN_CardPoolType::character;
			}
		}

		En_DrawCardResult currentResult = En_DrawCardResult::normal;

		if (currentPoolType == EN_CardPoolType::character)
		{
			currentResult = DrawCardAtOnce(currentPoolType, currentWrongGoldChaBefore, distanceToLastGoldCharacter,engine);
			distanceToLastGoldCharacter++;
		}
		else if (currentPoolType == EN_CardPoolType::weapon)
		{
			currentResult = DrawCardAtOnce(currentPoolType, currentWrongGoldWeaponBefore, distanceToLastGoldWeapon, engine);
			distanceToLastGoldWeapon++;
		}

		currentTicketCost++;

		switch(currentResult)
		{
			case En_DrawCardResult::normal:break;
			case En_DrawCardResult::character_UpGold:
			{
				currentGetUpGlodCharacter++;
				distanceToLastGoldCharacter = 1;
				currentWrongGoldChaBefore = false;
			}break;
			case En_DrawCardResult::character_wrongGold:
			{
				distanceToLastGoldCharacter = 1;
				currentWrongGoldChaBefore = true;
			}break;
			case En_DrawCardResult::weapon_UpGold:
			{
				currentGetUpGlodWeapon++;
				distanceToLastGoldWeapon = 1;
				currentWrongGoldWeaponBefore = false;
			}break;
			case En_DrawCardResult::weapon_wrongGold:
			{
				distanceToLastGoldWeapon = 1;
				currentWrongGoldWeaponBefore = true;
			}break;
		}

		if (RemainN != 0)
		{
			RemainN--;
		}
		else if (RemainM != 0)
		{
			RemainM--;
		}
		
		if(RemainN == 0 && RemainM == 0)
		{
			RemainN = N;
			RemainM = M;
		}
	}

	if (transfromType == En_PoolTransfromType::NTCharacterMTWeapon)
	{
		return QPair<int, int>(currentGetUpGlodCharacter, currentGetUpGlodWeapon);
	}
	else if (transfromType == En_PoolTransfromType::NTWeaponMTCharacter)
	{
		return QPair<int, int>(currentGetUpGlodWeapon, currentGetUpGlodCharacter);
	}

	return QPair<int, int>(-1, -1);
}

const EN_StarRailErrorNum StarRailMediator::checkRelicEstInputErr(const St_RelicValidEstimatePara & EstPara)
{
	if (EstPara.playTime <= 0)
	{
		return EN_StarRailErrorNum::RelicEst_NoPlayTime;
	}

	bool hasValidPrimeProperty =
		EstPara.PrimePro_Valid_AttackPercentage ||
		EstPara.PrimePro_Valid_AttackValue ||
		EstPara.PrimePro_Valid_BreakDamage ||
		EstPara.PrimePro_Valid_ChargeEfficiency ||
		EstPara.PrimePro_Valid_CriticalDamage ||
		EstPara.PrimePro_Valid_CriticalProb ||
		EstPara.PrimePro_Valid_DeBuffAccuracy ||
		EstPara.PrimePro_Valid_DefencePercentage ||
		EstPara.PrimePro_Valid_Fire ||
		EstPara.PrimePro_Valid_HealAddition ||
		EstPara.PrimePro_Valid_HPPercentage ||
		EstPara.PrimePro_Valid_HPValue ||
		EstPara.PrimePro_Valid_Ice ||
		EstPara.PrimePro_Valid_Null ||
		EstPara.PrimePro_Valid_Physical ||
		EstPara.PrimePro_Valid_Quantum ||
		EstPara.PrimePro_Valid_Speed ||
		EstPara.PrimePro_Valid_Thunder ||
		EstPara.PrimePro_Valid_Wind;

	if (!hasValidPrimeProperty)//û����Ч������
	{
		return EN_StarRailErrorNum::RelicEst_ValidPrimePropertyZero;
	}

	int ValidSubPropertyNum = 0;

	if (EstPara.SubPro_Valid_AttackPercentage)	ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_AttackValue)		ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_BreakDamage)		ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_CriticalDamage)	ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_CriticalProb)		ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_DeBuffAccuracy)	ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_DeBuffDefence)		ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_DefencePercentage) ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_DefenceValue)		ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_HPPercentage)		ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_HPValue)			ValidSubPropertyNum++;
	if (EstPara.SubPro_Valid_Speed)				ValidSubPropertyNum++;

	if(ValidSubPropertyNum < 4)//��Ч������С��4
	{
		return EN_StarRailErrorNum::RelicEst_ValidSubPropertyLessThan4;
	}

	return EN_StarRailErrorNum::RelicEst_InputNoError;
}

void StarRailMediator::sendRelicEstErrorMsg(const EN_StarRailErrorNum ErrNum)
{
	QString ErrMsg;
	switch (ErrNum)
	{
		case EN_StarRailErrorNum::RelicEst_InputNoError					: break;
		case EN_StarRailErrorNum::RelicEst_NoPlayTime					: ErrMsg = QString("�򱾴���С��1");break;
		case EN_StarRailErrorNum::RelicEst_ValidPrimePropertyZero		: ErrMsg = QString("ûѡ��Ч������");break;
		case EN_StarRailErrorNum::RelicEst_ValidSubPropertyLessThan4	: ErrMsg = QString("��Ч������С��4");break;
	}
	emit signal_RelicEstErrorMsg(ErrNum, ErrMsg);
}
