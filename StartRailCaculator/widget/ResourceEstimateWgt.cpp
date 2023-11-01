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

#include "ResourceEstimateWgt.h"
#pragma execution_character_set("utf-8")

ResourceEstimateWgt::ResourceEstimateWgt(QWidget* parent):QWidget(parent)
{
	Ui.setupUi(this);
	initPannelWgt();
	initGraphWgt();
	slot_resetParameter();
	slot_clearResult();
}

ResourceEstimateWgt::~ResourceEstimateWgt()
{
}

void ResourceEstimateWgt::initPannelWgt()
{	

	connect(Ui.checkBox_smallMonthCard, &QCheckBox::stateChanged, this, [=](int state)
		{
			if (state == Qt::Checked)
			{
				Ui.spinBox_smallMonthCardRemainDay->setEnabled(true);
			}
			else if (state == Qt::Unchecked)
			{
				Ui.spinBox_smallMonthCardRemainDay->setEnabled(false);
			}
		});

	Ui.spinBox_averageAbyssNum->setRange(0, 10);

	Ui.label_ErrorMessage->setStyleSheet("color:red");

	connect(Ui.pushButton_startCaculate,	&QPushButton::clicked, this, &ResourceEstimateWgt::slot_startEstmate);
	connect(Ui.pushButton_resetParameter,	&QPushButton::clicked, this, &ResourceEstimateWgt::slot_resetParameter);
	connect(Ui.pushButton_clearResult,	&QPushButton::clicked, this, &ResourceEstimateWgt::slot_clearResult);

}

void ResourceEstimateWgt::initGraphWgt()
{
	m_axisCrystalDate = new QDateTimeAxis();
	m_axisCrystalDate->setRange(Const_StarRailOpenDay, Const_StarRailLatestDay);
	m_axisCrystalDate->setFormat("yyyy/MM/dd");
	m_axisTicketDate = new QDateTimeAxis();
	m_axisTicketDate->setRange(Const_StarRailOpenDay, Const_StarRailLatestDay);
	m_axisTicketDate->setFormat("yyyy/MM/dd");

	m_axisCrystalVal = new QValueAxis();
	m_axisCrystalVal->setRange(0, 10000);
	m_axisCrystalVal->setLabelFormat("%d");
	m_axisTicketVal	= new QValueAxis;
	m_axisTicketVal->setRange(0, 100);
	m_axisTicketVal->setLabelFormat("%d");

	m_seriesEqualCrystal	= nullptr;
	m_seriesEqualTicket	= nullptr;

	m_ChtCrystal	= new QChart();
	m_ChtTicket	= new QChart();

	m_ChtCrystal->setTitle("每日等效星琼");
	m_ChtCrystal->legend()->hide();
	m_ChtCrystal->addAxis(m_axisCrystalDate, Qt::AlignBottom);
	m_ChtCrystal->addAxis(m_axisCrystalVal, Qt::AlignLeft);
	m_ChtCrystal->setTheme(QChart::ChartThemeDark);

	m_ChtTicket->setTitle("每日等效专票");
	m_ChtTicket->legend()->hide();
	m_ChtTicket->addAxis(m_axisTicketDate, Qt::AlignBottom);
	m_ChtTicket->addAxis(m_axisTicketVal, Qt::AlignLeft);
	m_ChtTicket->setTheme(QChart::ChartThemeDark);


	m_ChtViewCrystal = new QChartView(m_ChtCrystal);
	m_ChtViewCrystal->setRenderHint(QPainter::Antialiasing);
	m_ChtViewCrystal->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	m_ChtViewTicket	= new QChartView(m_ChtTicket);
	m_ChtViewTicket->setRenderHint(QPainter::Antialiasing);
	m_ChtViewTicket->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QVBoxLayout* Layout_GraphWgt = new QVBoxLayout(Ui.wgt_graph);
	Layout_GraphWgt->addWidget(m_ChtViewCrystal);
	Layout_GraphWgt->addWidget(m_ChtViewTicket);
	Ui.wgt_graph->setLayout(Layout_GraphWgt);

}

