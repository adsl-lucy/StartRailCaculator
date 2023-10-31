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

#include "RelicResult.h"

RelicResult::RelicResult()
{
	m_CurrentLevel = 1;

	initPriproMap();
	initSubProNumPos();
	resetPara();

}

RelicResult::~RelicResult()
{
}

void RelicResult::initPriproMap()
{
	int Clothes_Pripro_HPPercenagePos			= Const_PriPro_ratio_clothes_HPPercentage		* 100;
	int Clothes_Pripro_AttackPercentagePos		= Const_PriPro_ratio_clothes_attackPercentage	* 100 + Clothes_Pripro_HPPercenagePos;
	int Clothes_Pripro_defencePercentagePos		= Const_PriPro_ratio_clothes_defencePercentage	* 100 + Clothes_Pripro_AttackPercentagePos;
	int Clothes_Pripro_CRITProbPos				= Const_PriPro_ratio_clothes_CRITProb			* 100 + Clothes_Pripro_defencePercentagePos;
	int Clothes_Pripro_CRITDamagePos			= Const_PriPro_ratio_clothes_CRITDamage			* 100 + Clothes_Pripro_CRITProbPos;
	int Clothes_Pripro_HealAdditionPos			= Const_PriPro_ratio_clothes_HealAddition		* 100 + Clothes_Pripro_CRITDamagePos;
	int Clothes_Pripro_DebuffAccuracyPos		= Const_PriPro_ratio_clothes_DebuffAccuracy		* 100 + Clothes_Pripro_HealAdditionPos;

	m_mapClothesPripro.insert(Clothes_Pripro_HPPercenagePos			, En_RelicPrimeProperty::HPPercentage);
	m_mapClothesPripro.insert(Clothes_Pripro_AttackPercentagePos	, En_RelicPrimeProperty::AttackPercentage);
	m_mapClothesPripro.insert(Clothes_Pripro_defencePercentagePos	, En_RelicPrimeProperty::DefencePercentage);
	m_mapClothesPripro.insert(Clothes_Pripro_CRITProbPos			, En_RelicPrimeProperty::CriticalProb);
	m_mapClothesPripro.insert(Clothes_Pripro_CRITDamagePos			, En_RelicPrimeProperty::CriticalDamage);
	m_mapClothesPripro.insert(Clothes_Pripro_HealAdditionPos		, En_RelicPrimeProperty::HealAddition);
	m_mapClothesPripro.insert(Clothes_Pripro_DebuffAccuracyPos		, En_RelicPrimeProperty::DeBuffAccuracy);

	int Shoe_Pripro_HPPercenagePos			= Const_PriPro_ratio_shoes_HPPercentage			* 100;
	int Shoe_Pripro_AttackPercentagePos		= Const_PriPro_ratio_shoes_attackPercentage		* 100 + Shoe_Pripro_HPPercenagePos;
	int Shoe_Pripro_defencePercentagePos	= Const_PriPro_ratio_shoes_defencePercentage	* 100 + Shoe_Pripro_AttackPercentagePos;
	int Shoe_Pripro_SpeedProbPos			= Const_PriPro_ratio_shoes_speed				* 100 + Shoe_Pripro_defencePercentagePos;

	m_mapShoesPripro.insert(Shoe_Pripro_HPPercenagePos			, En_RelicPrimeProperty::HPPercentage);
	m_mapShoesPripro.insert(Shoe_Pripro_AttackPercentagePos		, En_RelicPrimeProperty::AttackPercentage);
	m_mapShoesPripro.insert(Shoe_Pripro_defencePercentagePos	, En_RelicPrimeProperty::DefencePercentage);
	m_mapShoesPripro.insert(Shoe_Pripro_SpeedProbPos			, En_RelicPrimeProperty::Speed);

	int Cord_Pripro_HPPercenagePos		= Const_PriPro_ratio_cord_HPPercentage			* 1000;
	int Cord_AttackPercentagePos		= Const_PriPro_ratio_cord_attackPercentage		* 1000 + Cord_Pripro_HPPercenagePos;
	int Cord_defencePercentagePos		= Const_PriPro_ratio_cord_defencePercentage		* 1000 + Cord_AttackPercentagePos;
	int Cord_breakDamagePos				= Const_PriPro_ratio_cord_breakDamage			* 1000 + Cord_defencePercentagePos;
	int Cord_chargeEfficiecyPos			= Const_PriPro_ratio_cord_chargeEfficiency		* 1000 + Cord_breakDamagePos;

	m_mapCordPripro.insert(Cord_Pripro_HPPercenagePos	, En_RelicPrimeProperty::HPPercentage);
	m_mapCordPripro.insert(Cord_AttackPercentagePos		, En_RelicPrimeProperty::AttackPercentage);
	m_mapCordPripro.insert(Cord_defencePercentagePos	, En_RelicPrimeProperty::DefencePercentage);
	m_mapCordPripro.insert(Cord_breakDamagePos			, En_RelicPrimeProperty::BreakDamage);
	m_mapCordPripro.insert(Cord_chargeEfficiecyPos		, En_RelicPrimeProperty::ChargeEfficiency);

	int  ball_HPPercenagePos			= Const_PriPro_ratio_ball_HPPercentage			* 1000;
	int  ball_AttackPercentagePos		= Const_PriPro_ratio_ball_attackPercentage		* 1000 + ball_HPPercenagePos;
	int  ball_defencePercentagePos		= Const_PriPro_ratio_ball_defencePercentage		* 1000 + ball_AttackPercentagePos;

	int  ball_firePos		= Const_PriPro_ratio_ball_fire		* 1000 + ball_defencePercentagePos;
	int  ball_thunderPos	= Const_PriPro_ratio_ball_thunder	* 1000 + ball_firePos;
	int  ball_windPos		= Const_PriPro_ratio_ball_wind		* 1000 + ball_thunderPos;
	int  ball_icePos		= Const_PriPro_ratio_ball_ice		* 1000 + ball_windPos;
	int  ball_nullPos		= Const_PriPro_ratio_ball_null		* 1000 + ball_icePos;
	int  ball_quantumPos	= Const_PriPro_ratio_ball_quantum	* 1000 + ball_nullPos;
	int  ball_physicalPos	= Const_PriPro_ratio_ball_physical	* 1000 + ball_quantumPos;

	m_mapBallPripro.insert(ball_HPPercenagePos			, En_RelicPrimeProperty::HPPercentage);
	m_mapBallPripro.insert(ball_AttackPercentagePos		, En_RelicPrimeProperty::AttackPercentage);
	m_mapBallPripro.insert(ball_defencePercentagePos	, En_RelicPrimeProperty::DefencePercentage);

	m_mapBallPripro.insert(ball_firePos		, En_RelicPrimeProperty::Fire);
	m_mapBallPripro.insert(ball_thunderPos	, En_RelicPrimeProperty::Thunder);
	m_mapBallPripro.insert(ball_windPos		, En_RelicPrimeProperty::Wind);
	m_mapBallPripro.insert(ball_icePos		, En_RelicPrimeProperty::Ice);
	m_mapBallPripro.insert(ball_nullPos		, En_RelicPrimeProperty::Null);
	m_mapBallPripro.insert(ball_quantumPos	, En_RelicPrimeProperty::Quantum);
	m_mapBallPripro.insert(ball_physicalPos	, En_RelicPrimeProperty::Physical);
}

