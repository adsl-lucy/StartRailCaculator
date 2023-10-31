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

#ifndef RELIC_CULTIVATE_WGT
#define RELIC_CULTIVATE_WGT

//有效圣遗物计算窗口
//原则上圣遗物的详细统计结果是一个15维向量，但是为了方便使用，这里只统计比某个圣遗物好的出货概率分布

#include <QWidget>
#include <QDate>
#include <QtCharts>

#include "./ui_RelicCultivateWgt.h"
#include "../protocol/protocol_StarRailCaculator.h"

class RelicCultivateWgt :
	public QWidget
{
	Q_OBJECT
public:
	RelicCultivateWgt(QWidget* parent);
	~RelicCultivateWgt();

signals:
	void	signal_StartRelicValidEstimate(const St_RelicValidEstimatePara& EstPara);
public slots:
	void	slot_getErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
	//更新计算进度条
	void	slot_UpdateRelicEstimateProgress(int val);
	//有效圣遗物计算结果
	void	slot_getRelicEstResult(const St_ValidRelicEstimateResult& EstResult);

protected:
	void	initUi();
	void	initSubProSpinboxUi();
	void	initGraphWgt();

	void	setPrimePropertyValidProportion(const QString& str);
	void	setPrimePropertyValidGetProbability(const QString& str);
	void	setPrimePropertyValidGetTimeExpectation(const QString& str);
	void	setPrimePropertyValidPlayTimeExpectation(const QString& str);

	void	setAllPropertyValidProportion(const QString& str);
	void	setAllPropertyValidGetProbaility(const QString& str);
	void	setAllPropertyValidGetTimeExpectation(const QString& str);
	void	setAllPropertyValidPlayTimeExpectation(const QString& str);

	int	getPrimeChtPointIndex(const QPointF& ChartPos);
	int	getAllChtPointIndex(const QPointF& ChartPos);

	void	enablePannel(bool state);


protected slots:
	void	slot_relicChanged(int btnId);
	void	slot_resetPara();
	void	slot_startEstimate();
	void	slot_clearResult();

	//处理等效星琼图表鼠标悬浮信号
	void slot_PrimePropertyChartMouseHovered(const QPointF &point, bool state);
	void slot_SubPropertyChartMouseHovered(const QPointF &point, bool state);


private:
	Ui_RelicCultivateWgt Ui;

	QButtonGroup*		m_RelicBtnGroupBox = nullptr;

	QVector <double>	m_VecPrimePropertyTimesProb;		//主属性有效遗器概率密度，index就是个数	
	QVector <double>	m_VecAllPropertyTimesProb;		//所有属性有效遗器概率密度，index就是个数，全属性有效= 主属性有效+副属性有效

	//图表相关
	QValueAxis*		m_axisPrimePropertyValidTime	= nullptr;
	QValueAxis*		m_axisAllPropertyValidTime	= nullptr;

	QValueAxis*		m_axisPrimePropertyValidProb	= nullptr;
	QValueAxis*		m_axisAllPropertyValidProb	= nullptr;

	//临时数据存储对象，图表清空时为空指针
	QLineSeries*		m_seriesPrimePropertyDensity	= nullptr;
	QLineSeries*		m_seriesAllPropertyDensity	= nullptr;

	QChart*			m_ChartPrimeProperty		= nullptr;
	QChart*			m_ChartAllProperty		= nullptr;
		
	QChartView*		m_ChartViewPrimeProperty	= nullptr;
	QChartView*		m_ChartViewAllProperty		= nullptr;

	//因为QChart自带图表的数据有丢失，所以额外添加一个算位置的中间量
	//主属性图
	qreal			m_PriChtStartValue	= 0;//图表开始的x值
	qreal			m_PriChtEndValue	= 0;//图表结束的x值
	qreal			m_PriChtTotalLength 	= 0;//图表x值跨度
	qreal			m_PriChtInterval	= 0;//图表一个点占据的长度
	//全属性图
	qreal			m_AllChtStartValue	= 0;//图表开始的x值
	qreal			m_AllChtEndValue	= 0;//图表结束的x值
	qreal			m_AllChtTotalLength 	= 0;//图表x值跨度
	qreal			m_AllChtInterval	= 0;//图表一个点占据的长度

};

#endif
