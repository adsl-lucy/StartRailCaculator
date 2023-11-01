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

#include "RelicCultivateWgt.h"
#pragma execution_character_set("utf-8")


RelicCultivateWgt::RelicCultivateWgt(QWidget* parent)
	:QWidget(parent)
{
	Ui.setupUi(this);
	initUi();
	initSubProSpinboxUi();
	initGraphWgt();
	slot_resetPara();
	slot_clearResult();
	slot_relicChanged(1);
}

RelicCultivateWgt::~RelicCultivateWgt()
{

}

void RelicCultivateWgt::slot_UpdateRelicEstimateProgress(int val)
{
	Ui.progressBar_EstimateProgress->setValue(val);
}

void RelicCultivateWgt::slot_getRelicEstResult(const St_ValidRelicEstimateResult & EstResult)
{
	setPrimePropertyValidProportion(QString::number(EstResult.primePropertyValidProportion * 100,'f',2) + "%");
	setPrimePropertyValidGetProbability(QString::number(EstResult.primePropertyValidGetProbbability * 100, 'f', 2) + "%");
	setPrimePropertyValidGetTimeExpectation(QString::number(EstResult.primePropertyValidGetTimeExpectation, 'f', 2));
	setPrimePropertyValidPlayTimeExpectation(QString::number(EstResult.primePropertyValidPlayTimeExpectation, 'f', 2));

	setAllPropertyValidProportion(QString::number(EstResult.allPropertyValidProportion * 100, 'f', 4) + "%");
	setAllPropertyValidGetProbaility(QString::number(EstResult.allPropertyValidGetProbbability * 100, 'f', 4) + "%");
	setAllPropertyValidGetTimeExpectation(QString::number(EstResult.allPropertyValidGetTimeExpectation, 'f', 4));
	setAllPropertyValidPlayTimeExpectation(QString::number(EstResult.allPropertyValidPlayTimeExpectation, 'f', 2));


	//处理图表
	m_VecPrimePropertyTimesProb.clear();
	m_VecAllPropertyTimesProb.clear();

	int maxPrimePropertyValidTime = 0;

	if (EstResult.mapPriProValidGetNumProb.isEmpty() == false)
	{
		maxPrimePropertyValidTime = EstResult.mapPriProValidGetNumProb.lastKey();
	}

	int maxAllPropertyValidTime = 0;

	if (EstResult.mapAllProValidGetNumProb.isEmpty() == false)
	{
		maxAllPropertyValidTime = EstResult.mapAllProValidGetNumProb.lastKey();
	}


	if (m_seriesPrimePropertyDensity != nullptr)
	{
		disconnect(m_seriesPrimePropertyDensity, &QLineSeries::hovered, this, &RelicCultivateWgt::slot_PrimePropertyChartMouseHovered);
	}


	if (m_seriesAllPropertyDensity != nullptr)
	{
		disconnect(m_seriesAllPropertyDensity, &QLineSeries::hovered, this, &RelicCultivateWgt::slot_SubPropertyChartMouseHovered);
	}


	m_ChartPrimeProperty->removeAllSeries();
	m_ChartAllProperty->removeAllSeries();

	m_seriesPrimePropertyDensity	= new QLineSeries();
	m_seriesAllPropertyDensity	= new QLineSeries();

	connect(m_seriesPrimePropertyDensity,	&QLineSeries::hovered, this, &RelicCultivateWgt::slot_PrimePropertyChartMouseHovered);
	connect(m_seriesAllPropertyDensity,	&QLineSeries::hovered, this, &RelicCultivateWgt::slot_SubPropertyChartMouseHovered);

	double largestPriProValidProb = 0;

	for (int currentIndex = 0; currentIndex <= maxPrimePropertyValidTime; currentIndex++)
	{
		int validTime = currentIndex;
		double accumulateProb = 0;
		auto mapPos = EstResult.mapPriProValidGetNumProb.find(validTime);

		if (mapPos != EstResult.mapPriProValidGetNumProb.end())
		{
			accumulateProb = mapPos.value();
			accumulateProb *= 100;
			if (accumulateProb < 0.01)
			{
				accumulateProb = 0;
			}
		}

		largestPriProValidProb = std::max(accumulateProb, largestPriProValidProb);

		m_seriesPrimePropertyDensity->append(validTime, accumulateProb);
		m_VecPrimePropertyTimesProb.push_back(accumulateProb);
	}

	double largestAllProValidProb = 0;

	for (int currentIndex = 0; currentIndex <= maxAllPropertyValidTime; currentIndex++)
	{
		int validTime = currentIndex;
		double accumulateProb = 0;
		auto mapPos = EstResult.mapAllProValidGetNumProb.find(validTime);

		if (mapPos != EstResult.mapAllProValidGetNumProb.end())
		{
			accumulateProb = mapPos.value();
			accumulateProb *= 100;
			if (accumulateProb < 0.01)
			{
				accumulateProb = 0;
			}
		}

		largestAllProValidProb = std::max(accumulateProb, largestAllProValidProb);

		m_seriesAllPropertyDensity->append(validTime, accumulateProb);
		m_VecAllPropertyTimesProb.push_back(accumulateProb);
	}

	m_ChartPrimeProperty->addSeries(m_seriesPrimePropertyDensity);
	m_ChartAllProperty->addSeries(m_seriesAllPropertyDensity);

	m_axisPrimePropertyValidTime->setRange(0, maxPrimePropertyValidTime);
	m_axisAllPropertyValidTime->setRange(0, maxAllPropertyValidTime);
	m_axisPrimePropertyValidProb->setRange(0, largestPriProValidProb);
	m_axisAllPropertyValidProb->setRange(0, largestAllProValidProb);



	//记录图表很坐标计算中间量
	QVector<QPointF> priVecPointF = m_seriesPrimePropertyDensity->pointsVector();

	m_PriChtStartValue	= priVecPointF.begin()->x();
	m_PriChtEndValue	= priVecPointF.rbegin()->x();
	m_PriChtTotalLength 	= m_PriChtEndValue - m_PriChtStartValue;
	m_PriChtInterval	= m_PriChtTotalLength / priVecPointF.size();

	//记录图表很坐标计算中间量
	QVector<QPointF> allVecPointF = m_seriesAllPropertyDensity->pointsVector();

	m_AllChtStartValue	= allVecPointF.begin()->x();
	m_AllChtEndValue	= allVecPointF.rbegin()->x();
	m_AllChtTotalLength 	= m_AllChtEndValue - m_AllChtStartValue;
	m_AllChtInterval	= m_AllChtTotalLength / allVecPointF.size();

	enablePannel(true);

}