void ResourceEstimateWgt::slot_startEstmate()
{
	St_ResourceEstimateParameter EstPara;
	EstPara.startDate		= Ui.dateEdit_today->date();
	EstPara.stopDate		= Ui.dateEdit_stopday->date();
	EstPara.currentTicket		= Ui.spinBox_currentTicket->value();
	EstPara.currentCrystal		= Ui.spinBox_currentCrystal->value();
	EstPara.currentPaidCrystal	= Ui.spinBox_currentPaidCrystal->value();
	EstPara.buySmallMonthCard	= Ui.checkBox_smallMonthCard->isChecked();
	EstPara.buyBigMonthCard		= Ui.checkBox_bigMonthCard->isChecked();
	EstPara.smallMonthCardLastday	= Ui.spinBox_smallMonthCardRemainDay->value();
	EstPara.abyssAverageNum		= Ui.spinBox_averageAbyssNum->value();

	emit signal_StartEstimateResource(EstPara);

}

void ResourceEstimateWgt::slot_getErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg)
{
	Ui.label_ErrorMessage->setText(ErrMsg);
}

void ResourceEstimateWgt::slot_resetParameter()
{
	Ui.dateEdit_today->setDate(QDate::currentDate());
	Ui.dateEdit_stopday->setDate(QDate::currentDate().addMonths(3));
	Ui.spinBox_currentCrystal->setValue(0);
	Ui.spinBox_currentTicket->setValue(0);
	Ui.spinBox_currentPaidCrystal->setValue(0);
	Ui.checkBox_smallMonthCard->setChecked(true);
	Ui.checkBox_bigMonthCard->setChecked(false);
	Ui.spinBox_smallMonthCardRemainDay->setValue(0);
	Ui.spinBox_averageAbyssNum->setValue(0);
	Ui.label_ErrorMessage->clear();
}

void ResourceEstimateWgt::slot_clearResult()
{
	setCurrentEqualCrystal(-1);
	setCurrentEqualTicket(-1);
	setStopDayCrystal(-1);
	setStopDayTicket(-1);
	setStopDayPaidCrystal(-1);
	setStopDayEqualCrystal(-1);
	setStopDayEqualTicket(-1);
	setTotalSmallMonthCardExpense(-1);
	setTotalBigMonthCardExpense(-1);
	setTotalExpense(-1);

	m_axisCrystalVal->setRange(0, 10000);
	m_axisTicketVal->setRange(0, 100);

	m_VecEstResult.clear();

	if (m_seriesEqualCrystal != nullptr)
	{
		disconnect(m_seriesEqualCrystal, &QLineSeries::hovered, this, &ResourceEstimateWgt::slot_CrystalChartMouseHovered);
	}

	if (m_seriesEqualTicket != nullptr)
	{
		disconnect(m_seriesEqualTicket, &QLineSeries::hovered, this, &ResourceEstimateWgt::slot_TicketChartMouseHovered);
	}

	m_ChtCrystal->removeAllSeries();
	m_ChtTicket->removeAllSeries();
	m_seriesEqualCrystal	= nullptr;
	m_seriesEqualTicket	= nullptr;

	m_startValue	= 0;
	m_endValue	= 0;
	m_totalLength	= 0;
	m_interval	= 0;
};


void ResourceEstimateWgt::setCurrentEqualCrystal(int value)
{
	QString baseText("当前等效星琼:");
	if (value == -1)
	{
		Ui.label_currentEqualCrystal->setText(baseText);
	}
	else
	{
		Ui.label_currentEqualCrystal->setText(baseText + QString::number(value));
	}
}

void ResourceEstimateWgt::setCurrentEqualTicket(int value)
{
	QString baseText("当前等效专票:");
	if (value == -1)
	{
		Ui.label_CurrentEqualTicket->setText(baseText);
	}
	else
	{
		Ui.label_CurrentEqualTicket->setText(baseText + QString::number(value));
	}
}

void ResourceEstimateWgt::setStopDayCrystal(int value)
{
	QString baseText("停止日期星琼:");
	if (value == -1)
	{
		Ui.label_StopDayCrystal->setText(baseText);
	}
	else
	{
		Ui.label_StopDayCrystal->setText(baseText + QString::number(value));
	}
}

void ResourceEstimateWgt::setStopDayTicket(int value)
{
	QString baseText("停止日期专票:");
	if (value == -1)
	{
		Ui.label_StopdayTicket->setText(baseText);
	}
	else
	{
		Ui.label_StopdayTicket->setText(baseText + QString::number(value));
	}
}