void RelicResult::initSubProNumPos()
{
	m_Affix2Pos = Const_ratio_SubPro_2Affix * 1000;
	m_Affix3Pos = Const_ratio_SubPro_2Affix * 1000 + m_Affix2Pos;
	m_Affix4Pos = Const_ratio_SubPro_2Affix * 1000 + m_Affix3Pos;
}

bool RelicResult::getBirth(const En_raidType& raidType, const St_RelicValidEstimatePara & EstPara, std::default_random_engine& engine)
{
	m_bSetCorrect	= creatSetState(engine);

	if (!m_bSetCorrect)
	{
		return false;
	}

	m_relicType		= creatType(raidType,engine);

	bool typeCorrect = m_relicType == EstPara.relicType;

	if (!typeCorrect)
	{
		return false;
	}

	m_primeProperty = createPrimeProperty(engine);

	bool primePropertyValid = checkPrimePropertyValid(EstPara);

	if (!primePropertyValid)
	{
		return false;
	}

	resetSubPropertyVec();
	int birthSubProNum = createSubPropertyNum(engine);

	switch (birthSubProNum)
	{
		case 4:	
		{
			m_fourthSubProType = creatNewSubProperty(engine);

			bool SubPro4TypeValid = checkSubProTypeVaildity(m_fourthSubProType,EstPara);
			if (!SubPro4TypeValid)
			{
				return false;
			}
			double upgradeValue4 = createNewSubPropertyValue(m_fourthSubProType,engine);
			upgradeOneSubProperty(m_fourthSubProType, upgradeValue4);
		}
		case 3:
		{
			m_thirdSubProType = creatNewSubProperty(engine);
			bool SubPro3TypeValid = checkSubProTypeVaildity(m_thirdSubProType, EstPara);
			if (!SubPro3TypeValid)
			{
				return false;
			}
			double upgradeValue3 = createNewSubPropertyValue(m_thirdSubProType, engine);
			upgradeOneSubProperty(m_thirdSubProType, upgradeValue3);
		}
		case 2:	
		{
			m_secondSubProType = creatNewSubProperty(engine);
			bool SubPro2TypeValid = checkSubProTypeVaildity(m_secondSubProType, EstPara);
			if (!SubPro2TypeValid)
			{
				return false;
			}
			double upgradeValue2 = createNewSubPropertyValue(m_secondSubProType, engine);
			upgradeOneSubProperty(m_secondSubProType, upgradeValue2);
		}
	}

	m_firstSubProType = creatNewSubProperty(engine);
	bool SubPro1TypeValid = checkSubProTypeVaildity(m_firstSubProType, EstPara);
	if (!SubPro1TypeValid)
	{
		return false;
	}
	double upgradeValue1 = createNewSubPropertyValue(m_firstSubProType, engine);
	upgradeOneSubProperty(m_firstSubProType, upgradeValue1);

	//初始化完成，等级设置为1
	m_CurrentLevel = 1;

	bool updateState = true;

	while (isHighestLevel() == false)
	{
		//有了4个属性又没数值要求，就直接成立了，返回true
		if (EstPara.vecSubPropertyValueRequirement.size() == 0 && getSubPropertyNum() == 4)
		{
			return true;
		}

		updateState = upgradeOnce(EstPara,engine);
		if (!updateState)
		{
			return false;
		}
	}
	bool allPropertyValid = true;

	for (auto pos : EstPara.vecSubPropertyValueRequirement)
	{
		En_RelicSubProperty propertyType = pos;
		bool currentState = false;

		switch (propertyType)
		{
			case En_RelicSubProperty::HPValue:
			{
				if (m_primeProperty == En_RelicPrimeProperty::HPValue)
				{
					continue;
				}
				else
				{
					currentState = checkSubProValueVaildity(En_RelicSubProperty::HPValue, m_dHPValue, EstPara);
				}
			}break;
			case En_RelicSubProperty::HPPercentage:
			{
				if (m_primeProperty == En_RelicPrimeProperty::HPPercentage)
				{
					continue;
				}
				else
				{
					currentState = checkSubProValueVaildity(En_RelicSubProperty::HPPercentage, m_dHPPercentage, EstPara);
				}
			}break;
			case En_RelicSubProperty::AttackValue:
			{
				if (m_primeProperty == En_RelicPrimeProperty::AttackValue)
				{
					continue;
				}
				else
				{
					currentState = checkSubProValueVaildity(En_RelicSubProperty::AttackValue, m_dAttackValue, EstPara);
				}
			}break;
			case En_RelicSubProperty::AttackPercentage:
			{
				if (m_primeProperty == En_RelicPrimeProperty::AttackPercentage)
				{
					continue;
				}
				else
				{
					currentState = checkSubProValueVaildity(En_RelicSubProperty::AttackPercentage, m_dAttackPercent, EstPara);
				}
			}break;
			case En_RelicSubProperty::DefenceValue:	
			{
				currentState = checkSubProValueVaildity(En_RelicSubProperty::AttackPercentage, m_dAttackPercent, EstPara);
			}break;
			case En_RelicSubProperty::DefencePercentage:
			{
				if (m_primeProperty == En_RelicPrimeProperty::DefencePercentage)
				{
					continue;
				}
				else
				{
					currentState = checkSubProValueVaildity(En_RelicSubProperty::DefencePercentage, m_dDefencePercentage, EstPara);
				}
			}break;
			case En_RelicSubProperty::CriticalProb:
			{
				if (m_primeProperty == En_RelicPrimeProperty::CriticalProb)
				{
					continue;
				}
				else
				{
					currentState = checkSubProValueVaildity(En_RelicSubProperty::CriticalProb, m_dCriticalProb, EstPara);
				}
			}break;
			case En_RelicSubProperty::CriticalDamage:
			{
				if (m_primeProperty == En_RelicPrimeProperty::CriticalDamage)
				{
					continue;
				}
				else
				{
					currentState = checkSubProValueVaildity(En_RelicSubProperty::CriticalDamage, m_dCriticalDamage, EstPara);
				}
			}break;
			case En_RelicSubProperty::Speed:
			{
				if (m_primeProperty == En_RelicPrimeProperty::Speed)
				{
					continue;
				}
				else
				{
					currentState = checkSubProValueVaildity(En_RelicSubProperty::Speed, m_dSpeed, EstPara);
				}
			}break;
			case En_RelicSubProperty::DeBuffDefence:
			{
				currentState = checkSubProValueVaildity(En_RelicSubProperty::Speed, m_dSpeed, EstPara);
			}break;
			case En_RelicSubProperty::BreakDamage:
			{
				if (m_primeProperty == En_RelicPrimeProperty::BreakDamage)
				{
					continue;
				}
				else
				{
					currentState = checkSubProValueVaildity(En_RelicSubProperty::BreakDamage, m_dBreakDamage, EstPara);
				}
			}break;
			case En_RelicSubProperty::DeBuffAccuracy:			
			{
				if (m_primeProperty == En_RelicPrimeProperty::DeBuffAccuracy)
				{
					continue;
				}
				else
				{
					currentState = checkSubProValueVaildity(En_RelicSubProperty::DeBuffAccuracy, m_dDeBuffAccuracy, EstPara);
				}
			}break;
		}
		allPropertyValid &= currentState;
	}

	return allPropertyValid;

}

