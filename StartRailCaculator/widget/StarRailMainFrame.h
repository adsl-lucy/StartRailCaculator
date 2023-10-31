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

#ifndef STARRAIL_MAINFRAME
#define STARRAIL_MAINFRAME

//主窗口，用于分离不同子窗口同时传递信号 + 控制tabWidget标签按钮状态

#include <QWidget>
#include <QTabWidget>

#include "ResourceEstimateWgt.h"
#include "CardPoolEstimateWgt.h"
#include "InvestmentIncomeWgt.h"
#include "RelicCultivateWgt.h"

#include "ui_StarRailMainFrame.h"

class StarRailMainFrame : public QWidget
{
	Q_OBJECT
public:
	StarRailMainFrame();
	~StarRailMainFrame();

signals:
	//发送资源计算信号
	void signal_StartEstimateResource(const St_ResourceEstimateParameter& EstPara);
	//发送资源错误信号
	void signal_ResouceEstErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
	//传递资源计算结果信号
	void signal_ResouceEstResult(const QVector<St_ResourceEstimateDateResult>& EstResultVec);
	//发送卡池停止实验模拟信号
	void signal_StartCardPoolEstimate(const St_CardPoolEstimatePara& EstPara);
	//N步之内出货概率模拟结果
	void signal_CardPoolEstResult(const St_CardPoolEstimateResult& EstResult);
	//N步之内出货概率模拟进度，0为刚开始，100为完成
	void signal_UpdateCardPoolEstmateProgress(const int value);
	//开始估算资源投入收益
	void signal_StartInvestmentIncomeEstimate(const St_InvestmentEstimatePara& EstPara);
	//资源投入收益模拟精度，0为刚开始，100为完成
	void signal_UpdateInvestmentEstimateProgress(const int val);
	//投资与收益结果统计
	void signal_InvestmentEstimateResult(const St_InvectmentEstimateResult& result);
	//开始估算有效圣遗物
	void signal_StartRelicValidEstimate(const St_RelicValidEstimatePara& EstPara);
	//有效圣遗物计算错误信号
	void signal_RelicEstErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
	//有效圣遗物计算模拟进度，0为刚开始，100为完成
	void signal_UpdateRelicEstimateProgress(const int val);
	//有效圣遗物计算结果
	void signal_RelicEstResult(const St_ValidRelicEstimateResult& EstResult);

protected:
	void initUi();
	void initSignalSlots();

private:
	Ui_StarRainMainFrame Ui;
	ResourceEstimateWgt*	m_ResourceEstimateWgt	= nullptr;
	CardPoolEstimateWgt*	m_CardPoolEstimateWgt	= nullptr;
	InvestmentIncomeWgt*	m_InvestmentIncomeWgt	= nullptr;
	RelicCultivateWgt*		m_RelicCultivateWgt		= nullptr;
};

#endif