void RelicCultivateWgt::initUi()
{
	m_RelicBtnGroupBox = new QButtonGroup(this);
	m_RelicBtnGroupBox->setExclusive(true);
	m_RelicBtnGroupBox->addButton(Ui.radioButton_head,	1);
	m_RelicBtnGroupBox->addButton(Ui.radioButton_hand,	2);
	m_RelicBtnGroupBox->addButton(Ui.radioButton_clothes,	3);
	m_RelicBtnGroupBox->addButton(Ui.radioButton_shoes,	4);
	m_RelicBtnGroupBox->addButton(Ui.radioButton_cord,	5);
	m_RelicBtnGroupBox->addButton(Ui.radioButton_ball,	6);

	Ui.radioButton_head->setChecked(true);

	Ui.label_ErrorMsg->setStyleSheet("color:red");

	Ui.progressBar_EstimateProgress->setValue(0);

	connect(m_RelicBtnGroupBox,		QOverload<int>::of(&QButtonGroup::buttonClicked),	this, &RelicCultivateWgt::slot_relicChanged);
	connect(Ui.pushButton_startEstimate, 	&QPushButton::clicked,					this, &RelicCultivateWgt::slot_startEstimate);
	connect(Ui.pushButton_resetPara,	&QPushButton::clicked,					this, &RelicCultivateWgt::slot_resetPara);
	connect(Ui.pushButton_clearResult,	&QPushButton::clicked,					this, &RelicCultivateWgt::slot_clearResult);

}

void RelicCultivateWgt::initSubProSpinboxUi()
{
	connect(Ui.checkBox_SubProAttackValue, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProAttackValue->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProAttackValue->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProAttackPercentage, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProAttactPercentage->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProAttactPercentage->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProDefenceValue, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProDefenceValue->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProDefenceValue->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProDefencePercentage, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProDefencePercentage->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProDefencePercentage->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProHPValue, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProHPValue->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProHPValue->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProHPPercentage, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProHPPercentage->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProHPPercentage->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProCriticalPercentage, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProCriticalPercentage->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProCriticalPercentage->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProCriticialDamage, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProCriticalDamage->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProCriticalDamage->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProSpeed, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProSpeed->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProSpeed->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProDebuffDefence, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProDebuffDefence->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProDebuffDefence->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProDebuffAccuracy, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProDebuffAccuracy->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProDebuffAccuracy->setEnabled(false);
		}
	});

	connect(Ui.checkBox_SubProBreakDamage, &QCheckBox::stateChanged, this, [=](int state)
	{
		if (state == Qt::Checked)
		{
			Ui.doubleSpinBox_SubProBreakDamage->setEnabled(true);
		}
		else
		{
			Ui.doubleSpinBox_SubProBreakDamage->setEnabled(false);
		}
	});


}