void RelicResult::resetPara()
{
	m_bSetCorrect		= false;							
	m_relicType			= En_RelicType::None;				
	m_primeProperty		= En_RelicPrimeProperty::None;		


	m_CurrentLevel	= 0;				


	m_firstSubProType	= En_RelicSubProperty::None;
	m_secondSubProType	= En_RelicSubProperty::None;
	m_thirdSubProType	= En_RelicSubProperty::None;
	m_fourthSubProType	= En_RelicSubProperty::None;

	m_dHPValue				= 0;			
	m_dHPPercentage			= 0;			
	m_dAttackValue			= 0;			
	m_dAttackPercent		= 0;			
	m_dDefenceValue			= 0;			
	m_dDefencePercentage	= 0;			

	m_dCriticalProb		= 0;			
	m_dCriticalDamage	= 0;			
	m_dSpeed			= 0;			

	m_dDeBuffDefence	= 0;			
	m_dBreakDamage		= 0;			
	m_dDeBuffAccuracy	= 0;

	m_vecSubProperty.clear();
}

int RelicResult::getRelicNum(std::default_random_engine & engine)
{
	int get3Pos = Const_3RelicProb * 100;
	int get2Pos = 100;

	std::uniform_int_distribution<int> di(1, 100);
	int resultPos = di(engine);

	if (resultPos <= get3Pos)
	{
		return 3;
	}
	else if (resultPos <= get2Pos)
	{
		return 2;

	}
	return 0;
}

