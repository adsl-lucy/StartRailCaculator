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

#include "CardPoolEstimateWgt.h"
#pragma execution_character_set("utf-8")

CardPoolEstimateWgt::CardPoolEstimateWgt(QWidget* parent)
{
	Ui.setupUi(this);
	initUI();
	initChartWgt();
	slot_resetPara();
	slot_clearResult();
}

CardPoolEstimateWgt::~CardPoolEstimateWgt()
{
}

void CardPoolEstimateWgt::slot_updateEstimateProgressVal(const int value)
{
	Ui.progressBar_EstimatePos->setValue(value);
}

void CardPoolEstimateWgt::initUI()
{
	m_poolTypeButtonGroup = new QButtonGroup(this);
	m_poolTypeButtonGroup->setExclusive(true);
	m_poolTypeButtonGroup->addButton(Ui.radioButton_character);
	m_poolTypeButtonGroup->addButton(Ui.radioButton_weapon);
	Ui.radioButton_character->setChecked(true);

	Ui.progressBar_EstimatePos->setValue(0);

	connect(Ui.pushButton_startEstimate,	&QPushButton::clicked, this, &CardPoolEstimateWgt::slot_startEstimate);
	connect(Ui.pushButton_resetPara,		&QPushButton::clicked, this, &CardPoolEstimateWgt::slot_resetPara);
	connect(Ui.pushButton_clearResult,		&QPushButton::clicked, this, &CardPoolEstimateWgt::slot_clearResult);
}

void CardPoolEstimateWgt::initChartWgt()
{
	m_axisTicket = new QValueAxis();
	m_axisTicket->setRange(1, 180);
	m_axisTicket->setLabelFormat("%d");
	m_axisTicket->setTitleText("累计抽卡次数");
	m_axisProb = new QValueAxis();
	m_axisProb->setRange(0, 100);
	m_axisProb->setLabelFormat("%.0f%%");
	m_axisProb->setTitleText("累计出货概率");

	m_seriesProbDistribution = nullptr;

	m_ChtProbDistribution = new QChart();

	m_ChtProbDistribution->setTitle("N抽之内出货概率");
	m_ChtProbDistribution->legend()->hide();
	m_ChtProbDistribution->addAxis(m_axisTicket, Qt::AlignBottom);
	m_ChtProbDistribution->addAxis(m_axisProb, Qt::AlignLeft);
	m_ChtProbDistribution->setTheme(QChart::ChartThemeBlueCerulean);

	m_ChtViewProbDistribution = new QChartView(m_ChtProbDistribution);
	m_ChtViewProbDistribution->setRenderHint(QPainter::Antialiasing);
	m_ChtViewProbDistribution->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


	QVBoxLayout* Layout_GraphWgt = new QVBoxLayout(Ui.widget_graph);
	Layout_GraphWgt->addWidget(m_ChtViewProbDistribution);
	Ui.widget_graph->setLayout(Layout_GraphWgt);
}

void CardPoolEstimateWgt::slot_startEstimate()
{
	setPanelEnable(false);
	St_CardPoolEstimatePara EstPara;
	if (Ui.radioButton_character->isChecked())
	{
		EstPara.poolType = EN_CardPoolType::character;
	}
	else if (Ui.radioButton_weapon->isChecked())
	{
		EstPara.poolType = EN_CardPoolType::weapon;
	}

	EstPara.wrongGold = Ui.checkBox_wrongGold->isChecked();
	EstPara.areadyInTicket = Ui.spinBox_areadyInTicket->value();

	emit signal_StartCardPoolEstimate(EstPara);

}

void CardPoolEstimateWgt::setPanelEnable(bool state)
{
	Ui.radioButton_character->setEnabled(state);
	Ui.radioButton_weapon->setEnabled(state);
	Ui.checkBox_wrongGold->setEnabled(state);
	Ui.spinBox_areadyInTicket->setEnabled(state);
	Ui.pushButton_startEstimate->setEnabled(state);
	Ui.pushButton_resetPara->setEnabled(state);
	Ui.pushButton_clearResult->setEnabled(state);
}

void CardPoolEstimateWgt::setCardPoolType(const QString & str)
{
	Ui.label_poolType->setText(QString("卡池类型:") + str);
}

void CardPoolEstimateWgt::setDistanceToBigGuarantee(const QString & str)
{
	Ui.label_distanceToBigGuarantee->setText(QString("距离大保底剩余抽数:") + str);
}

void CardPoolEstimateWgt::setGetUpOnSmallGuarantee(const QString & str)
{
	Ui.label_PorbGetUpAtsmallGuarantee->setText(QString("于小保底位置出货概率:") + str);
}

void CardPoolEstimateWgt::setGetUpOnBigGuarantee(const QString & str)
{
	Ui.label_PorbGetUpAtBigGuarantee->setText(QString("于大保底位置出货概率:") + str);
}