void RelicCultivateWgt::initGraphWgt()
{
	m_axisPrimePropertyValidTime = new QValueAxis();
	m_axisPrimePropertyValidTime->setRange(0, 20);
	m_axisPrimePropertyValidTime->setLabelFormat("%d");
	m_axisPrimePropertyValidTime->setTitleText("主属性有效遗器个数");

	m_axisPrimePropertyValidProb = new QValueAxis();
	m_axisPrimePropertyValidProb->setRange(0, 100);
	m_axisPrimePropertyValidProb->setLabelFormat("%.2f%%");
	m_axisPrimePropertyValidProb->setTitleText("发生概率");

	m_seriesPrimePropertyDensity = nullptr;

	m_ChartPrimeProperty = new QChart();

	m_ChartPrimeProperty->setTitle("主属性有效遗器数量概率密度分布");
	m_ChartPrimeProperty->legend()->hide();
	m_ChartPrimeProperty->addAxis(m_axisPrimePropertyValidTime, Qt::AlignBottom);
	m_ChartPrimeProperty->addAxis(m_axisPrimePropertyValidProb, Qt::AlignLeft);
	m_ChartPrimeProperty->setTheme(QChart::ChartThemeBlueCerulean);

	m_ChartViewPrimeProperty = new QChartView(m_ChartPrimeProperty);
	m_ChartViewPrimeProperty->setRenderHint(QPainter::Antialiasing);
	m_ChartViewPrimeProperty->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



	m_axisAllPropertyValidTime = new QValueAxis();
	m_axisAllPropertyValidTime->setRange(0, 20);
	m_axisAllPropertyValidTime->setLabelFormat("%d");
	m_axisAllPropertyValidTime->setTitleText("全属性有效遗器个数");

	m_axisAllPropertyValidProb = new QValueAxis();
	m_axisAllPropertyValidProb->setRange(0, 100);
	m_axisAllPropertyValidProb->setLabelFormat("%.2f%%");
	m_axisAllPropertyValidProb->setTitleText("发生概率");

	m_seriesAllPropertyDensity = nullptr;

	m_ChartAllProperty = new QChart();

	m_ChartAllProperty->setTitle("全属性有效遗器数量概率密度分布");
	m_ChartAllProperty->legend()->hide();
	m_ChartAllProperty->addAxis(m_axisAllPropertyValidTime, Qt::AlignBottom);
	m_ChartAllProperty->addAxis(m_axisAllPropertyValidProb, Qt::AlignLeft);
	m_ChartAllProperty->setTheme(QChart::ChartThemeBlueCerulean);

	m_ChartViewAllProperty = new QChartView(m_ChartAllProperty);
	m_ChartViewAllProperty->setRenderHint(QPainter::Antialiasing);
	m_ChartViewAllProperty->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QVBoxLayout* Layout_GraphWgt = new QVBoxLayout(Ui.widget_graph);
	Layout_GraphWgt->addWidget(m_ChartViewPrimeProperty);
	Layout_GraphWgt->addWidget(m_ChartViewAllProperty);
	Ui.widget_graph->setLayout(Layout_GraphWgt);
}

void RelicCultivateWgt::setPrimePropertyValidProportion(const QString& str)
{
	Ui.label_PriProValidProportion->setText(QString("主属性有效遗器比例:") + str);
}

void RelicCultivateWgt::setPrimePropertyValidGetProbability(const QString& str)
{
	Ui.label_PriProValidGetProbability->setText(QString("打本获取主属性有效遗物概率:") + str);
}

void RelicCultivateWgt::setPrimePropertyValidGetTimeExpectation(const QString & str)
{
	Ui.label_PriProValidGetTimeExpectation->setText(QString("主属性有效遗物获取期望:") + str);
}

void RelicCultivateWgt::setPrimePropertyValidPlayTimeExpectation(const QString & str)
{
	Ui.label_PriProValidGetPlayTimeExpectation->setText(QString("获取主属性有效遗物打本次数期望:") + str);
}

void RelicCultivateWgt::setAllPropertyValidProportion(const QString& str)
{
	Ui.label_AllProValidProportion->setText(QString("全属性有效遗物比例:") + str);
}

void RelicCultivateWgt::setAllPropertyValidGetProbaility(const QString& str)
{
	Ui.label_AllPropertyValidGetPercentage->setText(QString("打本获取全属性有效遗物概率:") + str);
}