const En_raidType RelicResult::getRaidType(const En_RelicType relicTYpe)
{
	switch (relicTYpe)
	{
		case En_RelicType::Head		:return En_raidType::Relic;
		case En_RelicType::Hand		:return En_raidType::Relic;
		case En_RelicType::Clothes	:return En_raidType::Relic;
		case En_RelicType::Shoes	:return En_raidType::Relic;
		case En_RelicType::Cord		:return En_raidType::SimulateUniverse;
		case En_RelicType::Ball		:return En_raidType::SimulateUniverse;
	}
	return En_raidType::Relic;
}

bool RelicResult::upgradeOnce(const St_RelicValidEstimatePara & EstPara, std::default_random_engine & engine)
{
	if (isHighestLevel())//最高级不升了
	{
		return true;
	}

	int currentSubPropertyNum = getSubPropertyNum();

	if (currentSubPropertyNum < 4)
	{
		En_RelicSubProperty newSubProType = creatNewSubProperty(engine);
		bool SubProTypeValid = checkSubProTypeVaildity(newSubProType, EstPara);
		if (!SubProTypeValid)
		{
			return false;
		}

		if (currentSubPropertyNum == 2)
		{
			m_thirdSubProType = newSubProType;
		}
		else if (currentSubPropertyNum == 3)
		{
			m_fourthSubProType = newSubProType;
		}
		double upgradeValue = createNewSubPropertyValue(newSubProType, engine);
		upgradeOneSubProperty(newSubProType, upgradeValue);
	}
	else
	{
		int upgradePos = getUpgradeSubProPos(engine);
		switch (upgradePos)
		{
		case 1:	
		{
			double upgradeValue = createNewSubPropertyValue(m_firstSubProType, engine);
			upgradeOneSubProperty(m_firstSubProType, upgradeValue);
		}break;
		case 2:
		{
			double upgradeValue = createNewSubPropertyValue(m_secondSubProType, engine);
			upgradeOneSubProperty(m_secondSubProType, upgradeValue);
		}break;
		case 3:
		{
			double upgradeValue = createNewSubPropertyValue(m_thirdSubProType, engine);
			upgradeOneSubProperty(m_thirdSubProType, upgradeValue);
		}break;
		case 4:
		{
			double upgradeValue = createNewSubPropertyValue(m_fourthSubProType, engine);
			upgradeOneSubProperty(m_fourthSubProType, upgradeValue);
		}break;
		}
	}

	switch (m_CurrentLevel)
	{
		case 1:m_CurrentLevel	= 4; break;
		case 4:m_CurrentLevel	= 8; break;
		case 8:m_CurrentLevel	= 12; break;
		case 12:m_CurrentLevel	= 15; break;
	}

	return true;

}

bool RelicResult::isPrimePropertyValid(const St_RelicValidEstimatePara & EstPara)
{
	return checkPrimePropertyValid(EstPara);
}

const int RelicResult::getSubPropertyNum()
{
	int SubPropertyNum = 0;

	if (m_firstSubProType	!= En_RelicSubProperty::None)	SubPropertyNum++;
	if (m_secondSubProType	!= En_RelicSubProperty::None)	SubPropertyNum++;
	if (m_thirdSubProType	!= En_RelicSubProperty::None)	SubPropertyNum++;
	if (m_fourthSubProType	!= En_RelicSubProperty::None)	SubPropertyNum++;

	return SubPropertyNum;
}

