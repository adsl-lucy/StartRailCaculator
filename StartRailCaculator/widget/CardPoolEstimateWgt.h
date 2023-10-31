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

#ifndef CARD_POOL_ESTIMATE_WGT
#define CARD_POOL_ESTIMATE_WGT

//卡池出货位置概率分布窗口
//仅包含UI逻辑，计算逻辑委托中介器完成
//这是一个重要的参考指标，可以判定当前状态下角色/武器出货的成本

#include <QWidget>
#include <QDate>
#include <QtCharts>

#include "./ui_CardPoolEstimateWgt.h"
#include "../protocol/protocol_StarRailCaculator.h"

class CardPoolEstimateWgt :
	public QWidget
{
	Q_OBJECT
public:
	CardPoolEstimateWgt(QWidget* parent);
	~CardPoolEstimateWgt();

signals:
	void signal_StartCardPoolEstimate(const St_CardPoolEstimatePara& EstPara);

public slots:
	//具体的图表刷新逻辑
	void  slot_getCardPoolEstimateResult(const St_CardPoolEstimateResult& EstResult);
	void  slot_updateEstimateProgressVal(const int value);

protected:
	void initUI();

	void initChartWgt();
	//在计算过程中控制空间是否可更改
	void setPanelEnable(bool state);


	void setCardPoolType(const QString& str);
	void setDistanceToBigGuarantee(const QString& str);
	void setGetUpOnSmallGuarantee(const QString& str);
	void setGetUpOnBigGuarantee(const QString& str);
	void setGetUpPosExpectation(const QString& str);
	void setGetUpCrystalExpenceExpectation(const QString& str);

	int  getPointIndex(const QPointF& ChartPos);


protected slots:
	void  slot_startEstimate();
	void  slot_resetPara();
	void  slot_clearResult();

	//处理等效星琼图表鼠标悬浮信号
	void  slot_chartMouseHovered(const QPointF &point, bool state);


private:
	Ui_CardPoolEstimateWgt Ui;

	QButtonGroup*		m_poolTypeButtonGroup = nullptr;

	//存储数据计算结果
	QMap<int, double>	m_mapEstResult;

	//图表相关
	QValueAxis*		m_axisTicket = nullptr;

	QValueAxis*		m_axisProb = nullptr;

	//临时数据存储对象，图表清空时为空指针
	QLineSeries*		m_seriesProbDistribution = nullptr;

	QChart*			m_ChtProbDistribution = nullptr;

	QChartView*		m_ChtViewProbDistribution = nullptr;

	//因为QChart自带图表的数据有丢失，所以额外添加一个算位置的中间量
	qreal			m_startValue	= 0;		//图表开始的x值
	qreal			m_endValue	= 0;		//图表结束的x值
	qreal			m_totalLength	= 0;		//图表x值跨度
	qreal			m_interval	= 0;		//图表一个点占据的长度

};

#endif