void RelicCultivateWgt::setAllPropertyValidGetTimeExpectation(const QString & str)
{
	Ui.label_AllProValidGetTimeExpectation->setText(QString("全属性有效遗物获取期望:") + str);
}

void RelicCultivateWgt::setAllPropertyValidPlayTimeExpectation(const QString & str)
{
	Ui.label_AllPropertyGetPlayTimeExpectation->setText(QString("获取全属性有效遗物打本次数期望:") + str);
}

int RelicCultivateWgt::getPrimeChtPointIndex(const QPointF & ChartPos)
{
	if (m_seriesPrimePropertyDensity == nullptr)
	{
		return 0;
	}

	qreal indexInQreal = (ChartPos.x() - m_PriChtStartValue) / m_PriChtInterval + qreal(0.5);
	int   indexInInt = int(indexInQreal);
	return indexInInt;
}

int RelicCultivateWgt::getAllChtPointIndex(const QPointF & ChartPos)
{
	if (m_seriesAllPropertyDensity == nullptr)
	{
		return 0;
	}

	qreal indexInQreal = (ChartPos.x() - m_AllChtStartValue) / m_AllChtInterval + qreal(0.5);
	int   indexInInt = int(indexInQreal);
	return indexInInt;
}

void RelicCultivateWgt::enablePannel(bool state)
{
	Ui.groupBox_targetRelic->setEnabled(state);
	Ui.groupBox_ValidPriProperites->setEnabled(state);
	Ui.groupBox_SubProFilter->setEnabled(state);
	Ui.spinBox_playTime->setEnabled(state);
	if (state)
	{
		slot_relicChanged(m_RelicBtnGroupBox->checkedId());
	}

	Ui.pushButton_startEstimate->setEnabled(state);
	Ui.pushButton_clearResult->setEnabled(state);
	Ui.pushButton_resetPara->setEnabled(state);

}

void RelicCultivateWgt::slot_resetPara()
{
	Ui.radioButton_head->setChecked(true);
	slot_relicChanged(1);

	Ui.checkBox_PriProAttactPercent->setChecked(false);
	Ui.checkBox_PriProBreakDamage->setChecked(false);
	Ui.checkBox_PriProChargeEfficiency->setChecked(false);
	Ui.checkBox_PriProCriticalDamage->setChecked(false);
	Ui.checkBox_PriProCriticalProb->setChecked(false);
	Ui.checkBox_PriProDebuffAccuracy->setChecked(false);
	Ui.checkBox_PriProDefencePercentage->setChecked(false);
	Ui.checkBox_PriProHealAddition->setChecked(false);
	Ui.checkBox_PriProHPPercentage->setChecked(false);
	Ui.checkBox_PriProSpeed->setChecked(false);

	Ui.checkBox_PriProFire->setChecked(false);
	Ui.checkBox_PriProIce->setChecked(false);
	Ui.checkBox_PriProNull->setChecked(false);
	Ui.checkBox_PriProPhysical->setChecked(false);
	Ui.checkBox_PriProQuantum->setChecked(false);
	Ui.checkBox_PriProThunder->setChecked(false);
	Ui.checkBox_PriProWind->setChecked(false);

	Ui.checkBox_SubProAttackPercentage->setChecked(true);
	Ui.checkBox_SubProAttackValue->setChecked(true);
	Ui.checkBox_SubProBreakDamage->setChecked(true);
	Ui.checkBox_SubProCriticalPercentage->setChecked(true);
	Ui.checkBox_SubProCriticialDamage->setChecked(true);
	Ui.checkBox_SubProDebuffAccuracy->setChecked(true);
	Ui.checkBox_SubProDefencePercentage->setChecked(true);
	Ui.checkBox_SubProDebuffDefence->setChecked(true);
	Ui.checkBox_SubProDefenceValue->setChecked(true);
	Ui.checkBox_SubProHPPercentage->setChecked(true);
	Ui.checkBox_SubProHPValue->setChecked(true);
	Ui.checkBox_SubProSpeed->setChecked(true);

	Ui.spinBox_playTime->setValue(200);
	Ui.doubleSpinBox_SubProAttackValue->setValue(0);
	Ui.doubleSpinBox_SubProDefenceValue->setValue(0);
	Ui.doubleSpinBox_SubProHPValue->setValue(0);
	Ui.doubleSpinBox_SubProAttactPercentage->setValue(0);
	Ui.doubleSpinBox_SubProBreakDamage->setValue(0);
	Ui.doubleSpinBox_SubProCriticalDamage->setValue(0);
	Ui.doubleSpinBox_SubProCriticalPercentage->setValue(0);
	Ui.doubleSpinBox_SubProDebuffAccuracy->setValue(0);
	Ui.doubleSpinBox_SubProDebuffDefence->setValue(0);
	Ui.doubleSpinBox_SubProDefencePercentage->setValue(0);
	Ui.doubleSpinBox_SubProHPPercentage->setValue(0);
	Ui.doubleSpinBox_SubProSpeed->setValue(0);

	Ui.label_ErrorMsg->clear();

}

