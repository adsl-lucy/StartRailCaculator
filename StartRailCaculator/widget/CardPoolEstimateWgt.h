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

//���س���λ�ø��ʷֲ�����
//������UI�߼��������߼�ί���н������
//����һ����Ҫ�Ĳο�ָ�꣬�����ж���ǰ״̬�½�ɫ/���������ĳɱ�

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
	//�����ͼ��ˢ���߼�
	void  slot_getCardPoolEstimateResult(const St_CardPoolEstimateResult& EstResult);
	void  slot_updateEstimateProgressVal(const int value);

protected:
	void initUI();

	void initChartWgt();
	//�ڼ�������п��ƿռ��Ƿ�ɸ���
	void setPanelEnable(bool state);


	void setCardPoolType(const QString& str);
	void setDistanceToBigGuarantee(const QString& str);
	void setGetUpOnSmallGuarantee(const QString& str);
	void setGetUpOnBigGuarantee(const QString& str);
	void setGetUpPosExpectation(const QString& str);
	void setGetUpCrystalExpenceExpectation(const QString& str);

	int	 getPointIndex(const QPointF& ChartPos);


protected slots:
	void  slot_startEstimate();
	void  slot_resetPara();
	void  slot_clearResult();

	//�����Ч����ͼ����������ź�
	void  slot_chartMouseHovered(const QPointF &point, bool state);


private:
	Ui_CardPoolEstimateWgt Ui;

	QButtonGroup*		m_poolTypeButtonGroup = nullptr;

	//�洢���ݼ�����
	QMap<int, double>	m_mapEstResult;

	//ͼ�����
	QValueAxis*			m_axisTicket = nullptr;

	QValueAxis*			m_axisProb = nullptr;

	//��ʱ���ݴ洢����ͼ�����ʱΪ��ָ��
	QLineSeries*		m_seriesProbDistribution = nullptr;

	QChart*				m_ChtProbDistribution = nullptr;

	QChartView*			m_ChtViewProbDistribution = nullptr;

	//��ΪQChart�Դ�ͼ��������ж�ʧ�����Զ������һ����λ�õ��м���
	qreal				m_startValue	= 0;		//ͼ��ʼ��xֵ
	qreal				m_endValue		= 0;		//ͼ�������xֵ
	qreal				m_totalLength	= 0;		//ͼ��xֵ���
	qreal				m_interval		= 0;		//ͼ��һ����ռ�ݵĳ���

};

#endif