bool RelicResult::creatSetState(std::default_random_engine & engine)
{
	std::uniform_int_distribution<int> di(0, 999);

	int randomNum = di(engine);

	if (randomNum < 500)
	{
		m_bSetCorrect = true;
	}
	else
	{
		m_bSetCorrect = false;
	}

	return m_bSetCorrect;

}

En_RelicType RelicResult::creatType(const En_raidType raidType, std::default_random_engine & engine)
{
	if (raidType == En_raidType::Relic)
	{
		std::uniform_int_distribution<int> di(1, 4);
		int result = di(engine);
		switch (result)
		{
			case 1:m_relicType = En_RelicType::Head		; break;
			case 2:m_relicType = En_RelicType::Hand		; break;
			case 3:m_relicType = En_RelicType::Clothes	; break;
			case 4:m_relicType = En_RelicType::Shoes	; break;
		}
	}
	else if (raidType == En_raidType::SimulateUniverse)
	{
		std::uniform_int_distribution<int> di(1, 2);
		int result = di(engine);
		switch (result)
		{
			case 1:m_relicType = En_RelicType::Cord; break;
			case 2:m_relicType = En_RelicType::Ball; break;
		}
	}

	return m_relicType;
}

En_RelicPrimeProperty RelicResult::createPrimeProperty(std::default_random_engine & engine)
{

	switch (m_relicType)
	{
		case En_RelicType::Head: m_primeProperty = En_RelicPrimeProperty::HPValue; break;
		case En_RelicType::Hand: m_primeProperty = En_RelicPrimeProperty::AttackValue; break;
		case En_RelicType::Clothes:
		{
			std::uniform_int_distribution<int> di(1, 100);
			int result = di(engine);
			auto pos = m_mapClothesPripro.lowerBound(result);
			if (pos != m_mapClothesPripro.end())
			{
				return pos.value();
			}
			else
			{
				return En_RelicPrimeProperty::None;
			}
		}break;
		case En_RelicType::Shoes:
		{
			std::uniform_int_distribution<int> di(1, 100);
			int result = di(engine);
			auto pos = m_mapShoesPripro.lowerBound(result);
			if (pos != m_mapShoesPripro.end())
			{
				return pos.value();
			}
			else
			{
				return En_RelicPrimeProperty::None;
			}
		}break;
		case En_RelicType::Cord:
		{
			std::uniform_int_distribution<int> di(1, 1000);
			int result = di(engine);
			auto pos = m_mapCordPripro.lowerBound(result);
			if (pos != m_mapCordPripro.end())
			{
				return pos.value();
			}
			else
			{
				return En_RelicPrimeProperty::None;
			}
		}break;
		case En_RelicType::Ball:
		{
			std::uniform_int_distribution<int> di(1, 1000);
			int result = di(engine);
			auto pos = m_mapBallPripro.lowerBound(result);
			if (pos != m_mapBallPripro.end())
			{
				return pos.value();
			}
			else
			{
				return En_RelicPrimeProperty::None;
			}
		}break;
	}
	return m_primeProperty;
}

int RelicResult::createSubPropertyNum(std::default_random_engine & engine)
{

	std::uniform_int_distribution<int> di(1, m_Affix4Pos);
	int result = di(engine);

	if (result <= m_Affix2Pos)
	{
		return 2;
	}
	else if (result <= m_Affix3Pos)
	{
		return 3;
	}
	else if (result <= m_Affix4Pos)
	{
		return 4;
	}

	return 0;
}

