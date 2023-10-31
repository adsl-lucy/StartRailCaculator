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

//��Чʥ������㴰��
//ԭ����ʥ�������ϸͳ�ƽ����һ��15ά����������Ϊ�˷���ʹ�ã�����ֻͳ�Ʊ�ĳ��ʥ����õĳ������ʷֲ�

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
	//���¼��������
	void	slot_UpdateRelicEstimateProgress(int val);
	//��Чʥ���������
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

	int		getPrimeChtPointIndex(const QPointF& ChartPos);
	int		getAllChtPointIndex(const QPointF& ChartPos);

	void	enablePannel(bool state);


protected slots:
	void	slot_relicChanged(int btnId);
	void	slot_resetPara();
	void	slot_startEstimate();
	void	slot_clearResult();

	//�����Ч����ͼ����������ź�
	void slot_PrimePropertyChartMouseHovered(const QPointF &point, bool state);
	void slot_SubPropertyChartMouseHovered(const QPointF &point, bool state);


private:
	Ui_RelicCultivateWgt Ui;

	QButtonGroup*		m_RelicBtnGroupBox = nullptr;

	QVector <double>	m_VecPrimePropertyTimesProb;		//��������Ч���������ܶȣ�index���Ǹ���	
	QVector <double>	m_VecAllPropertyTimesProb;			//����������Ч���������ܶȣ�index���Ǹ�����ȫ������Ч= ��������Ч+��������Ч

	//ͼ�����
	QValueAxis*			m_axisPrimePropertyValidTime	= nullptr;
	QValueAxis*			m_axisAllPropertyValidTime		= nullptr;

	QValueAxis*			m_axisPrimePropertyValidProb	= nullptr;
	QValueAxis*			m_axisAllPropertyValidProb		= nullptr;

	//��ʱ���ݴ洢����ͼ�����ʱΪ��ָ��
	QLineSeries*		m_seriesPrimePropertyDensity	= nullptr;
	QLineSeries*		m_seriesAllPropertyDensity		= nullptr;

	QChart*				m_ChartPrimeProperty			= nullptr;
	QChart*				m_ChartAllProperty				= nullptr;
		
	QChartView*			m_ChartViewPrimeProperty		= nullptr;
	QChartView*			m_ChartViewAllProperty			= nullptr;

	//��ΪQChart�Դ�ͼ��������ж�ʧ�����Զ������һ����λ�õ��м���
	//������ͼ
	qreal			m_PriChtStartValue	= 0;//ͼ��ʼ��xֵ
	qreal			m_PriChtEndValue	= 0;//ͼ�������xֵ
	qreal			m_PriChtTotalLength = 0;//ͼ��xֵ���
	qreal			m_PriChtInterval	= 0;//ͼ��һ����ռ�ݵĳ���
	//ȫ����ͼ
	qreal			m_AllChtStartValue	= 0;//ͼ��ʼ��xֵ
	qreal			m_AllChtEndValue	= 0;//ͼ�������xֵ
	qreal			m_AllChtTotalLength = 0;//ͼ��xֵ���
	qreal			m_AllChtInterval	= 0;//ͼ��һ����ռ�ݵĳ���

};

#endif