void CardPoolEstimateWgt::setGetUpPosExpectation(const QString & str)
{
	Ui.label_ExpectationGetPos->setText(QString("期望出货位置:") + str);
}

void CardPoolEstimateWgt::setGetUpCrystalExpenceExpectation(const QString & str)
{
	Ui.label_ExpectationCrystalExpense->setText(QString("期望投入星琼:") + str);
}

int CardPoolEstimateWgt::getPointIndex(const QPointF & ChartPos)
{
	if (m_seriesProbDistribution == nullptr)
	{
		return 0;
	}

	qreal indexInQreal = (ChartPos.x() - m_startValue) / m_interval + qreal(0.5);
	int   indexInInt = int(indexInQreal);
	return indexInInt;
}

void CardPoolEstimateWgt::slot_resetPara()
{
	Ui.radioButton_character->setChecked(true);
	Ui.checkBox_wrongGold->setChecked(false);
	Ui.spinBox_areadyInTicket->setValue(0);
}

void CardPoolEstimateWgt::slot_clearResult()
{
	setCardPoolType("");
	setDistanceToBigGuarantee("");
	setGetUpOnSmallGuarantee("");
	setGetUpOnBigGuarantee("");
	setGetUpPosExpectation("");
	setGetUpCrystalExpenceExpectation("");
	Ui.progressBar_EstimatePos->setValue(0);

	m_mapEstResult.clear();
	m_axisTicket->setRange(1, Const_LargestGetGoldCharTNum * 2);
	if (m_seriesProbDistribution != nullptr)
	{
		disconnect(m_seriesProbDistribution, &QLineSeries::hovered, this, &CardPoolEstimateWgt::slot_chartMouseHovered);
	}
	m_ChtProbDistribution->removeAllSeries();
	m_seriesProbDistribution = nullptr;
}

void CardPoolEstimateWgt::slot_chartMouseHovered(const QPointF & point, bool state)
{
	int pointIndex = getPointIndex(point);

	if (pointIndex > m_mapEstResult.size() - 1)
	{
		return;
	}

	double PointProb = m_mapEstResult.find(pointIndex).value();

	QString showText;

	showText.push_back(QString::number(pointIndex));
	showText.push_back("抽之内出货概率:");
	showText.push_back(QString::asprintf("%.2f%%", PointProb));

	QToolTip::showText(QCursor::pos(), showText);
}

void CardPoolEstimateWgt::slot_getCardPoolEstimateResult(const St_CardPoolEstimateResult & EstResult)
{
	if (EstResult.poolType == EN_CardPoolType::character)
	{
		setCardPoolType("角色池");
	}
	else if (EstResult.poolType == EN_CardPoolType::weapon)
	{
		setCardPoolType("光锥池");
	}

	//打印统计结果
	setDistanceToBigGuarantee(QString::number(EstResult.distanceToBigGuarantee));
	setGetUpOnSmallGuarantee(QString::asprintf("%.2f%%", EstResult.smallGraranteeGetUpProb * 100));
	setGetUpOnBigGuarantee(QString::asprintf("%.2f%%", EstResult.bigGuaranteeGetTupProb *100));
	setGetUpPosExpectation(QString::asprintf("%.2f", EstResult.getUpPosExpectation));
	setGetUpCrystalExpenceExpectation(QString::asprintf("%.2f", EstResult.crystalExpenExpectation));

	//处理图表
	m_mapEstResult.clear();

	m_axisTicket->setRange(0, EstResult.distanceToBigGuarantee);


	if (m_seriesProbDistribution != nullptr)
	{
		disconnect(m_seriesProbDistribution, &QLineSeries::hovered, this, &CardPoolEstimateWgt::slot_chartMouseHovered);
	}


	m_ChtProbDistribution->removeAllSeries();

	m_seriesProbDistribution = new QLineSeries();

	connect(m_seriesProbDistribution, &QLineSeries::hovered, this, &CardPoolEstimateWgt::slot_chartMouseHovered);

	for (auto pos = EstResult.mapPorbDistribution.cbegin(); pos != EstResult.mapPorbDistribution.cend(); pos++)
	{
		int ticket = pos.key();
		double accumulatePob = pos.value() * 100;

		m_seriesProbDistribution->append(ticket, accumulatePob);
		m_mapEstResult.insert(pos.key(), accumulatePob);
	}

	m_ChtProbDistribution->addSeries(m_seriesProbDistribution);

	//记录图表很坐标计算中间量
	QVector<QPointF> vecPointF = m_seriesProbDistribution->pointsVector();

	//Debug用，实际不应存在的情况
	if (vecPointF.size() == 0 || vecPointF.size() == 1)
	{
		m_startValue = 0;
		m_endValue = 0;
		m_totalLength = 0;
		m_interval = 0;
	}
	m_startValue = vecPointF.begin()->x();
	m_endValue = vecPointF.rbegin()->x();
	m_totalLength = m_endValue - m_startValue;
	m_interval = m_totalLength / vecPointF.size();

	setPanelEnable(true);

}