void RelicResult::resetSubPropertyVec()
{
	m_vecSubProperty.clear();

	if (m_primeProperty != En_RelicPrimeProperty::HPValue)
	{
		for (int count = 0; count < Const_SubPro_weight_HPValue; count++)
		{
			m_vecSubProperty.push_back(En_RelicSubProperty::HPValue);
		}
	}

	if (m_primeProperty != En_RelicPrimeProperty::HPPercentage)
	{
		for (int count = 0; count < Const_SubPro_weight_HPPercentage; count++)
		{
			m_vecSubProperty.push_back(En_RelicSubProperty::HPPercentage);
		}
	}

	if (m_primeProperty != En_RelicPrimeProperty::AttackValue)
	{
		for (int count = 0; count < Const_SubPro_weight_attackValue; count++)
		{
			m_vecSubProperty.push_back(En_RelicSubProperty::AttackValue);
		}
	}

	if (m_primeProperty != En_RelicPrimeProperty::AttackPercentage)
	{
		for (int count = 0; count < Const_SubPro_weight_attackPercentage; count++)
		{
			m_vecSubProperty.push_back(En_RelicSubProperty::AttackPercentage);
		}
	}

	for (int count = 0; count < Const_SubPro_weight_defenceValue; count++)
	{
		m_vecSubProperty.push_back(En_RelicSubProperty::DefenceValue);
	}
	

	if (m_primeProperty != En_RelicPrimeProperty::DefencePercentage)
	{
		for (int count = 0; count < Const_SubPro_weight_defencePercentage; count++)
		{
			m_vecSubProperty.push_back(En_RelicSubProperty::DefencePercentage);
		}
	}

	if (m_primeProperty != En_RelicPrimeProperty::CriticalProb)
	{
		for (int count = 0; count < Const_SubPro_weight_CRITProb; count++)
		{
			m_vecSubProperty.push_back(En_RelicSubProperty::CriticalProb);
		}
	}

	if (m_primeProperty != En_RelicPrimeProperty::CriticalDamage)
	{
		for (int count = 0; count < Const_SubPro_weight_CRITDamage; count++)
		{
			m_vecSubProperty.push_back(En_RelicSubProperty::CriticalDamage);
		}
	}

	if (m_primeProperty != En_RelicPrimeProperty::DeBuffAccuracy)
	{
		for (int count = 0; count < Const_SubPro_weight_DebuffAccuracy; count++)
		{
			m_vecSubProperty.push_back(En_RelicSubProperty::DeBuffAccuracy);
		}
	}

	for (int count = 0; count < Const_SubPro_weight_DebuffDefence; count++)
	{
		m_vecSubProperty.push_back(En_RelicSubProperty::DeBuffDefence);
	}
	

	if (m_primeProperty != En_RelicPrimeProperty::BreakDamage)
	{
		for (int count = 0; count < Const_SubPro_weight_breakDamage; count++)
		{
			m_vecSubProperty.push_back(En_RelicSubProperty::BreakDamage);
		}
	}

	if (m_primeProperty != En_RelicPrimeProperty::Speed)
	{
		for (int count = 0; count < Const_SubPro_weight_speed; count++)
		{
			m_vecSubProperty.push_back(En_RelicSubProperty::Speed);
		}
	}
}

En_RelicSubProperty RelicResult::creatNewSubProperty(std::default_random_engine & engine)
{	

	std::uniform_int_distribution<int> di(0, m_vecSubProperty.size() -1);
	int resultNum = di(engine);
	if (resultNum < m_vecSubProperty.size())
	{
		En_RelicSubProperty resultProperty = m_vecSubProperty[resultNum];

		int removeCount = 0;

		switch (resultProperty)
		{
			case En_RelicSubProperty::HPValue			:removeCount = Const_SubPro_weight_HPValue			; break;
			case En_RelicSubProperty::HPPercentage		:removeCount = Const_SubPro_weight_HPPercentage		; break;
			case En_RelicSubProperty::AttackValue		:removeCount = Const_SubPro_weight_attackValue		; break;
			case En_RelicSubProperty::AttackPercentage	:removeCount = Const_SubPro_weight_attackPercentage	; break;
			case En_RelicSubProperty::DefenceValue		:removeCount = Const_SubPro_weight_defenceValue		; break;
			case En_RelicSubProperty::DefencePercentage	:removeCount = Const_SubPro_weight_defencePercentage; break;
			case En_RelicSubProperty::CriticalProb		:removeCount = Const_SubPro_weight_CRITProb			; break;
			case En_RelicSubProperty::CriticalDamage	:removeCount = Const_SubPro_weight_CRITDamage		; break;
			case En_RelicSubProperty::Speed				:removeCount = Const_SubPro_weight_speed			; break;
			case En_RelicSubProperty::DeBuffDefence		:removeCount = Const_SubPro_weight_DebuffDefence	; break;
			case En_RelicSubProperty::BreakDamage		:removeCount = Const_SubPro_weight_breakDamage		; break;
			case En_RelicSubProperty::DeBuffAccuracy	:removeCount = Const_SubPro_weight_DebuffAccuracy	; break;
		}

		int removePos = resultNum;
		while (removePos - 1 >= 0)
		{
			if (m_vecSubProperty[removePos - 1] != resultProperty)
			{
				break;
			}
			removePos--;
		}

		m_vecSubProperty.remove(removePos,removeCount);

		return resultProperty;
	}

	return En_RelicSubProperty::None;
}

