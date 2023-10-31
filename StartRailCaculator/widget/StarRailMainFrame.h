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

//�����ڣ����ڷ��벻ͬ�Ӵ���ͬʱ�����ź� + ����tabWidget��ǩ��ť״̬

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
	//������Դ�����ź�
	void signal_StartEstimateResource(const St_ResourceEstimateParameter& EstPara);
	//������Դ�����ź�
	void signal_ResouceEstErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
	//������Դ�������ź�
	void signal_ResouceEstResult(const QVector<St_ResourceEstimateDateResult>& EstResultVec);
	//���Ϳ���ֹͣʵ��ģ���ź�
	void signal_StartCardPoolEstimate(const St_CardPoolEstimatePara& EstPara);
	//N��֮�ڳ�������ģ����
	void signal_CardPoolEstResult(const St_CardPoolEstimateResult& EstResult);
	//N��֮�ڳ�������ģ����ȣ�0Ϊ�տ�ʼ��100Ϊ���
	void signal_UpdateCardPoolEstmateProgress(const int value);
	//��ʼ������ԴͶ������
	void signal_StartInvestmentIncomeEstimate(const St_InvestmentEstimatePara& EstPara);
	//��ԴͶ������ģ�⾫�ȣ�0Ϊ�տ�ʼ��100Ϊ���
	void signal_UpdateInvestmentEstimateProgress(const int val);
	//Ͷ����������ͳ��
	void signal_InvestmentEstimateResult(const St_InvectmentEstimateResult& result);
	//��ʼ������Чʥ����
	void signal_StartRelicValidEstimate(const St_RelicValidEstimatePara& EstPara);
	//��Чʥ�����������ź�
	void signal_RelicEstErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
	//��Чʥ�������ģ����ȣ�0Ϊ�տ�ʼ��100Ϊ���
	void signal_UpdateRelicEstimateProgress(const int val);
	//��Чʥ���������
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