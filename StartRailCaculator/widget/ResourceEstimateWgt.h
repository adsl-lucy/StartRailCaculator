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

#ifndef RESOURCE_ESTIMATE_WGT
#define RESOURCE_ESTIMATE_WGT

//指定日期资源计算窗口，用以估计卡池前后的资源状况
//仅包含权重最大的几个收益点：日常/大小月卡/模拟宇宙/深渊
//误差最大的窗口，主要在于目前活动收益不大好判断，所以忽略活动
//蚊子腿不统计是为了面板简洁

#include <QWidget>
#include <QDate>
#include <QtCharts>

#include "./ui_ResourceEstimateWgt.h"
#include "../protocol/protocol_StarRailCaculator.h"

class ResourceEstimateWgt :
    public QWidget
{
    Q_OBJECT
public:
    ResourceEstimateWgt(QWidget* parent);
    ~ResourceEstimateWgt();

signals:
    void signal_StartEstimateResource(const St_ResourceEstimateParameter& EstPara);


protected:
    void initPannelWgt();
    void initGraphWgt();

protected:
	//统计结论打印逻辑，输入-1则清空数值
    void setCurrentEqualCrystal(int value);
    void setCurrentEqualTicket(int value);
    void setStopDayCrystal(int value);
    void setStopDayTicket(int value);
    void setStopDayPaidCrystal(int value);
    void setStopDayEqualCrystal(int value);
    void setStopDayEqualTicket(int value);
    void setTotalSmallMonthCardExpense(int value);
    void setTotalBigMonthCardExpense(int value);
    void setTotalExpense(int value);

    int	 getEqualCrystal(const St_ResourceEstimateDateResult& EstResult);
    int  getEqualTicket(const St_ResourceEstimateDateResult& EstResult);
    int	 getPointIndex(const QPointF& ChartPos);

public slots:
    void slot_getErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
    void slot_getResourceEstResult(const QVector<St_ResourceEstimateDateResult>& EstResultVec);

//处理图表鼠标悬停事件
//处理等效星琼图表鼠标悬浮信号
    void slot_CrystalChartMouseHovered(const QPointF &point, bool state);
    void slot_TicketChartMouseHovered(const QPointF &point, bool state);

protected slots:
    void slot_startEstmate();
    void slot_resetParameter();
    void slot_clearResult();



private:
	Ui_ResourceEstimateWgt Ui;
    //存储数据计算结果
	QVector<St_ResourceEstimateDateResult> m_VecEstResult;

	//图表相关
	QDateTimeAxis*  m_axisCrystalDate	= nullptr;
	QDateTimeAxis*  m_axisTicketDate	= nullptr;

	QValueAxis*	m_axisCrystalVal	= nullptr;
	QValueAxis*	m_axisTicketVal		= nullptr;

	//临时数据存储对象，图表清空时为空指针
	QLineSeries*	m_seriesEqualCrystal	= nullptr;	
	QLineSeries*	m_seriesEqualTicket	= nullptr;

	QChart*		m_ChtCrystal		= nullptr;
	QChart*		m_ChtTicket		= nullptr;

	QChartView*	m_ChtViewCrystal	= nullptr;
	QChartView*	m_ChtViewTicket		= nullptr;

	//因为QChart自带图表的数据有丢失，所以额外添加一个算位置的中间量
	qreal		m_startValue	= 0;//图表开始的x值
	qreal		m_endValue	= 0;//图表结束的x值
	qreal		m_totalLength	= 0;//图表x值跨度
	qreal		m_interval	= 0;//图表一个点占据的长度
};

#endif