double RelicResult::createNewSubPropertyValue(En_RelicSubProperty SubProType, std::default_random_engine & engine)
{
	std::uniform_int_distribution<int> di(1, 3);
	int resultCase = di(engine);

	switch (SubProType)
	{
		case En_RelicSubProperty::HPValue:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_HPValue;
				case 2:return Const_SubPro_value_caseB_HPValue;
				case 3:return Const_SubPro_value_caseC_HPValue;
			}
		}break;
		case En_RelicSubProperty::HPPercentage:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_HPPercentage;
				case 2:return Const_SubPro_value_caseB_HPPercentage;
				case 3:return Const_SubPro_value_caseC_HPPercentage;
			}
		}break;
		case En_RelicSubProperty::AttackValue:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_attackValue;
				case 2:return Const_SubPro_value_caseB_attackValue;
				case 3:return Const_SubPro_value_caseC_attackValue;
			}
		}break;
		case En_RelicSubProperty::AttackPercentage:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_aattackPercentage;
				case 2:return Const_SubPro_value_caseB_aattackPercentage;
				case 3:return Const_SubPro_value_caseC_aattackPercentage;
			}
		}break;
		case En_RelicSubProperty::DefenceValue:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_defenceValue;
				case 2:return Const_SubPro_value_caseB_defenceValue;
				case 3:return Const_SubPro_value_caseC_defenceValue;
			}
		}break;
		case En_RelicSubProperty::DefencePercentage:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_defencePercentage;
				case 2:return Const_SubPro_value_caseB_defencePercentage;
				case 3:return Const_SubPro_value_caseC_defencePercentage;
			}
		}break;
		case En_RelicSubProperty::CriticalProb:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_CRITProb;
				case 2:return Const_SubPro_value_caseB_CRITProb;
				case 3:return Const_SubPro_value_caseC_CRITProb;
			}
		}break;
		case En_RelicSubProperty::CriticalDamage:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_CRITDamage;
				case 2:return Const_SubPro_value_caseB_CRITDamage;
				case 3:return Const_SubPro_value_caseC_CRITDamage;
			}
		}break;
		case En_RelicSubProperty::Speed:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_speed;
				case 2:return Const_SubPro_value_caseB_speed;
				case 3:return Const_SubPro_value_caseC_speed;
			}
		}break;
		case En_RelicSubProperty::DeBuffDefence:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_DebuffDefence;
				case 2:return Const_SubPro_value_caseB_DebuffDefence;
				case 3:return Const_SubPro_value_caseC_DebuffDefence;
			}
		}break;
		case En_RelicSubProperty::BreakDamage:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_breakDamage;
				case 2:return Const_SubPro_value_caseB_breakDamage;
				case 3:return Const_SubPro_value_caseC_breakDamage;
			}
		}break;
		case En_RelicSubProperty::DeBuffAccuracy:
		{
			switch (resultCase)
			{
				case 1:return Const_SubPro_value_caseA_DebuffAccuracy;
				case 2:return Const_SubPro_value_caseB_DebuffAccuracy;
				case 3:return Const_SubPro_value_caseC_DebuffAccuracy;
			}
		}break;
	}

	return -1;

}

void RelicResult::upgradeOneSubProperty(En_RelicSubProperty SubProType, double value)
{
	switch (SubProType)
	{
		case En_RelicSubProperty::HPValue			:m_dHPValue				+= value;break;
		case En_RelicSubProperty::HPPercentage		:m_dHPPercentage		+= value;break;
		case En_RelicSubProperty::AttackValue		:m_dAttackValue			+= value;break;
		case En_RelicSubProperty::AttackPercentage	:m_dAttackPercent		+= value;break;
		case En_RelicSubProperty::DefenceValue		:m_dDefenceValue		+= value;break;
		case En_RelicSubProperty::DefencePercentage	:m_dDefencePercentage	+= value;break;
		case En_RelicSubProperty::CriticalProb		:m_dCriticalProb		+= value;break;
		case En_RelicSubProperty::CriticalDamage	:m_dCriticalDamage		+= value;break;
		case En_RelicSubProperty::Speed				:m_dSpeed				+= value;break;
		case En_RelicSubProperty::DeBuffDefence		:m_dDeBuffDefence		+= value;break;
		case En_RelicSubProperty::BreakDamage		:m_dBreakDamage			+= value;break;
		case En_RelicSubProperty::DeBuffAccuracy	:m_dDeBuffAccuracy		+= value;break;
	}
}

int RelicResult::getUpgradeSubProPos(std::default_random_engine & engine)
{
	std::uniform_int_distribution<int> di(1, 4);
	int result = di(engine);
	return result;
}