void RelicCultivateWgt::slot_startEstimate()
{
	St_RelicValidEstimatePara EstiPara;

	EstiPara.playTime	= Ui.spinBox_playTime->value();

	switch (m_RelicBtnGroupBox->checkedId())
	{
		case 1:EstiPara.relicType = En_RelicType::Head;		break;
		case 2:EstiPara.relicType = En_RelicType::Hand;		break;
		case 3:EstiPara.relicType = En_RelicType::Clothes;	break;
		case 4:EstiPara.relicType = En_RelicType::Shoes;	break;
		case 5:EstiPara.relicType = En_RelicType::Cord;		break;
		case 6:EstiPara.relicType = En_RelicType::Ball;		break;
	}

	switch (EstiPara.relicType)
	{
		case En_RelicType::Head:
		{
			EstiPara.PrimePro_Valid_HPValue = true;
		}break;
		case En_RelicType::Hand:
		{
			EstiPara.PrimePro_Valid_AttackValue = true;
		}break;
		case En_RelicType::Clothes:
		{
			EstiPara.PrimePro_Valid_AttackPercentage	= Ui.checkBox_PriProAttactPercent->isChecked();
			EstiPara.PrimePro_Valid_HPPercentage		= Ui.checkBox_PriProHPPercentage->isChecked();
			EstiPara.PrimePro_Valid_DefencePercentage	= Ui.checkBox_PriProDefencePercentage->isChecked();

			EstiPara.PrimePro_Valid_CriticalProb		= Ui.checkBox_PriProCriticalProb->isChecked();
			EstiPara.PrimePro_Valid_CriticalDamage		= Ui.checkBox_PriProCriticalDamage->isChecked();
			EstiPara.PrimePro_Valid_HealAddition		= Ui.checkBox_PriProHealAddition->isChecked();
			EstiPara.PrimePro_Valid_DeBuffAccuracy		= Ui.checkBox_PriProDebuffAccuracy->isChecked();
		}break;
		case En_RelicType::Shoes:
		{
			EstiPara.PrimePro_Valid_AttackPercentage	= Ui.checkBox_PriProAttactPercent->isChecked();
			EstiPara.PrimePro_Valid_HPPercentage		= Ui.checkBox_PriProHPPercentage->isChecked();
			EstiPara.PrimePro_Valid_DefencePercentage	= Ui.checkBox_PriProDefencePercentage->isChecked();

			EstiPara.PrimePro_Valid_Speed			= Ui.checkBox_PriProSpeed->isChecked();
		}break;
		case En_RelicType::Cord:
		{
			EstiPara.PrimePro_Valid_AttackPercentage	= Ui.checkBox_PriProAttactPercent->isChecked();
			EstiPara.PrimePro_Valid_HPPercentage		= Ui.checkBox_PriProHPPercentage->isChecked();
			EstiPara.PrimePro_Valid_DefencePercentage	= Ui.checkBox_PriProDefencePercentage->isChecked();

			EstiPara.PrimePro_Valid_BreakDamage		= Ui.checkBox_PriProBreakDamage->isChecked();
			EstiPara.PrimePro_Valid_ChargeEfficiency	= Ui.checkBox_PriProChargeEfficiency->isChecked();
		}break;
		case En_RelicType::Ball:
		{
			EstiPara.PrimePro_Valid_AttackPercentage	= Ui.checkBox_PriProAttactPercent->isChecked();
			EstiPara.PrimePro_Valid_HPPercentage		= Ui.checkBox_PriProHPPercentage->isChecked();
			EstiPara.PrimePro_Valid_DefencePercentage	= Ui.checkBox_PriProDefencePercentage->isChecked();

			EstiPara.PrimePro_Valid_Fire			= Ui.checkBox_PriProFire->isChecked();
			EstiPara.PrimePro_Valid_Thunder			= Ui.checkBox_PriProThunder->isChecked();
			EstiPara.PrimePro_Valid_Wind			= Ui.checkBox_PriProWind->isChecked();
			EstiPara.PrimePro_Valid_Ice			= Ui.checkBox_PriProIce->isChecked();
			EstiPara.PrimePro_Valid_Null			= Ui.checkBox_PriProNull->isChecked();
			EstiPara.PrimePro_Valid_Quantum			= Ui.checkBox_PriProQuantum->isChecked();
			EstiPara.PrimePro_Valid_Physical		= Ui.checkBox_PriProPhysical->isChecked();
		}break;
	}
	//副词缀筛选器

	auto getSubProFlagAndValue = [=](bool& flagRef,double& valueRef,QCheckBox* flagCheckBox,QDoubleSpinBox* doubleSpinBox)
	{
		flagRef = flagCheckBox->isChecked();
		if (flagRef)
		{
			valueRef = doubleSpinBox->value();
		}
		else
		{
			valueRef = 0;
		}
	};

	//固定生命值
	if (EstiPara.relicType != En_RelicType::Head)
	{
		getSubProFlagAndValue(EstiPara.SubPro_Valid_HPValue, EstiPara.SubPro_Value_HP, 
							Ui.checkBox_SubProHPValue,		Ui.doubleSpinBox_SubProHPValue);
		if (EstiPara.SubPro_Value_HP > 0)
		{
			EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::HPValue);
		}
	}
	else
	{
		EstiPara.SubPro_Valid_HPValue = false;
	}

	//固定攻击力
	if (EstiPara.relicType != En_RelicType::Hand)
	{
		getSubProFlagAndValue(EstiPara.SubPro_Valid_AttackValue, EstiPara.SubPro_Value_AttackValue, 
							Ui.checkBox_SubProAttackValue,		Ui.doubleSpinBox_SubProAttackValue);
		if (EstiPara.SubPro_Value_AttackValue > 0)
		{
			EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::AttackValue);
		}
	}
	else
	{
		EstiPara.SubPro_Valid_AttackValue = false;
	}
	


	//百分比攻击
	getSubProFlagAndValue(EstiPara.SubPro_Valid_AttackPercentage, EstiPara.SubPro_Value_AttackPercentage,
						Ui.checkBox_SubProAttackPercentage, Ui.doubleSpinBox_SubProAttactPercentage);

	if (EstiPara.SubPro_Value_AttackPercentage > 0)
	{
		EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::AttackPercentage);
	}


	//暴击率
	getSubProFlagAndValue(EstiPara.SubPro_Valid_CriticalProb, EstiPara.SubPro_Value_CriticalProb,
						Ui.checkBox_SubProCriticalPercentage, Ui.doubleSpinBox_SubProCriticalPercentage);

	if (EstiPara.SubPro_Value_CriticalProb > 0)
	{
		EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::CriticalProb);
	}

	//暴击伤害
	getSubProFlagAndValue(EstiPara.SubPro_Valid_CriticalDamage, EstiPara.SubPro_Value_CriticalDamage,
							Ui.checkBox_SubProCriticialDamage,	Ui.doubleSpinBox_SubProCriticalDamage);

	if (EstiPara.SubPro_Value_CriticalDamage > 0)
	{
		EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::CriticalDamage);
	}

	//速度
	getSubProFlagAndValue(EstiPara.SubPro_Valid_Speed, EstiPara.SubPro_Value_Speed, 
						Ui.checkBox_SubProSpeed, Ui.doubleSpinBox_SubProSpeed);

	if (EstiPara.SubPro_Value_Speed > 0)
	{
		EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::Speed);
	}

	//效果命中
	getSubProFlagAndValue(EstiPara.SubPro_Valid_DeBuffAccuracy, EstiPara.SubPro_Value_DeBuffAccuracy, 
						Ui.checkBox_SubProDebuffAccuracy,		Ui.doubleSpinBox_SubProDebuffAccuracy);

	if (EstiPara.SubPro_Value_DeBuffAccuracy > 0)
	{
		EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::DeBuffAccuracy);
	}

	//击破特攻
	getSubProFlagAndValue(EstiPara.SubPro_Valid_BreakDamage, EstiPara.SubPro_Value_BreakDamage, 
						Ui.checkBox_SubProBreakDamage, Ui.doubleSpinBox_SubProBreakDamage);

	if (EstiPara.SubPro_Value_BreakDamage > 0)
	{
		EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::BreakDamage);
	}

	//固定生命值
	getSubProFlagAndValue(EstiPara.SubPro_Valid_HPPercentage, EstiPara.SubPro_Value_HPPercentage, 
						Ui.checkBox_SubProHPPercentage, Ui.doubleSpinBox_SubProHPPercentage);

	if (EstiPara.SubPro_Value_HPPercentage > 0)
	{
		EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::HPPercentage);
	}

	//固定防御力
	getSubProFlagAndValue(EstiPara.SubPro_Valid_DefenceValue, EstiPara.SubPro_Value_DefenceValue, 
						Ui.checkBox_SubProDefenceValue, Ui.doubleSpinBox_SubProDefenceValue);

	if (EstiPara.SubPro_Value_DefenceValue > 0)
	{
		EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::DefenceValue);
	}

	//百分比防御力
	getSubProFlagAndValue(EstiPara.SubPro_Valid_DefencePercentage, EstiPara.SubPro_Value_DefencePercentage, 
					Ui.checkBox_SubProDefencePercentage, Ui.doubleSpinBox_SubProDefencePercentage);

	if (EstiPara.SubPro_Value_DefencePercentage > 0)
	{
		EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::DefencePercentage);
	}

	//效果抵抗
	getSubProFlagAndValue(EstiPara.SubPro_Valid_DeBuffDefence, EstiPara.SubPro_Value_DeBuffDefence, 
						Ui.checkBox_SubProDebuffDefence, Ui.doubleSpinBox_SubProDebuffDefence);

	if (EstiPara.SubPro_Value_DeBuffDefence > 0)
	{
		EstiPara.vecSubPropertyValueRequirement.push_back(En_RelicSubProperty::DeBuffDefence);
	}

	//百分数自动除以100
	EstiPara.SubPro_Value_HPPercentage	/= 100;
	EstiPara.SubPro_Value_AttackPercentage	/= 100;
	EstiPara.SubPro_Value_DefencePercentage /= 100;
	EstiPara.SubPro_Value_CriticalProb	/= 100;
	EstiPara.SubPro_Value_CriticalDamage	/= 100;
	EstiPara.SubPro_Value_DeBuffDefence	/= 100;
	EstiPara.SubPro_Value_BreakDamage	/= 100;
	EstiPara.SubPro_Value_DeBuffAccuracy	/= 100;


	enablePannel(false);

	emit signal_StartRelicValidEstimate(EstiPara);

}

