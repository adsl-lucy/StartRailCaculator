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

#ifndef INVESTMENT_INCOME_WGT
#define INVESTMENT_INCOME_WGT

//投资收益分析窗口
//主要功能为统计花光输入资源之后，各种可能事件的概率分布
//可能是这个软件最有价值的模块

#include <QWidget>
#include <QDate>
#include <QSlider>
#include <QButtonGroup>
#include <QtDataVisualization>

using namespace QtDataVisualization;

#include "ui_InvestmentIncomeWgt.h"
#include "../protocol/protocol_StarRailCaculator.h"


class InvestmentIncomeWgt :
	public QWidget
{
	Q_OBJECT
public:
	InvestmentIncomeWgt(QWidget* parent);
	~InvestmentIncomeWgt();

signals:
	//开始估算资源投入收益
	void signal_StartInvestmentIncomeEstimate(const St_InvestmentEstimatePara& EstPara);

public slots:
	void slot_updateEstimateProgress(const int val);
	//接受计算结果，具体的图表刷新逻辑
	void slot_getInvestmentIncomeResult(const St_InvectmentEstimateResult& result);


protected:
	void	initUi();
	void	init3DGraph();

	//计算过程锁面板
	void enablePanel(bool state);

	void setInputCrystal(int value);
	void setInputTicket(int value);
	void setDrawCardType(En_DrawCardType drawCardType,En_PoolTransfromType	poolTransformType,int N,int M);
	void setNoUpCharacterProb(double prob);
	void setNoUpWeaponValue(double prob);
	void setUpCharacterGetExpectation(double expectation);
	void setUpWeaponGetExpectation(double expectation);

protected slots:
	void slot_drawCardObjChanged();
	void slot_transformTypeChanged();
	void slot_resetParameter();
	void slot_clearResult();
	void slot_startEstimate();

	void slot_cameraHAngleChanged(double degree);
	void slot_cameraVAanglechanged(double degree);
	void slot_cameraZoomLevelChanged(double zoomLevel);

	void slot_HAngleSliderValueChanged(int value);
	void slot_VAngleSliderValueChanged(int value);
	void slot_ZoomLevelSliderValueChanged(int value);

private:
	Ui_InvestmentIncomeWgt Ui;

	Q3DBars* m_Graph = nullptr;

	//摄像机
	Q3DCamera*			m_camera = nullptr;

	//三个坐标轴
	QCategory3DAxis*	m_axisCharacterNum	= nullptr;
	QCategory3DAxis*	m_axisWeaponNum		= nullptr;
	QValue3DAxis*		m_axisProbability	= nullptr;

	//概率密度矩阵
	QBar3DSeries*		m_seriesProbabilityDenseMatrix = nullptr;
	//具体的数据容器
	QBarDataProxy*		m_dataProxy = nullptr;
	
	QButtonGroup*		m_btnGroupDrawCardObj		= nullptr;		//抽卡对象按钮群
	QButtonGroup*		m_btnGroupPoolTransformType = nullptr;		//抽卡方式按钮群

};

#endif