bool RelicResult::checkPrimePropertyValid(const St_RelicValidEstimatePara & EstPara)
{
	switch (m_primeProperty)
	{
		case En_RelicPrimeProperty::None				: return false;//这个case是套装或部位错误的情况
		case En_RelicPrimeProperty::HPValue				: return EstPara.PrimePro_Valid_HPValue;
		case En_RelicPrimeProperty::HPPercentage		: return EstPara.PrimePro_Valid_HPPercentage;
		case En_RelicPrimeProperty::AttackValue			: return EstPara.PrimePro_Valid_AttackValue;
		case En_RelicPrimeProperty::AttackPercentage	: return EstPara.PrimePro_Valid_AttackPercentage;
		case En_RelicPrimeProperty::DefencePercentage	: return EstPara.PrimePro_Valid_DefencePercentage;
		case En_RelicPrimeProperty::CriticalProb		: return EstPara.PrimePro_Valid_CriticalProb;
		case En_RelicPrimeProperty::CriticalDamage		: return EstPara.PrimePro_Valid_CriticalDamage;
		case En_RelicPrimeProperty::Speed				: return EstPara.PrimePro_Valid_Speed;
		case En_RelicPrimeProperty::BreakDamage			: return EstPara.PrimePro_Valid_BreakDamage;
		case En_RelicPrimeProperty::DeBuffAccuracy		: return EstPara.PrimePro_Valid_DeBuffAccuracy;
		case En_RelicPrimeProperty::ChargeEfficiency	: return EstPara.PrimePro_Valid_ChargeEfficiency;
		case En_RelicPrimeProperty::Fire				: return EstPara.PrimePro_Valid_Fire;
		case En_RelicPrimeProperty::Thunder				: return EstPara.PrimePro_Valid_Thunder;
		case En_RelicPrimeProperty::Wind				: return EstPara.PrimePro_Valid_Wind;
		case En_RelicPrimeProperty::Ice					: return EstPara.PrimePro_Valid_Ice;
		case En_RelicPrimeProperty::Null				: return EstPara.PrimePro_Valid_Null;
		case En_RelicPrimeProperty::Quantum				: return EstPara.PrimePro_Valid_Quantum;
		case En_RelicPrimeProperty::Physical			: return EstPara.PrimePro_Valid_Physical;
	};
	return false;
}

bool RelicResult::checkSubProTypeVaildity(En_RelicSubProperty SubProType, const St_RelicValidEstimatePara & EstPara)
{
	switch (SubProType)
	{
		case En_RelicSubProperty::HPValue			: return EstPara.SubPro_Valid_HPValue;
		case En_RelicSubProperty::HPPercentage		: return EstPara.SubPro_Valid_HPPercentage;
		case En_RelicSubProperty::AttackValue		: return EstPara.SubPro_Valid_AttackValue;
		case En_RelicSubProperty::AttackPercentage	: return EstPara.SubPro_Valid_AttackPercentage;
		case En_RelicSubProperty::DefenceValue		: return EstPara.SubPro_Valid_DefenceValue;
		case En_RelicSubProperty::DefencePercentage	: return EstPara.SubPro_Valid_DefencePercentage;
		case En_RelicSubProperty::CriticalProb		: return EstPara.SubPro_Valid_CriticalProb;
		case En_RelicSubProperty::CriticalDamage	: return EstPara.SubPro_Valid_CriticalDamage;
		case En_RelicSubProperty::Speed				: return EstPara.SubPro_Valid_Speed;
		case En_RelicSubProperty::DeBuffDefence		: return EstPara.SubPro_Valid_DeBuffDefence;
		case En_RelicSubProperty::BreakDamage		: return EstPara.SubPro_Valid_BreakDamage;
		case En_RelicSubProperty::DeBuffAccuracy	: return EstPara.SubPro_Valid_DeBuffAccuracy;
	};
	return false;
}

bool RelicResult::checkSubProValueVaildity(En_RelicSubProperty SubProType, double SubProValue, const St_RelicValidEstimatePara & EstPara)
{
	switch (SubProType)
	{
		case En_RelicSubProperty::HPValue			: return SubProValue >= EstPara.SubPro_Value_HP;
		case En_RelicSubProperty::HPPercentage		: return SubProValue >= EstPara.SubPro_Value_HPPercentage;
		case En_RelicSubProperty::AttackValue		: return SubProValue >= EstPara.SubPro_Value_AttackValue;
		case En_RelicSubProperty::AttackPercentage	: return SubProValue >= EstPara.SubPro_Value_AttackPercentage;
		case En_RelicSubProperty::DefenceValue		: return SubProValue >= EstPara.SubPro_Value_DefenceValue;
		case En_RelicSubProperty::DefencePercentage	: return SubProValue >= EstPara.SubPro_Value_DefencePercentage;
		case En_RelicSubProperty::CriticalProb		: return SubProValue >= EstPara.SubPro_Value_CriticalProb;
		case En_RelicSubProperty::CriticalDamage	: return SubProValue >= EstPara.SubPro_Value_CriticalDamage;
		case En_RelicSubProperty::Speed				: return SubProValue >= EstPara.SubPro_Value_Speed;
		case En_RelicSubProperty::DeBuffDefence		: return SubProValue >= EstPara.SubPro_Value_DeBuffDefence;
		case En_RelicSubProperty::BreakDamage		: return SubProValue >= EstPara.SubPro_Value_BreakDamage;
		case En_RelicSubProperty::DeBuffAccuracy	: return SubProValue >= EstPara.SubPro_Value_DeBuffAccuracy;
	};
	return false;
}
