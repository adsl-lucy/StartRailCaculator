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

#include "StarRailMainFrame.h"
#pragma execution_character_set("utf-8")

StarRailMainFrame::StarRailMainFrame():QWidget(nullptr)
{
	initUi();
	initSignalSlots();
	//setSize
}

StarRailMainFrame::~StarRailMainFrame()
{
}

void StarRailMainFrame::initUi()
{
	Ui.setupUi(this);

	m_ResourceEstimateWgt	= new ResourceEstimateWgt(this);
	m_CardPoolEstimateWgt	= new CardPoolEstimateWgt(this);
	m_InvestmentIncomeWgt	= new InvestmentIncomeWgt(this);
	m_RelicCultivateWgt	= new RelicCultivateWgt(this);

	Ui.tabWidget->insertTab(0, m_ResourceEstimateWgt,	"资源计算器");
	Ui.tabWidget->insertTab(1, m_CardPoolEstimateWgt,	"N抽之内出货概率");
	Ui.tabWidget->insertTab(2, m_InvestmentIncomeWgt,	"资源投入与出货分析");
	Ui.tabWidget->insertTab(3, m_RelicCultivateWgt,		"有效圣遗物估计");

	//直接第3页，因为这一页最有用
	Ui.tabWidget->setCurrentIndex(2);

}

void StarRailMainFrame::initSignalSlots()
{
	connect(m_ResourceEstimateWgt,  &ResourceEstimateWgt::signal_StartEstimateResource,	this,			&StarRailMainFrame::signal_StartEstimateResource);
	connect(this,			&StarRailMainFrame::signal_ResouceEstErrorMsg,		m_ResourceEstimateWgt,	&ResourceEstimateWgt::slot_getErrorMsg);
	connect(this,			&StarRailMainFrame::signal_ResouceEstResult,		m_ResourceEstimateWgt,	&ResourceEstimateWgt::slot_getResourceEstResult);

	connect(m_CardPoolEstimateWgt,	&CardPoolEstimateWgt::signal_StartCardPoolEstimate, this,					
		[=](const St_CardPoolEstimatePara& EstPara)
	{
		Ui.tabWidget->tabBar()->setEnabled(false);
		emit signal_StartCardPoolEstimate(EstPara);
	});
	connect(this,	&StarRailMainFrame::signal_CardPoolEstResult,	this,
		[=](const St_CardPoolEstimateResult& EstResult)
	{
		Ui.tabWidget->tabBar()->setEnabled(true);
		m_CardPoolEstimateWgt->slot_getCardPoolEstimateResult(EstResult);
	});

	connect(this,	&StarRailMainFrame::signal_UpdateCardPoolEstmateProgress, m_CardPoolEstimateWgt, &CardPoolEstimateWgt::slot_updateEstimateProgressVal);

	connect(m_InvestmentIncomeWgt, &InvestmentIncomeWgt::signal_StartInvestmentIncomeEstimate, this,
		[=](const St_InvestmentEstimatePara& EstPara)
	{
		Ui.tabWidget->tabBar()->setEnabled(false);
		emit signal_StartInvestmentIncomeEstimate(EstPara);
	});

	connect(this, &StarRailMainFrame::signal_UpdateInvestmentEstimateProgress, m_InvestmentIncomeWgt, &InvestmentIncomeWgt::slot_updateEstimateProgress);
	connect(this, &StarRailMainFrame::signal_InvestmentEstimateResult,this,
		[=](const St_InvectmentEstimateResult& result)
	{
		Ui.tabWidget->tabBar()->setEnabled(true);
		m_InvestmentIncomeWgt->slot_getInvestmentIncomeResult(result);
	});

	connect(m_RelicCultivateWgt, &RelicCultivateWgt::signal_StartRelicValidEstimate, this,
		[=](const St_RelicValidEstimatePara& EstPara)
	{
		Ui.tabWidget->tabBar()->setEnabled(false);
		emit signal_StartRelicValidEstimate(EstPara);
	});

	connect(this, &StarRailMainFrame::signal_RelicEstErrorMsg, this, [=](const EN_StarRailErrorNum ErrNum, const QString& ErrMsg) 
	{
		if (ErrNum != EN_StarRailErrorNum::RelicEst_InputNoError)
		{
			Ui.tabWidget->tabBar()->setEnabled(true);
		}
		m_RelicCultivateWgt->slot_getErrorMsg(ErrNum, ErrMsg);
	});
	connect(this, &StarRailMainFrame::signal_UpdateRelicEstimateProgress, m_RelicCultivateWgt, &RelicCultivateWgt::slot_UpdateRelicEstimateProgress);
	connect(this, &StarRailMainFrame::signal_RelicEstResult, m_RelicCultivateWgt, &RelicCultivateWgt::slot_getRelicEstResult);

	connect(this, &StarRailMainFrame::signal_RelicEstResult, this,
		[=](const St_ValidRelicEstimateResult& EstResult)
	{
		Ui.tabWidget->tabBar()->setEnabled(true);
		m_RelicCultivateWgt->slot_getRelicEstResult(EstResult);
	});



}