void ResourceEstimateWgt::setStopDayPaidCrystal(int value)
{
	QString baseText("停止日期古老梦华:");
	if (value == -1)
	{
		Ui.label_StopDayPaidCrystal->setText(baseText);
	}
	else
	{
		Ui.label_StopDayPaidCrystal->setText(baseText + QString::number(value));
	}
}

void ResourceEstimateWgt::setStopDayEqualCrystal(int value)
{
	QString baseText("停止日期等效星琼:");
	if (value == -1)
	{
		Ui.label_StopdayEqualCrystal->setText(baseText);
	}
	else
	{
		Ui.label_StopdayEqualCrystal->setText(baseText + QString::number(value));
	}
}

void ResourceEstimateWgt::setStopDayEqualTicket(int value)
{
	QString baseText("停止日期等效专票:");
	if (value == -1)
	{
		Ui.label_StopDayEqualTicket->setText(baseText);
	}
	else
	{
		Ui.label_StopDayEqualTicket->setText(baseText + QString::number(value));
	}
}

void ResourceEstimateWgt::setTotalSmallMonthCardExpense(int value)
{
	QString baseText("累计小月卡投入:");
	if (value == -1)
	{
		Ui.label_SmallMonthCardInvestment->setText(baseText);
	}
	else
	{
		Ui.label_SmallMonthCardInvestment->setText(baseText + QString::number(value));
	}
}

void ResourceEstimateWgt::setTotalBigMonthCardExpense(int value)
{
	QString baseText("累计大月卡投入:");
	if (value == -1)
	{
		Ui.label_BigMonthCardInvestment->setText(baseText);
	}
	else
	{
		Ui.label_BigMonthCardInvestment->setText(baseText + QString::number(value));
	}
}

void ResourceEstimateWgt::setTotalExpense(int value)
{
	QString baseText("累计总投入:");
	if (value == -1)
	{
		Ui.label_TotalInvestMent->setText(baseText);
	}
	else
	{
		Ui.label_TotalInvestMent->setText(baseText + QString::number(value));
	}
}

int ResourceEstimateWgt::getEqualCrystal(const St_ResourceEstimateDateResult & EstResult)
{
	return EstResult.currentCrystal + EstResult.currentTicket * 160 + EstResult.currentPaidCrystal;
}

int ResourceEstimateWgt::getEqualTicket(const St_ResourceEstimateDateResult & EstResult)
{
	return EstResult.currentTicket + (EstResult.currentCrystal + EstResult.currentPaidCrystal) / 160;
}

int ResourceEstimateWgt::getPointIndex(const QPointF & ChartPos)
{
	if (m_seriesEqualCrystal == nullptr)
	{
		return 0 ;
	}

	qreal indexInQreal = (ChartPos.x() - m_startValue) / m_interval + qreal(0.5);
	int   indexInInt = int(indexInQreal);
	return indexInInt;
}