void RelicCultivateWgt::slot_clearResult()
{
	setPrimePropertyValidProportion("");
	setPrimePropertyValidGetProbability("");
	setPrimePropertyValidGetTimeExpectation("");
	setPrimePropertyValidPlayTimeExpectation("");

	setAllPropertyValidProportion("");
	setAllPropertyValidGetProbaility("");
	setAllPropertyValidGetTimeExpectation("");
	setAllPropertyValidPlayTimeExpectation("");	

	Ui.progressBar_EstimateProgress->setValue(0);

	m_VecPrimePropertyTimesProb.clear();
	m_VecAllPropertyTimesProb.clear();

	m_axisPrimePropertyValidTime->setRange(0, 20);
	m_axisAllPropertyValidTime->setRange(0, 20);
	if (m_seriesPrimePropertyDensity != nullptr)
	{
		disconnect(m_seriesPrimePropertyDensity, &QLineSeries::hovered, this, &RelicCultivateWgt::slot_PrimePropertyChartMouseHovered);
	}

	if (m_seriesAllPropertyDensity != nullptr)
	{
		disconnect(m_seriesAllPropertyDensity, &QLineSeries::hovered, this, &RelicCultivateWgt::slot_SubPropertyChartMouseHovered);
	}

	m_ChartPrimeProperty->removeAllSeries();
	m_ChartAllProperty->removeAllSeries();

	m_seriesPrimePropertyDensity = nullptr;
	m_seriesAllPropertyDensity = nullptr;

}

void RelicCultivateWgt::slot_PrimePropertyChartMouseHovered(const QPointF & point, bool state)
{
	int pointIndex = getPrimeChtPointIndex(point);

	if (pointIndex > m_VecPrimePropertyTimesProb.size() - 1)
	{
		return;
	}

	double PointProb = m_VecPrimePropertyTimesProb[pointIndex];

	QString showText;

	showText.push_back("主属性有效遗器个数:");
	showText.push_back(QString::number(pointIndex));
	showText.push_back("发生概率:");
	showText.push_back(QString::asprintf("%.2f%%", PointProb));

	QToolTip::showText(QCursor::pos(), showText);
}

void RelicCultivateWgt::slot_SubPropertyChartMouseHovered(const QPointF & point, bool state)
{
	int pointIndex = getAllChtPointIndex(point);

	if (pointIndex > m_VecAllPropertyTimesProb.size() - 1)
	{
		return;
	}

	double PointProb = m_VecAllPropertyTimesProb[pointIndex];

	QString showText;

	showText.push_back("全属性有效遗器个数:");
	showText.push_back(QString::number(pointIndex));
	showText.push_back("发生概率:");
	showText.push_back(QString::asprintf("%.2f%%", PointProb));

	QToolTip::showText(QCursor::pos(), showText);
}