void ResourceEstimateWgt::slot_getResourceEstResult(const QVector<St_ResourceEstimateDateResult>& EstResultVec)
{
	if (EstResultVec.isEmpty())
	{
		return;
	}

	St_ResourceEstimateDateResult startDayResult = *EstResultVec.begin();

	int startDayEqualCrystal	= getEqualCrystal(startDayResult);
	int startDayEqualTicket		= getEqualTicket(startDayResult);

	St_ResourceEstimateDateResult endDayResult = *EstResultVec.rbegin();

	int endDayEqualCrystal	= getEqualCrystal(endDayResult);
	int endDayEqualTicket	= getEqualTicket(endDayResult);

	//打印右侧标签
	setCurrentEqualCrystal(startDayEqualCrystal);
	setCurrentEqualTicket(startDayEqualTicket);
	setStopDayCrystal(endDayResult.currentCrystal);
	setStopDayTicket(endDayResult.currentTicket);
	setStopDayPaidCrystal(endDayResult.currentPaidCrystal);
	setStopDayEqualCrystal(endDayEqualCrystal);
	setStopDayEqualTicket(endDayEqualTicket);
	setTotalSmallMonthCardExpense(endDayResult.totalSmallCardExpence);
	setTotalBigMonthCardExpense(endDayResult.totalBigMonthCardExpence);
	setTotalExpense(endDayResult.totalExpense);

	//处理图表
	m_VecEstResult.clear();

	m_axisCrystalDate->setRange(QDateTime(startDayResult.currentDate), QDateTime(endDayResult.currentDate));
	m_axisTicketDate->setRange(QDateTime(startDayResult.currentDate), QDateTime(endDayResult.currentDate));

	m_axisCrystalVal->setRange(startDayEqualCrystal, endDayEqualCrystal);
	m_axisTicketVal->setRange(startDayEqualTicket, endDayEqualTicket);

	if (m_seriesEqualCrystal != nullptr)
	{
		disconnect(m_seriesEqualCrystal,	&QLineSeries::hovered, this, &ResourceEstimateWgt::slot_CrystalChartMouseHovered);
	}

	if (m_seriesEqualTicket != nullptr)
	{
		disconnect(m_seriesEqualTicket,		&QLineSeries::hovered, this, &ResourceEstimateWgt::slot_TicketChartMouseHovered);
	}

	m_ChtCrystal->removeAllSeries();
	m_ChtTicket->removeAllSeries();

	m_seriesEqualCrystal = new QLineSeries();
	m_seriesEqualTicket = new QLineSeries();

	connect(m_seriesEqualCrystal, &QLineSeries::hovered, this, &ResourceEstimateWgt::slot_CrystalChartMouseHovered);
	connect(m_seriesEqualTicket, &QLineSeries::hovered, this, &ResourceEstimateWgt::slot_TicketChartMouseHovered);

	for (auto pos = EstResultVec.cbegin(); pos!= EstResultVec.cend(); pos++)
	{
		m_VecEstResult.push_back(*pos);

		QDateTime currentDate((*pos).currentDate);
		
		qint64 MescEpoch = currentDate.toMSecsSinceEpoch();
		int EqualCrystal = getEqualCrystal(*pos);
		int EqualTicket = getEqualTicket(*pos);

		m_seriesEqualCrystal->append(MescEpoch, EqualCrystal);
		m_seriesEqualTicket->append(MescEpoch, EqualTicket);
	}

	m_ChtCrystal->addSeries(m_seriesEqualCrystal);
	m_ChtTicket->addSeries(m_seriesEqualTicket);

	//记录图表很坐标计算中间量
	QVector<QPointF> vecPointF = m_seriesEqualCrystal->pointsVector();

	//Debug用，实际不存在的情况
	if (vecPointF.size() == 0 || vecPointF.size() == 1)
	{
		m_startValue	= 0;
		m_endValue	= 0;
		m_totalLength	= 0;
		m_interval	= 0;
	}
	m_startValue		= vecPointF.begin()->x();
	m_endValue		= vecPointF.rbegin()->x();
	m_totalLength		= m_endValue - m_startValue;
	m_interval		= m_totalLength / vecPointF.size();


}

void ResourceEstimateWgt::slot_CrystalChartMouseHovered(const QPointF &point, bool state)
{
	int pointIndex = getPointIndex(point);

	if (pointIndex > m_VecEstResult.size() - 1)
	{
		return;
	}

	St_ResourceEstimateDateResult PointValue = m_VecEstResult[pointIndex];

	QString showText;

	showText.push_back("日期:");
	showText.push_back(PointValue.currentDate.toString("yyyy/MM/dd"));
	showText.push_back("\n等效星琼:");
	showText.push_back(QString::number(getEqualCrystal(PointValue)));

	QToolTip::showText(QCursor::pos(), showText);
}

void ResourceEstimateWgt::slot_TicketChartMouseHovered(const QPointF & point, bool state)
{
	int pointIndex = getPointIndex(point);

	if (pointIndex > m_VecEstResult.size() - 1)
	{
		return;
	}

	St_ResourceEstimateDateResult PointValue = m_VecEstResult[pointIndex];

	QString showText;

	showText.push_back("日期:");
	showText.push_back(PointValue.currentDate.toString("yyyy/MM/dd"));
	showText.push_back("\n等效专票:");
	showText.push_back(QString::number(getEqualTicket(PointValue)));

	QToolTip::showText(QCursor::pos(), showText);
}