void RelicCultivateWgt::slot_relicChanged(int btnId)
{
	Ui.checkBox_PriProAttactPercent->setEnabled(false);
	Ui.checkBox_PriProBreakDamage->setEnabled(false);
	Ui.checkBox_PriProChargeEfficiency->setEnabled(false);
	Ui.checkBox_PriProCriticalDamage->setEnabled(false);
	Ui.checkBox_PriProCriticalProb->setEnabled(false);
	Ui.checkBox_PriProDebuffAccuracy->setEnabled(false);
	Ui.checkBox_PriProDefencePercentage->setEnabled(false);
	Ui.checkBox_PriProHealAddition->setEnabled(false);
	Ui.checkBox_PriProHPPercentage->setEnabled(false);
	Ui.checkBox_PriProSpeed->setEnabled(false);

	Ui.checkBox_PriProFire->setEnabled(false);
	Ui.checkBox_PriProIce->setEnabled(false);
	Ui.checkBox_PriProNull->setEnabled(false);
	Ui.checkBox_PriProPhysical->setEnabled(false);
	Ui.checkBox_PriProQuantum->setEnabled(false);
	Ui.checkBox_PriProThunder->setEnabled(false);
	Ui.checkBox_PriProWind->setEnabled(false);
	
	//因为切头和花会影响副词缀范围，所以这要抵消上述切换的作用
	Ui.checkBox_SubProHPValue->setEnabled(true);
	Ui.checkBox_SubProAttackValue->setEnabled(true);
	Ui.doubleSpinBox_SubProHPValue->setEnabled(Ui.checkBox_SubProHPValue->isChecked());
	Ui.doubleSpinBox_SubProAttackValue->setEnabled(Ui.checkBox_SubProAttackValue->isChecked());
	
	switch (btnId)
	{
		case 1:
		{
			Ui.checkBox_SubProHPValue->setEnabled(false);
			Ui.doubleSpinBox_SubProHPValue->setEnabled(false);
		}break;
		case 2:
		{
			Ui.checkBox_SubProAttackValue->setEnabled(false);
			Ui.doubleSpinBox_SubProAttackValue->setEnabled(false);

		}break;
		case 3:
		{
			Ui.checkBox_PriProHPPercentage->setEnabled(true);
			Ui.checkBox_PriProAttactPercent->setEnabled(true);
			Ui.checkBox_PriProDefencePercentage->setEnabled(true);
			Ui.checkBox_PriProCriticalProb->setEnabled(true);
			Ui.checkBox_PriProCriticalDamage->setEnabled(true);
			Ui.checkBox_PriProHealAddition->setEnabled(true);
			Ui.checkBox_PriProDebuffAccuracy->setEnabled(true);
		}break;
		case 4:
		{
			Ui.checkBox_PriProHPPercentage->setEnabled(true);
			Ui.checkBox_PriProAttactPercent->setEnabled(true);
			Ui.checkBox_PriProDefencePercentage->setEnabled(true);
			Ui.checkBox_PriProSpeed->setEnabled(true);
		}break;
		case 5:
		{
			Ui.checkBox_PriProHPPercentage->setEnabled(true);
			Ui.checkBox_PriProAttactPercent->setEnabled(true);
			Ui.checkBox_PriProDefencePercentage->setEnabled(true);
			Ui.checkBox_PriProBreakDamage->setEnabled(true);
			Ui.checkBox_PriProChargeEfficiency->setEnabled(true);
		}break;
		case 6:
		{
			Ui.checkBox_PriProHPPercentage->setEnabled(true);
			Ui.checkBox_PriProAttactPercent->setEnabled(true);
			Ui.checkBox_PriProDefencePercentage->setEnabled(true);
			Ui.checkBox_PriProFire->setEnabled(true);
			Ui.checkBox_PriProIce->setEnabled(true);
			Ui.checkBox_PriProNull->setEnabled(true);
			Ui.checkBox_PriProPhysical->setEnabled(true);
			Ui.checkBox_PriProQuantum->setEnabled(true);
			Ui.checkBox_PriProThunder->setEnabled(true);
			Ui.checkBox_PriProWind->setEnabled(true);
		}break;
	}
}

void RelicCultivateWgt::slot_getErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg)
{
	if (ErrNum != EN_StarRailErrorNum::RelicEst_InputNoError)
	{
		enablePannel(true);
	}
	Ui.label_ErrorMsg->setText(ErrMsg);
}
